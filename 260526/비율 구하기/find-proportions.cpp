#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
string str[10000];
map<string, int> dict;
map<string, int>::iterator it;

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> str[i];
    }

    for(int i=0; i<n; i++){
        dict[str[i]]++;
    }

    for(it=dict.begin(); it!=dict.end(); it++){
        cout << it->first << " ";
        printf("%.4f\n",(float)it->second/n*100);
    }
    return 0;
}