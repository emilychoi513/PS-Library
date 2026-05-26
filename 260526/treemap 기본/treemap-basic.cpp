#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];
map<int, int> m;
map<int, int>::iterator it; //오름차순 정렬

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        if (cmd[i] == "add") {
            cin >> k[i] >> v[i];

        } else if (cmd[i] == "remove" || cmd[i] == "find") {
            cin >> k[i];
        }
    }

    for(int i=0; i<n; i++){
        if(cmd[i] == "add") {
            m[k[i]] = v[i];
        }
        else if(cmd[i] == "remove") {
            m.erase(k[i]);
        }
        else if(cmd[i] == "find"){
            if(m.find(k[i]) != m.end()){
                cout << m[k[i]] << '\n';
            }else{
                cout << "None" << '\n';
            }
        }
        else{
            if(m.empty()){
                cout << "None" << '\n';
            }else{
                for(it=m.begin(); it!=m.end(); it++){
                    cout << it->second <<  " ";
                }cout << '\n';
            }
        }
    }

    return 0;
}
