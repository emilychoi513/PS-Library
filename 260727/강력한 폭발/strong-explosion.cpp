#include <iostream>
#include <algorithm>
#include <vector>
#define DEBUG 0
using namespace std;

int n;
int grid[30][30];
int visited[30][30];
vector<pair<int, int>> bomb;
int max_bombed = 0;

int dx[3][5] = {
    {-2, -1, 0, 1, 2},
    {-1, 0, 0, 0, 1},
    {-1, -1, 0, 1, 1},
};

int dy[3][5] = {
    {0, 0, 0, 0, 0},
    {0, -1, 0, 1, 0},
    {-1, 1, 0, -1, 1},
};

bool Exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

void Print(){
    if(!DEBUG) return;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << visited[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

void Push(int i, int t){
    int x = bomb[i].first;
    int y = bomb[i].second;

    for(int d=0; d<5; d++){
        int nx = x + dx[t][d];
        int ny = y + dy[t][d];

        if(Exit(nx, ny)) continue;

        visited[nx][ny]++;
    }

    Print();
}

void Remove(int i, int t){
    int x = bomb[i].first;
    int y = bomb[i].second;

    for(int d=0; d<5; d++){
        int nx = x + dx[t][d];
        int ny = y + dy[t][d];

        if(Exit(nx, ny)) continue;

        visited[nx][ny]--;
    }
}


void Count(int bomb_pos_idx){
    if(bomb_pos_idx == bomb.size()){
        int bombed = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] >= 1) bombed++;
            }
        }
        max_bombed = max(max_bombed, bombed);

        Print();
        return;
    }

    for(int i=0; i<3; i++){
        Push(bomb_pos_idx, i);
        Count(bomb_pos_idx + 1);
        Remove(bomb_pos_idx, i);
    }

    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    //따로 폭탄 놓을 위치 저장 : n x n
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                bomb.push_back({i, j});
            }
        }
    }

    Count(0);
    cout << max_bombed;

    return 0;
}
