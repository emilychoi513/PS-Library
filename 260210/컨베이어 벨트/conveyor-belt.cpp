#include <iostream>

using namespace std;

int n, t;
int c[400];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> c[n+i];
    
    for(int i=0; i<t; i++){
        int tmp = c[2*n-1];

        for(int j=2*n-1; j>0; j--){
            c[j] = c[j-1];
        }
        c[0] = tmp;
    }

    for(int i=0; i<n; i++) cout << c[i] << " ";
    cout << '\n';
    for(int i=0; i<n; i++) cout << c[n+i] << " ";

    return 0;
}
