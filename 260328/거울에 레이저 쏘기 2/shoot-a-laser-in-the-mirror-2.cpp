#include <iostream>

using namespace std;

int n;
char grid[1000][1000];
int k;

bool Exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> k;
    k--; //0 1 2 ... 11

    int dx, dy;
    int x, y;

    if(k<n) dx=1, dy=0, x=0, y=k%n;
    else if(k<2*n) dx=0, dy=-1, x=k%n, y=n-1;
    else if(k<3*n) dx=-1, dy=0, x=n-1, y=(n-1)-(k%n);
    else dx=0, dy=1, x=(n-1)-(k%n), y=0;

    //cout << dx << " " << dy << " " << x << " " << y << endl;

    int answer = 0;
    while(!Exit(x, y)){
        answer++;

        if(grid[x][y] == '/'){
            int tmp = dy;
            dy = -1 * dx;
            dx = -1 * tmp;
        }else{
            int tmp = dy;
            dy = dx;
            dx = tmp;
        }

        x += dx;
        y += dy;

        //cout << x << " " << y << endl;
    }

    cout << answer;

    return 0;
}