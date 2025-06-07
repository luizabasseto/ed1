#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <climits>
#include "recursao.hpp"

using namespace std;

Recursividade ::Recursividade() {};

int Recursividade::sum(vector<int> &vec, int n)
{
    if (n <= 0)
        return 0;

    if (vec[n] % 2 == 0)
    {
        return vec[n] + sum(vec, n - 1);
    }
    else
    {
        return sum(vec, n - 1);
    }
};

int Recursividade::product(list<int> &lst, list<int>::iterator it)
{
    if (it == lst.end())
    {
        return 1;
    }
    else
    {
        return *it * product(lst, ++it);
    }
};

int Recursividade::min(vector<int> &vec, int n)
{
    if (n == 1)
        return vec[0];
    int menorDoResto = min(vec, n - 1);
    return (vec[n - 1] < menorDoResto) ? vec[n - 1] : menorDoResto;
};

int Recursividade::min(list<int> &lst, list<int>::iterator it)
{
    if (it == lst.end())
        return INT_MAX; 
    int atual = *it;
    int menorDoResto = min(lst, ++it);
    return (atual < menorDoResto) ? atual : menorDoResto;
}

bool Recursividade::find(vector<int> &vec, int n, int elem)
{
    if (n == 0)
        return false;
    if (vec[n - 1] == elem)
    {
        return true;
    }
    else
    {
        find(vec, n - 1, elem);
    }
}

int Recursividade::count(vector<int> &vec, int n, int elem)
{
    if (n == 0)
        return 0;
    if (vec[n - 1] == elem)
    {
        return 1 + count(vec, n - 1, elem);
    }
    else
    {
        count(vec, n - 1, elem);
    }
}

void Recursividade::reverse(vector<int> &vec, int first, int last)
{
    if (last == first)
    {
        return;
    }
    else
    {
        swap(vec[first], vec[last]);
        reverse(vec, first + 1, last - 1);
    }
}

void Recursividade::reverse(list<int> &lst, list<int>::iterator first, list<int>::iterator last)
{
    if (first == last)
    {
        return;
    }
    else
    {
        swap(*first, *last);
        reverse(lst, ++first, --last);
    }
}

bool Recursividade::palindrome(string &str, int first, int last)
{
    if (first != last)
    {
        if (str[first] != str[last])
        {
            return false;
        }
        else
        {
            palindrome(str, first + 1, last - 1);
        }
    } else{
        return true;
    }
};

bool Recursividade::palindrome(list<int> &lst, list<int>::iterator first, list<int>::iterator last)
{
    if (first != last)
    {
        if (*first != *last)
        {
            return false;
        }
        else
        {
            palindrome(lst, ++first, --last);
        }
    }
    else
    {
        return true;
    }
};