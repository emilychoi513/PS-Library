#include <iostream>

using namespace std;

int a, b;

bool haveNum(int num){
    int tmp = num;

    while(tmp){
        if((tmp%10)==3 || (tmp%10)==6 || (tmp%10)==9) return true;
        tmp/=10;
    }

    return false;
}

int game(int mn, int mx){
    int cnt=0;

    for(int i=mn; i<=mx; i++){
        if(i%3==0) cnt++;
        else if(haveNum(i)) cnt++;
    }

    return cnt;
}

int main() {
    cin >> a >> b;

    cout << game(a, b);

    return 0;
}