#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define D 0
using namespace std;

int L, N, Q;
int grid[50][50]; //0~L+1
pair<int, int> cmd[105];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct Man{ //0부터 시작
    int r, c;
    int h, w;
    int k;
    int d;
};

Man man[35];

void Print(){
    if(!D) return;
    // for(int i=0; i<=L+1; i++){
    //     for(int j=0; j<=L+1; j++){
    //         cout << grid[i][j] << " ";
    //     }cout << endl;
    // }

    for(int i=0; i<N; i++){
        printf("(%d,%d), h:%d w:%d, k:%d, d:%d\n", man[i].r, man[i].c, man[i].h, man[i].w, man[i].k, man[i].d);
    }
    cout << "-------------" << endl;
}

void Input(){
    cin >> L >> N >> Q;

    for(int i=1; i<=L; i++){
        for(int j=1; j<=L; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<N; i++){
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k;
        man[i] = {r, c, h, w, k, 0};
    }

    for(int i=0; i<Q; i++){
        int id, d;
        cin >> id >> d;
        cmd[i] = {id-1, d};
    }

    for(int i=0; i<=L+1; i++){
        grid[0][i] = 2;
        grid[i][0] = 2;
        grid[L+1][i] = 2;
        grid[i][L+1] = 2;
    }
}

void Damage(int m, int d){
    int trap=0;
    for(int r=0; r<man[m].h; r++){
        for(int c=0; c<man[m].w; c++){
            if(grid[man[m].r + r][man[m].c + c] == 1){
                trap++;
            }
        }
    }

    man[m].k -= trap;
    man[m].d += trap;
    if(man[m].k <= 0) man[m].k = -1;
}

void Turn(int s, int d){
    queue<int> q;
    vector<bool> visited(N, false);

    q.push(s); visited[s]=true;

    bool is_wall = false;
    while(!q.empty()){
        vector<pair<int, int>> tmp;
        int id=q.front(); q.pop();
        // cout << "id : " << id << " " << endl;

        if(d==0){
            for(int i=0; i<man[id].w; i++){
                tmp.push_back({man[id].r - 1, man[id].c + i});
            }
        }else if(d==1){
            for(int i=0; i<man[id].h; i++){
                tmp.push_back({man[id].r + i, man[id].c + man[id].w});
            }
        }else if(d==2){
            for(int i=0; i<man[id].w; i++){
                tmp.push_back({man[id].r + man[id].h, man[id].c + i});
            }
        }else{
            for(int i=0; i<man[id].h; i++){
                tmp.push_back({man[id].r + i, man[id].c - 1});
            }
        }

        // for(auto [nr, nc]: tmp){
        //     printf("next pos: (%d,%d)\n", nr, nc);
        // }

        for(auto [nr, nc]:tmp){
            if(grid[nr][nc]==2){  //1. 벽이면 중지 -> 모든 기사는 움직이지 않음 -> while문 빠져나가기
                is_wall = true;
                // break;
            }

            for(int i=0; i<N; i++){ //2. 다른 기사가 존재할때 -> push해서 bfs계속 진행
                if(man[i].k == -1) continue;
                if(visited[i]) continue;

                bool other_r = (man[i].r <= nr && nr < man[i].r + man[i].h);
                bool other_c = (man[i].c <= nc && nc < man[i].c + man[i].w);

                if(other_r && other_c){
                    // cout << "other man: " << i << endl;
                    q.push(i); visited[i]=true;
                } 
            }
            //3. 빈칸이면 넘어가기
        }
    }
    
    if(is_wall){
        // cout << "there is wall" << endl;
        Print();
        return;
    }else{
        // cout << "no wall, can move" << endl;

        for(int i=0; i<N; i++){
            if(!visited[i]) continue;

            man[i].r += dr[d];
            man[i].c += dc[d];

            if(i==s) continue;
            Damage(i, d);
        }
        
        Print();
    }
}

int main() {
    Input();
    Print();

    for(int i=0; i<Q; i++){
        // cout << "cmd: " << cmd[i].first << " " << cmd[i].second << endl;
        if(man[cmd[i].first].k == -1) continue;
        Turn(cmd[i].first, cmd[i].second);
    }

    int ans=0;
    for(int i=0; i<N; i++){
        if(man[i].k==-1) continue;
        ans += man[i].d;
    }

    cout << ans;

    return 0;
}