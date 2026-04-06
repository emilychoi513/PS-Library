#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, K, B;
int missing[100001];
int prefix_miss[100001];

int main() {
    cin >> N >> K >> B;

    for (int i = 0; i < B; i++) {
        cin >> missing[i];
        prefix_miss[missing[i]] = 1;
    }

    prefix_miss[0] = 0;
    for(int i=1; i<=N; i++){
        prefix_miss[i] += prefix_miss[i-1];
    }

    int answer = INT_MAX;
    for(int i=1; i+K-1 <= N; i++){
        answer = min(answer, prefix_miss[i+K-1] - prefix_miss[i-1]); // i ~ i+K-1
    }

    cout << answer;
    return 0;
}
