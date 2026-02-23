#include <iostream>

using namespace std;

int a, b, c;

int Min(int a, int b, int c){
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}

int main() {
    cin >> a >> b >> c;

    cout << Min(a, b, c);

    return 0;
}