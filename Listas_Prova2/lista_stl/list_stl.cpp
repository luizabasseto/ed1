#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "list_stl.hpp"

using namespace std;

ListSTL ::ListSTL() {};

vector<int> ListSTL::vet_to_vector(int *v, int n)
{
    vector<int> vet;
    for (int i = 0; i < n; i++)
    {
        vet.push_back(v[i]);
    }

    return vet;
}

list<int> ListSTL::vet_to_flist(int *v, int n)
{
    list<int> listNew;
    for (int i = 0; i < n; i++)
    {
        listNew.push_back(v[i]);
    }
    return listNew;
}

stack<int> ListSTL::vet_to_stack(int *v, int n)
{
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        stk.push(v[i]);
    }

    return stk;
}

vector<int> ListSTL::list_concat(list<int> &list1, list<int> &list2)
{
    vector<int> vec;
    for (int val : list1)
    {
        vec.push_back(val);
    }

    for (int val : list2)
    {
        vec.push_back(val);
    }
    return vec;
}

bool ListSTL::check_brackets(string expression)
{
    stack<char> stk;
    for (size_t i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            stk.push(expression[i]);
        }
        else if ((expression[i] == ')' && stk.top() == '(') || (expression[i] == ']' && stk.top() == '[') || (expression[i] == '}' && stk.top() == '{'))
        {
            if (stk.empty())
                return false;

            stk.pop();
        }
    }

    return stk.empty();
}

vector<string> ListSTL::vectorize_expression(string expression)
{
    vector<string> exp;
    string temp;
    for (size_t i = 0; i < expression.length(); i++)
    {
        if (expression[i] != ' ')
        {
            temp += expression[i];
        }
        else if (!temp.empty())
        {
            exp.push_back(temp);
            temp.clear();
        }
    }
    if (!temp.empty())
    {
        exp.push_back(temp);
    }

    return exp;
}

float ListSTL::calc_posfix(string expression)
{
    vector<string> exp = vectorize_expression(expression);
    stack<float> stk;
    for (size_t i = 0; i < exp.size(); i++)
    {
        if (isdigit(exp[i][0]) || (exp[i][0] == '-' && isdigit(exp[i][1])))
        {
            stk.push(stof(exp[i]));
        }
        else if (exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/")
        {
            float b = stk.top();
            stk.pop();
            float a = stk.top();
            stk.pop();
            float result;
            if (exp[i] == "+")
                result = a + b;
            else if (exp[i] == "-")
                result = a - b;
            else if (exp[i] == "*")
                result = a * b;
            else if (exp[i] == "/")
                result = a / b;
            stk.push(result);
        }
    }

    return stk.top();
}

bool ListSTL::check_posfix(string expression)
{
    vector<string> exp = vectorize_expression(expression);
    int n = 0;
    for (size_t i = 0; i < exp.size(); i++)
    {
        if (isdigit(exp[i][0]) || (exp[i][0] == '-' && isdigit(exp[i][1])))
        {
            n++;
        }
        else if (exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/")
        {
            if (n >= 2)
            {
                n -= 1;
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
        if (isdigit(exp[i][0]) || (exp[i][0] == '-' && isdigit(exp[i][1])))
        {
            operandos.push(stof(exp[i]));
        }
        else if (exp[i] == "(")
        {
            operadores.push('(');
        }
        else if (exp[i] == ")")
        {
            while (!operadores.empty() && operadores.top() != '(')
            {
                char op = operadores.top();
                operadores.pop();
                float b = operandos.top();
                operandos.pop();
                float a = operandos.top();
                operandos.pop();

                switch (op)
                {
                case '+':
                    operandos.push(a + b);
                    break;
                case '-':
                    operandos.push(a - b);
                    break;
                case '*':
                    operandos.push(a * b);
                    break;
                case '/':
                    operandos.push(a / b);
                    break;
                }
            }

            if (!operadores.empty())
                operadores.pop(); // remove '('
        }
        else // operador
        {
            operadores.push(exp[i][0]); // apenas empilha
        }
    }

    return operandos.top();
}

int ListSTL::precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string ListSTL::posfix_to_infix(string expression)
{
    vector<string> temp = vectorize_expression(expression);
    stack<string> infix;
    for (size_t i = 0; i < temp.size(); i++)
    {
        if (isdigit(temp[i][0]))
        {
            infix.push(temp[i]);
        }

        if (temp[i] == "+" || temp[i] == "-" || temp[i] == "*" || temp[i] == "/")
        {
            string b = infix.top();
            infix.pop();
            string a = infix.top();
            infix.pop();
            string expr = "( " + a + " " + temp[i] + " " + b + " )";
            infix.push(expr);
        }
    }

    return infix.top();
}
