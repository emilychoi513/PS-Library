#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int A[100];
int dp[10000 + 1];

void Initial(){
    for(int i=0; i<=m; i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    Initial();

    for(int i=0; i<n; i++){
        for(int j=m; j>=0; j--){
            if(j >= A[i]){
                if(dp[j - A[i]] == INT_MAX) continue;

                dp[j] = min(dp[j], dp[j - A[i]] + 1);
            }
        }
    }

    /*
    for(int i=0; i<=m; i++){
        cout << dp[i] << " ";
    }cout << endl;
    */
    
    int ans = dp[m];
    if(ans == INT_MAX){
        ans = -1;
    }

    cout << ans;

    return 0;
}
