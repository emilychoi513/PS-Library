#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int mcnt = 0; // output
int nums[12];
vector<int> horse;

void maxScore(int step){ 
    if(step == n){
        int cnt = 0;
        for(int i=0; i<k; i++){
            if(horse[i] >= m) cnt++;
        }
        mcnt = max(mcnt, cnt);
        return;
    }

    for(int i=0; i<k; i++){
        if(horse[i] >= m) continue;

        horse[i] += nums[step];
        maxScore(step + 1);
        horse[i] -= nums[step];
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    horse.resize(k, 1); //말은 1에서 출발
    maxScore(0);
    
    cout << mcnt;

    return 0;
}