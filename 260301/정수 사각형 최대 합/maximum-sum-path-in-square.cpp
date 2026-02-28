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
        for(int j=1; j<=n; j++){
            dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][n];

    return 0;
}
