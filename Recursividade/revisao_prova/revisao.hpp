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

    void print_txt(char *text, int count);

    void count(int num);

    void count_max(int num, int max);

    void print_vec(vector<int> &vec, int idx);

    void print_even(vector<int> &vec, int idx);

    void print_list(list<int> &lst, list<int>::iterator &it);

    void print_rev(forward_list<int> &lst, forward_list<int>::iterator &it);

    void remove_all(vector<int> &vec);

    void print_stack(stack<int> stk);

    void push_to(stack<int> stk1, stack<int> &stk2);

    void copy(vector<int> &vec1, int idx, vector<int> &vec2);

    void copy(list<int> &list1, list<int>::iterator &it, list<int> &list2);

    int fib(int n, vector<int> &mem);

        int sum(vector<int> &vec, int n);

    int product(list<int> &lst, list<int>::iterator it);

    int min(vector<int> &vec, int n);

    int min(list<int> &lst, list<int>::iterator it);

    bool find(vector<int> &vec, int n, int elem);

    int count(vector<int> &vec, int n, int elem);

    void reverse(vector<int> &vec, int first, int last);

    void reverse(list<int> &lst, list<int>::iterator first, list<int>::iterator last);

    bool palindrome(string &str, int first, int last);
    
    bool palindrome(list<int> &lst, list<int>::iterator first, list<int>::iterator last);

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