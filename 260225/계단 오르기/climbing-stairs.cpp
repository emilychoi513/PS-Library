#include <iostream>
#include <algorithm>
#define MAX 1000
#define SET 10007

using namespace std;

int n;
int method[MAX + 1];

int dp(int step){
    if(step<0) return 0;
    
    if(method[step] != -1){
        return method[step];
    }else{
        long long result = (dp(step-2) + dp(step-3)) % SET;
        return method[step] = result;
    }
}

int main() {
    cin >> n;

    fill(method, method + MAX + 1, -1);
    method[0] = 0, method[1] = 0;
    method[2] = 1, method[3] = 1;
    cout << dp(n);

    return 0;
}