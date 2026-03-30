#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int a[100][100];
bool visited[100][100];
queue<pair<int, int>> q;

bool InRange(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

bool CanGo(int x, int y){
    if(!InRange(x, y) || visited[x][y] || a[x][y]==0) return false;

    return true;
}

void Print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << visited[i][j] << " ";
        }cout << endl;
    }
}

void Push(int x, int y){
    visited[x][y] = true;
    q.push(make_pair(x, y));
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
                Push(nx, ny);
            }
        }
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    Push(0, 0);
    BFS();
    bool answer = visited[n-1][m-1];
    cout << answer << endl;

    //Print();
    

    return 0;
}
