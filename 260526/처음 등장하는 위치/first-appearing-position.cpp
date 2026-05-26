#include <iostream>
#include <map>
using namespace std;

int n;
map<int, int> m;
map<int, int>::iterator it;
int num;

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> num;
        if(m.find(num) == m.end()){
            m[num] = i+1;
        }
    }

    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}