#include <iostream>
#include <vector>
#include <string>
#include "recursividade3.hpp"

using namespace std;

int main()
{
    Recursividade r;

    cout << "Potencia de 2^5 = " << r.potencia(2, 5) << endl;

    cout << "MDC de 48 e 18 = " << r.mdc(48, 18) << endl;

    /* cout << "Permutacoes da string 'ABC': " << endl;
    r.permutacao("ABC", 0, 2);

    cout << "Subconjuntos do vetor {1, 2, 3}:" << endl;
    vector<int> conjunto = {1, 2, 3};
    vector<int> subconjunto;
    r.subconjuntos(conjunto, 0, subconjunto);*/

    vector<int> vetor = {1, 3, 5, 7, 9, 11, 13};
    int elemento = 7;
    int resultadoBusca = r.BuscaBinaria(vetor, elemento, 0, vetor.size() - 1);
    if (resultadoBusca != -1)
        cout << "Busca binaria: elemento " << elemento << " encontrado na posicao " << resultadoBusca << endl;
    else
        cout << "Busca binaria: elemento " << elemento << " nao encontrado." << endl;

    /*  cout << "Solucoes para o problema das 4 rainhas:" << endl;
    r.ProblemaNRainhas(4);
*/
    cout << "Soma dos digitos de 12345 = " << r.soma_digitos(12345) << endl;

    cout << "Inverter string 'recursao': ";
    r.inverterString("recursao", 0);
    cout << endl;

    cout << "Combinacoes C(5, 3) = " << r.combinacoes(5, 3) << endl;

    cout<<endl;
    
    cout << "Teste palindromo para 'arara': ";
    r.palindromo("arara", 0);
    cout << endl;

    cout << "Teste palindromo para 'teste': ";
    r.palindromo("teste", 0);
    cout << endl;

    return 0;
}
