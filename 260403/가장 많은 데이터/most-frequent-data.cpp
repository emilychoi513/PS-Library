#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
string words[100000];
unordered_map<string, int> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];

        if(m.find(words[i]) == m.end()){
            m.insert({words[i], 1});
        }else{
            m[words[i]]++;
        }
    }

    int mx = 0;
    for(auto it = m.begin(); it != m.end(); it++){
        //cout << it->second << endl;
        mx = max(mx, it -> second);
    }

    cout << mx;

    return 0;
}
