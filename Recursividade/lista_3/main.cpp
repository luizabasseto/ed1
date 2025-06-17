#include "recursividade3.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Recursividade rec;

    cout << "Potência de 2^5: " << rec.potencia(2, 5) << endl;

    cout << "MDC de 48 e 18: " << rec.mdc(54, 15) << endl;

    cout << "Soma dos dígitos de 1234: " << rec.soma_digitos(1234) << endl;

    vector<int> vetor = {1, 3, 5, 7, 9, 11, 13};
    int elemento = 7;
    int resultado = rec.BuscaBinaria(vetor, elemento, 0, vetor.size() - 1);
    if (resultado != -1)
        cout << "Elemento " << elemento << " encontrado na posição " << resultado << endl;
    else
        cout << "Elemento não encontrado" << endl;

  /* cout << "Inverter a palavra 'recursao': ";
    rec.inverterString("recursao", 0);
    cout << endl;

    cout << "Combinação de 5 elementos tomados de 2 em 2: " << rec.combinacoes(5, 2) << endl;

    cout << "Verificar se 'arara' é palíndromo: ";
    rec.palindromo("arara", 0);
    cout << endl;

    cout << "Solução para o problema das 4 rainhas:" << endl;
    rec.ProblemaNRainhas(4);*/

    return 0;
}
