#include <iostream>
#include <utility>
#include <algorithm>
#include <tuple>
#include <vector>
#define DEBUG 0
using namespace std;

int N, M, K;
int grid[15][15];
bool flagE = false;

struct Man{
    int r;
    int c;
    int d;
    bool e;
};

Man man[15];

void Print(){
    if(!DEBUG) return;

    cout << "--------" << endl;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }
    
    for(int i=0; i<M; i++){
        if(man[i].e) cout << "exit - ";
        printf("%d %d %d\n", man[i].r, man[i].c, man[i].d);
    }
    // cout << "--------" << endl;
}

void Input(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<M; i++){
        cin >> man[i].r >> man[i].c;
        man[i].d = 0;
        man[i].e = false;
    }

    int er, ec;
    cin >> er >> ec;
    grid[er][ec] = -1;
}

pair<int, int> Find_exit(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(grid[i][j] == -1){
                return {i, j};
            }
        }
    }
}

int Dist(int r1, int c1, int r2, int c2){
    return abs(r1 - r2) + abs(c1 - c2);
}

tuple<int, int, int> Find_sqa(){
    for(int s=2; s<=N; s++){
        for(int r=1; r+s-1<=N; r++){
            for(int c=1; c+s-1<=N; c++){ // (r, c) - (r+s-1, c+s-1)

                bool f1=false; bool f2=false;
                for(int row=r; row<r+s; row++){
                    for(int col=c; col<c+s; col++){
                        if(grid[row][col]==-1){
                            f1=true;
                        }
                        for(int m=0; m<M; m++){
                            if(man[m].e) continue;
                            if(man[m].r==row && man[m].c==col){
                                f2=true; 
                                break;
                            }
                        }

                        if(f1 && f2){
                            return {s, r, c};
                        }
                    }
                }
            }
        }
    }
}

void Rotate_Dec(int s, int r, int c){
    vector<vector<int>> tmp(s, vector<int>(s, 0));

    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            tmp[i][j] = grid[s-1-j+r][i+c];

            if(tmp[i][j] > 0) tmp[i][j]--;
        }
    }

    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            grid[r+i][c+j] = tmp[i][j];
        }
    }

    for(int i=0; i<M; i++){
        if(man[i].e) continue;
        if(man[i].r >= r && man[i].r < r+s && man[i].c >= c && man[i].c < c+s){
            int mr = man[i].r-r; int mc = man[i].c-c;
            man[i].r = mc + r;
            man[i].c = s-1-mr + c;
        }
    }
}

bool All_exit(){
    for(int i=0; i<M; i++){
        if(man[i].e == false) return false;
    }
    return true;
}

void Turn(){
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    //exit 좌표 찾기
    auto [er, ec] = Find_exit();

    //참가자 움직임
    for(int i=0; i<M; i++){
        if(man[i].e) continue;
        int r = man[i].r; int c = man[i].c;
        for(int dir=0; dir<4; dir++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if(grid[nr][nc] > 0) continue;
            if(Dist(nr, nc, er, ec) >= Dist(r, c, er, ec)) continue;

            if(grid[nr][nc] == -1) man[i].e = true;
            man[i].r = nr; man[i].c = nc;
            man[i].d++;

            break;
        }
    }
    Print();

    if(All_exit()){
        flagE = true;
        return;
    }

    auto [s, r, c] = Find_sqa(); //정사각형 찾기
    Rotate_Dec(s, r, c); //회전하고 내구도 감소하기
    Print();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    while(K-- && !flagE){
        Turn();
    }

    int ans = 0;
    for(int i=0; i<M; i++){
        ans += man[i].d;
    }
    cout << ans << endl;

    auto [ec, er] = Find_exit();
    cout << ec << " " << er << endl;


    return 0;
}