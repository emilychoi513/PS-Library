/*
    sol1: 내 풀이. 
    아름다운 수의 '개수'만 구하므로 효율적이며 문제 의도 파악을 잘함.
    ---------------------------------------------------
    sol2: 정답 풀이.
    아름다운 수 자체를 출력할 수도 있음
        알고리즘: 모든 n자리 수를 구한 후 -> 아름다운 수인지 체크
*/


#include <iostream>

using namespace std;

int n;
int cnt = 0;

void beauty(int git){

    if(git == 0){
        cnt++;
        return;
    }else if(git < 0){
        return;
    }

    for(int i=1; i<=4; i++){
        git -= i;
        beauty(git);
        git += i;
    }
}

int main() {
    cin >> n;

    beauty(n);
    cout << cnt;
    return 0;
}
