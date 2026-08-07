#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> v;

void bt(int cnt){
    if(cnt == N){
        for(int x:v){
            cout << x << " ";
        }cout << '\n';
        return;
    }

    for(int i=1; i<=K; i++){
        v.push_back(i);
        bt(cnt+1);
        v.pop_back();
    }
}

int main() {
    cin >> K >> N;

    bt(0);

    return 0;
}
