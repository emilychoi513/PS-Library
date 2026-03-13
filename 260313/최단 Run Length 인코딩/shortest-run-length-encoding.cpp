#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A;
int len;
int mn;

int lengthCheck(){
    int curr = 0;
    char c = A[0];
    int change = 0;

    for(int i=0; i<len; i++){
        if(A[i] == c){
            curr++;
            if(i == len - 1){   //special case
                //cout << curr << " ";
                if(curr == 10) return 3;
                else change++;
            }
        }
        else{
            //cout << curr << " ";
            change++;
            c = A[i];
            curr = 1;

            if(i == len - 1){
                //cout << curr << " ";
                change++;
            }
        }
    }

    //cout << 2 * change << endl;

    return (2 * change);
}

void shift(){
    char tmp = A[0];
    for(int i=0; i<len-1; i++){
        A[i] = A[i+1];
    }
    A[len-1] = tmp;

    /*
    for(int i=0; i<len; i++){
        cout << A[i] << " ";
    }endl;
    */
}

int main() {
    cin >> A;

    len = A.size();

    mn = 10;
    for(int i=0; i<len; i++){
        shift();
        mn = min(mn, lengthCheck());
    }

    cout << mn;

    return 0;
}
