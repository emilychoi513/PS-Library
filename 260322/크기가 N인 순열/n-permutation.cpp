#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
int visited[9];

void Permutation(int digit){
    if(digit == n){
        for(int i=0; i<n; i++){
            cout << v[i] << " ";
        }cout << endl;

        return;
    }

    for(int i=1; i<=n; i++){
        if(visited[i]) continue;

        v.push_back(i);
        visited[i] = 1;
        Permutation(digit + 1);
        v.pop_back();
        visited[i] = 0;
    }
}

int main() {
    cin >> n;

    Permutation(0);
    
    return 0;
}