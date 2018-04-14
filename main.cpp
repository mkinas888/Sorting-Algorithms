#include "AlgorithmsDeclarations.hh"
#include "AlgorithmsImplementation.cpp"
#include <time.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

int main () {
    
    const int SIZE = 10000;     // variable defining lenght of array to sort
    int Tk[SIZE];                 // array to sort
    int i,x,i1,i2;                // helper variables

    srand(time(NULL));            // generator pseudorandom numbers


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

    auto start = std::chrono::system_clock::now();
    //sortByQuicksort<int>(Tk, 0, SIZE - 1);
    //sortByMerge<int>(Tk, 0, SIZE - 1);
    //sortByHeapSort<int>(Tk, SIZE);
    //sortByIntroSort<int>(Tk, SIZE);
    //sortByInsertionSort<int>(Tk, SIZE);
    
    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    /*
    for (int x = 0; x < SIZE; x++) {
        cout << Tk[x] << endl;
    }
    */
    if(checkIfArrayIsSorted<int>(Tk, SIZE)) {
        cout << "Array is sorted" <<endl;
    }

    cout << elapsed << endl;

    
}