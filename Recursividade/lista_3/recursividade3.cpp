#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "recursividade3.hpp"

using namespace std;

Recursividade ::Recursividade() {};


int Recursividade::BuscaBinaria(vector<int> vector, int elem, int low, int high){
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (elem == vet[mid]){
            return mid;
        }
        if (elem > vet[mid]){
            return BuscaBinaria(vector,elem, mid+1, high);
        }
        else{
            return BuscaBinaria(vector,elem, low, mid-1);
        }
    }

    return -1;
}

int Recursividade::potencia(int num, int expoente){
    
}