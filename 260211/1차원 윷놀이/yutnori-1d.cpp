#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int nums[12];

vector<int> horse;
int mcnt = 0; // output

int Count(){
    int cnt = 0;
    for(int i=0; i<k; i++){
        if(horse[i] >= m) cnt++;
    }
    return cnt;
}

void maxScore(int step){ 
    int i, j;

    mcnt = max(mcnt, Count());

    if(step == n){
        return;
    }

    for(j=0; j<k; j++){
        if(horse[j] >= m) continue;

        horse[j] += nums[step];
        maxScore(step + 1);
        horse[j] -= nums[step];
    }
}

int main() {
    int i;

    cin >> n >> m >> k;

    for (i = 0; i < n; i++) {
        cin >> nums[i];
    }

    horse.resize(k+1, 1); //말은 1에서 출발
    maxScore(0);
    
    cout << mcnt;

    return 0;
}