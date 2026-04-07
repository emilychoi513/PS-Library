#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

const int MAX_N = 100000;
int n, q;
//입력
int points[MAX_N];
int a[MAX_N], b[MAX_N];

set<int> pointset;
unordered_map<int, int> mapper;

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    for (int i = 0; i < n; i++) {
        pointset.insert(points[i]);
    }

    int cnt = 0;
    for(set<int>::iterator it=pointset.begin(); it!=pointset.end(); it++){
        mapper[*it] = ++cnt;
        //cout << *it << " -> " << cnt << endl;
    }

    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < q; i++) {
        cout << mapper[b[i]] - mapper[a[i]] + 1 << endl;
    }

    return 0;
}
