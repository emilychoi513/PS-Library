#include <iostream>
#define MAX 45

using namespace std;

int N;
int fibbo[MAX + 1];

int main() {
    cin >> N;

    fibbo[1] = 1;
    fibbo[2] = 1;
    for(int i=3; i<=N; i++){
        fibbo[i] = fibbo[i-1] + fibbo[i-2];
    }

    cout << fibbo[N];

    return 0;
}
