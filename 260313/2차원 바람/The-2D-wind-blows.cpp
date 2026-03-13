#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
int a[100][100];

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

bool exit(int x, int y){
    return (x<0 || x>=n || y<0 || y>=m);
}

void rotate(int r1, int c1, int r2, int c2){
    int len = 2 * (r2+c2-r1-c1);
    vector<int> rot(len);
    int idx;
    int tmp;

    idx = 0;
    for(int i=c1; i<c2; i++) rot[idx++] = a[r1][i];
    for(int i=r1; i<r2; i++) rot[idx++] = a[i][c2];
    for(int i=c2; i>c1; i--) rot[idx++] = a[r2][i];
    for(int i=r2; i>r1; i--) rot[idx++] = a[i][c1];

    tmp = rot[len - 1];
    for(int i=len-1; i>0; i--){
        rot[i] = rot[i-1];
    }
    rot[0] = tmp;

    idx = 0;
    for(int i=c1; i<c2; i++) a[r1][i] = rot[idx++];
    for(int i=r1; i<r2; i++) a[i][c2] = rot[idx++];
    for(int i=c2; i>c1; i--) a[r2][i] = rot[idx++];
    for(int i=r2; i>r1; i--) a[i][c1] = rot[idx++];

    //cout << "---rotate---" << endl;
    //print();
}

void mean(int r1, int c1, int r2, int c2){
    int r = r2-r1+1;
    int c = c2-c1+1;
    vector<vector<int>> mat(r, vector<int>(c, 0));
    int dx[5] = {0, 0, 0, -1, 1};
    int dy[5] = {0, -1, 1, 0, 0};
    int sum;
    int div;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            sum = 0;
            div = 5;
            for(int k=0; k<5; k++){
                if(exit(r1+i+dx[k], c1+j+dy[k])){
                    div--;
                    continue;
                }
                sum += a[r1 + i + dx[k]][c1 + j + dy[k]];
            }
            mat[i][j] = (sum/div);
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            a[r1 + i][c1 + j] = mat[i][j];
        }
    }

    //cout << "---mean---" << endl;
    //print();
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--; // 순서 고려
        //cout << r1 << c1 << r2 << c2 << endl;

        rotate(r1, c1, r2, c2);
        mean(r1, c1, r2, c2);
    }

    print();

    return 0;
}
