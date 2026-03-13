#include <iostream>
using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;
int tmp[10000];
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, -1, 1};
int cnt;

void copy(){
    int idx = 0;
    int x = r;
    int y = c;

    for(int i=0; i<m1; i++){
        tmp[idx++] = grid[x][y];
        x += dx[0];
        y += dy[0];
    }
    for(int i=0; i<m2; i++){
        tmp[idx++] = grid[x][y];
        x += dx[1]; 
        y += dy[1];
    }
    for(int i=0; i<m3; i++){
        tmp[idx++] = grid[x][y];
        x += dx[2]; 
        y += dy[2];
    }
    for(int i=0; i<m4; i++){
        tmp[idx++] = grid[x][y];
        x += dx[3]; 
        y += dy[3];
    }

    cnt = idx;
}

void paste(){
    int idx = 0;
    int x = r;
    int y = c;

    for(int i=0; i<m1; i++){
        grid[x][y] = tmp[idx++];
        x += dx[0];
        y += dy[0];
    }
    for(int i=0; i<m2; i++){
        grid[x][y] = tmp[idx++];
        x += dx[1];
        y += dy[1];
    }
    for(int i=0; i<m3; i++){
        grid[x][y] = tmp[idx++];
        x += dx[2];
        y += dy[2];
    }
    for(int i=0; i<m4; i++){
        grid[x][y] = tmp[idx++];
        x += dx[3];
        y += dy[3];
    }
}

void rotate(int direction){
    int t;

    if(direction == 0){ //반시계 - 뒤로
        t = tmp[cnt-1];
        for(int i=cnt-1; i>0; i--){
            tmp[i] = tmp[i-1];
        }tmp[0] = t;

    }else{
        t = tmp[0];
        for(int i=0; i<cnt-1; i++){
            tmp[i] = tmp[i+1];
        }tmp[cnt-1] = t;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    r--; c--;
    copy();
    rotate(dir);
    paste();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }

    return 0;
}
