#include <iostream>
#include <map>
using namespace std;

int n;
map<string, int> dict;
map<string, int>::iterator it;
string str;

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> str;
        dict[str]++;
    }

    for(it = dict.begin(); it!=dict.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}