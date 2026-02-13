#include <iostream>
#include <vector>

using namespace std;

int n;
int grid[200][200];
int r, c;

bool rangeExit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

void boom(int bound, int x, int y){
    int nx, ny;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    grid[x][y] = 0;
    for(int i=0; i<4; i++){
        for(int j=1; j<bound; j++){
            nx = x + j * dx[i];
            ny = y + j * dy[i];

            if(rangeExit(nx, ny)) break;
            grid[nx][ny] = 0;
        }
    }
}

void gravity(int col){
    for(int col=0; col<n; col++){
        
        vector<int> temp(n, 0);
        int cnt = 0;

        for(int row=n-1; row>=0; row--){
            if(grid[row][col] == 0) continue;

            temp[cnt] = grid[row][col];
            cnt++;
        }

        for(int row=n-1; row>=0; row--){
            grid[row][col] = temp[(n-1)-row];
        }
    }
}


int main() {
    vector<int> temp;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    r--; c--;
    boom(grid[r][c], r, c);

    for(int col=0; col<n; col++){
        gravity(col);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        }cout << "\n";
    }

    return 0;
}
