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

    void subconjuntos(string &s, int i, string atual);

    void permutacao(string s, size_t ini); 

    int BuscaBinaria(vector<int> &vet, int elem, int low, int high); //feito

    void ProblemaNRainhas(vector<vector<int>>& mat, int row); //feito

    int soma_digitos(int n); //feito

    void inverterString(std::string text, int index); //feito

    float combinacoes(int n, int k); //feito

    void palindromo(std::string text, int index); //feito

    void troca(size_t i, string s, size_t ini); //feito

};