#include <iostream>

using namespace std;

int n, k;
int arr[1000+1];
int Sum[1000+1];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    Sum[0] = 0, arr[0] = 0;
    for(int i=1; i<=n; i++){
        Sum[i] = Sum[i-1] + arr[i];
    }

    int answer = 0;
    
    for(int i=n; i>0; i--){
        for(int j=i-1; j>=0; j--){
            //cout << Sum[i] - Sum[j] << " ";
            if((Sum[i] - Sum[j]) == k){
                answer++;
            }
        }//cout << endl;
    }

    cout << answer;
    return 0;
}
