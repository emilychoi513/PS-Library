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
