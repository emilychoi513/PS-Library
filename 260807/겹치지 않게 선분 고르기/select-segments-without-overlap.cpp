#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
pair<int, int> seg[1005];

vector<pair<int, int>> selected_seg;
int ans;

bool Overlapped(pair<int, int> seg1, pair<int, int> seg2){
    int s1, e1;
    tie(s1, e1) = seg1;

    int s2, e2;
    tie(s2, e2) = seg2;

    return (s1 <= s2 && s2 <= e1 || s1 <= e2 && e2 <= e1 || s2 <= s1 && s1 <= e2 || s2 <= e1 && e1 <= e2);
}

bool Possible(){
    for(int i=0; i<(int)selected_seg.size(); i++){
        for(int j=i+1; j<(int)selected_seg.size(); j++){
            if(Overlapped(selected_seg[i], selected_seg[j])) return false;
        }
    }

    return true;
}

void FindMaxSeg(int cnt){
    if(cnt == n){
        if(Possible()){
            ans = max(ans, (int)selected_seg.size());
        }
        return;
    }

    selected_seg.push_back(seg[cnt]);
    FindMaxSeg(cnt + 1);
    selected_seg.pop_back();

    FindMaxSeg(cnt + 1);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> seg[i].first >> seg[i].second;
    }

    FindMaxSeg(0);

    cout << ans;

    return 0;
}
