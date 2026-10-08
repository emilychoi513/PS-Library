#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#define D 0
using namespace std;

int M, T;
int pr, pc;
struct Monster{
    int r, c;
    int dir;
    int stat;
};

vector<Monster> mst;

void Print(){
    if(!D) return;
    for(Monster m:mst){
        printf("(%d, %d), dir(%d), stat(%d)\n", m.r, m.c, m.dir, m.stat);
    }
}

void Input(){
    cin >> M >> T;

    cin >> pr >> pc;

    for(int i=0; i<M; i++){
        int r, c, dir;
        cin >> r >> c >> dir;
        mst.push_back({r, c, dir-1, 2});
    }
}

void Init(){
    for(Monster& m:mst){
        if(m.stat < 0) m.stat++;
    }
}

void Copy(){
    vector<Monster> tmp;

    for(Monster m:mst){
        tmp.push_back(m);

        if(m.stat == 2){
            tmp.push_back({m.r, m.c, m.dir, 1});
        }
    }

    mst = tmp;
}

bool Exit(int x, int y){
    return (x<=0 || x>4 || y<=0 || y>4);
}

void Move_Monster(){
    vector<vector<int>> body(10, vector<int>(10, 0));
    int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

    for(Monster m:mst){
        if(m.stat <= 0){
            body[m.r][m.c] = 1;
        }
    }

    // cout << "body: " << endl;
    // for(int i=1; i<=4; i++){
    //     for(int j=1; j<=4; j++){
    //         cout << body[i][j] << " ";
    //     }cout << endl;
    // }cout <<endl;

    for(Monster& m:mst){
        if(m.stat != 2) continue;

        for(int d=0; d<8; d++){
            int nr = m.r + dr[(m.dir + d)%8];
            int nc = m.c + dc[(m.dir + d)%8];

            bool can_move = true;

            if(nr==pr && nc==pc) can_move = false;
            else if(body[nr][nc]) can_move = false;
            else if(Exit(nr, nc)) can_move = false;
            
            if(can_move){
                m.dir = (m.dir + d)%8;
                m.r = nr;
                m.c = nc;
                break;
            }else{
                continue;
            }
        }
    }
}

void Move_Pacman(){
    vector<vector<int>> tmp(5, vector<int>(5, 0));
    int dr[] = {-1, 0, 1, 0}; //상좌하우
    int dc[] = {0, -1, 0, 1};

    for(Monster m:mst){
        if(m.stat == 2){
            tmp[m.r][m.c]++;
        }
    }

    // for(int i=1; i<=4; i++){
    //     for(int j=1; j<=4; j++){
    //         cout << tmp[i][j] << " ";
    //     }cout << endl;
    // }cout << endl;

    // printf("pacman loc: (%d, %d)\n", pr, pc);

    pair<int, int> p[3];
    int mx = -1;
    for(int i=0; i<4; i++){
        int r1 = pr + dr[i];
        int c1 = pc + dc[i];
        if(Exit(r1, c1)) continue;

        for(int j=0; j<4; j++){
            int r2 = r1 + dr[j];
            int c2 = c1 + dc[j];
            if(Exit(r2, c2)) continue;

            for(int k=0; k<4; k++){
                int r3 = r2 + dr[k];
                int c3 = c2 + dc[k];
                if(Exit(r3, c3)) continue;

                int s = tmp[r1][c1] + tmp[r2][c2] + tmp[r3][c3];
                if(r1==r3 && c1==c3){
                    s -= tmp[r1][c1];
                }
                // printf("%d(%d,%d) %d(%d,%d) %d(%d,%d): %d\n", i, r1, c1, j,r2, c2, k,r3, c3,s );
                if(s > mx){
                    // printf("%d %d %d: %d\n", i, j, k, s);
                    mx = s;
                    p[0] = {r1, c1};
                    p[1] = {r2, c2};
                    p[2] = {r3, c3};
                }
            }
        }
    }

    //팩맨 위치 반영
    pr = p[2].first;
    pc = p[2].second;

    //먹은 몬스터는 시체로 변환
    for(Monster& m:mst){
        if(m.stat != 2) continue;
        for(pair<int, int> pos:p){
            if(m.r == pos.first && m.c == pos.second){
                m.stat = -2;
                break;
            }
        }
    }
    // cout << "pacman pos: " << pr << " " <<pc <<endl;
}

void Remove_Body(){
    vector<Monster> tmp;

    for(Monster m:mst){
        if(m.stat != 0) tmp.push_back(m);
    }

    mst = tmp;
}

void Copy_Complete(){
    for(Monster& m:mst){
        if(m.stat==1) m.stat=2;
    }
}

void Turn(){
    Init();

    Copy();
    // cout << "Copy: \n"; Print();

    Move_Monster();
    // cout << "Move Monster: \n"; Print();

    Move_Pacman();
    // cout << "Move Pacman: \n"; Print();

    Remove_Body();
    Copy_Complete();

    // cout << "Remove and Copy: \n"; Print();
}

int main() {
    Input();

    while(T--){
        Turn();
    }

    int ans = 0;
    for(Monster m:mst){
        if(m.stat == 2){
            ans++;
        }
    }

    cout << ans;

    return 0;
}