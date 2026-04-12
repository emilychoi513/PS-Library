#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int s;
int arr[100000];
int min_len = INT_MAX;

int main() {
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int Sum = 0;
    int r = 0;
    for(int l=0; l<n; l++){
        while(r < n && Sum < s){
            Sum += arr[r];
            r++;
        }

        if(Sum < s) break;
        
        min_len = min(min_len, r-l+1);
        Sum -= arr[l];
    }

    if(min_len == INT_MAX) min_len = -1;
    cout << min_len;
    return 0;
}