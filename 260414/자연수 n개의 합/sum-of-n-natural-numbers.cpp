#include <iostream>
#include <algorithm>
using namespace std;

long long s;

long long bs(long long target_val){
    long long l = 1;
    long long r = s;
    long long max_num = 0;

    while(l <= r){
        long long mid = (r+l)/2;
        
        if(mid*(mid + 1)/2 <= target_val){
            l = mid + 1;
            max_num = max(max_num, mid);
        }else{
            r = mid - 1;
        }
    }

    return max_num;
}

int main() {
    cin >> s;

    cout << bs(s);

    return 0;
}
