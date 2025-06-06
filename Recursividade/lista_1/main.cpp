#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <forward_list>
#include "recursividade.hpp" 

using namespace std;

int main() {
    Recursividade rec;

    char txt[] = "Olá, mundo!";
    cout << "print_txt:" << endl;
    rec.print_txt(txt,5);
    cout << "\n\n";

    cout << "count de 0 até 5:" << endl;
    rec.count(5);
    cout << "\n\n";

    cout << "count_max de 3 até 7:" << endl;
    rec.count_max(3, 7);
    cout << "\n\n";

    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "print_vec:" << endl;
    rec.print_vec(vec, 0);
    cout << "\n\n";

    cout << "print_even:" << endl;
    rec.print_even(vec, vec.size()-1);
    cout << "\n\n";

    list<int> lst = {10, 20, 30, 40};
    auto it_list = lst.begin();
    cout << "print_list:" << endl;
    rec.print_list(lst, it_list);
    cout << "\n\n";

    forward_list<int> fwd_lst = {1, 2, 3, 4};
    auto it_fwd = fwd_lst.begin();
    cout << "print_rev:" << endl;
    rec.print_rev(fwd_lst, it_fwd);
    cout << "\n\n";

    vector<int> vec2 = {7, 8, 9};
    cout << "remove_all:" << endl;
    rec.remove_all(vec2);
    cout << "Tamanho após remover: " << vec2.size() << "\n\n";

    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout << "print_stack:" << endl;
    rec.print_stack(stk);
    cout << "\n\n";

    stack<int> stk2;
    cout << "push_to (stk -> stk2):" << endl;
    rec.push_to(stk, stk2);
    cout << "stk2 após push_to:" << endl;
    rec.print_stack(stk2);
    cout << "\n\n";

    vector<int> copy_from = {4, 5, 6};
    vector<int> copy_to;
    cout << "copy vector:" << endl;
    rec.copy(copy_from, 0, copy_to);
    for (int val : copy_to) {
        cout << val << " ";
    }
    cout << "\n\n";

    list<int> l1 = {11, 22, 33};
    list<int> l2;
    auto it_l1 = l1.begin();
    cout << "copy list:" << endl;
    rec.copy(l1, it_l1, l2);
    for (int val : l2) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
