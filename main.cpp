#include "AlgorithmsDeclarations.hh"
#include "AlgorithmsImplementation.cpp"
#include <time.h>
#include <chrono>
#include <iostream>

using namespace std;

int main () {
    
    int SIZE = 1000000;           // variable defining lenght of array to sort
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

    sortByQuicksort<int>(Tk, 0, SIZE - 1);
    
    for (int j = 0; j < SIZE - 1; j++) {
        cout << Tk[j] << endl;
    }

}