#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <queue>
#include <climits>
#define D 0
using namespace std;

int N, K, L;
int grid[40][40];
int dr[] = {0, 1, 0, -1}; //우하좌상
int dc[] = {1, 0, -1, 0}; 

struct Robot{
    int r, c;
};

Robot rb[60];

void Print(){
    if(!D) return;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

void Input(){
    cin >> N >> K >> L;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<K; i++){
        cin >> rb[i].r >> rb[i].c;
    }

    for(int i=0; i<=N+1; i++){
        grid[i][0] = -1;
        grid[0][i] = -1;
        grid[i][N+1] = -1;
        grid[N+1][i] = -1;
    }

    // for(int i=0; i<=N+1; i++){
    //     for(int j=0; j<=N+1; j++){
    //         cout << grid[i][j] << " ";
    //     }cout << endl;
    // }

    // for(int i=0; i<K; i++){
        // printf("[%d: %d, %d]\n", i, rb[i].r, rb[i].c);
    // } //초기 위치 처리: 먼지X는 보장. / 물건이나 다른 로봇청소기와 겹칠때 처리 필요
}

void MoveRobot(int ri){
    vector<vector<int>> robot(N+2, vector<int>(N+2, 0));
    queue<pair<int, int>> q;
    vector<vector<int>> visited(N+2, vector<int>(N+2, -1));

    for(int i=0; i<K; i++){
        if(i==ri) continue;
        robot[rb[i].r][rb[i].c] = 1;
    }

    q.push({rb[ri].r, rb[ri].c}); 
    visited[rb[ri].r][rb[ri].c] = 0;

    while(!q.empty()){
        int r, c;
        tie(r, c) = q.front(); q.pop();

        for(int d=0; d<4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];

            if(grid[nr][nc]!=-1 && !robot[nr][nc] && visited[nr][nc]==-1){
                q.push({nr, nc});
                visited[nr][nc] = visited[r][c] + 1;
            }
        }
    }

    // printf("%d move: \n", ri);
    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cout << visited[i][j] << " ";
    //     }cout << endl;
    // }

    int dist = INT_MAX;
    int r=-1; int c=-1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(grid[i][j]>0 && visited[i][j]!=-1 && visited[i][j] < dist){
                dist = visited[i][j];
                r = i; c = j;
            }
        }
    }

    if(r!=-1){ //만약 더이상 오염된 격자 없으면?
        rb[ri].r = r; rb[ri].c = c;
        // printf("%d move: %d %d\n", ri, rb[ri].r, rb[ri].c);
    }
}

void Clean(int ri){
    int r = rb[ri].r; int c = rb[ri].c;
    int tar_sum = 0; int tar_dir = -1;

    for(int d=0; d<4; d++){ //우하좌상
        int tmp_sum = 0;
        int tdr[] = {0, dr[d], dr[(d+3)%4], dr[(d+1)%4]};
        int tdc[] = {0, dc[d], dc[(d+3)%4], dc[(d+1)%4]};

        for(int k=0; k<4; k++){
            int tr = r + tdr[k];
            int tc = c + tdc[k];

            if(grid[tr][tc]>0){
                // cout << tr << " " << tc << endl;
                tmp_sum += min(20, grid[tr][tc]);
            }
        }
        // printf("dir %d -> %d\n", d, tmp_sum);
        if(tmp_sum > tar_sum){
            tar_sum = tmp_sum;
            tar_dir = d;
        }
    }

    // printf("%d clean: sum %d, dir %d\n", ri, tar_sum, tar_dir);

    int tdr[] = {0, dr[tar_dir], dr[(tar_dir+3)%4], dr[(tar_dir+1)%4]};
    int tdc[] = {0, dc[tar_dir], dc[(tar_dir+3)%4], dc[(tar_dir+1)%4]};
    for(int d=0; d<4; d++){
        int tr = r + tdr[d];
        int tc = c + tdc[d];
        
        if(grid[tr][tc]>0){
            grid[tr][tc] -= min(grid[tr][tc], 20);
        }
    }

    // Print();
}

void Add(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(grid[i][j] > 0){
                grid[i][j] += 5;
            }
        }
    }
}

void Spread(){
    vector<vector<int>> tmp(N+2, vector<int>(N+2, 0));

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(grid[i][j] == 0){
                int sum_dust = 0;
                for(int d=0; d<4; d++){
                    int ni = i + dr[d];
                    int nj = j + dc[d];

                    if(grid[ni][nj] > 0) sum_dust += grid[ni][nj];
                }

                tmp[i][j] = sum_dust / 10;
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            grid[i][j] += tmp[i][j];   
        }
    }
}

void Turn(){
    for(int i=0; i<K; i++){
        MoveRobot(i);
    }
    
    for(int i=0; i<K; i++){
        Clean(i);
    }

    Print();

    Add();
    Print();
    
    Spread();
    Print();
}

int SumDust(){
    int s = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(grid[i][j] > 0) s += grid[i][j];
        }
    }

    return s;
}

int main(){
    Input();

    while(L--){
        Turn();
        
        int ans = SumDust();
        cout << ans << endl;
        if(ans == 0) break;
    }
}