#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int A[100];
int sum[10000 + 1];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sum[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=m; j>=0; j--){
            if(j >= A[i]){
                sum[j] = max(sum[j], sum[j-A[i]]);
            }
        }

        /*
        for(int k=1; k<=m; k++){
            cout << sum[k] << " ";
        }cout << endl; */
    }
/*
    cout << endl << endl;

    for(int i=1; i<=m; i++){
        cout << sum[i] << " ";
    }cout << endl;
*/
    if(sum[m] == 1) cout << "Yes";
    else cout << "No";

    return 0;
}
