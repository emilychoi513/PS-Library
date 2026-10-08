#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>
#include <utility>
#define D 0
using namespace std;

int N, M;
int tree[20][20];
vector<vector<int>> pill(20, vector<int>(20, 0));
pair<int, int> direct[105];

void Print(){
    if(!D) return;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << pill[i][j] << " ";
            // cout << tree[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

void Input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> tree[i][j];
        }
    }

    for(int i=0; i<M; i++){
        cin >> direct[i].first >> direct[i].second;
    }

    pill[N-1][0] = 1;
    pill[N-2][0] = 1;
    pill[N-1][1] = 1;
    pill[N-2][1] = 1;
}

void Move(int d, int p){
    int dr[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
    int dc[] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
    vector<vector<int>> tmp(N, vector<int>(N, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(pill[i][j] == 1){
                int ni = i + p*dr[d];
                int nj = j + p*dc[d];

                ni = (ni + 2*N)%N;
                nj = (nj + 2*N)%N;

                tmp[ni][nj] = 1;
            }
        }
    }

    pill = tmp;
}

void Push(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(pill[i][j] == 1){
                tree[i][j]++;
            }
        }
    }

    Print();
}

bool Exit(int x, int y){
    return (x<0 || x>=N || y<0 || y>=N);
}

void Add(){
    int dx[] = {-1, 1, -1, 1};
    int dy[] = {-1, -1, 1, 1};
    vector<vector<int>> tmp(N, vector<int>(N, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(pill[i][j] == 1){
                int s = 0;

                for(int d=0; d<4; d++){
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if(!Exit(ni, nj) && tree[ni][nj] >= 1){
                        s++;
                    }
                }

                tmp[i][j] += s;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tree[i][j] += tmp[i][j];
        }
    }

    Print();
}

void Change(){
    vector<vector<int>> tmp(N, vector<int>(N, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(pill[i][j]!=1){
                if(tree[i][j] >= 2){
                    tree[i][j] -= 2;
                    tmp[i][j] = 1;
                }
            }
        }
    }

    pill = tmp;

    Print();
}

int main() {
    Input();

    for(int i=0; i<M; i++){
        Move(direct[i].first, direct[i].second);

        Push();
        Add();
        Change();
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans += tree[i][j];
        }
    }

    cout << ans;

    return 0;
}