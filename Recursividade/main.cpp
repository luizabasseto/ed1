#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int fib(int n, vector<int> &mem)
{
    if (n <= 1)
    {
        return n;
    }
    else if (n >= mem.size())
    {
        mem.push_back(fib(n - 1, mem));
    }

    return fib(n - 2, mem) + fib(n - 1, mem);
}

int main()
{

    int n = 0;
    cout << "Digite o valor de n" << endl;
    cin >> n;

    vector<int> mem = {0};

    cout << "Resultado: " << fib(n, mem);
    cout << endl;

    return 0;
}