#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cnt, mcnt;
    cnt = 1;
    mcnt = 1;
    for(int i=1; i<N; i++){
        if(arr[i-1] == arr[i]){
            cnt++;
        }else{
            mcnt = max(mcnt, cnt);
            cnt = 1;
        }
    }

    cout << mcnt;

    return 0;
}