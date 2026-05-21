#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int arr[1003];

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int answer = INT_MAX;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            int tmp = (i+j)%n;

            sum += arr[tmp] * j;
        }
        //cout << sum << endl;
        answer = min(answer, sum);
    }

    cout << answer;

    return 0;
}