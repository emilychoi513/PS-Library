#include <iostream>
#include <unordered_set>
using namespace std;

int n;
unordered_set<int> s;

int main() {
    cin >> n;

    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        s.insert(num);
    }

    cout << s.size();

    return 0;
}