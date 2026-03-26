#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];
bool visited[100][100];
int cnt;
int NumBoom;
int MaxBlock;

bool Exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

bool CanGo(int x, int y){
    if(Exit(x, y)) return false;
    if(visited[x][y]) return false;

    return true;
}

void DFS(int m, int x, int y){
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(CanGo(nx, ny) && grid[nx][ny] == m){
            visited[nx][ny] = true;
            cnt++;
            
            DFS(m, nx, ny);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    NumBoom = 0;
    MaxBlock = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(CanGo(i, j)){
                visited[i][j] = true;
                cnt = 1;

                DFS(grid[i][j], i, j);

                if(cnt >= 4) NumBoom++;
                MaxBlock = max(MaxBlock, cnt);
            }
        }
    }

    cout << NumBoom << " " << MaxBlock;

    return 0;
}
