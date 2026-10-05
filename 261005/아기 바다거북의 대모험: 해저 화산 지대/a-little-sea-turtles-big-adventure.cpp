#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <climits>
#define D 0
using namespace std;

int N, M, K;
int grid[30][30];

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

struct Turtle{
    int r, c;
    int turn;
};

struct FireMountain{
    int r, c;
    int s, p;
};

Turtle tt[15];
FireMountain fm[15];

void Print(){
    if(!D) return;
    cout << "Turtle: " << endl;
    for(int i=0; i<M; i++){
        printf("[%d: (%d, %d), %d]\n", i+1, tt[i].r, tt[i].c, tt[i].turn);
    }
    cout << "Fire Mount: " << endl;
    for(int i=0; i<K; i++){
        printf("[%d: (%d, %d), %d/%d]\n", i+1, fm[i].r, fm[i].c, fm[i].s, fm[i].p);
    }cout << endl;
}

void Input(){
    cin >> N >> M >> K;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<M; i++){
        int r, c;
        cin >> r >> c;
        tt[i] = {r+1, c+1, 0};
    }

    for(int i=0; i<K; i++){
        int r, c, P;
        cin >> r >> c >> P;
        fm[i] = {r+1, c+1, 0, P};
    }

    for(int i=0; i<=N+1; i++){
        grid[0][i] = 1;
        grid[i][0] = 1;
        grid[N+1][i] = 1;
        grid[i][N+1] = 1;
    }

    // for(int i=0; i<=N+1; i++){
    //     for(int j=0; j<=N+1; j++){
    //         cout << grid[i][j] << " ";
    //     }cout << endl;
    // }
}

bool there_is_turtle(int r, int c){ //10
    for(int m=0; m<M; m++){ //거북이(살아있는/화석)
        if(tt[m].turn>0) continue;

        if(r==tt[m].r && c==tt[m].c){
            return true;
        }
    }

    return false;
}

int FindDir(int ti){
    vector<vector<bool>> turt(N+2, vector<bool>(N+2, 0));
    queue<pair<int, int>> q;
    vector<vector<int>> dist(N+2, vector<int>(N+2, -1));

    for(int t=0; t<M; t++){ //안식처에 도달하지 않은 것만 기록.
        if(tt[t].turn <= 0){
            turt[tt[t].r][tt[t].c] = true;
        }
    }

    q.push({N, N}); dist[N][N]=0;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for(int d=0; d<4; d++){
            int nx = x + dr[d];
            int ny = y + dc[d];

            if(grid[nx][ny]==0 && !turt[nx][ny] && dist[nx][ny]==-1){
                q.push({nx, ny}); dist[nx][ny]=dist[x][y]+1;
            }
        }
    }

    int dis = INT_MAX; int dir = -1;
    for(int d=0; d<4; d++){
        int nr = tt[ti].r + dr[d];
        int nc = tt[ti].c + dc[d];
        if(dist[nr][nc]!=-1 && dist[nr][nc] < dis){
            dis = dist[nr][nc];
            dir = d;
        }
    }

    return dir;
}

void TurtleMove(int turn){
    for(int t=0; t<M; t++){
        if(tt[t].turn != 0) continue;

        int dir = FindDir(t);
        if(dir == -1) continue;

        tt[t].r += dr[dir];
        tt[t].c += dc[dir];

        if(tt[t].r == N && tt[t].c == N){
            tt[t].turn = turn;
        }
    }
}

void FireInc(){
    for(int i=0; i<K; i++){
        fm[i].s += 10;
    }
}

void Bomb(){
    vector<vector<int>> hot(N+2, vector<int>(N+2, 0));
    vector<bool> bombed(K, 0);

    //열기 전파
    bool bombFlag=false;
    for(int i=0; i<K; i++){
        if(fm[i].s >= fm[i].p){
            bombed[i] = true;
            bombFlag=true;

            int r=fm[i].r; int c=fm[i].c; int p=fm[i].p;
            hot[r][c] += p;

            for(int d=0; d<4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];
                int np = (int)p/2;

                while(grid[nr][nc]==0 && np>0){
                    hot[nr][nc]+=np;

                    nr += dr[d]; nc += dc[d]; np /= 2;
                }
            }
        }
    }
    if(!bombFlag) return;

    // cout << "hot after bomb: " << endl;
    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cout << hot[i][j] << " ";
    //     }cout << endl;
    // }

    //연쇄 반응
    while(1){
        bombFlag = false;

        for(int i=0; i<K; i++){
            if(bombed[i]) continue;

            if(fm[i].s + hot[fm[i].r][fm[i].c] >= fm[i].p){
                bombed[i] = true;
                bombFlag=true;

                int r=fm[i].r; int c=fm[i].c; int p=fm[i].p;
                hot[r][c] += p;

                for(int d=0; d<4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    int np = (int)p/2;

                    while(grid[nr][nc]==0 && np>0){
                        hot[nr][nc]+=np;

                        nr += dr[d]; nc += dc[d]; np /= 2;
                    }
                }
            }
        }

        if(!bombFlag) break;
    }

    // cout << "hot after chain responses: " << endl;
    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cout << hot[i][j] << " ";
    //     }cout << endl;
    // }

    //화석화
    for(int i=0; i<M; i++){
        if(tt[i].turn == 0){
            if(hot[tt[i].r][tt[i].c] >= 20){
                tt[i].turn = -1;
            }
        }
    }

    //초기화
    for(int i=0; i<K; i++){
        if(bombed[i]){
            fm[i].s = 0;
        }
    }

    // Print();
}

void Turn(int turn){
    TurtleMove(turn);

    FireInc();

    Bomb();
}

bool there_is_alive_turtle(){
    for(int i=0; i<M; i++){
        if(tt[i].turn == 0) return true;
    }

    return false;
}

int main() {
    Input();
    Print();

    for(int t=1; t<=100; t++){
        if(!there_is_alive_turtle()) break;
        Turn(t);
        Print();
    }

    for(int i=0; i<M; i++){
        int ans = tt[i].turn;
        if(ans == 0) ans = -1;
        cout << ans << endl;
    }

    return 0;
}