#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int boxSize = 3;
    int boxMax = boxSize * boxSize;

    int curr = 0;
    int res = curr;

    for(int i=0; i+boxSize-1<N; i++){
        for(int j=0; j+boxSize-1<N; j++){

            curr = 0;

            for(int k=i; k<i+boxSize; k++){
                for(int p=j; p<j+boxSize; p++){
                    curr += grid[k][p];
                }
            }

            res = max(res, curr);

            if(res == boxMax){
                cout << res; //optimization
                return 0;
            }
        }
    }

    cout << res;

    return 0;
}
