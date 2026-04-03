#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
int arr[100000];
unordered_map<int, int> m;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        m[arr[i]]++;
    }

    int answer = 0;
    for (const auto& [key, value] : m) {
        int curr = 0;
        int cmp = k - key;
        
        //same num
        if(cmp == key){
            curr = (value - 1) * value;
        }
        else if(m.find(cmp) != m.end()){
            curr = (m[cmp]);
        }

        //cout << curr << " ";
        answer += curr;
    }

    cout << answer/2;
        

    return 0;
}
