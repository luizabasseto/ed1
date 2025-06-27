#include "revisao.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <stack>
#include <string>

using namespace std;

int main()
{
    Recursividade r;

    // --- 1. print_txt
    char texto[] = "Exemplo";
    r.print_txt(texto, 0);

    // --- 2. count e count_max
    r.count(2);
    r.count_max(2, 5);

    // --- 3. print_vec e print_even
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    r.print_vec(vec, 0);
    r.print_even(vec, 0);
/*
    // --- 4. print_list
    list<int> lst = {10, 20, 30, 40};
    auto it = lst.begin();
    r.print_list(lst, it);

    // --- 5. print_rev (forward_list reversa)
    forward_list<int> flst = {1, 2, 3, 4};
    auto fit = flst.begin();
    r.print_rev(flst, fit);

    // --- 6. remove_all
    vector<int> to_remove = {1, 2, 3};
    r.remove_all(to_remove);

    // --- 7. print_stack
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    r.print_stack(stk);

    // --- 8. push_to
    stack<int> stk2;
    r.push_to(stk, stk2);

    // --- 9. copy vector
    vector<int> vec_copy;
    r.copy(vec, 0, vec_copy);

    // --- 10. copy list
    list<int> lst2;
    auto lit = lst.begin();
    r.copy(lst, lit, lst2);

    // --- 11. fib com memoization
    vector<int> memo(10, -1);
    cout << "Fib(6): " << r.fib(6, memo) << endl;

    // --- 12. sum de vetor
    cout << "Soma: " << r.sum(vec, vec.size()) << endl;

    // --- 13. product de list
    cout << "Produto: " << r.product(lst, lst.begin()) << endl;

    // --- 14. min de vector e list
    cout << "Min vetor: " << r.min(vec, vec.size()) << endl;
    cout << "Min list: " << r.min(lst, lst.begin()) << endl;

    // --- 15. find e count
    cout << "Encontrado? " << r.find(vec, vec.size(), 3) << endl;
    cout << "Ocorrências de 3: " << r.count(vec, vec.size(), 3) << endl;

    // --- 16. reverse de vetor e list
    r.reverse(vec, 0, vec.size() - 1);
    r.reverse(lst, lst.begin(), --lst.end());

    // --- 17. palindrome string e list
    string palavra = "arara";
    cout << "Palíndromo string? " << r.palindrome(palavra, 0, palavra.length() - 1) << endl;

    list<int> pal_lst = {1, 2, 3, 2, 1};
    cout << "Palíndromo lista? " << r.palindrome(pal_lst, pal_lst.begin(), --pal_lst.end()) << endl;

    // --- 18. potencia
    cout << "2^4 = " << r.potencia(2, 4) << endl;

    // --- 19. mdc
    cout << "MDC(30, 18) = " << r.mdc(30, 18) << endl;

    // --- 20. subconjuntos
    string s = "abc";
    r.subconjuntos(s, 0, "");

    // --- 21. permutacao
    r.permutacao("abc", 0);

    // --- 22. Busca Binária
    vector<int> ordenado = {1, 2, 3, 4, 5, 6};
    cout << "Busca Binária por 4: " << r.BuscaBinaria(ordenado, 4, 0, ordenado.size() - 1) << endl;

    // --- 23. Problema das N-Rainhas
    vector<vector<int>> tab(8, vector<int>(8, 0));
    r.ProblemaNRainhas(tab, 0);

    // --- 24. soma de dígitos
    cout << "Soma dígitos de 1234: " << r.soma_digitos(1234) << endl;

    // --- 25. inverter string
    r.inverterString("recursao", 0);

    // --- 26. combinações
    cout << "C(5,2) = " << r.combinacoes(5, 2) << endl;

    // --- 27. palindromo (versão que imprime)
    r.palindromo("radar", 0);

    // --- 28. troca
    r.troca(0, "abc", 0);*/

    return 0;
}
