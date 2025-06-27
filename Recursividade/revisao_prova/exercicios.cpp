#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "revisao.hpp"

using namespace std;

Recursividade::Recursividade() {}

void Recursividade::print_txt(char *text, int count)
{
    if(count==10) return;
    cout<< text << endl;

    print_txt(text,++count);
}

void imprimir_numeros(int n, int max){
    if(n==max+1) return;
    cout << n << endl;
    imprimir_numeros(++n,max);
}

void Recursividade::count(int num){
    if(num==0) return;
    imprimir_numeros(0,50);
    count(--num);
}

void Recursividade::count_max(int num, int max){
    if(num==0) return;
    imprimir_numeros(0,max);
    count(--num);
}

void Recursividade::print_vec(vector<int> &vec, int idx){
    if(idx>vec.size()-1) return ;
    cout <<vec[idx] << endl;
    print_vec(vec,idx+1);
}

void Recursividade::print_even(vector<int> &vec, int idx){
    if(vec.size()-1-idx==0) return;
    int indice = vec.size()-1-idx;
    if(vec[indice]%2==0) cout << vec[indice] << endl;
    print_even(vec,idx+1);
}

void Recursividade::print_list(list<int> &lst, list<int>::iterator &it){
    if(lst.end()==it) return;

    cout << it <<
}

void print_rev(forward_list<int> &lst, forward_list<int>::iterator &it);

void remove_all(vector<int> &vec);

void print_stack(stack<int> stk);

void push_to(stack<int> stk1, stack<int> &stk2);

void copy(vector<int> &vec1, int idx, vector<int> &vec2);

void copy(list<int> &list1, list<int>::iterator &it, list<int> &list2);

int fib(int n, vector<int> &mem);