#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
string words[100000];
string queries[100000];
unordered_map<string, int> simap;
unordered_map<int, string> ismap;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    for(int i=1; i<=n; i++){
        simap[words[i]] = i;
        ismap[i] = words[i];
    }

    for(int i=0; i<m; i++){
        if(simap.find(queries[i]) != simap.end()){
            cout << simap[queries[i]] << endl;
        }else{
            int idx = stoi(queries[i]);
            cout << ismap[idx] << endl;
        }
    }

    return 0;
}
