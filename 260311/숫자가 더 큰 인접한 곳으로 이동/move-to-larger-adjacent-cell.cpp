#include <iostream>

using namespace std;

int n;
int r, c;
int a[100][100];

bool exit(int x, int y){
    return (x<=0 || x>n || y<=0 || y>n);
}

int main() {
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int x = r;
    int y = c;
    
    while(!exit(x, y)){
        bool flag = false;
        cout << a[x][y] << " ";
        for(int i=0; i<4; i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            if(a[nx][ny] > a[x][y]){
                flag = true;
                x = nx;
                y = ny;
                break;
            }
        }

        if(!flag) break;

        
    }

    return 0;
}
