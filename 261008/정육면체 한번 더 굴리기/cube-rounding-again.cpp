#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <utility>
using namespace std;

int N, M;
int grid[30][30];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int r, c;
int u, f, s;
int dir;
int score;

void Print(){
    printf("(%d, %d), u(%d), f(%d), s(%d), dir(%d), score(%d)\n", r, c, u, f, s, dir, score);
}

void Input(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
        }
    }

    r=0, c=0;
    u=1, f=2, s=3;
    dir=0, score=0;
}


bool Exit(int x, int y){
    return (x<0 || x>=N || y<0 || y>=N);
}

void Move(){
    //주사위 위치
    int nr = r + dr[dir];
    int nc = c + dc[dir];

    // cout << r << " " << c << endl;

    if(Exit(nr, nc)){
        // cout << "Exit! " << endl;
        dir = (dir + 2)%4;
        r = r + dr[dir];
        c = c + dc[dir];
    }else{
        r = nr;
        c = nc;
    }

    //주사위 위앞옆
    int tu, tf, ts;
    if(dir == 0){
        tu = 7-s;
        tf = f;
        ts = u;
    }else if(dir == 1){
        tu = 7-f;
        tf = u;
        ts = s;
    }else if(dir == 2){
        tu = s;
        tf = f;
        ts = 7-u;
    }else{
        tu = f;
        tf = 7-u;
        ts = s;
    }

    u = tu, f = tf, s = ts;
}


void Score(){
    queue<pair<int, int>> q;
    vector<vector<int>> visited(N, vector<int>(N, 0));

    q.push({r, c}); visited[r][c]=1;
    int s = 1;

    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front(); q.pop();

        for(int d=0; d<4; d++){
            int nx = x + dr[d];
            int ny = y + dc[d];

            if(!Exit(nx, ny) && grid[nx][ny]==grid[r][c] && !visited[nx][ny]){
                q.push({nx, ny}); visited[nx][ny] = 1; s++;
            }
        }
    }

    // cout << s << " ";
    score += s*grid[r][c];
    // cout << score << endl;
}

void NextDir(){
    int down = 7-u;

    if(down > grid[r][c]){
        dir = (dir + 1)%4;
    }else if(down < grid[r][c]){
        dir = (dir + 3)%4;
    }
}

int main() {
    Input();
    // Print();

    while(M--){
        Move();
        // cout << "move "; Print();
        Score();
        // cout << "score "; Print();
        NextDir();
        // cout << "dir "; Print();
    }

    cout << score << endl;

    return 0;
}