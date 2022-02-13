#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int x;
    int y;
    cin >> x >> y;
    int res = 1;
    for(int i=0; i<y; i++){
        res *= x;
    }
    cout << res << endl;
}

return