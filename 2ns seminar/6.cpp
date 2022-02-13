#include <iostream>

using namespace std;

unsigned long long fib(int N){
    if(N == 2) {
        return 1;
    }
    if(N == 1) {
        return 0;
    }
    return fib(N-1) + fib(N-2);
}

int main(){
    cout << fib(6);
}