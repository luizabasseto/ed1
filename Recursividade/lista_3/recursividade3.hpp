#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <forward_list>

using namespace std;

class Recursividade
{

public:
    Recursividade();

    int potencia(int num, int expoente);

    int mdc(int a, int b);

    void subconjuntos();

    int BuscaBinaria(vector<int> &vet, int elem, int low, int high);

    void ProblemaNRainhas(int n);

    int soma_digitos(int n);

    void inverterString(std::string text, int index);

    float combinacoes(int n, int k);

    void palindromo(std::string text, int index);
};