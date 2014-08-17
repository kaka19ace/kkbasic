#ifndef KKBASIC_STACK_H
#define KKBASIC_STACK_H

#include "kkbasic/list.hpp"

namespace kkbasic {

template <typename T>
struct Stack {
public:
    bool empty() const { return list->empty(); }
    T const& top() const throw (std::runtime_error) {
        if (true == list->empty()) { 
            throw std::runtime_error("kkbasic::Stack is empty");
        }
        return list->front();
    }

    void push(T const &v) {
        list->push_front(v);
    }

    void pop() {
        if (false == list->empty()) {
            list->pop_front();
        }
    }

    Stack() { list = new ListType; }
    ~Stack() {
        while (!list->empty()) {
            list->pop_front();
        }
        delete list;
    }


private:
    typedef List<T> ListType;
    ListType *list;

    // NO COPY CONSTRUCT, NO ASSIGN
    Stack operator=(Stack const &) {}
    Stack(Stack const &s) {}
};


}

#endif // KKBASIC_STACK_H
