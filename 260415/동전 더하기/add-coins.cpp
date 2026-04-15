#include <iostream>

using namespace std;

int n, k;
int coins[10];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int cnt = 0;
    for(int i=n-1; i>=0; i--){
        cnt += k/coins[i];
        k %= coins[i];
        //cout << k << endl;
    }

    cout << cnt;
    return 0;
}
