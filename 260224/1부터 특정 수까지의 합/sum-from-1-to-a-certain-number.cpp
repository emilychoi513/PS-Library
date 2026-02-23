#include <iostream>

using namespace std;

int N;

int func(int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }

    return (int)sum/10;
}

int main() {
    cin >> N;

    cout << func(N);

    return 0;
}