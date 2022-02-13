#include <iostream>

using namespace std;

void print_binary(unsigned long long value){
    if(value == 1) {
        cout << 1;
        return;
    }
    print_binary(value/2);
    cout << value%2;
}

int main(){
    print_binary(105);
}