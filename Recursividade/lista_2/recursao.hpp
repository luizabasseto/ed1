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
};