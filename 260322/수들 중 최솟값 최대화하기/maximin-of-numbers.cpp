#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int A[10][10];
int visitedCol[10];
vector<int> v;
int global_min;

void Move(int row){
    if(row == n){
        int local_min = v[0];
        for(int i=0; i<row; i++){
            //cout << v[i] << " ";
            local_min = min(local_min, v[i]);
        }//cout << endl;

        global_min = max(global_min, local_min);
        return;
    }

    
    for(int j=0; j<n; j++){
        if(visitedCol[j]) continue;

        visitedCol[j] = 1;
        v.push_back(A[row][j]);

        Move(row + 1);

        visitedCol[j] = 0;
        v.pop_back();
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    global_min = 0;
    Move(0);

    cout << global_min;

    return 0;
}
