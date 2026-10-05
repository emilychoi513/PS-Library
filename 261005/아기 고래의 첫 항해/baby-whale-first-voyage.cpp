#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
#include <climits>
using namespace std;

int N;
int grid[60][60];
int visited[60][60];

int dr[]={-1, 0, 1, 0};
int dc[]={0, -1, 0, 1};

struct Whale{
    int r, c, d;
};

Whale w;

void Print(){
    // printf("[%d %d %d]\n", w.r, w.c, w.d);
    printf("%d %d\n", w.r, w.c);
}

void Input(){
    cin >> N >> w.r >> w.c >> w.d;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> grid[i][j];
        }
    }

    if(w.d==1) w.d=0;
    else if(w.d==3) w.d=1;
    else if(w.d==2) w.d=2;
    else if(w.d==4) w.d=3;

    for(int i=0; i<=N+1; i++){
        grid[0][i]=1;
        grid[i][0]=1;
        grid[N+1][i]=1;
        grid[i][N+1]=1;
    }

    // for(int i=0; i<=N+1; i++){
    //     for(int j=0; j<=N+1; j++){
    //         cout << grid[i][j] << " ";
    //     }cout << endl;
    // }
}

void Explore(){
    int di[]={0, 1, 3, 2};

    while(1){
        // printf("[%d %d %d] -> ", w.r, w.c, w.d);

        bool flag=false;

        for(int i=0; i<4; i++){
            int nd = (w.d+di[i])%4;
            int nr = w.r + dr[nd];
            int nc = w.c + dc[nd];

            if(grid[nr][nc]==0 && !visited[nr][nc]){
                visited[nr][nc] = 1;
                w.r = nr; w.c = nc; w.d=nd;
                Print();
                
                flag=true;
                break;
            }
        }

        if(!flag) break;
    }
}

// pair<int, int> FindSea(){
//     queue<pair<int, int>> q;
//     vector<vector<int>> v(N+2, vector<int>(N+2, -1));

//     q.push({w.r, w.c}); v[w.r][w.c]=0;

//     while(!q.empty()){
//         auto [r, c] = q.front(); q.pop();

//         for(int i=0; i<4; i++){
//             int nr = r + dr[i];
//             int nc = c + dc[i];

//             if(grid[nr][nc]==0 && v[nr][nc]==-1){
//                 q.push({nr, nc}); v[nr][nc]=v[r][c]+1;
//             }
//         }
//     }

//     int ar, ac;
//     int adist = INT_MAX;
//     for(int i=1; i<=N; i++){
//         for(int j=1; j<=N; j++){
//             if(grid[i][j]==0 && !visited[i][j] && v[i][j] < adist){
//                 adist = v[i][j];
//                 ar = i;
//                 ac = j;
//             }
//         }
//     }
//     // cout << "sea: " << ar << " " << ac << endl;
//     return {ar, ac};
// }


pair<int, int> FindSea(){
    priority_queue<tuple<int, int, int>> q;
    vector<vector<bool>> v(N+2, vector<bool>(N+2, false));

    q.push({0, -w.r, -w.c}); v[w.r][w.c]=true;

    while(!q.empty()){
        auto [cnt, r, c] = q.top(); q.pop();
        cnt = -cnt; r = -r; c = -c;
        // printf("pop %d %d %d\n", cnt, r, c);

        if(grid[r][c]==0 && !visited[r][c]){
            return {r, c};
        }

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(grid[nr][nc]==0 && !v[nr][nc]){
                q.push({-(cnt+1), -nr, -nc}); 
                v[nr][nc]=true;
            }
        }
    }
}

void Move2Sea(){
    int di[] = {1, 2, 3, 0};
    queue<pair<int, int>> q;
    vector<vector<bool>> v(N+2, vector<bool>(N+2, false));

    auto [tr, tc] = FindSea();
    
    q.push({w.r, w.c}); v[w.r][w.c]=true;
    
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dr[di[i]];
            int nc = c + dc[di[i]];

            if(grid[nr][nc]==0 && !v[nr][nc]){
                if(tr==nr && tc==nc){
                    w.r=nr; w.c=nc; w.d=di[i];
                    visited[w.r][w.c]=1;
                    Print();
                    return;
                }else{
                    q.push({nr, nc}); v[nr][nc]=true;
                }
            }
        }
    }
}

bool Unvisited(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(grid[i][j]==0 && !visited[i][j]){
                return true;
            }
        }
    }
    return false;
}

int main() {
    Input();

    visited[w.r][w.c]=1;
    Print();
    
    while(1){
        Explore();
        if(!Unvisited()) break;
        Move2Sea();
    }
    return 0;
}