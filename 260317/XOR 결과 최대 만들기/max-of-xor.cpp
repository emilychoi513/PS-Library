#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int A[20];
int XOR;
int MAX;

void Choose(int cnt, int idx){
    if(cnt == m){
        //cout << XOR << endl;
        MAX = max(MAX, XOR);
        return;
    }

    for(int i=idx; i<n; i++){
        XOR = XOR ^ A[i];
        Choose(cnt + 1, idx + 1);
        XOR = XOR ^ A[i];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    XOR = 0;
    MAX = 0;
    Choose(0, 0);

    cout << MAX;


    return 0;
}