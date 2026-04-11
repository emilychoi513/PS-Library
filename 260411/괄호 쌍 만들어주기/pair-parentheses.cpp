#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

vector<pair<int, int>> Open;
vector<pair<int, int>> Close;
string str;

int main() {
    cin >> str;

    int pre_idx = 0, cnt = 1;
    for(int i=1; i<str.length(); i++){
        if(str[i] == str[pre_idx]){
            cnt++;
        }else{
            if(cnt < 2){
                pre_idx = i, cnt = 1;
                continue;
            }

            if(str[pre_idx] == '('){
                Open.push_back(make_pair(pre_idx, cnt));
            }else{
                Close.push_back(make_pair(pre_idx, cnt));
            }
            pre_idx = i, cnt = 1;
        }
    }
    if(str[pre_idx] == '(') Open.push_back(make_pair(pre_idx, cnt));
    else Close.push_back(make_pair(pre_idx, cnt));

    int ans = 0;
    for(auto x:Open){
        for(auto y:Close){
            if(x.first + (x.second - 1) < y.first){
                ans += (x.second - 1) * (y.second - 1);
            }
        }
    }

    cout << ans;

    
    return 0;
}