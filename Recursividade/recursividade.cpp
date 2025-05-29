#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "recursividade.hpp"

using namespace std;

Recursividade ::Recursividade() {};

Recursividade::void print_txt(char *text)
{
    int x = 0;
    if (x <= 10)
    {
        x--;
        cout << text << endl;
        return print_txt(text);
    }
}

Recursividade::void count(int num)
{
    if (num == 50)
    {
        cout << num << endl;
    }
    cout << num << endl;
    return count(num + 1);
}

Recursividade::void count_max(int num, int max)
{
    if (num == max)
    {
        cout << num << endl;
    }
    else
    {
        cout << num++ << endl;
        return count_max(num + 1, max);
    }
}

Recursividade::void print_vec(vector<int> &vec, int idx){
    
}
