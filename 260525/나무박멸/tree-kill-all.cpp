#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>
#include <utility>
#include <iomanip>
using namespace std;

int n;
int m; //박멸 년
int k; //제초제 확산 범위
int c; //제초제 유지 년
int grid[20][20];
int frozen_years[20][20];
int answer;

void Print(){
    int width = 3;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << setw(width) << grid[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

bool Exit(int x, int y){
    return (x<0||x>=n||y<0||y>=n);
}

void grow(){
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    //count 인접 나무 수 (>0)
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] <= 0) continue;
            int tree_cnt = 0;
            for(int dir=0; dir<4; dir++){
                int ni = i+dx[dir];
                int nj = j+dy[dir];
                if(Exit(ni, nj)) continue;
                if(grid[ni][nj] > 0){
                    tree_cnt++;
                }
            }
            grid[i][j] += tree_cnt;
        }
    }
    //cout << "grow: " << endl; Print();
}

void born(){
    vector<vector<int>> tmp_grid(n, vector<int>(n, 0));
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] <= 0) continue;

            int empty_cnt = 0;
            for(int dir=0; dir<4; dir++){
                int ni = i+dx[dir];
                int nj = j+dy[dir];
                if(Exit(ni, nj)) continue;
                if(frozen_years[ni][nj] > 0) continue;
                if(grid[ni][nj] == 0){
                    empty_cnt++;
                }
            }

            if(empty_cnt == 0) continue;

            for(int dir=0; dir<4; dir++){
                int ni = i+dx[dir];
                int nj = j+dy[dir];
                if(Exit(ni, nj)) continue;
                if(frozen_years[ni][nj] > 0) continue;
                if(grid[ni][nj] == 0){
                    tmp_grid[ni][nj] += grid[i][j] / empty_cnt;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j] += tmp_grid[i][j];
        }
    }

    //cout << "born: " << endl; Print();
}

tuple<int, int, int> kill_select(){
    vector<vector<int>> killed_tree(n, vector<int>(n, 0));
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, -1, 1};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] <= 0) continue;
            killed_tree[i][j] += grid[i][j];

            for(int dir=0; dir<4; dir++){
                for(int step=1; step<=k; step++){
                    int ni = i + dx[dir]*step;
                    int nj = j + dy[dir]*step;

                    if(Exit(ni, nj)) break;
                    if(grid[ni][nj] <= 0) break;

                    killed_tree[i][j] += grid[ni][nj];
                }
            }
        }
    }
    int Max_killed = 0;
    int mx, my;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(killed_tree[i][j] > Max_killed){
                Max_killed = killed_tree[i][j];
                mx = i; my = j;
            }   
        }
    }
    //cout << "push loc: " << endl;
    //cout << mx << " " << my << endl;
    //cout << "killed tree: " << endl;
    //cout << Max_killed << endl;
    return make_tuple(mx, my, Max_killed);
}

void kill_update(){
    //박멸 연도 업데이트
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(frozen_years[i][j] > 0){
                frozen_years[i][j]--;
            }
        }
    }
}

void kill(){
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, -1, 1};

    //year update: 제초제 유지 연도 업데이트
    kill_update();

    //select
    int kx, ky, knum;
    tie(kx, ky, knum) = kill_select();
    if(knum == 0){
        return;
    }

    //answer update
    answer += knum;
    
    //kill: 제초제 새로 뿌리기
    frozen_years[kx][ky] = c;
    grid[kx][ky] = 0;
    for(int dir=0; dir<4; dir++){
        for(int step=1; step<=k; step++){
            int nx = kx + dx[dir]*step;
            int ny = ky + dy[dir]*step;

            if(Exit(nx, ny)) break;
            frozen_years[nx][ny] = c;
            if(grid[nx][ny] <= 0) {
                break;
            }
            grid[nx][ny] = 0;

        }
    }

    /*cout << "frozen years: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << frozen_years[i][j] << " ";
        }cout << endl;
    }cout << endl;*/

    //cout << "kill 1 year: " << endl; Print();
}

void one_year(){ //c년 동안 유지
    grow();
    born();
    kill();
}

int main() {
    cin >> n >> m >> k >> c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    answer = 0;
    for(int i=0; i<m; i++){
        //cout << "======== " << i+1 << " ========" << endl;
        one_year();
    }
    //cout << "answer: " << answer << endl;
    cout << answer;
    
    return 0;
}