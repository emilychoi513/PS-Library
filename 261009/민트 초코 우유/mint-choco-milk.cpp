#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#define D 0
using namespace std;

int N, T;
int B[60][60];
vector<char> F[60][60]; //123을 가짐

void Input(){
    cin >> N >> T;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            char c;
            cin >> c;
            F[i][j].push_back(c);
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> B[i][j];
        }
    }
}

void Print(){
    if(!D) return;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << B[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

void Morning(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            B[i][j]++;
        }
    }

    Print();
}

bool Exit(int x, int y){
    return (x<=0 || x>N || y<=0 || y>N);
}

vector<pair<int, int>> Lunch(){
    queue<pair<int, int>> q;
    vector<vector<int>> v(N+1, vector<int>(N+1, 0)); //전체 grid에서 찾기 할때
    vector<tuple<int, int, int, int>> heads; 
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    // 모든 그룹을 찾기
    //     1. 그룹 찾기(BFS)
    //     2. 대표자 뽑기 - visited 배열 돌면서 신앙심 최대인 곳 기록
    //     3. 신앙심 옮기기 - 대표자 위치에 그룹원 수 만큼 더 더하기, 대표자 포함 나머지 모두 -1
    //     4. 대표자 정보(신앙음식(F), 신앙심(B), 행, 열) -> 그냥 행열만 기록해서 dinner에 전달
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(v[i][j]) continue;

            vector<vector<int>> group(N+1, vector<int>(N+1, 0));
            q.push({i, j}); group[i][j] = 1;

            while(!q.empty()){
                int x, y;
                tie(x, y) = q.front(); q.pop();

                for(int d=0; d<4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(!Exit(nx, ny) && !group[nx][ny] && F[nx][ny] == F[i][j]){
                        q.push({nx, ny});
                        group[nx][ny] = 1;
                    }
                }
            }

            //대표자 정하기
            int hr = -1; int hc = -1;
            int mx = -1;
            int num = 0;
            for(int a=1; a<=N; a++){
                for(int b=1; b<=N; b++){
                    if(group[a][b] == 0) continue;
                    
                    v[a][b] = 1;
                    num++;
                    
                    if(B[a][b] > mx){
                        mx = B[a][b];
                        hr = a; hc = b;
                    }

                    B[a][b]--;
                }
            }

            //신앙심 옮기기
            B[hr][hc] += num;

            // printf("[%d %d %d %d]\n", F[hr][hc].size(), B[hr][hc], hr, hc);
            // printf("%d %d\n", hr, hc);
            heads.push_back({F[hr][hc].size(), -B[hr][hc], hr, hc});
        }
    }

    sort(heads.begin(), heads.end()); //오름차순

    vector<pair<int, int>> heads_pos;
    for(tuple<int, int, int, int> t:heads){
        int f, b, r, c;
        tie(f, b, r, c) = t;
        heads_pos.push_back({r, c});
    }
    
    //Dinner에 전달
    return heads_pos;
}

void Dinner(){
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    //전파자 정보(위치)만 받기
    vector<pair<int, int>> waver = Lunch();
    vector<vector<int>> waved(N+1, vector<int>(N+1, 0));
    
    //모든 전파자에 대해 아래 수행(전파 당한 전파자 제외)
    for(pair<int, int> p:waver){
        int r, c;
        tie(r, c) = p;
        // cout << r << " " << c << endl;

        if(waved[r][c]) continue; //전파당한 전파자는 처리 안함
        // 1. 정보 업데이트 - 전파 방향: B%4, 간절함: x = B-1, 신앙심: B=1
        int dir = B[r][c]%4;
        int x = B[r][c]-1;
        B[r][c] = 1;
        // 2. 한칸씩 이동 반복 시작
        int nr = r;
        int nc = c;
        while(1){
            if(x == 0) break;

            nr += dr[dir];
            nc += dc[dir];

            if(Exit(nr, nc)) break;
            if(F[nr][nc] == F[r][c]) continue;
            
            waved[nr][nc] = 1;
            
            if(x > B[nr][nc]){
                x -= (B[nr][nc]+1);
                B[nr][nc]++;
                F[nr][nc] = F[r][c];
            }else{
                B[nr][nc] += x;
                x = 0;

                for(char waving:F[r][c]){
                    bool flag = false;
                    for(char waved:F[nr][nc]){
                        if(waved == waving) flag = true;
                    }

                    if(!flag){
                        F[nr][nc].push_back(waving);
                    }
                }
                sort(F[nr][nc].begin(), F[nr][nc].end());
            }
        }

        // Print();
    }
}

void Count(){
    vector<char> str[] = {{'C', 'M', 'T'}, {'C', 'T'}, {'M', 'T'}, {'C', 'M'}, {'M'}, {'C'}, {'T'}};
    vector<int> cnt(7, 0);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<7; k++){
                if(F[i][j] == str[k]){
                    cnt[k] += B[i][j];
                }
            }
        }
    }

    for(int i=0; i<7; i++){
        cout << cnt[i] << " ";
    }cout << endl;
}

void Day(){
    Morning();
    Dinner();
    Print();
    Count();
}

int main() {
    Input();

    while(T--){
        Day();
    }

    return 0;
}