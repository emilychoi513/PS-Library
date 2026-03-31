#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n, k;
int a[100][100];
vector<vector<bool>> visited;
vector<vector<bool>> answer(100, vector<bool>(100, false));
queue<pair<int, int>> q;

bool Exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

bool CanGo(int x, int y){
    if(Exit(x, y) || visited[x][y] || a[x][y]==1) return false;
    return true;
}

void Push(int x, int y){
    q.push(make_pair(x, y));
    visited[x][y] = true;
    answer[x][y] = true;
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
            cin >> a[i][j];
        }
    }

    int x, y;
    for(int i=0; i<k; i++){
        cin >> x >> y;

        visited.assign(n, vector<bool>(n, false));
        Push(x-1, y-1);
        BFS();
        //Print();
    }

    int Sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Sum += answer[i][j];
        }
    }

    cout << Sum;

    return 0;
}
