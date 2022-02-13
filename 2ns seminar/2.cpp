#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

unsigned long long read_int_value(){
    char value;
    string result = "";
    while (cin >> value)
    {
        if(value == '\n') {
            break;
        }
        int n = value - '0'; 
        if(n >=0 && n < 10) {
            result += value;
        }
    }
    return atoi(result.c_str());    
}

int main() {
    cout << read_int_value();
}