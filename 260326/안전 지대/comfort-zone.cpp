#include <iostream>
#include <utility>
#define MaxHeight 100
#define NumDir 4
using namespace std;

int N, M;
int grid[50][50];
bool visited[50][50];
pair<int, int> Answer;

bool Exit(int x, int y){
    return (x<0 || x>=N || y<0 || y>=M);
}

bool CanGo(int h, int x, int y){
    if(Exit(x, y)) return false;
    if(visited[x][y]) return false;
    if(grid[x][y] <= h) return false;

    return true;
}

void DFS(int h, int x, int y){
    int dx[NumDir] = {0, 0, -1, 1};
    int dy[NumDir] = {-1, 1, 0, 0};

    for(int i=0; i<NumDir; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(CanGo(h, nx, ny)){
            visited[nx][ny] = true;
            DFS(h, nx, ny);
        }
    }
}

void Initial(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            visited[i][j] = false;
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    for(int k=MaxHeight; k>0; k--){
        Initial();
        int num_village = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(CanGo(k, i, j)){
                    visited[i][j] = true;
                    num_village++;
                    DFS(k, i, j);
                }
            }
        }
        //cout << num_village << endl;
        if(num_village >= Answer.second){
            Answer.first = k;
            Answer.second = num_village;
        }
    }

    cout << Answer.first << " " << Answer.second;

    return 0;
}