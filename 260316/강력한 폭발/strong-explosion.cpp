#include <iostream>
#include <algorithm>
#define bomb_type 3
using namespace std;

int n;
int grid[20][20];
int bomb_num;
int answer;
int bomb_x[10];
int bomb_y[10];
int dx[3][4] = {{-1, -2, 1, 2},
                {0, 0, -1, 1},
                {-1, -1, 1, 1}};

int dy[3][4] = {{0, 0, 0, 0},
                {-1, 1, 0, 0},
                {-1, 1, -1, 1}};

bool exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

int count(){
    int s = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] >= 1) s++;
        }
    }

    return s;
}

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

void bomb(int idx){
    if(idx == bomb_num){
        answer = max(answer, count());
        //cout << "* " << count() << endl;
        //print();
        return;
    }


    for(int i=0; i<bomb_type; i++){
        for(int j=0; j<4; j++){
            if(exit(bomb_x[idx] + dx[i][j], bomb_y[idx] + dy[i][j])) continue;

            grid[bomb_x[idx] + dx[i][j]][bomb_y[idx] + dy[i][j]]++;
        }

        bomb(idx + 1);

        for(int j=0; j<4; j++){
            if(exit(bomb_x[idx] + dx[i][j], bomb_y[idx] + dy[i][j])) continue;

            grid[bomb_x[idx] + dx[i][j]][bomb_y[idx] + dy[i][j]]--;
        }
    }
}


int main() {
    cin >> n;

    bomb_num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                bomb_x[bomb_num] = i;
                bomb_y[bomb_num] = j;
                bomb_num++;
            }
        }
    }

    answer = 0;
    bomb(0);
    cout << answer;

    return 0;
}
