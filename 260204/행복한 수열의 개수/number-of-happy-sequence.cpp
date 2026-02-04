#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int pre;
    int curr;
    int cnt;
    int happy = 0;

    //m==1 -> 2 * n
    //m>n -> 0
    //pre-processed
    if(m==1){
        happy = 2 * n;
        cout << happy;
        return 0;
    }
    if(m > n){
        happy = 0;
        cout << happy;
        return 0;
    }

    //가로줄
    for(int i=0; i<n; i++){
        cnt = 1;
        pre = grid[i][0];
        for(int j=1; j<n; j++){
            curr = grid[i][j];

            if(pre == curr){
                cnt++;
                if(cnt >= m){
                    happy++;
                    break;
                }
            }else{
                cnt = 1;
                pre = grid[i][j];
            }
        }
    }

    //세로줄
    for(int j=0; j<n; j++){
        cnt = 1;
        pre = grid[0][j];
        for(int i=1; i<n; i++){
            curr = grid[i][j];
            if(pre == curr){
                cnt++;
                if(cnt >= m){
                    happy++;
                    break;
                }
            }else{
                cnt = 1;
                pre = grid[i][j];
            }
        }
    }

    cout << happy;


    return 0;
}
