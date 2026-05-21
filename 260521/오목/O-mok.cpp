#include <iostream>
using namespace std;

int arr[20][20];

int main() {
    for(int i=1; i<20; i++){
        for(int j=1; j<20; j++){
            cin >> arr[i][j];
        }
    }

    int dx[4] = {0, 1, 1, -1};
    int dy[4] = {1, 0, 1, 1};

    for(int i=1; i<20; i++){
        for(int j=1; j<20; j++){
            if(arr[i][j] == 0) continue;
            for(int d=0; d<4; d++){
                int pre = arr[i][j];
                bool flag = true;
                for(int s=1; s<5; s++){
                    if(pre != arr[i+dx[d]*s][j+dy[d]*s]) {flag = false; break;}
                    else pre = arr[i+dx[d]*s][j+dy[d]*s];
                }

                if(flag){
                    cout << arr[i][j] << endl;
                    cout << i+dx[d]*2 << " " << j+dy[d]*2 << endl;
                    return 0;
                }
            }
        }
    }

    cout << 0 << endl;
    
    return 0;
}