#include <iostream>

using namespace std;

int n, m;
int arr[100000];

int searchMin(int target_val){
    int left = 0;
    int right = n-1;
    int min_idx = n;

    while(left <= right){
        int mid = (left + right)/2;
        if(arr[mid] >= target_val){
            right = mid - 1;
            min_idx = min(min_idx, mid);
        }
        else{
            left = mid + 1;
        }
    }

    return min_idx;
}

int searchMax(int target_val){
    int left = 0;
    int right = n-1;
    int min_idx = n;

    while(left <= right){
        int mid = (left + right)/2;
        if(arr[mid] > target_val){
            right = mid - 1;
            min_idx = min(min_idx, mid);
        }
        else{
            left = mid + 1;
        }
    }

    return min_idx;
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        cout << searchMax(x) - searchMin(x) << endl;
    }

    return 0;
}
