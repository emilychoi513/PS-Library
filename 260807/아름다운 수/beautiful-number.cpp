#include <iostream>
#include <vector>
#define DEBUG 1
using namespace std;

int n;
int answer;
vector<int> v;

void Print(){
    //if(!DEBUG) return;

    for(int x:v) cout << x << " ";
    cout << endl;
}

bool is_beauty(){
    for(int i=0; i<v.size(); i+=v[i]){
        if(i + v[i] - 1 >= n) return false;
        for(int j=i; j< i + v[i]; j++){    
            if(v[j] != v[i]) {
                return false;
            }
        }
    }
    return true;
}

void bt(int len){
    if(len == n){
        if(is_beauty()){
            answer++;
        }
        return;
    }

    for(int i=1; i<=4; i++){
        v.push_back(i);
        bt(len + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n;
    bt(0);
    cout << answer;

    return 0;
}
