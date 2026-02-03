#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;

    int v = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << v << " ";
            if(v == 9) v = 0;
            v++;
        }
        cout << '\n';
    }

    return 0;
}