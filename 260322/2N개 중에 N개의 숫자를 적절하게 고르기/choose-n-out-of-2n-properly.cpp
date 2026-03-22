#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int num[20];
int sub_sum;
int total_sum;
int answer;

void Div(int next, int cnt){
    if(cnt == n){
        int group_delta = abs((total_sum - sub_sum) - sub_sum);
        //cout << group_delta << endl;
        answer = min(answer, group_delta);
        return;
    }

    for(int i=next; i<2 * n; i++){
        sub_sum += num[i];
        Div(i+1, cnt+1);
        sub_sum -= num[i];
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
    }

    total_sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        total_sum += num[i];
    }

    sub_sum = 0;
    answer = INT_MAX;
    Div(0, 0);
    cout << answer;

    return 0;
}
