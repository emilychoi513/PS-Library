#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <queue>
#include <climits>
#define D 0
using namespace std;

int N, Q;
vector<vector<int>> grid(20, vector<int>(20, 0));

struct Pos{
    int r1, c1;
    int r2, c2;
};

struct Micro{
    int area; //사라지면 0이 된다.
    int r, c;
};

Pos pos[60];
vector<Micro> mic(60);

void Input(){
    cin >> N >> Q;

    for(int i=1; i<=Q; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        pos[i] = {r1, c1, r2, c2};
        mic[i] = {0, r1, c1};
    }
}

bool Exit(int x, int y){
    return (x<0 || x>=N || y<0 || y>=N);
}

void Print(){
    if(!D) return;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

void Push(int mid){
    Pos p = pos[mid];
    for(int i=p.r1; i<p.r2; i++){
        for(int j=p.c1; j<p.c2; j++){
            grid[i][j] = mid;
        }
    }


// 2. 영역 검사: 
//     둘 이상으로 나누어지면 grid에서 해당 미생물 없애기(시작 좌표와 영역 크기 업데이트))
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    vector<vector<int>> v(N, vector<int>(N, 0));

    vector<int> visited_group(Q+1, 0);
    vector<int> rm_group(Q+1, 0);
    
    vector<Micro> tmp_mic(Q+1);

    for(int i=1; i<=Q; i++){
        tmp_mic[i] = {0, -1, -1};
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j]==0 || v[i][j]) continue;

            q.push({i, j}); v[i][j] = 1;
            int area = 1;

            while(!q.empty()){
                int x, y;
                tie(x, y) = q.front(); q.pop();

                for(int d=0; d<4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(!Exit(nx, ny) && grid[nx][ny]==grid[i][j] && !v[nx][ny]){
                        q.push({nx, ny}); v[nx][ny] = 1;
                        area++;
                    }
                }
            }

            // area, i, j
            int id = grid[i][j];
            if(visited_group[id]) rm_group.push_back(id); 
            
            visited_group[id] = 1;
            tmp_mic[id] = {area, i, j};
        }
    }


    for(int id:rm_group){
        tmp_mic[id] = {0, -1, -1};

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] == id){
                    grid[i][j] = 0;
                }
            }
        }
    }

    mic = tmp_mic;

    // printf("%d번째: \n", mid); Print();
}

void Move(){
    vector<tuple<int, int>> order;
    vector<vector<int>> new_grid(N, vector<int>(N, 0));

    for(int i=1; i<=Q; i++){
        if(mic[i].area == 0) continue;
        order.push_back({-mic[i].area, i});
    }

    sort(order.begin(), order.end());

    // for(tuple<int, int> t:order){
    //     int area, id;
    //     tie(area, id) = t;
    //     area = -area;
    //     printf("id: %d, area: %d\n", id, area);
    // }

    for(tuple<int, int> t:order){
        int area, id;
        tie(area, id) = t;

        int sr = mic[id].r;
        int sc = mic[id].c;
        
        // printf("[%d %d %d %d]\n", id, -area, sr, sc);
        vector<pair<int, int>> vp;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] == id){
                    vp.push_back({i-sr, j-sc});
                    // printf("pos: %d %d\n", i-sr, j-sc);
                }
            }
        }

        bool flag;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){ //시작 좌표
                
                flag = true;
                for(pair<int, int> p: vp){
                    int x, y;
                    tie(x, y) = p;

                    if(Exit(x + i, y + j) || new_grid[x + i][y + j]!=0){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    for(pair<int, int> p:vp){
                        new_grid[p.first + i][p.second + j] = id;
                        mic[id].r = i; mic[id].c = j;
                    }
                    // printf("start: %d (%d, %d)\n", id, i, j);
                    break;
                }
            }

            if(flag) break;
        }
        
        // for(int i=0; i<N; i++){
        //     for(int j=0; j<N; j++){
        //         cout << new_grid[i][j] << " ";
        //     }cout << endl;
        // }cout << endl;
    }

    grid = new_grid;

    Print();
}

void Result(){
// 실험 결과 기록
// 1. near 2차원 배열 만들어서(near[A][B] = 1, near[B][A] = 1)
// 2. grid BFS: 모든 인접한 무리 쌍 찾기
// 3. 모든 무리의 영역 넓이 반영해서 결과 출력
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    vector<vector<int>> near(Q+1, vector<int>(Q+1, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j] == 0) continue;

            for(int d=0; d<4; d++){
                int ni = i + dx[d];
                int nj = j + dy[d];

                if(Exit(ni, nj) || grid[ni][nj]==0) continue;

                if(grid[ni][nj] != grid[i][j]){
                    int x = grid[i][j];
                    int y = grid[ni][nj];

                    near[x][y] = 1;
                    near[y][x] = 1;
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=Q; i++){
        for(int j=i; j<=Q; j++){
            if(near[i][j] == 1){
                ans += mic[i].area * mic[j].area;
            }
        }
    }

    cout << ans << endl;
}

void Turn(int mid){
    Push(mid);

    Move();

    Result();
}

int main() {
    Input();

    for(int i=1; i<=Q; i++){
        Turn(i);
    }
    
    return 0;
}