#include <iostream>

using namespace std;

int n;
int blocks[100];
int temp[100];
int temp2[100];
int s1, e1;
int s2, e2;



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(i >= s1-1 && i <= e1-1) continue;
        temp[cnt] = blocks[i];
        cnt++;
    }

    int cnt2 = 0;
    for(int i=0; i<cnt; i++){
        if(i >= s2-1 && i <= e2-1) continue;
        temp2[cnt2] = temp[i];
        cnt2++;
    }

    cout << cnt2 << '\n';
    for(int i=0; i<cnt2; i++){
        cout << temp2[i] << endl;
    }

    return 0;
}
