#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>
#include <climits>
#include <deque>
#define D 0
using namespace std;

int N, M, K;
int grid[15][15];
int grow[15][15];
deque<int> vs[15][15];

void Print(){
    if(!D) return;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }cout << endl;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int s = 0;
            for(int x:vs[i][j]){
                if(x == INT_MAX) break;
                s++;
            }

            cout << s << " ";
        }cout << endl;
    }cout << endl;
}

void Input(){
    cin >> N >> M >> K;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> grow[i][j];
        }
    }

    for(int i=0; i<M; i++){
        int r, c, age;
        cin >> r >> c >> age;
        vs[r][c].push_back(age);
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            grid[i][j] = 5;
            sort(vs[i][j].begin(), vs[i][j].end());
        }
    }
}

void Take_and_Push(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int died = 0;
            deque<int> tmp;

            for(int x:vs[i][j]){
                if(x <= grid[i][j]){
                    grid[i][j] -= x;
                    tmp.push_back(x+1);
                }else{
                    died += x/2;
                }
            }

            vs[i][j] = tmp;
            grid[i][j] += died;
        }
    }
}

bool Exit(int r, int c){
    return (r<=0 || r>N || c<=0 || c>N);
}

void Spread(){
    int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int x:vs[i][j]){
                if(x%5==0){
                    for(int d=0; d<8; d++){
                        int ni = i + dr[d];
                        int nj = j + dc[d];

                        if(!Exit(ni, nj)){
                            vs[ni][nj].push_front(1);
                        }
                    }
                }
            }
        }
    }
}

void Add(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            grid[i][j] += grow[i][j];
        }
    }
}

void Turn(){
    Take_and_Push();
    Print();

    Spread();
    Print();

    Add();
    Print();
}

int CheckVirus(){
    int s = 0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            s += vs[i][j].size();
        }
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Input();

    Print();

    // Turn();
    while(K--){
        Turn();
    }

    cout << CheckVirus();
    
    return 0;
}