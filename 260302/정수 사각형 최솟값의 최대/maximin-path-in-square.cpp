#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];
int dp[100][100]; //min 값 저장

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    //초기화
    dp[0][0] = grid[0][0];
    for(int i=1; i<n; i++){
        dp[i][0] = min(grid[i][0], grid[i-1][0]);
    }

    for(int j=1; j<n; j++){
        dp[0][j] = min(grid[0][j], grid[0][j-1]);
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            int tmp = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = min(tmp, grid[i][j]);
        }
    }

    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }cout << endl;
    */
    cout << dp[n-1][n-1];

    return 0;
}
