#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

int n, k;
int arr[1000];
unordered_multimap<int, pair<int, int>> twin;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            twin.insert({arr[i] + arr[j], make_pair(i, j)});
        }
    }

    /*
    for(auto it=twin.begin(); it != twin.end(); it++){
        cout << it->first << it->second.first << it->second.second << endl;
    }*/

    int ans = 0;
    for(int i=0; i<n; i++){
        auto [begin, end] = twin.equal_range(k-arr[i]);
        for(auto it=begin; it!=end; it++){
            if(it->second.second < i) ans++;
        }
    }

    cout << ans;

    return 0;
}
