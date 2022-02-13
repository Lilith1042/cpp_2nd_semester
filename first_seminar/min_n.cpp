//5. Прочитать множество чисел и вывести число с минимальным остатком от деления на 101
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n;
     cin>>a;
     a=a%101;
        for(int i=0; i<n-1; i++){
           cin>> b;
           b=b%101;
           if(b<a)
           a=b;
        }   
cout<<a<<endl;
return 0;
}

