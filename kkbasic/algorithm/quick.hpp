/*  
 *  @file     kkbasic/algorithm/quick.hpp  
 *  @author   kaka_ace <xiang.ace@gmail.com>
 *  @date     Mon Aug 18 01:29:00 2014
 *  @brief    quick sort cpp with template 
 *            when sort list length is less than 10, i used insert sort 
 */

#ifdef KKBASIC_ALGORITHM_QUICK_H

namespace kkbasic {
namespace algorithm {
// insert sort (shell sort)
template<typename T, size_t N>
void shell(T (&array)[N])
{
    unsigned int gap = N;
    T temp; 
    do {
        gap = gap / 3 + 1; 
        for (int i = 0; i + gap < N; i++) {
            if (array[i] > array[i + gap]) {
                T temp = array[i + gap];
                int j = i;
                for (; j >= 0 && array[j] > temp;  j-=gap) {
                    array[j+gap] = array[j]; 
                }
                array[j+gap] = temp; 
            } 
        }
    } while(gap  > 1);
}

template<typename T>
unsigned int getMidValueItem(T a, T b, T c)
{
    if (b <= a && a <= c) {
        return 1;
    } 
    if (a <= b && b <= c) {
        return 2;
    }
    return 3;
}

template<typename T, size_t N>
void swap(T (&array)[N], unsigned int i, unsigned int j)
{
    T temp = array[i]; 
    array[i] = array[j];
    array[j] = temp;
}



template<typename T, size_t N>
unsigned int partition(T (&array)[N], unsigned int low, unsigned int high)
{
    T pivotkey;
    unsigned int i = 0;
    unsigned int mid = (low + high) / 2; 
    i = getMidValueItem(array[low], array[mid], array[high]); 
    pivotkey = array[low]; 
    if (i == 2) {
        pivotkey = array[mid]; 
        array[mid] = array[low];
        array[low] = pivotkey; 
    }
    if (i == 3) {
        pivotkey = array[high]; 
        array[high] = array[low];
        array[low] = pivotkey; 
    }

    while (low < high) {
        while (low < high && array[high] >= pivotkey) { high--; }
        swap(array, low, high);
        while (low < high && array[low] <= pivotkey) { low++; }
        swap(array, low, high);
    }
    return low;
}

template<typename T, size_t N>
void quick(T (&array)[N], unsigned int low, unsigned int high)
{
    if (low >= high) { return; }
    if (high - low <= 10) {
        shell<T>(array);
        return;
    }
    unsigned int pivot = partition(array, low, high);
    quick(array, low, pivot - 1);
    quick(array, pivot + 1, high);
}


} // namespace algorithm
} // namespace kkbasic

#endif // KKBASIC_ALGORITHM_QUICK_H

// test 
/*
#include <iostream>
using namespace std;
#include "kkbasic/algorithm.hpp"
int main()
{
    int a[10] = {9,  8, 3, 4, 5, 1, 6, 0, 2, 7};
    kkbasic::algorithm::quick<int>(a, 0, 9);
    for (int i; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
*/


