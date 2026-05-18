#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int answer;
    int part;
    int arr[100000];
    int n;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    part = 0;
    answer = -1000-1;
    for(int i=0; i<n; i++){
        part += arr[i];
        answer = max(answer, part);
        if(part < 0){
            part = 0;
        }
    }

    cout << answer;

    return 0;
}