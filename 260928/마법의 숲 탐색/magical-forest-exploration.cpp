#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int R, C, K;
int arr[80][80];
int row[1005];
int col[1005];
int dir[1005];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void Print(){
    for(int i=0; i<=R+3; i++){
        for(int j=0; j<=C+1; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }
}

void init(){
    for(int i=0; i<=R+3; i++){
        for(int j=0; j<=C+1; j++){
            arr[i][j] = 0;   
        }
    }
    for(int i=0; i<=R+3; i++){
        arr[i][0] = 1;
        arr[i][C+1] = 1;
    }
    for(int j=0; j<=C+1; j++){
        arr[R+3][j] = 1;
    }
}

int final_pos(int r, int c){
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(R+4, vector<bool>(C+2, false));

    q.push({r, c}); visited[r][c]=true;

    int max_row = -1;
    // cout << "-----------" << endl;
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        // cout << x-2 << " " << y << endl;
        max_row = max(max_row, x-2);

        for(int i=0; i<4; i++){
            int nx = x + dr[i];
            int ny = y + dc[i];

            if(arr[nx][ny]>1 && !visited[nx][ny]){
                if(arr[x][y]>1001 || arr[nx][ny]==arr[x][y] || arr[nx][ny]==arr[x][y]+1000){
                    q.push({nx, ny}); visited[nx][ny] = true;
                }
            }
        }
    }

    // cout << max_row << endl;
    return max_row;
}

int main() {
    cin >> R >> C >> K;
    for(int i=0; i<K; i++){
        cin >> col[i] >> dir[i];
    }

    init();

    int answer = 0;
    for(int i=0; i<K; i++){
        int r = 1; int c = col[i]; int d = dir[i];
        while(1){
            if(arr[r+1][c-1]+arr[r+2][c]+arr[r+1][c+1] == 0){
                r++;
            }else if(arr[r-1][c-1]+arr[r][c-2]+arr[r+1][c-1]+arr[r+1][c-2]+arr[r+2][c-1]==0){
                r++; c--; d = (d+3)%4;
            }else if(arr[r-1][c+1]+arr[r][c+2]+arr[r+1][c+1]+arr[r+1][c+2]+arr[r+2][c+1]==0){
                r++; c++; d = (d+1)%4;
            }else{
                break;
            }
        }

        //2~
        arr[r][c] = i+2; arr[r-1][c] = i+2; arr[r+1][c] = i+2; arr[r][c-1] = i+2; arr[r][c+1] = i+2;
        arr[r+dr[d]][c+dc[d]]=i+1002; //출구만 따로 표시: 1002~

        //cout << "pos " << r << " " << c << endl;
        //if(i >=3 ) 
        // Print();

        if(r<4){ //초기화
            init();
            //Print();
            continue;
        }else{ //bfs
            answer += final_pos(r, c);
        }
    }

    cout << answer;
    return 0;
}