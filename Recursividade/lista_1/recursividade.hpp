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
};