#include <iostream>
#include <algorithm>
#define MAX 100+1
using namespace std;

int n;
int grid[MAX][MAX];
int dp[MAX][MAX];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=n; j>0; j--){
            if(i==1) dp[i][j] = grid[i][j] + dp[i][j+1];
            else if(j==n) dp[i][j] = grid[i][j] + dp[i-1][j];
            else dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i-1][j]);
        }
    }

    cout << dp[n][1];

    return 0;
}
