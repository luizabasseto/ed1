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

void count_aux(int i) {
    if (i > 50) return;
    cout << i << " ";
    count_aux(i + 1);
}

void Recursividade::count(int num)
{
    if (num <= 0) return;
    count_aux(0);           
    cout << endl;
    count(num - 1);

};

void count_auxMax(int i, int max) {
    if (i > max) return;
    cout << i << " ";
    count_auxMax(i + 1,max);
}

void Recursividade::count_max(int num, int max)
{
    if (num <= 0) return;
    count_auxMax(0,max);           
    cout << endl;
    count_max(num - 1,max);
};

void Recursividade::print_vec(vector<int> &vec, int idx)
{
    if (idx >= vec.size()) return; 
    cout << vec.at(idx) << endl;
    print_vec(vec, idx + 1); 
};

void Recursividade::print_even(vector<int> &vec, int idx)
{
idx--;
    if (idx < 1) return; 

    if (vec[idx] % 2 == 0) {
        cout << vec[idx] << endl;  
    }

    print_even(vec, idx - 1); 
    
};

void Recursividade::print_list(list<int> &lst, list<int>::iterator &it)
{
    if (it != lst.end()) {
        cout << *it << " ";
        ++it;
        print_list(lst, it);
    }
};

void Recursividade::print_rev(forward_list<int> &lst, forward_list<int>::iterator &it)
{
    if (it != lst.end()) {
        auto current = it;
        ++it;
        print_rev(lst, it); 
        std::cout << *current << " ";
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
        stk2.push(stk1.top());
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
    if (it != list1.end()) {
        list2.push_back(*it);
        ++it;
        copy(list1, it, list2);
    }
}

int Recursividade::fib(int n, vector<int> &mem)
{
    if (n <= 1)
    {
        return n;
    }
    else if (n >= mem.size())
    {
        mem.push_back(fib(n - 1, mem));
    }

    return fib(n - 2, mem) + fib(n - 1, mem);
}