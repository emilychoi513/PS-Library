#include <iostream>
#include <algorithm>
using namespace std;

int n;
int M[100+1][100+1];

struct Position{
    int x;
    int y;
};

struct Spot{
    int s1;
    int s2;
    int s3;
    int s4;
};

Spot spot;
Position pos[100];

int main() {
    cin >> n;    

    int x, y;
    for(int i=0; i<n; i++){
        cin >> pos[i].x >> pos[i].y;
    }

    int answer = 100;
    for(int i=0; i<100; i+=2){
        for(int j=0; j<100; j+=2){
            spot.s1 = 0; spot.s2 = 0; spot.s3 = 0; spot.s4 = 0;
            int tmp_max = 0;
            for(int p=0; p<n; p++){
                int x = pos[p].x;
                int y = pos[p].y;

                if(x < i){
                    if(y < j) spot.s1++;
                    else spot.s2++;
                }else{
                    if(y < j) spot.s3++;
                    else spot.s4++;
                }
            }

            tmp_max = max({spot.s1, spot.s2, spot.s3, spot.s4});
            answer = min(answer, tmp_max);
        }
    }

    cout << answer;

    return 0;
}