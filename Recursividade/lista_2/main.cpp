#include <iostream>
#include <vector>
#include <list>
#include "recursao.hpp"

using namespace std;

int main()
{
    Recursividade r;

    vector<int> vec = {1, 2, 3, 2, 3, 2, 1};
    int vecSize = vec.size();

    cout << "Soma em posições pares: " << r.sum(vec, vecSize-1) << endl;
    cout << "Elemento 3 encontrado? " << (r.find(vec, vecSize, 3) ? "Sim" : "Não") << endl;
    cout << "Quantidade de vezes que 2 aparece: " << r.count(vec, vecSize, 2) << endl;

    cout << "Vetor original: ";
    for (int v : vec)
        cout << v << " ";
    cout << endl;
    r.reverse(vec, 0, vecSize - 1);
    cout << "Vetor invertido: ";
    for (int v : vec)
        cout << v << " ";
    cout << endl;

    cout << "Menor elemento do vetor: " << r.min(vec, vecSize) << endl;

    string texto = "arara";
    cout << "String '" << texto << "' é palíndromo? "<< (r.palindrome(texto, 0, texto.size() - 1) ? "Sim" : "Não") << endl;


    list<int> lst = {1, 2, 3, 2, 1};
    cout << "Produto dos elementos da lista: " << r.product(lst, lst.begin()) << endl;
    cout << "Menor elemento da lista: " << r.min(lst, lst.begin()) << endl;

    cout << "Lista original: ";
    for (int i : lst)
        cout << i << " ";
    cout << endl;

    auto first = lst.begin();
    auto last = lst.end();
    --last; 
    r.reverse(lst, first, last);

    cout << "Lista invertida: ";
    for (int i : lst)
        cout << i << " ";
    cout << endl;

    cout << "Lista é palíndromo? "<< (r.palindrome(lst, lst.begin(), --lst.end()) ? "Sim" : "Não") << endl;

    return 0;
}
