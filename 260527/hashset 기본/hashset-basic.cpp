#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int n;
unordered_set<int> us;

int main() {
    cin >> n;


    string cmd;
    int num;
    for(int i=0; i<n; i++){
        cin >> cmd;
        cin >> num;

        if(cmd == "find"){
            if(us.find(num) != us.end()) cout << "true" << endl;
            else cout << "false" << endl;
        }else if(cmd == "add"){
            us.insert(num);
        }else{
            us.erase(num);
        }
    }
    return 0;
}