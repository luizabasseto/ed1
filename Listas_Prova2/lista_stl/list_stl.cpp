#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "list_stl.hpp"

using namespace std;

ListSTL ::ListSTL() {

};

vector<int> ListSTL::vet_to_vector(int v *, int n)
{
    vector<int> vet;
    for (int i = 0; i < n; i++)
    {
        vet2.push_back(vet[i]);
    }

    return vet;
}

list<int> ListSTL::vet_to_flist(int *v, int n)
{
    list<int> listNew;
    for (int i = 0; i < n; i++)
    {
        listNew.push_front(vet[i]);
    }
}

stack<int> ListSTL::vet_to_stack(int v *, int n)
{
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        stk.push(vet[i]);
    }

    return stk;
}

vector<int> ListSTL::list_concat(list &list1, list &list2)
{
    vector<int> vec;
    int i = 0 while (!list1.empty())
    {
        vec[i] = list1[i];
        i++;
    }
    int n=i;
    i=0;
    while (!list2.empty())
    {
        vec[n+i] = list1[i];
        i++;
    }
    return vec;
}

bool ListSTL::check_brackets(string expression)
{
    stack<char> stk;
    for (size_t i = 0; i < expression.length; i++)
    {
        if(expression[i]=='(' || expression[i]==')' || expression[i]=='[' || expression[i]==']'){
            stk.push(expression[i]);
        }
    }
    
}

vector<string> ListSTL::vectorize_expression(string expression)
{
    vector<string> exp;
    for (size_t i = 0; i < expression.length(); i++)
    {
        if(expression[i]!=' '){
            exp.push_back(expression[i]);
        }
    }
    return exp;
}

float ListSTL::calc_posfix(string expression)
{
}

bool ListSTL::check_posfix(string expression)
{
}

float ListSTL::calc_infix(string expression)
{
}

string ListSTL::posfix_to_infix(string expression)
{
}