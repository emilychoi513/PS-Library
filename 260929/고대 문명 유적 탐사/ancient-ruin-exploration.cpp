#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#define DEBUG 0
using namespace std;

int K, M;
vector<vector<int>> grid(5, vector<int>(5));
int wall[305];
int widx;
int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void input(){
    cin >> K >> M;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<M; i++){
        cin >> wall[i];
    }
}

void Print(){
    if(!DEBUG) return;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

bool Exit(int x, int y){
    return (x<0 || x>=5 || y<0 || y>=5);
}

//비워야 하는 칸의 좌표 반환 - 최대 가치(점수)를 함께 알 수 있음
vector<pair<int, int>> get_pieces(vector<vector<int>>& mat){ //bfs
    vector<vector<int>> visited(5, vector<int>(5, 0));
    vector<pair<int, int>> result;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            queue<pair<int, int>> q;
            vector<pair<int, int>> group;
            if(visited[i][j]) continue;

            q.push({i, j}); visited[i][j] = 1;
            group.push_back({i, j});

            while(!q.empty()){
                auto [x, y] = q.front(); q.pop();
                for(int k=0; k<4; k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];

                    if(!Exit(nx, ny) && !visited[nx][ny] && mat[nx][ny]==mat[i][j]){
                        q.push({nx, ny}); visited[nx][ny] = 1;
                        group.push_back({nx, ny});
                    }
                }
            }

            if(group.size() >= 3){
                for(auto p:group){
                    result.push_back(p);
                }
                // cout << i << " " << j << " " << cnt << endl;
            }
        }
    }

    return result;
}

//90도 시계 방향 회전
void rotate90(vector<int>& tmp){
    int t0 = tmp[6]; int t1 = tmp[7];
    for(int p=7; p>=2; p--){
        tmp[p] = tmp[p-2];
    }
    tmp[0] = t0; tmp[1] = t1;
}

//탐사 진행
int explore(){
    priority_queue<tuple<int, int, int, int>> pq;
    //탐사하기 -> 최적의 좌표, 회전각도를 찾기
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            vector<int> tmp;
            for(int k=0; k<8; k++){
                tmp.push_back(grid[i+dr[k]][j+dc[k]]);
            }

            for(int a=0; a<3; a++){
                rotate90(tmp);

                vector<vector<int>> mat = grid;

                for(int b=0; b<8; b++){
                    mat[i+dr[b]][j+dc[b]] = tmp[b];
                }

                pq.push({(int)get_pieces(mat).size(), -a, -j, -i});
            }
        }
    }

    int val, rot, x, y;
    tie(val, rot, y, x) = pq.top();
    rot=-rot; x=-x; y=-y;

    if(val==0) return 0;
    
    //grid에 반영하기 -> 찾은 최적의 조합으로 grid에 반영하기
    vector<int> tmp; //tmp
    for(int k=0; k<8; k++){
        tmp.push_back(grid[x+dr[k]][y+dc[k]]);
    }
    for(int a=0; a<=rot; a++){ //tmp rotate
        rotate90(tmp);
    }
    for(int b=0; b<8; b++){ //tmp -> grid
        grid[x+dr[b]][y+dc[b]] = tmp[b];
    }
    Print();
    return val;
}

void gain(){
    int total = 0;

    while(1){
        //유물 조각 자리를 비우기
        vector<pair<int, int>> vp = get_pieces(grid);
        total += vp.size();

        if(vp.size()==0) break;

        for(int i=0; i<vp.size(); i++){
            grid[vp[i].first][vp[i].second]=0;
        }
        Print();

        //벽면의 숫자를 차례대로 채우기
        for(int j=0; j<5; j++){
            for(int i=4; i>=0; i--){
                if(grid[i][j] == 0){
                    grid[i][j] = wall[widx];
                    widx++;
                }
            }
        }
        Print();
    }

    cout << total << " ";
}

int main() {
    input();

    widx = 0;

    for(int i=0; i<K; i++){
        //explore 이후 1차 유물 획득: 0이면 전체 종료
        if(!explore()) break;
        //비우고 채워는 걸 반복 -> 점수 업데이트하기
        gain();
    }

    return 0;
}