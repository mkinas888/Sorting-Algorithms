#ifndef ALGORITHMSDECLARATIONS_HH
#define ALGORITHMSDECLARATIONS_HH

/* Function declarations for merge sort */
template <typename type> void sortByMerge (type  array[], type firstElem, type lastElem);
template <typename type> void mergeArray(type  array[], type low, type high, type mid);

/* Function declarations for quick sort */
template <typename type> void sortByQuicksort (type array[], type firstElem, type lastElem);
template <typename type> void swapElements (type & firstElem, type & secondElem);

#endif