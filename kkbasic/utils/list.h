/*  
 *  @file     list.h
 *  @author   kaka_ace <xiang.ace@gmail.com>
 *  @date     Mon Aug 18  01:24:00 2014
 *  @brief    list with template 
 *            inspired from redis adlist.{h,c} and rtmpd(version 781)
 */


#ifndef KKBASIC_LIST_H
#define KKBASIC_LIST_H 

/*
 *  non thread-safe
 *  To do:
 *  1. now just using new delete, not high performence
 *     maybe add array to prepare some space 
 *  2. iterator 
 *
 */

#include <stdexcept>

namespace kkbasic { 
namespace utils { 

template<typename T>
struct ListNode {
    ListNode<T> *pPrev;
    ListNode<T> *pNext;
    T info;
};


template<typename T> 
struct List {
public:
    List() {
        pFront_ = nullptr;
        pBack_ = nullptr;
        size_ = 0; 
    }
    ~List() {
        while (size_ > 0) {
            pop_list_(true);
        }
    }

    T const& front() const throw (std::runtime_error) {
        if (pFront_ == nullptr) {
            throw std::runtime_error("kkbasic::List is empty!!, could not get front");
        } 
        return pFront_->info; 
    }

    T const& back() const throw (std::runtime_error) {
        if (pBack_ == nullptr) {
            throw std::runtime_error("kkbasic::List is empty!!, could not get back");
        } 
        return pBack_->info;
    }

    void push_front(T info) {
        push_list_(info, false); 
    } 

    void pop_front() {
        pop_list_(false);
    } 

    void push_back(T info) {
        push_list_(info, true); 
    } 

    void pop_back() {
        pop_list_(true);
    } 

    bool empty() { return size_ == 0; }

    std::size_t size() {
        return size_;     
    }

private:
    typedef ListNode<T> NodeType;
    NodeType *pFront_;
    NodeType *pBack_;
    std::size_t size_;

    void push_list_(T info, bool positive = true); // positive == true : after pBack or before pFront
    void pop_list_(bool positive = true);
};

template <typename T>
void List<T>::push_list_(T info, bool positive) {
    NodeType *pNode = new NodeType;
    pNode->pNext = nullptr;
    pNode->pPrev = nullptr;
    pNode->info = info;

    if (size_ == 0) {
        pFront_ = pBack_ = pNode;
    } else {
        if (positive) {
            pBack_->pNext = pNode;
            pNode->pPrev = pBack_; 
            pBack_ = pNode;
        } else {
            pNode->pNext = pFront_;
            pFront_->pPrev = pNode;
            pFront_ = pNode;
        }
    }
    ++size_;
}

template<typename T>
void List<T>::pop_list_(bool positive) {
    if (size_ == 0) { // equal to this->empty() == true, just no need call function  
        return; 
    }

    NodeType *pTmp; 
    if (positive == true) {
        pTmp = pBack_;
        pBack_ = pTmp->pPrev;
        if (pBack_ != nullptr) // size_ > 1
            pBack_->pNext = nullptr;
    } else {
        pTmp = pFront_;         
        pFront_ = pTmp->pNext;
        if (pFront_ != nullptr) // size_ > 1
            pFront_->pPrev = nullptr;
    }
    delete pTmp;
    size_--;
}

} // namespace utils  
} // namespace kkbasic
#endif /* KKBASIC_LIST_H */
