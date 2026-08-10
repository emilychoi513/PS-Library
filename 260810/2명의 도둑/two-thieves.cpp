#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, c;
int weight[10][10];

int a[10];

int ans;
int max_val;

void FindMaxSum(int idx, int weight, int val){
    if(idx == m){
        if(weight <= c){
            max_val = max(max_val, val);
        }
        return;
    }

    FindMaxSum(idx+1, weight, val); //미포함
    FindMaxSum(idx+1, weight + a[idx], val + pow(a[idx], 2)); //포함

}

int FindMax(int x, int y){
    for(int i=0; i<m; i++){
        a[i] = weight[x][y+i];
    }

    max_val = 0;
    FindMaxSum(0, 0, 0);
    return max_val;
}

bool Possible(int r1, int c1, int r2, int c2){
    //경계 초과
    if(c1+m-1>=n || c2+m-1>=n) return false;

    //겹침
    if(r1 == r2){
        if(!((c1+m-1 < c2) || (c2+m-1 < c1))) return false;
    }

    return true;
}

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }

    for(int r1=0; r1<n; r1++){
        for(int c1=0; c1<n; c1++){
            for(int r2=0; r2<n; r2++){
                for(int c2=0; c2<n; c2++){
                    if(Possible(r1, c1, r2, c2)){
                        ans = max(ans, FindMax(r1, c1) + FindMax(r2, c2));
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}