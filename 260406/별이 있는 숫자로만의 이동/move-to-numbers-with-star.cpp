#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int board[400+1][400+1];
int prefix_row[400+1][400+1];

void Print(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << prefix_row[i][j] << " ";
        }cout << endl;
    }
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            prefix_row[i][j] = board[i][j] + prefix_row[i][j-1];
        }
    }

    //Print();

    int answer = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int Sum = 0;
            for(int r=-k; r<=k; r++){
                int row = r + i;
                if(row <= 0) continue;

                int bound = k - abs(r);
                int right = min(n, j + bound);
                int left = max(1, j - bound);

                Sum += prefix_row[row][right] - prefix_row[row][left-1];
            }
            answer = max(answer, Sum);
        }
    }

    cout << answer;

    return 0;
}
