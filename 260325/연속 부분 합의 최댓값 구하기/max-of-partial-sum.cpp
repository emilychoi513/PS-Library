#include <iostream>
#include <climits>
using namespace std;

int n;
int a[100000];
int dp[100000];

void Initialize(){
    for(int i=0; i<n; i++){
        dp[i] = INT_MIN;
    }

    dp[0] = a[0];
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    Initialize();
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1] + a[i], a[i]);
    }

    int answer = INT_MIN;
    for(int i=0; i<n; i++){
        answer = max(answer, dp[i]);
    }

    cout << answer;
    return 0;
}