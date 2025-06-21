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

    int potencia(int num, int expoente); //feito

    int mdc(int a, int b); //feito

    void subconjuntos();

    void permutacao(string text, int index, int n); 

    int BuscaBinaria(vector<int> &vet, int elem, int low, int high); //feito

    void ProblemaNRainhas(vector<vector<int>> mat, int row, int col);

    int soma_digitos(int n); //feito

    void inverterString(std::string text, int index); //feito

    float combinacoes(int n, int k); //feito

    void palindromo(std::string text, int index); //feito

};