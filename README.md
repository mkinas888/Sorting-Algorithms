# Sorting-Algorithms
Mergesort Quicksort and Introsort implemented on template.

When using program you must pass two argument:
  * Percent of elements sorted in array at the beginnig
  * Number of elements in array to be sorted
  * **Optional** String "reverse" if you want to have array sorted in reverse order at the beginning

There is an option to generate CSV with results of automatic test.
To do so you need to set sorting algorithm in program and then run *script.rb*
Generated data in CSV file will contain results of sorting 100 arrays of each size:
  * 10 000 elements
  * 50 000 elements
  * 100 000 elements
  * 500 000 elements
  * 1 000 000 elements
And each level of initially sorted elements:
  * 0% - totally random data
  * 25%
  * 50%
  * 75%
  * 95%
  * 99%
  * 99,7%
  * array sorted in reverse order

