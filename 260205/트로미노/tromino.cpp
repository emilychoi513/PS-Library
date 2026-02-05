#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[200][200];

int main() {
    int result; //최댓값 결과를 저장하는 변수
    int square;
    int current;

    cin >> n >> m;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }


    result = 0;

    //블록1 2 * 2 블록을 먼저 생각
    // 왼쪽 위 & 왼쪽 아래 & 오른쪽 위 & 오른쪽 아래에 대해 각각 current 구해보기
    for(int i=0; i+1<n; i++){
        for(int j=0; j+1<m; j++){
            square = grid[i][j] + grid[i][j+1] + grid[i+1][j] + grid[i+1][j+1]; 

            result = max(result, square-grid[i][j]);        //오른쪽 아래 모서리
            result = max(result, square-grid[i+1][j]);      //오른쪽 위 모서리
            result = max(result, square-grid[i][j+1]);      //왼쪽 아래 모서리
            result = max(result, square-grid[i+1][j+1]);    //왼쪽 위 모서리
        }
    }

    current = 0;
    //블록2 세로
    for(int i=0; i<n; i++){
        for(int j=0; j+3-1<m; j++){
            current = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            result = max(result, current);
        }
    }
    //블록2 가로
    for(int j=0; j<m; j++){
        for(int i=0; i+3-1<n; i++){
            current = grid[i][j] + grid[i+1][j] + grid[i+2][j];
            result = max(result, current);
        }
    }

    cout << result;

    return 0;
}
