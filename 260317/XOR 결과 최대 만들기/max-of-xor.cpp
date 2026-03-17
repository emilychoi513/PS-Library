#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int A[20];
int XOR;
int MAX;

void Choose(int idx, int cnt, int val){
    if(cnt == m){
        //cout << XOR << endl;
        MAX = max(MAX, val);
        return;
    }

    if(idx >= n || n - idx < m - cnt) return;

    Choose(idx+1, cnt+1, val ^ A[idx]);
    Choose(idx+1, cnt, val);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    XOR = 0;
    MAX = 0;
    Choose(0, 0, 0);

    cout << MAX;


    return 0;
}