//Прочитать множество чисел и вывести число с минимальным остатком от деления на 101
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n%5==0){
        for(int i=0; i<n; i++){
            cout << "@\n";
        }   
    }
    else{
            cout << "%\n";
        }
return 0;
}

