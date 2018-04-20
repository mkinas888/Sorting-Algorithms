#include "AlgorithmsDeclarations.hh"

#include <iostream>
#include <cmath>

using namespace std;

template <typename type>
void sortByMerge (type array[], type firstElem, type lastElem) {
  type middleElem; 
  if(firstElem < lastElem) {
    middleElem = (firstElem + lastElem) / 2;      // find the middle so as to split array in half
    sortByMerge(array, firstElem, middleElem);    // next sort two halves of initial array
    sortByMerge(array, middleElem + 1, lastElem); 
    mergeArray(array, firstElem, middleElem, lastElem); //merge sorted halves into sorted array
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
    i = 0;                                          // index of tempLeft
    j = 0;                                          // index of tempRight
    k = firstElem;                                  // index of sorted array

    /* As long as both arrays are not exceeded */
    while (i < tempLeftSize && j < tempRightSize)   
    {
        if (tempLeft[i] <= tempRight[j])            // choose smaller element
        {
            /* If left array element is smaller put it into array to be sorted */
            array[k] = tempLeft[i];                 
            i++;                                    
        }
        else
        {
            /* If not put element from right array */
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

template <typename type>
void swapElements (type & firstElem, type & secondElem) {
    type tempElem = firstElem;              // helper variable set as first element to swap
    firstElem = secondElem;                 // first element becomes second
    secondElem = tempElem;                  // second becomes first
}

template <typename type>
void sortByQuicksort(type array[], type firstElem, type lastElem) {

    type i, j, pivotElem;                           // helper variables
    i = firstElem;
    j = lastElem;
    pivotElem = array[(firstElem + lastElem) / 2];  // pivotElem is chosen in the middle

    while (i <= j) {

     while (array[i] < pivotElem) {
        i++;
     }
     while (array[j] > pivotElem) {
         j--;
     }
    if (i <= j) {
        swapElements(array[i], array[j]);
        i++;
        j--;
    }
    }; 

    /* Recusively sort elements so as to array become sorted */
    if (firstElem < j) { 
        sortByQuicksort(array, firstElem, j);
    }

    if (i < lastElem) {
        sortByQuicksort(array, i, lastElem);
    }
}





template <typename type>
type calculatePartitionSize(type array[], type firstElem, type lastElem) {

    type pivotElem = array[lastElem];   
    type i = firstElem ;  
 
    for (type j = firstElem; j <= lastElem; j++)
    {
        if (array[j] <= pivotElem)      // If current element is smaller than or equal to pivot
        {
            i++;                                // go further in array
            swapElements(array[i], array[j]);   // and swap current elements  
        }
    }
    swapElements(array[i], array[lastElem]);
    return i ;
}
 







template <typename type>
void fixHeapStructure(type array[], type heapSize, type index) {
    
	type leftHalf = (index + 1) * 2 - 1;                 // Divide array on two halves
	type rightHalf = (index + 1) * 2;
	type largestElem = 0;

    /* Decide where is largest element */
	if (leftHalf < heapSize && array[leftHalf] > array[index])
		largestElem = leftHalf;
	else
		largestElem = index;

	if (rightHalf < heapSize && array[rightHalf] > array[largestElem])
		largestElem = rightHalf;

	if (largestElem != index)                            // if largest element is not index
	{
        swapElements(array[index], array[largestElem]);  // swap index and largest elem
		fixHeapStructure(array, heapSize, largestElem);  // fix structure again
	}                                                    // until index is largest
}

template <typename type>
void sortByHeapSort(type array[], type size) {
	type heapSize = size;

	for (type i = (heapSize - 1) / 2; i >= 0; i--)
		fixHeapStructure(array, heapSize, i);            // Fix structure for first half 

	for (type j = size - 1; j > 0; j--)
	{
		swapElements(array[j], array[0]);                // swap elements
		heapSize--;                                      // decrease size of heap
		fixHeapStructure(array, heapSize, 0);            // fix structure
	}
}

template <typename type>
void sortByInsertionSort(type array[], type size) {
	for (type i = 1; i < size; ++i)                      // Cycle through array
	{
		type j = i;

		while (j > 0)
		{
			if (array[j - 1] > array[j])                 // If previous element is bigger than current
			{
				swapElements(array[j-1], array[j]);      // swap them
				--j;                                
			}
			else
			{
				break;
			}
		}
	}
}

template <typename type>
void sortByIntroSort(type array[], type size) {
	type partitionSize = calculatePartitionSize(array, 0, size - 1);

    /* Depending on partition size choose which sorting algorithm you should use */
	if (partitionSize < 16)
	{
		sortByInsertionSort(array,size);
	}
	else if (partitionSize >(2 * log(size)))
	{
		sortByHeapSort(array, size);
	}
	else
	{
		sortByQuicksort(array, 0, size - 1);
	}
}


template <typename type>
bool checkIfArrayIsSorted (type array[], type size) {
    bool isSorted = true;
    for(type i = 0; i < size - 1; i++) {
        if (array[i] > array[i+1]) {       // Check if previous element is smaller than current
            isSorted = false;              // set param isSorted to false
        }
    }
    return isSorted;
}
 
 