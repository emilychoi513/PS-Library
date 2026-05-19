#include <iostream>
#include <algorithm>
using namespace std;

string a;
int arr[10];

int main() {
    cin >> a;

    for(int i=0; i<a.size(); i++){
        arr[i] = a[i] - '0';
    }

    int answer = 0;
    for(int i=1; i<a.size(); i++){
        arr[i] = 1 - arr[i];

        int sum = 0;
        for(int j=0; j<a.size(); j++){
            sum = sum * 2 + arr[j];
        }

        arr[i] = 1 - arr[i];
        answer = max(answer, sum);
        //cout << sum << endl;
    }

    cout << answer;
    return 0;
}