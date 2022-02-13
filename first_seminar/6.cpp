#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    int count = 1;
    int max_count = 1;
    int prev, cur;
    cin >> n >> prev;
    for(int i = 0; i<n-1; ++i) {
        cin >> cur;
        if(cur > prev) {
            count++;
            prev = cur;
        } else {
            prev = cur;
            if(count > max_count){
                max_count = count;
            }
            count = 1;
        }
    }
    cout << max_count;
}
