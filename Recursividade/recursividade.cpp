#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "recursividade.hpp"

using namespace std;

Recursividade ::Recursividade() {};

void Recursividade::print_txt(char *text, int count)
{
    if (count > 0)
    {
        cout << text << endl;
        return print_txt(text, count - 1);
    }
};

void Recursividade::count(int num)
{
    if (num <= 50)
    {
        cout << num << endl;
        return count(num + 1);
    }
};

void Recursividade::count_max(int num, int max)
{
    if (num == max)
    {
        cout << num << endl;
    }
    else
    {
        cout << num++ << endl;
        return count_max(num + 1, max);
    }
};

void Recursividade::print_vec(vector<int> &vec, int idx)
{
    if (idx <= vec.size())
    {
        cout << vec.at(idx) << endl;
        return print_vec(vec, idx++);
    }
};

void Recursividade::print_even(vector<int> &vec, int idx)
{
    int x = vec.size() - idx;
    if (idx <= vec.size())
    {
        if (vec[x] % 2 == 0)
        {
            cout << vec.at(x) << endl;
        }
        return print_even(vec, idx++);
    }
};

void Recursividade::print_list(list<int> &lst, list<int>::iterator &it)
{
    if (!lst.end())
        return print_list(lst, it++)
};

void Recursividade::print_rev(forward_list<int> &lst, forward_list<int>::iterator &it)
{
    int x = lst.size() - it - 1;
    if (x > 0)
    {
        cout << lst[x] << endl;
        return print_even(lst, it++);
    }
};

void Recursividade::remove_all(vector<int> &vec)
{
    int x = vec.size() - 1;
    if (x > 0)
    {
        vec.pop_back();
        return remove_all(vec);
    }
}

void Recursividade::print_stack(stack<int> &stk)
{
    if (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
        return print_stack(stk);
    }
}

void Recursividade::push_to(stack<int> &stk1, stack<int> &stk2)
{
    if (!stk1.empty())
    {
        stk2.push(st1.top());
        stk1.pop();
        return push_to(stk1, stk2);
    }
}

void Recursividade::copy(vector<int> &vec1, int idx, vector<int> &vec2)
{

    if (vec2.size() < vec1.size())
    {
        vec2.push_back(vec1[idx]);
        return copy(vec1, idx++, vec2);
    }
}

void Recursividade::copy(list<int> &list1, list<int>::iterator &it, list<int> &list2)
{
    if (list2.size() < list1.size())
    {
        list1.push_back(list1[idx]);
        return copy(list1, it++, list2);
    }
}