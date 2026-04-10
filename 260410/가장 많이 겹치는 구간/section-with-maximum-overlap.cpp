#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x1[100000], x2[100000];
int p[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    int Bound = 0;
    for (int i = 0; i < n; i++) {
        Bound = max(Bound, x2[i]);
        p[x1[i]]++;
        p[x2[i]]--;
    }

    int Sum = 0, maxSum = 0;
    for (int i = 1; i <= Bound; i++) {
        Sum += p[i];
        //cout << Sum << " ";
        maxSum = max(maxSum, Sum);
    }

    cout << maxSum;

    return 0;
}
