#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[20][20];

int numGold(int k, int cost, int x, int y){
    int cntGold = 0;
    bool boundaryExit = false;

    for(int dx=-k; dx<=k; dx++){
        if(x+dx < 0 || x+dx >= n){
            boundaryExit = true;
            break;
        }

        for(int dy=-(k-abs(dx)); dy<=k-abs(dx); dy++){
            if(y+dy < 0 || y+dy >= n){
                boundaryExit = true;
                break;
            }

            cntGold += grid[x+dx][y+dy];
        }

        if(boundaryExit) break;
    }

    if(boundaryExit){
        return 0;
    }else if(cost > cntGold * m){
        return 0;
    }else{
        return cntGold;
    }
}



int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int res = 0;

    for(int K=(n-1)/2; K>=0; K--){
        int Cost = K*K + (K+1)*(K+1);
        for(int X=0; X<n; X++){
            for(int Y=0; Y<n; Y++){
                res = max(res, numGold(K, Cost, X, Y));
            }
        }
    }

    cout << res;
    return 0;
}
