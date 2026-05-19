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
        int mul = 1;
        for(int j=a.size()-1; j>=0; j--){
            sum += arr[j] * mul;
            mul *= 2;
        }

        arr[i] = 1 - arr[i];
        answer = max(answer, sum);
    }

    cout << answer;
    return 0;
}