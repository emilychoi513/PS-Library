#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> answer;

void Choose(int idx, int num){
    if(idx == M){
        for(int i=0; i<M; i++){
            cout << answer[i] << " ";
        }cout << endl;
        return;
    }

    for(int i=num + 1; i<=N; i++){
        answer.push_back(i);
        Choose(idx + 1, i);
        answer.pop_back();
    }


}


int main() {
    cin >> N >> M;

    Choose(0, 0);

    return 0;
}
