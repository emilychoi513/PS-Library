#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int answer = INT_MAX;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            sum += A[j] * abs(i-j);
        }

        answer = min(answer, sum);
        //cout << sum << endl;
    }

    cout << answer;

    return 0;
}