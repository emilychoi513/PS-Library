#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Open;
vector<int> Close;
string str;

int main() {
    cin >> str;

    for(int i=0; i<str.length()-1; i++){
        if(str[i] == str[i+1]){
            if(str[i] == '('){
                Open.push_back(i);
            }else{
                Close.push_back(i);
            }
        }
    }

    int answer = 0;
    for(int x:Open){
        for(int y:Close){
            if(x < y) answer++;
        }
    }

    cout << answer;

    
    return 0;
}