#include <iostream>
#define MOD 10007

using namespace std;

int n;
int ele[3] = {1, 2, 5};
long long cnt;

void dp(int sum){
    if(sum == n){
        cnt++;
        return;
    }else if(sum > n){
        return;
    }

    for(int i=0; i<3; i++){
        sum += ele[i];
        dp(sum);
        sum -= ele[i];
    }
}

int main() {
    cin >> n;

    cnt = 0;
    dp(0);
    cnt %= MOD;
    cout << cnt;

    return 0;
}
