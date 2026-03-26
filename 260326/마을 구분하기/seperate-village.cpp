#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[25][25];
bool visited[25][25];
vector<int> v;
int cnt;

bool Exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

bool CanGo(int x, int y){
    if(Exit(x, y)) return false;

    if(visited[x][y] || grid[x][y]==0) return false;

    return true;
}

void Print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << visited[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

void DFS(int x, int y){
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(CanGo(nx, ny)){
            visited[nx][ny] = true;
            cnt++;
            DFS(nx, ny);
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

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(CanGo(i, j)){
                visited[i][j] = true;
                cnt = 1;
                DFS(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}
