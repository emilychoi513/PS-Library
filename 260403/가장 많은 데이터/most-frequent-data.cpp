#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
string words[100000];
unordered_map<string, int> m;
int answer;

int main() {
    cin >> n;

    answer = 0;
    for (int i = 0; i < n; i++) {
        cin >> words[i];

        if(m.find(words[i]) == m.end()){
            m.insert({words[i], 1});
        }else{
            m[words[i]]++;
        }
        
        answer = max(answer, m[words[i]]);
    }

    cout << answer;

    return 0;
}
