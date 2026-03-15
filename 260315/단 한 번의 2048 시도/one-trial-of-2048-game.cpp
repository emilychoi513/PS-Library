#include <iostream>

using namespace std;

int grid[4][4];
char dir;
// L, R, U, D
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void print(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;


    if(dir == 'L'){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(j==3) continue;

                if(grid[i][j]==0){
                    int tmp = grid[i][j];
                    grid[i][j] = grid[i][j+1];
                    grid[i][j+1] = tmp;
                }
            }
        }

        //print();

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(j==3) continue;

                if(grid[i][j]==grid[i][j+1]){
                    grid[i][j] *= 2;
                    grid[i][j+1] = 0;
                }
            }
        }

        //print();

        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(j==3) continue;

                if(grid[i][j]==0){
                    int tmp = grid[i][j];
                    grid[i][j] = grid[i][j+1];
                    grid[i][j+1] = tmp;
                }
            }
        }

        //print();
    }

    else if(dir == 'R'){
        for(int i=0; i<4; i++){
            for(int j=3; j>=0; j--){
                if(j==0) continue;

                if(grid[i][j]==0){
                    int tmp = grid[i][j];
                    grid[i][j] = grid[i][j-1];
                    grid[i][j-1] = tmp;
                }
            }
        }

        //print();

        for(int i=0; i<4; i++){
            for(int j=3; j>=0; j--){
                if(j==0) continue;

                if(grid[i][j] == grid[i][j-1]){
                    grid[i][j] *= 2;
                    grid[i][j-1] = 0;
                }
            }
        }

        //print();

        for(int i=0; i<4; i++){
            for(int j=3; j>=0; j--){
                if(j==0) continue;

                if(grid[i][j]==0){
                    int tmp = grid[i][j];
                    grid[i][j] = grid[i][j-1];
                    grid[i][j-1] = tmp;
                }
            }
        }

        //print();
    }

    else if(dir == 'U'){
        for(int j=0; j<4; j++){
            for(int i=0; i<4; i++){
                if(i==3) continue;

                if(grid[i][j]==0){
                    int tmp = grid[i][j];
                    grid[i][j] = grid[i+1][j];
                    grid[i+1][j] = tmp;
                }
            }
        }

        //print();

        for(int j=0; j<4; j++){
            for(int i=0; i<4; i++){
                if(i==3) continue;

                if(grid[i][j] == grid[i+1][j]){
                    grid[i][j] *= 2;
                    grid[i+1][j] = 0;
                }
            }
        }

        //print();

        for(int j=0; j<4; j++){
            for(int i=0; i<4; i++){
                if(i==3) continue;

                if(grid[i][j]==0){
                    int tmp = grid[i][j];
                    grid[i][j] = grid[i+1][j];
                    grid[i+1][j] = tmp;
                }
            }
        }

        //print();
    }

    else{
        for(int j=0; j<4; j++){
            for(int i=3; i>=0; i--){
                if(i==0) continue;

                if(grid[i][j]==0){
                    int tmp = grid[i][j];
                    grid[i][j] = grid[i-1][j];
                    grid[i-1][j] = tmp;
                }
            }
        }

        //print();

        for(int j=0; j<4; j++){
            for(int i=3; i>=0; i--){
                if(i==0) continue;

                if(grid[i][j]==grid[i-1][j]){
                    grid[i][j] *= 2;
                    grid[i-1][j] = 0;
                }
            }
        }

        //print();

        for(int j=0; j<4; j++){
            for(int i=3; i>=0; i--){
                if(i==0) continue;

                if(grid[i][j]==0){
                    int tmp = grid[i][j];
                    grid[i][j] = grid[i-1][j];
                    grid[i-1][j] = tmp;
                }
            }
        }

        //print();
    }

    print();

    return 0;
}
