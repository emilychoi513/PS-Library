#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int n, m;
int ans = INT_MAX;
vector<pair<int, int>> l;
vector<pair<int, int>> tmpl;
vector<int> p(n+1);

bool is_possible(){
    vector<int> tmpp(n+1);
    for(int i=1; i<=n; i++) tmpp[i] = i;

    for(int i=0; i<tmpl.size(); i++){
        int x = tmpl[i].second;
        swap(tmpp[x], tmpp[x + 1]);
    }


    for(int i=1; i<=n; i++){
        if(tmpp[i] != p[i]) return false;
    }

    // for(int i=0; i<tmpl.size(); i++){ cout << tmpl[i].first << " " << tmpl[i].second << endl;}
    // for(int i=1; i<=n; i++){cout << tmpp[i] << " ";} cout << endl;
    // cout << tmpl.size() << endl << endl;

    return true;
}

void FindMin(int cnt){
    if(cnt == m){
        if(is_possible()){
            ans = min(ans, (int)tmpl.size());
        }
        return;
    }

    tmpl.push_back(l[cnt]);
    FindMin(cnt + 1);
    tmpl.pop_back();

    FindMin(cnt + 1);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> c >> r;
        l.push_back({r, c});
    }

    sort(l.begin(), l.end());

    for(int i=1; i<=n; i++){
        p[i] = i;
    }
    for(int i=0; i<m; i++){
        int x = l[i].second;
        swap(p[x], p[x + 1]);
    }


    FindMin(0);

    cout << ans;

    return 0;
}
