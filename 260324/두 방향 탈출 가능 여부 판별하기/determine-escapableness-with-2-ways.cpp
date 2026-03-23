#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
bool visited[100][100];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int flag;

bool exitRange(int x, int y){
    return (x<0 || x>=n || y<0 || y>=m);
}

bool passing(int x, int y){
    if(exitRange(x, y)) return false;
    if(visited[x][y])   return false;
    if(grid[x][y]==0)   return false;

    return true;
}

void DFS(int x, int y){
    if(x == n-1 && y == m-1){
        flag = 1;
        /*
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << visited[i][j] << " ";
            }cout << endl;
        }*/
        return;
    }

    for(int i=0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(passing(nx, ny)){
            visited[nx][ny] = 1;
            DFS(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    flag = 0;
    DFS(0, 0);
    cout << flag;

    return 0;
}
