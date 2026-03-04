#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M[1000];
int dp[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    dp[0] = 1; 

    for(int i=1; i<N; i++){
        int mx = 0;

        for(int j=0; j<i; j++){
            if(M[j] < M[i]){
                mx = max(mx, dp[j]);
            }
        }

        dp[i] = mx + 1;
    }

    /*
    for(int i=0; i<N; i++){
        cout << dp[i] << " ";
    }cout << endl;
    */

    int ans = 0;
    for(int i=0; i<N; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}
