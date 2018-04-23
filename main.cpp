#include "AlgorithmsDeclarations.hh"
#include "AlgorithmsImplementation.cpp"
#include <time.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

int main (int argc, char *argv[]) {
    
    const int SIZE = atoi(argv[2]);     // variable defining lenght of array to sort
    int Tk[SIZE];                 // array to sort
    int i,x,i1,i2;                // helper variables
    int *firstElem, *lastElem;

    srand(time(NULL));            // generator pseudorandom numbers


    if(argv[3] == "reverse") {
        for(int k = SIZE; k > 0; k++) {
            Tk[k] = k;
        }
        } else {
    
        for(i = 0; i < SIZE  ; i++)   // fill array 
            Tk[i] = i + 1;
        
        for(i = 0; i < 2*SIZE ; i++)  // mix values so as to get random sorted data
        {
            i1 = rand() % SIZE;       // take two random values
            i2 = rand() % SIZE;

            x = Tk[i1];               // and next swap the values
            Tk[i1] = Tk[i2];
            Tk[i2] = x;
        }
        

        for(int j = 0; j < (SIZE*atoi(argv[1])/100); j++) {
            Tk[j] = j;
        }
        }
        firstElem = &Tk[0];
        lastElem = &Tk[SIZE - 1];

    auto start = std::chrono::system_clock::now();
    // Choose algorithm to sort array

    //sortByQuicksort<int>(Tk, 0, SIZE - 1);
    //sortByMerge<int>(Tk, 0, SIZE - 1);
    //sortByHeapSort<int>(Tk, SIZE);
    sortByIntroSort<int>(Tk, SIZE, firstElem, lastElem);
    //sortByInsertionSort<int>(Tk, SIZE);
    
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    // Check if array is sorted correctly comment because of automatic tests
    /*
    if(checkIfArrayIsSorted<int>(Tk, SIZE)) {
        cout << "Array is sorted" <<endl;
    }
    */
    
    cout << elapsed << endl;

    
}