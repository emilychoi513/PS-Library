#include <iostream>

using namespace std;

int n, m;
int func(int a, int b);

int main() {
    cin >> n >> m;
    cout << func(n, m);
    return 0;
}

int func(int a, int b){
    for(int m = a; m > 0; m--){
        if((a % m == 0) && (b % m == 0)){
            return m;
        }
    }
}