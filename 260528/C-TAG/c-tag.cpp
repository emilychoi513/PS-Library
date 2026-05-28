#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int n, m;
string A[500];
string B[500];
unordered_set<string> s;
int answer;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    for(int i=0; i<m-2; i++){
        for(int j=i+1; j<m-1; j++){
            for(int k=j+1; k<m; k++){
                s.clear();
                for(int l=0; l<n; l++){
                    string str = { A[l][i], A[l][j], A[l][k] };
                    s.insert(str);
                }

                bool flag = true;
                for(int l=0; l<n; l++){
                    string str = { B[l][i], B[l][j], B[l][k] };
                    if(s.find(str) != s.end()){
                        flag = false;
                        break;
                    }
                }

                if(flag) answer++;
            }
        }
    }

    cout << answer;

    return 0;
}
