#include "AlgorithmsDeclarations.hh"
#include "AlgorithmsImplementation.cpp"
#include<time.h>
#include <chrono>

using namespace std;

int main () {
    
    int ROZMIAR = 1000;
    int Tk[ROZMIAR];   // tablica kluczy węzłów
    int i,x,i1,i2;

    srand(time(NULL));        // inicjujemy generator pseudolosowy


    for(i = 0; i < ROZMIAR  ; i++)   // Tablicę wypełniamy wartościami kluczy
        Tk[i] = i + 1;
    
    for(i = 0; i < 2*ROZMIAR ; i++)  // Mieszamy tablicę
    {
        i1 = rand() % ROZMIAR;       // Losujemy 2 indeksy
        i2 = rand() % ROZMIAR;

        x = Tk[i1];             // Wymieniamy Tk[i1] <--> Tk[i2]
        Tk[i1] = Tk[i2];
        Tk[i2] = x;
    }
        /* !!! */

    sortByMerge<int>(Tk, 0, ROZMIAR - 1);
    
    for (int j = 0; j < ROZMIAR - 1; j++) {
        cout << Tk[j] << endl;
    }

}