#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "alg_ordenacao.hpp"

using namespace std;
template T;

ListAlg_ordenacao ::ListAlg_ordenacao() {};

bool ListAlg_ordenacao::bubble_sort(vector<T> vec)
{
    int n = sizeof(vec);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                int temp = vec[j+1];
                vec[j+1] vec[j];
                vec[j] = temp;
            }
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        if (vec[n]>vec[n+1])
        {
         return false;
        }
        
    }

    return true;
    
}

bool ListAlg_ordenacao::insertionSort(vector<T> vec){

}