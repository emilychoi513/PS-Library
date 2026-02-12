#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> blocks(100);
int s1, e1;
int s2, e2;


int removeJenga(int cnt, int s, int e){
    vector<int> temp(100, 0);
    int tcnt = 0;

    for(int i=0; i<cnt; i++){
        if(i >= s-1 && i <= e-1) continue;

        temp[tcnt] = blocks[i];
        tcnt++;
    }

    blocks.resize(tcnt, 0);
    for(int i=0; i<tcnt; i++){
        blocks[i] = temp[i];
    }

    return tcnt;
}



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    int cnt1 = removeJenga(n, s1, e1);
    int cnt2 = removeJenga(cnt1, s2, e2);

    cout << cnt2 << '\n';
    for(int i=0; i<cnt2; i++){
        cout << blocks[i] << endl;
    }

    return 0;
}
