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

//Flood Fill
queue<pair<int, int>> qq;
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
            //4 -> 1
            for(int a=0; a<rsize; a++){
                for(int b=0; b<rsize; b++){
                    int x = i, y = j;
                    temp_grid[x+a][y+b] = grid[x+rsize+a][y+b];
                }
            }
            //1 -> 2
            for(int a=0; a<rsize; a++){
                for(int b=0; b<rsize; b++){
                    int x = i, y = j+rsize;
                    temp_grid[x+a][y+b] = grid[x+a][y-rsize+b];
                }
            }
            //2 -> 3
            for(int a=0; a<rsize; a++){
                for(int b=0; b<rsize; b++){
                    int x = i+rsize, y = j+rsize;
                    temp_grid[x+a][y+b] = grid[x-rsize+a][y+b];
                }
            }
            //3 -> 4
            for(int a=0; a<rsize; a++){
                for(int b=0; b<rsize; b++){
                    int x = i+rsize, y = j;
                    temp_grid[x+a][y+b] = grid[x+a][y+rsize+b];
                }
            }

            // //
            // for(int a=0; a<size; a++){
            //     for(int b=0; b<size; b++){
            //         cout << temp_grid[i+a][j+b] << " ";
            //     } cout << endl;
            // }cout << endl;
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
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

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

int cal_crowd(){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int crowd_size = 0;

    while(!qq.empty()){
        int x, y;
        tie(x, y) = qq.front();
        qq.pop();
        crowd_size++;

        for(int d=0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(!Exit(nx, ny) && grid[nx][ny]!=0 && !visited[nx][ny]){
                qq.push({nx, ny});
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
                qq.push({i, j});
                visited[i][j] = true;
                
                mx = max(mx, cal_crowd());
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