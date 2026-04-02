#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];
unordered_map<int, int> m;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        cin >> k[i];
        if (cmd[i] == "add") {
            cin >> v[i];
        }
    }

    for(int i=0; i<n; i++){
        if(cmd[i] == "add"){
            //m.insert({k[i], v[i]}); 덮어쓰기 못하며, 기존 값이 유지
            m[k[i]] = v[i];
        }
        else if(cmd[i] == "remove"){
            m.erase(k[i]);
        }
        else{
            if(m.find(k[i]) == m.end()){
                cout << "None" << endl;
            }else{
                cout << m[k[i]] << endl;
            }
        }
    }

    return 0;
}
