#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int A[10][10];
int visited[10];
int answer;
int tmp;

void Move(int curr, int cnt){
    if(cnt == n-1){
        if(A[curr][0] == 0) return;

        answer = min(answer, tmp + A[curr][0]);
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        if(A[curr][i] == 0) continue;

        v.push_back(i);
        tmp += A[curr][i];
        visited[i] = 1;

        Move(i, cnt + 1);

        v.pop_back();
        tmp -= A[curr][i];
        visited[i] = 0;
    }
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }

    answer = INT_MAX;
    tmp = 0;

    visited[0] = 1;
    Move(0, 0);

    cout << answer;

    return 0;
}
