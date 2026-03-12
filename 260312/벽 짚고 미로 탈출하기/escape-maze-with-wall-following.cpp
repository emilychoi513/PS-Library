#include <iostream>
using namespace std;

int N;
int init_x, init_y;
int dx[4] = {0, -1, 0, 1}; // 반시계 방향
int dy[4] = {1, 0, -1, 0};
char grid[101][101];
int cnt;

bool exit(int x, int y){
    return (x <= 0 || x > N || y <= 0 || y > N);
}

int run(int x, int y, int rot){
    //cout << "( " << x << ", " << y << " )" << endl;

    int nx = x + dx[rot];
    int ny = y + dy[rot]; // 다음 스텝

    if(nx == init_x && ny == init_y) return -1; // 실패 조건: 자기 자신으로 돌아올때
    if(grid[x+dx[0]][y+dy[0]]=='#' && grid[x+dx[1]][y+dy[1]]=='#' && grid[x+dx[2]][y+dy[2]]=='#' && grid[x+dx[3]][y+dy[3]]=='#') return -1;

    if(grid[nx][ny] == '#'){ // step 1: 방향 전환
        //cout << "turn " << (rot+1)%4 << endl;
        return run(x, y, ((rot+1)%4));
    }else{
        //cout << "( " << x << ", " << y << " )" << endl;
        //if(nx == init_x && ny == init_y) return -1; // 실패 조건: 자기 자신으로 돌아올때
        cnt++; // next가 벽만 아니면 일단 이동할 것이므로
    }


    if(exit(nx, ny)){ // step 2 --- case 1: next가 격자 밖
        return cnt;
    }

    int rx = nx + dx[((rot+3)%4)];
    int ry = ny + dy[((rot+3)%4)];
    if(grid[rx][ry] == '#'){ // step2 --- case2: next의 오른쪽에 짚을 벽이 있을때
        return run(nx, ny, rot);
    }else{  // step2 --- case3: next의 오른쪽에 벽이 존재하지 않을때
        return run(nx, ny, ((rot+3) % 4));
    }
}

int main() {
    cin >> N;
    cin >> init_x >> init_y;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    cout << run(init_x, init_y, 0);

    return 0;
}
