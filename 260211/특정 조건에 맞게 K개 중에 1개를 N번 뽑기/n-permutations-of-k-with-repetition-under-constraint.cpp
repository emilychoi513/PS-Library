#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> answer;

void Print(){
    int l = answer.size();
    for(int j=0; j<l; j++){
        cout << answer[j] << " ";
    }cout << '\n';
}

void Choose(int num){
    if(num == N+1){
        Print();
        return;
    }

    for(int i=1; i<=K; i++){
        if(num >= 3 && (answer[num-3] == answer[num-2] && answer[num-2] == i)) continue; //answer[n-1] = i

        answer.push_back(i);
        Choose(num+1);
        answer.pop_back();
    }
}

int main() {
    cin >> K >> N;

    Choose(1);

    return 0;
}
