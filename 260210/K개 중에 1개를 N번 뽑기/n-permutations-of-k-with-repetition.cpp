#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> answer;

void Print(){
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }
    
    cout << "\n";
}

void Recur(int cnt){
    if(cnt == N + 1){
        Print();
        return;
    }

    for(int i=1; i<=K; i++){
        answer.push_back(i);
        Recur(cnt+1);
        answer.pop_back();
    }
}

int main() {
    cin >> K >> N;

    Recur(1);

    return 0;
}
