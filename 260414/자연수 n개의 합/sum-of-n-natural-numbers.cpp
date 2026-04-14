#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long s;
long long q;

long long bs(long long target_val){
    long long l = 1;
    long long r = 2 * q;
    long long max_num = 0;

    while(l <= r){
        long long mid = l + (r-l)/2;
        //cout << mid << endl;

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
    
    q = (long long)sqrt(s);

    cout << bs(s);

    return 0;
}
