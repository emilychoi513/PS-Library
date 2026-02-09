#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[20][20];

int getSum(int x, int y, int w, int h){
    int sum = 0;

    //화살표 시작 포함. 화살표 끝 불포함
    for(int i=0; i<w; i++){
        sum += grid[x-i][y+i];  //1
    }

    for(int j=0; j<h; j++){
        sum += grid[x-w-j][y+w-j];  //2
    }

    for(int i=0; i<w; i++){
        sum += grid[x-w-h+i][y+w-h-i];  //3
    }

    for(int j=0; j<h; j++){
        sum += grid[x-h+j][y-h+j];  //4
    }

    return sum;
}

int getPosMax(int x, int y){
    int posMax = 0; //현재 위치에서 가질 수 있는 최댓값

    for(int w=1; y+w < n; w++){
        for(int h=1; y-h>=0 && x-w-h>=0; h++){
            posMax = max(posMax, getSum(x, y, w, h));
        }
    }
    return posMax;
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int mx = 0;
    for(int x=2; x<n; x++){
        for(int y=1; y<n-1; y++){
            mx = max(mx, getPosMax(x, y));
        }
    }

    cout << mx;

    return 0;
}
