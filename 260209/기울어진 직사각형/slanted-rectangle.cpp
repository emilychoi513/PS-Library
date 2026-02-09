/*
    modify version that refer the answer code
    But, not perfect. need optimalization
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[20][20];

bool checkRange(int x, int y){
    return (x>=0 && x<n && y>=0 && y<n);
}

int getSum(int x, int y, int w, int h){
    int dir = 4;
    int dx[dir] = {-1, -1, 1, 1};
    int dy[dir] = {1, -1, -1, 1};
    int numMove[dir] = {w, h, w, h};

    int sum = 0;
    for(int i=0; i<dir; i++){
        for(int m=0; m<numMove[i]; m++){
            x += dx[i];
            y += dy[i];

            if(!checkRange(x, y)) return 0;

            sum += grid[x][y];
        }
    }

    return sum;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int mx = 0;
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            for(int w=1; w<n; w++){
                for(int h=1; h<n; h++){
                    mx = max(mx, getSum(x, y, w, h));
                }
            }
        }
    }

    cout << mx;
    return 0;
}
