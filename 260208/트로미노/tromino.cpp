#include <iostream>

using namespace std;

int n, m;
int grid[200][200];

int shape[6][3][3] = {
    {{1, 1, 0},
    {1, 0, 0},
    {0, 0, 0}},
    
    {{1, 1, 0},
    {0, 1, 0},
    {0, 0, 0}},

    {{1, 0, 0},
    {1, 1, 0},
    {0, 0, 0}},

    {{0, 1, 0},
    {1, 1, 0},
    {0, 0, 0}},

    {{1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}},

    {{1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}}
};

int maxReturn(int x, int y){
    int sum;
    bool flag;
    int maxSum = 0;

    for(int i=0; i<6; i++){

        sum = 0;
        flag = true;

        for(int dx=0; dx<3; dx++){
            for(int dy=0; dy<3; dy++){
                if(shape[i][dx][dy] == 0) continue;
                if(x+dx>=n || y+dy>=m) {
                    flag = false;
                }
                else{
                    sum += grid[x+dx][y+dy];
                }
            }
        }

        if(flag){
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int res = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            res = max(res, maxReturn(i, j));
        }
    }

    cout << res;

    return 0;
}
