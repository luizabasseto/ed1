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
    int n = i;
    i = 0;
    while (!list2.empty())
    {
        vec[n + i] = list1[i];
        i++;
    }
    return vec;
}

bool ListSTL::check_brackets(string expression)
{
    stack<char> stk;
    for (size_t i = 0; i < expression.length; i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            stk.push(expression[i]);
        }

        if ((expression[i] == ')' && stk.top() == '(') || (expression[i] == ']' && stk.top() == '[') || (expression[i] == '}' && stk.top() == '{'))
        {
            stk.pop();
        }
        else
        {
            return false;
        }
    }

    if (stk.empty())
    {
        return true;
    }
}

vector<string> ListSTL::vectorize_expression(string expression)
{
    vector<string> exp;
    vector<string> temp;
    int j = 0;
    for (size_t i = 0; i < expression.length(); i++)
    {
        if (expression[i] != ' ')
        {
            temp[j] += expression[i];
        }
        else
        {
            exp.push_back(temp);
            j++;
        }
    }
    return exp;
}

float ListSTL::calc_posfix(string expression)
{
    vector<string> exp = vectorize_expression(expression);
    stack<float> stk;
    for (size_t i = 0; i < exp.size(); i++)
    {
        if (stoi(exp[i]).isdigit())
        {
            stk.push(exp[i]);
        }

        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            int b = stk.top();
            stk.pop;
            int a = stk.top();
            stk.pop;
            int op = stoi(exp[i]) float res = a, op, b;
            stk.push(res);
        }
    }

    return stk.top();
}

bool ListSTL::check_posfix(string expression)
{
    vector<string> exp = vectorize_expression(expression);
    stack<float> stk;
    int n = 0;
    for (size_t i = 0; i < exp.size(); i++)
    {
        if (stoi(exp[i]).isdigit())
        {
            stk.push(exp[i]);
            n++;
        }

        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            if (n >= 2)
            {
                stk.pop();
                n = 0;
            }
        }
    }

    if (n == 1)
        return true;

    return false;
}

float ListSTL::calc_infix(string expression)
{
    vector<string> exp = vectorize_expression(expression);
    stack<float> operandos;
    stack<char> operadores;

    for (size_t i = 0; i < exp.size(); i++)
    {
        if (stoi(exp[i]).isdigit())
        {
            operandos.push(exp[i]);
        }
        if (exp[i] == '(')
            operadores.push(exp[i]);

        if (exp[i] == '+' || exp[i] == '-')
        {
            operadores.push(exp[i]);
        }

        if (exp[i] == '*' || exp[i] == '/')
        {
            int b = operandos.top();
            operandos.pop();
            int a = operandos.top;
            operandos.pop();
            char op = operadores.top();
            operadores.pop();
            int res = a, op, b;

            operandos.push(res);
        }

        if (exp[i] == ')')
        {
            do
            {
                int b = operandos.top();
                operandos.pop();
                int a = operandos.top;
                operandos.pop();
                char op = operadores.top();
                operadores.pop();
                int res = a, op, b;

                operandos.push(res);
            } while (operadores.top() == '(');

            operadores.pop();
        }
    }

    return operandos.top();
}

string ListSTL::posfix_to_infix(string expression)
{
    stack<string> infix;
    for (size_t i = 0; i < expression.length(); i++)
    {
        if (stoi(expression[i]).isdigit())
        {
            infix.push(expression[i]);
        }

        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            string a = '(' + infix.top();
            infix.pop();
            string b = infix.top();
            infix.pop();
            string exp = strcat(exp, a, expression[i], b, ')');
        }
    }

    return infix;
}

