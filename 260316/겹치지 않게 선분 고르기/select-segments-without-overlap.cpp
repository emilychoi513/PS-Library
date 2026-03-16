#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int x1[15], x2[15];
int visited[15];
int last;
int answer;
int cnt;

void Choose(int end){
    bool Exist = false;
    for(int i=0; i<n; i++){
        if(visited[i] == 1) continue;
        if(x1[i] > end) Exist = true;
    }
    if(!Exist){
        //cout << cnt << " : ";
        //for(int i=0; i<n; i++){
            //cout << visited[i] << " ";
        //}cout << endl;
        answer = max(answer, cnt);
        return;
    }


    for(int i=0; i<n; i++){
        if(visited[i] == 1) continue;
        if(x1[i] <= end) continue;
        
        cnt++;
        visited[i] = 1;
        Choose(x2[i]);
        cnt--;
        visited[i] = 0;
    }
}



int main() {
    cin >> n;

    last = 0;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        last = max(last, x2[i]);
    }

    cnt = 0;
    answer = cnt;
    Choose(0);
    cout << answer;
    

    return 0;
}