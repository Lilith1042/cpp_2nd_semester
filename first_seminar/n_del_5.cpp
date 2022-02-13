//Получить N и вывести N символов @ если N % 5 == 0 или % если N % 5 != 0
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

