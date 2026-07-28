#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>

#define DEBUG 0

using namespace std;

int n, q;
int grid[100][100];
int temp_grid[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

//Flood Fill
bool visited[100][100];

void input_grid(){
    cin >> n >> q;

    n = pow(2, n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
}

void Print(){
    if(!DEBUG) return;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

void move_box(int st_r, int st_c, int rsize, int dir){
    for(int r=st_r; r<st_r + rsize; r++){
        for(int c=st_c; c<st_c + rsize; c++){
            int nr = r + dx[dir] * rsize;
            int nc = c + dy[dir] * rsize;

            temp_grid[nr][nc] = grid[r][c];
        }
    }
}

void rotate(int level){
// 2^L x 2^L 씩 독립적으로 시행되며
// 2^L만 봤을때 4덩어리가 시계방향 회전
// next grid(temp) 를 만든다.
    if(level == 0) return;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp_grid[i][j] = 0;
        }
    }

    int size = pow(2, level);
    int rsize = size / 2;

    // cout << "size : " << size << " " << rsize << endl;

    for(int i=0; i<n; i+=size){
        for(int j=0; j<n; j+=size){
            //1 -> 2
            move_box(i, j, rsize, 0);
            //2 -> 3
            move_box(i, j+rsize, rsize, 1);
            //3 -> 4
            move_box(i+rsize, j+rsize, rsize, 2);
            //4 -> 1
            move_box(i+rsize, j, rsize, 3);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j] = temp_grid[i][j];
        }
    }

    Print();
}

bool Exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

void melt(){
// 1x1 칸 기준으로 인접한 4칸 중 3칸 이상 빙하라면 안녹음, 3칸 미만 -> -1
// 동시성 보장 -> temp 배열 만들어서 진행
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp_grid[i][j] = grid[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 0) continue;

            int cnt = 0;
            for(int d=0; d<4; d++){
                int ni = i + dx[d];
                int nj = j + dy[d];
                if(!Exit(ni, nj) && grid[ni][nj] != 0) cnt++;
            }
            if(cnt < 3) temp_grid[i][j]--;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j] = temp_grid[i][j];
        }
    }

    Print();
}

int count_total_glacier(){
// 빙하 총량
    int Sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Sum += grid[i][j];
        }
    }
    
    return Sum;
}

int cal_crowd(pair<int, int> pos){
    queue<pair<int, int>> q;
    int crowd_size = 0;

    q.push(pos);
    visited[pos.first][pos.second] = true;

    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        crowd_size++;

        for(int d=0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(!Exit(nx, ny) && grid[nx][ny]!=0 && !visited[nx][ny]){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return crowd_size;
}

int cal_max_crowd(){
// 최대 군집 크기: BFS
    int mx = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] != 0 && !visited[i][j]){
                mx = max(mx, cal_crowd({i, j}));
            }
        }
    }

    return mx;
}

int main() {
    input_grid();

    while(q--){
        int level;
        cin >> level;

        rotate(level);

        melt();
    }

    cout << count_total_glacier() << '\n';
    cout << cal_max_crowd();
    
    return 0;
}