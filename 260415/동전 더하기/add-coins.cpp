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
    int Sum = 0;
    while(Sum < k){
        cnt++;

        for(int i=n-1; i>=0; i--){
            if(Sum + coins[i] > k) continue;

            Sum += coins[i];
            break;
        }

        //cout << cnt << " " << Sum << endl;
    }

    cout << cnt;
    return 0;
}
