#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
int coin[100];
int dp[10000 + 1];

void Initial(){
    for(int i=0; i<=M; i++){
        dp[i] = INT_MIN;
    }

    dp[0] = 0;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    Initial();

    for(int i=1; i<=M; i++){
        for(int j=0; j<N; j++){
            if(i >= coin[j]){
                if(dp[i-coin[j]] == INT_MIN) continue;

                dp[i] = max(dp[i], dp[i-coin[j]] + 1);
            }
        }
    }

/*
    for(int i=0; i<=M; i++){
        cout << dp[i] << " ";
    }cout << endl;
*/
    int ans = dp[M];
    if(ans == 0) ans = -1;
    cout << ans;

    return 0;
}
