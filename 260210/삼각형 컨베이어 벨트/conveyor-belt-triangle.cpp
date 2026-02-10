#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];
int T[600];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) cin >> r[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    int len = 3 * n;
    for(int i=0; i<n; i++) T[i] = l[i];
    for(int i=0; i<n; i++) T[n+i] = r[i];
    for(int i=0; i<n; i++) T[2*n + i] = d[i];


    for(int i=0; i<t; i++){
        int tmp = T[len - 1];

        for(int j=len-1; j>0; j--){
            T[j] = T[j-1];
        }
        T[0] = tmp;
    }

    for(int i=0; i<len; i++){
        cout<< T[i] << " ";

        if(i == 2 || i == 5) cout << '\n';
    }

    return 0;
}
