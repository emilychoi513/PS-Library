#include <iostream>

using namespace std;

int n, m;
int r, c;
int x, y;
char dir;
int grid[100][100];
int top, front, side;
int sum;

bool exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=n);
}

void round(int direct){

    int tmp;

    if(direct == 'L'){
        if(exit(x, y-1)) return;
        else y--;

        tmp = top; 
        top = side; 
        side = 7-tmp;

    }else if(direct == 'R'){
        if(exit(x, y+1)) return;
        else y++;

        tmp = side;
        side = top;
        top = 7-tmp;

    }else if(direct == 'U'){
        if(exit(x-1, y)) return;
        else x--;

        tmp = top;
        top = front;
        front = 7-tmp;

    }else if(direct == 'D'){
        if(exit(x+1, y)) return;
        else x++;

        tmp = front;
        front = top;
        top = 7-tmp;
    }

    grid[x][y] = 7-top;

    //cout << x << " " << y << " " << endl;
    //cout << top << " " << front << " " << side << endl << endl;
}

int main() {
    cin >> n >> m >> r >> c;

    x = r-1; y = c-1;
    top = 1; front = 2; side = 3;

    //cout << x << " " << y << " " << endl;
    //cout << top << " " << front << " " << side << endl << endl;

    grid[x][y] = 7-top;
    for (int i = 0; i < m; i++) {
        cin >> dir;
        round(dir);
    }

    sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //cout << grid[i][j] << " ";
            sum += grid[i][j];
        }//cout << endl;
    }

    cout << sum;
    

    return 0;
}
