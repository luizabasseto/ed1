#include <iostream>

using namespace std;

void hanoi(int n, char ori, char dest, char aux){
    if(n==1){
        cout <<" Mover disco 1 de " << ori << " para " << dest << endl;
        return;
    }
    hanoi(n-1,ori,aux,dest);
    cout <<" Mover disco " << n << " de " << ori << " para " << dest << endl;
    hanoi(n-1,aux,dest,ori);
}

int main(){
    int n = 3;
    hanoi(n,'A','C','B');
    return 0;
}