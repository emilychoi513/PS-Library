#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int num[10];
int answer;

void Move(int loc, int cnt){
    if(loc == n-1){
        answer = min(answer, cnt);
        return;
    }

    for(int i=1; i<=num[loc]; i++){
        Move(loc+i, cnt+1);
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    answer = INT_MAX;
    Move(0, 0);
    if(answer == INT_MAX){
        answer = -1;
    }


    cout << answer;
    

    return 0;
}
