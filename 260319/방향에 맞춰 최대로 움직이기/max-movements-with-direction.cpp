#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[4][4];
int dir[4][4];
int r, c;
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int answer;

bool Exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

void Move(int x, int y, int cnt){
    if(Exit(x, y)) {
        //cout << cnt << endl;
        answer = max(answer, cnt);
        return;
    }

    int v = num[x][y];
    int d = dir[x][y];

    bool can_move = false;
    for(int i=1; i<n; i++){
        int nx = x + dx[d] * i;
        int ny = y + dy[d] * i;
        if(num[nx][ny] > v) {
            can_move = true;
            Move(nx, ny, cnt+1);
        }
    }

    if(!can_move){
        //cout << cnt << endl;
        answer = max(answer, cnt);
        return;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> dir[i][j];
    cin >> r >> c;

    answer = 0;
    Move(r-1, c-1, 0);
    cout << answer;

    return 0;
}
