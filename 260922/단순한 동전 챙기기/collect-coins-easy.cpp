#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

int N;
char grid[20][20];
int ans = INT_MAX;

struct loc{
    int x; int y;
};

loc st;
loc ed;
vector<loc> num(10);
vector<int> n;
vector<int> order;

void input(){
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            char tmp;
            cin >> tmp;

            if(tmp == '.') continue;

            if(tmp == 'S'){st.x = i; st.y = j;}
            else if(tmp == 'E'){ed.x = i; ed.y = j;}
            else{
                int idx = tmp-'0';
                num[idx].x = i; num[idx].y = j;
                n.push_back(idx);
            }
        }
    }

    // cout << st.x << " " << st.y << endl;
    // cout << ed.x << " " << ed.y << endl;
    // for(int i=0; i<=9; i++){
    //     cout << num[i].x << " " << num[i].y << endl;
    // }

    sort(n.begin(), n.end());

    // for(int i=0; i<n.size(); i++){
    //     cout << n[i] << endl;
    // }
}

int dist(loc a, loc b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void path(){
    int d = dist(st, num[order[0]]) + dist(num[order[0]], num[order[1]]) + dist(num[order[1]], num[order[2]]) + dist(num[order[2]], ed);
    //cout << "distance: " << d << endl;
    ans = min(ans, d);
}

void number(int idx){
    if(order.size() >= 3){
        //for(int x:order) cout << x << " "; cout << endl;
        path();
        return;
    }

    for(int i=idx; i<n.size(); i++){
        order.push_back(n[i]);
        number(i+1);
        order.pop_back();
    }
}



int main() {
    input();
    if(n.size() < 3) {cout << -1 << endl; return 0;}
    
    number(0);

    cout << ans;

    return 0;
}
