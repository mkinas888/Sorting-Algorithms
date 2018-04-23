#ifndef ALGORITHMSDECLARATIONS_HH
#define ALGORITHMSDECLARATIONS_HH

/* Function declarations for merge sort */
template <typename type> void sortByMerge (type  array[], type firstElem, type lastElem);
template <typename type> void mergeArray(type  array[], type low, type high, type mid);

/* Function declarations for quick sort */
template <typename type> void sortByQuicksort (type array[], type firstElem, type lastElem);
template <typename type> void swapElements (type & firstElem, type & secondElem);

/* Function declarations for intro sort */

/* Function declarations for heap sort */
template <typename type> void fixHeapStructure(type array[], type heapSize, type index);
template <typename type> void sortByHeapSort(type array[], type size);

/* Function declarations for insertion sort */
template <typename type> void sortByInsertionSort(type array[], type size);

template <typename type> void sortByIntroSort(type array[], type size, type *firstElem, type *lastElem);

/* Function for validation if array is sorted properly */
template <typename type> bool checkIfArrayIsSorted (type array[], type size);

#endif