#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];

void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }cout << endl;
    }
}

bool check_condition(int r1, int r2){
    bool flag = false;

    for(int i=0; i<m; i++){
        if(a[r1][i] == a[r2][i]){
            flag = true;
            break;
        }
    }

    return flag;
}

void right_shift(int r){
    int tmp = a[r][0];

    for(int i=0; i<m-1; i++){
        a[r][i] = a[r][i+1];
    }
    a[r][m-1] = tmp;
}

void left_shift(int r){
    int tmp = a[r][m-1];

    for(int i=m-1; i>0; i--){
        a[r][i] = a[r][i-1];
    }
    a[r][0] = tmp;
}

void round(int r, char d){
    if(d == 'L'){
        left_shift(r);
    }else if(d == 'R'){
        right_shift(r);
    }

    int ur = r-1;
    char ud = d;
    int dr = r+1;
    char dd = d;
    while(ur >= 0){
        if(!check_condition(ur, ur+1)) break;
        
        if(ud == 'L'){
            ud = 'R';
            right_shift(ur);
        }else{
            ud = 'L';
            left_shift(ur);
        }

        ur--;
    }
    
    while(dr <= n-1){
        if(!check_condition(dr, dr-1)) break;

        if(dd == 'L'){
            dd = 'R';
            right_shift(dr);
        }else{
            dd = 'L';
            left_shift(dr);
        }

        dr++;
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;

        r--;// 순서 반영
        round(r, d);
    }

    print();

    return 0;
}
