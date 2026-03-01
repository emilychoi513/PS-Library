#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];
int mn[100][100]; //min 값 저장

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    //초기화
    mn[0][0] = grid[0][0];
    for(int i=1; i<n; i++){
        mn[i][0] = min(grid[i][0], mn[i-1][0]);
    }

    for(int j=1; j<n; j++){
        mn[0][j] = min(grid[0][j], mn[0][j-1]);
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            int tmp = max(mn[i-1][j], mn[i][j-1]);
            mn[i][j] = min(tmp, grid[i][j]);
        }
    }

    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mn[i][j] << " ";
        }cout << endl;
    }cout << endl;
    */
    
    cout << mn[n-1][n-1];

    return 0;
}
