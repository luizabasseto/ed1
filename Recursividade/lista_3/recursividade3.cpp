#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "recursividade3.hpp"

using namespace std;

Recursividade::Recursividade() {}

int Recursividade::BuscaBinaria(vector<int> &vet, int elem, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (elem == vet[mid])
        {
            return mid;
        }
        if (elem > vet[mid])
        {
            return BuscaBinaria(vet, elem, mid + 1, high);
        }
        else
        {
            return BuscaBinaria(vet, elem, low, mid - 1);
        }
    }
    else
    {
        return -1;
    }
};

int Recursividade::potencia(int num, int expoente)
{
    if (expoente == 0)
        return 1;
    else
        return num * potencia(num, expoente - 1);
};

int Recursividade::soma_digitos(int n){
    if (n==0)
    {
        return 0;
    } else{
        return n%10 + soma_digitos(n/10);
    }
    
}

int Recursividade::mdc(int a, int b){
    if(a%b==0){
        return b;
    } else{
        return mdc(b, a%b);
    }
}