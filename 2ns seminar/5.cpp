#include <iostream>

using namespace std;

unsigned long long factorial(int N){
    if(N > 1) {
        return N*factorial(N-1);
    }
    return 1;
}

int main(){
    cout << factorial(5);
}