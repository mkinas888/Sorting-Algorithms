#ifndef ALGORITHMSDECLARATIONS_HH
#define ALGORITHMSDECLARATIONS_HH

#include <iostream>

template <typename type>
void sortByMerge (type *array, type firstElem, type lastElem) {
  type middleElem; 
  if(firstElem < lastElem) {
    middleElem = (firstElem + lastElem) / 2;      // find the middle so as to split array in half
    sortByMerge(array, firstElem, middleElem);    // next sort two halves of initial array
    sortByMerge(array, middleElem + 1, lastElem); 
    mergeArray (array, firstElem, middleElem, lastElem); //merge sorted halves into sorted array
  }
}

#endif