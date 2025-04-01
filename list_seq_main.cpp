#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

int main()
{
    ListSeq ls(5);
    ls.add(5); // adiciona no final
    ls.add(9);
    ls.add(15);
    ls.add(7);
    ls.remove(); // remove no final
    ls.print();  // mostra elementosListSeq ls(5);

    return 0;
}