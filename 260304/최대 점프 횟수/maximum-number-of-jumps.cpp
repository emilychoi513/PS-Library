#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int dp[1000];

void Initial(){
    for(int i=0; i<n; i++){
        dp[i] = -1000;
    }

    dp[0] = 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Initial();

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){            
            if(dp[j] == -1000) continue; // 초기화되지 못하는 요소 존재하므로.

            if(arr[j] + j >= i){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    /*
    for(int i=0; i<n; i++){
        cout << dp[i] << " ";
    }cout << endl;
    */

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}
