#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int coin[100];
int dp[10000+1];

void Initial(){
    for(int i=0; i<=M; i++){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    Initial();

    for(int i=1; i<=M; i++){ //dp
        for(int j=0; j<N; j++){
            if(i - coin[j] >= 0){
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    
    /*    
    for(int i=1; i<=M; i++){
        cout << dp[i] << " ";
    }cout << endl;
    */

    if(dp[M] == INT_MAX){
        cout << -1;
        return 0;
    }else{
        cout << dp[M];
    }

    return 0;
}
