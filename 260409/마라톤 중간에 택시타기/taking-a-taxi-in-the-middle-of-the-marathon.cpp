#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int x[100000], y[100000];
int L[100000];
int R[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i=1; i<n; i++){
        L[i] += L[i-1] + abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
    }

    for(int i=n-2; i>=0; i--){
        R[i] += R[i+1] + abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
    }

    int answer = INT_MAX;
    for(int i=1; i<n-1; i++){
        int candi = L[i-1] + R[i+1] + abs(x[i+1] - x[i-1]) + abs(y[i+1] - y[i-1]);
        answer = min(answer, candi);
    }

    cout << answer;

    return 0;
}
