#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> a;
int b[100000];

int main() {
    int n, m;

    cin >> n;
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        a.insert(num);
    }

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    for(int i=0; i<m; i++){
        if(a.find(b[i]) != a.end()){
            cout << 1;
        }else cout << 0;

        cout << endl;
    }

    return 0;
}