#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

string expression;
map<char, int> m;

int ans = INT_MIN;

int calculate(){
    int s = m[expression[0]];
    //cout << s << " ";

    for(int i=1; i<expression.size(); i+=2){
        if(expression[i] == '+'){
            s += m[expression[i+1]];
        }else if(expression[i] == '-'){
            s -= m[expression[i+1]];
        }else if(expression[i] == '*'){
            s *= m[expression[i+1]];
        }
        //cout << s << " ";
    }

    return s;
}

void mapping(int idx){
    if(idx >= expression.size()){
        
        // cout << "==============" << endl;
        // map<char, int>::iterator it;
        // for (it = m.begin(); it != m.end(); ++it) {
        //     cout << it->first << " : " << it->second << "\n";
        // }
        //cout << calculate() << endl << endl;
        ans = max(ans, calculate());

        return;
    }

    if(m.find(expression[idx]) == m.end()){
        for(int n=1; n<=4; n++){
            m[expression[idx]] = n;
            mapping(idx + 2);
            m.erase(expression[idx]);
        }
    }else{
        mapping(idx + 2);
    }

    return;
}


int main() {
    cin >> expression;
    //cout << "size " << expression.size() << endl;

    mapping(0);
    cout << ans;

    return 0;
}
