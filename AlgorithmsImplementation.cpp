#include "AlgorithmsDeclarations.hh"

template <typename type>
void sortByMerge (type array[], type firstElem, type lastElem) {
  type middleElem; 
  if(firstElem < lastElem) {
    middleElem = (firstElem + lastElem) / 2;      // find the middle so as to split array in half
    sortByMerge(array, firstElem, middleElem);    // next sort two halves of initial array
    sortByMerge(array, middleElem + 1, lastElem); 
    mergeArray (array, firstElem, middleElem, lastElem); //merge sorted halves into sorted array
  }
}

template <typename type>
void mergeArray (type array[], type firstElem, type middleElem, type lastElem) {

 type i, j, k;                                              //helper variables
    type tempLeftSize = middleElem - firstElem + 1;         // get size needed to create temp arrays
    type tempRightSize =  lastElem - middleElem;
    type tempLeft[tempLeftSize], tempRight[tempRightSize];  // create temp arrays 
 
    /* Copy data to temp arrays tempLeft and tempRight */
    for (i = 0; i < tempLeftSize; i++)
        tempLeft[i] = array[firstElem + i];
    for (j = 0; j < tempRightSize; j++)
        tempRight[j] = array[middleElem + 1+ j];
 
    /* Merge the temp arrays back into sorted array*/
    i = 0;                                          // Index of tempLeft
    j = 0;                                          // Index of tempRight
    k = firstElem;                                  // Index of sorted array
    while (i < tempLeftSize && j < tempRightSize)
    {
        if (tempLeft[i] <= tempRight[j])
        {
            array[k] = tempLeft[i];
            i++;
        }
        else
        {
            array[k] = tempRight[j];
            j++;
        }
        k++;
    }
 
    /* If some elemnts of temp arrays are left copy them too */
    while (i < tempLeftSize)
    {
        array[k] = tempLeft[i];
        i++;
        k++;
    }
 
    while (j < tempRightSize)
    {
        array[k] = tempRight[j];
        j++;
        k++;
    }
}
 
 