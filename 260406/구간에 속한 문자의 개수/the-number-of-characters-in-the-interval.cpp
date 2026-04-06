#include <iostream>

using namespace std;

int n, m, k;
char grid[1000][1000];

struct Char{
    int a, b, c;
};

Char arr[1000][1000];

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'a') arr[i][j].a++;
            else if(grid[i][j] == 'b') arr[i][j].b++;
            else arr[i][j].c++;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            arr[i][j].a += arr[i-1][j].a + arr[i][j-1].a - arr[i-1][j-1].a;
            arr[i][j].b += arr[i-1][j].b + arr[i][j-1].b - arr[i-1][j-1].b;
            arr[i][j].c += arr[i-1][j].c + arr[i][j-1].c - arr[i-1][j-1].c;
        }
    }
/*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << arr[i][j].a << " ";
        }cout << endl;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << arr[i][j].b << " ";
        }cout << endl;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << arr[i][j].c << " ";
        }cout << endl;
    }
*/
    for (int i = 0; i < k; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << arr[r2][c2].a - arr[r2][c1-1].a - arr[r1-1][c2].a + arr[r1-1][c1-1].a << " ";
        cout << arr[r2][c2].b - arr[r2][c1-1].b - arr[r1-1][c2].b + arr[r1-1][c1-1].b << " ";
        cout << arr[r2][c2].c - arr[r2][c1-1].c - arr[r1-1][c2].c + arr[r1-1][c1-1].c << endl;
    }

    // Please write your code here.

    return 0;
}
