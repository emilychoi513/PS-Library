#include <iostream>
#include <algorithm>
#define BOUND 200000
using namespace std;

int n;
int x1[100000], x2[100000];
int p[BOUND+1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for (int i = 0; i < n; i++) {
        p[x1[i]]++;
        p[x2[i]]--;
    }

    int Sum = 0, maxSum = 0;
    for (int i = 1; i <= BOUND; i++) {
        Sum += p[i];
        maxSum = max(maxSum, Sum);
    }

    cout << maxSum;

    return 0;
}
