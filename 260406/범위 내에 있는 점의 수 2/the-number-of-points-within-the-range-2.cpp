#include <iostream>

using namespace std;

int N, Q;
int arr[1000000 + 1];
int points[1000000 + 1];

int main() {
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        arr[p] = 1;
    }

    points[0] = arr[0];
    for(int i=1; i<=1000000; i++){
        points[i] = points[i-1] + arr[i];
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        if(a == 0) cout << points[b] << endl;
        else cout << points[b] - points[a-1] << endl;
    }

    return 0;
}
