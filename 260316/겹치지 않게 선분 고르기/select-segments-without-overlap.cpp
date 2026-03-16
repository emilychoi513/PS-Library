#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x1[15], x2[15];
int last;
int answer;
int cnt;

void Choose(int end){
    if(end >= last){
        answer = max(answer, cnt);
        return;
    }


    for(int i=0; i<n; i++){
        if(x1[i] > end){
            cnt++;
            Choose(x2[i]);
            cnt--;
        }
    }
}



int main() {
    cin >> n;

    last = 0;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        last = max(last, x2[i]);
    }

    cnt = 0;
    answer = cnt;
    Choose(0);
    cout << answer;
    

    return 0;
}