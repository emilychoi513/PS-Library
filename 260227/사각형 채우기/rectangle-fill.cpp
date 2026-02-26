#include <iostream>
#define MAX 1000
using namespace std;

int n;
int dp[MAX + 1];

int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];

    return 0;
}
