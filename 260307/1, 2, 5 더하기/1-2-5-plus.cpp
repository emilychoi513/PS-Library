#include <iostream>
#define MOP 10007

using namespace std;

int n;
int ele[3] = {1, 2, 5};
long long dp[1000 + 1]; //dp[i] : i를 합으로 하는 경우의 수

int main() {
    cin >> n;

    dp[0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            if(i >= ele[j]){
                dp[i] += (dp[i - ele[j]]);
                dp[i] %= MOP;
            }
        }
    }

/*
    for(int i=0; i<=n; i++){
        cout << dp[i] << " ";
    }cout << endl;
*/

    long long ans = dp[n] % MOP;
    cout << ans;

    return 0;
}
