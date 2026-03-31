#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, k;
int grid[100][100];

int visited[100][100];
queue<pair<int, int>> q;

bool Exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

bool CanGo(int x, int y){
    if(Exit(x, y) || visited[x][y] || grid[x][y]==1) return false;
    return true;
}

void BFS(){
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    while(!q.empty()){
        pair<int, int> pos = q.front();
        q.pop();

        int x = pos.first;
        int y = pos.second;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(CanGo(nx, ny)){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

void Print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << visited[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    while(k--){
        int x, y;
        cin >> x >> y;
        q.push(make_pair(x-1, y-1));
        visited[x-1][y-1] = true;
    }

    BFS();

    int Sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Sum += visited[i][j];
        }
    }

    cout << Sum;

    return 0;
}
