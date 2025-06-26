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

int Recursividade::soma_digitos(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n % 10 + soma_digitos(n / 10);
    }
}

int Recursividade::mdc(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return mdc(b, a % b);
    }
}

void Recursividade::inverterString(std::string text, int index)
{
    if (index < text.length() / 2)
    {
        swap(text[index], text[text.length() - index - 1]);
        inverterString(text, index + 1);
    }
    else
    {
        cout << text << endl;
    }
}

void Recursividade::palindromo(std::string text, int index)
{
    if (index < text.length() / 2)
    {
        if (text[index] == text[text.length() - index - 1])
        {
            palindromo(text, index + 1);
        }
        else
        {
            cout << "Não é palíndromo" << endl;
            return;
        }
    }
    else
    {
        cout << "É palíndromo" << endl;
    }
}

float Recursividade::combinacoes(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    else
    {
        return combinacoes(n - 1, k) + combinacoes(n - 1, k - 1);
    }
}

void print_matriz(const vector<vector<int>> &tabuleiro, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
}

void Recursividade::ProblemaNRainhas(vector<vector<int>> &mat, int row)
{
    if (row == 8)
    {
        print_matriz(mat, 8);
        return;
    }
    int coluna;
    if (row < 4)
    {
        coluna = row * 2;
    }
    else
    {
        coluna = (row - 4) * 2 + 1;
    }

    mat[row][coluna] = 1;

    ProblemaNRainhas(mat, row + 1);
}

void Recursividade::troca(size_t i, string s, size_t ini)
{
    swap(s[ini], s[i]);     // troca o atual
    permutacao(s, ini + 1); // permuta
    swap(s[ini], s[i]);     // backtracking
    if (i == s.size() - 1)
        return;
    troca(i + 1, s, ini);
}

void Recursividade::permutacao(string s, size_t ini)
{
    if (ini == s.size() - 1)
    {
        cout << s << endl;
        return;
    }

    troca(ini, s, ini);
}

void Recursividade::subconjuntos(string &s, int i, string atual)
{
    if (i == s.size())
    {
        cout << "{" << atual << "}" << endl;
        return;
    }

    // Caso 1: incluir s[i]
    subconjuntos(s, i + 1, atual + s[i]);

    // Caso 2: não incluir s[i]
    subconjuntos(s, i + 1, atual);
}