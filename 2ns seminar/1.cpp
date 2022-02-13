#include <iostream>

using namespace std;

bool is_prime(unsigned long long value){
    for(int i = 2; i*i <= value; ++i) {
        if(value%i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << is_prime(n);
}