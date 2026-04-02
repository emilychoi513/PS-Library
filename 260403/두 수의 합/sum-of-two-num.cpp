#include <iostream>
#include <unordered_map>
using namespace std;

int n, k;
int arr[100000];
unordered_map<int, int> m;
int answer;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
        m.insert({arr[i], i});
    }

    answer = 0;
    for(int i=0; i<n; i++){
        auto it = m.find(k - arr[i]);

        if(it == m.end()) continue;
        if(it->second <= i) continue;

        answer++;
    }

    cout << answer;
    return 0;
}
