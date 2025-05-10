#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "list_stl.hpp"

int main()
{
    // Criando o objeto da classe ListSTL
    ListSTL listSTL;

    // Testando a função vet_to_vector
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vec = listSTL.vet_to_vector(arr, 5);
    cout << "vet_to_vector: ";
    for (int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    // Testando a função vet_to_flist
    list<int> flist = listSTL.vet_to_flist(arr, 5);
    cout << "vet_to_flist: ";
    for (int v : flist)
    {
        cout << v << " ";
    }
    cout << endl;

    // Testando a função vet_to_stack
    stack<int> stk = listSTL.vet_to_stack(arr, 5);
    cout << "vet_to_stack: ";
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    // Testando a função list_concat
    list<int> list1 = {1, 2, 3};
    list<int> list2 = {4, 5, 6};
    vector<int> concatenated = listSTL.list_concat(list1, list2);
    cout << "list_concat: ";
    for (int v : concatenated)
    {
        cout << v << " ";
    }
    cout << endl;

    // Testando a função check_brackets
    string expression1 = "[(x + 8) * (9-2)]";
    string expression2 = "[(x + 8) * (9-2]";
    cout << "check_brackets (expression 1): " << listSTL.check_brackets(expression1) << endl;
    cout << "check_brackets (expression 2): " << listSTL.check_brackets(expression2) << endl;

    // Testando a função calc_posfix
    string postfix = "24 32 + 2 / 41 5 * +";
    cout << "calc_posfix result: " << listSTL.calc_posfix(postfix) << endl;

    // Testando a função check_posfix
    string postfixExpr = "24 32 + 2 / 41 5 * +";
    cout << "check_posfix result: " << listSTL.check_posfix(postfixExpr) << endl;

    // Testando a função calc_infix
    string infixExpr = "((6 + 9) / 3) * (6 - 4)";
    cout << "calc_infix result: " << listSTL.calc_infix(infixExpr) << endl;

    // Testando a função posfix_to_infix
    string posfixExpr = "6 9 + 3 / 6 4 - *";
    cout << "posfix_to_infix result: " << listSTL.posfix_to_infix(posfixExpr) << endl;

    return 0;
}
