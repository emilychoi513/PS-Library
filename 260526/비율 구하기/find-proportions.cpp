#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;
map<string, int> dict;
map<string, int>::iterator it;

int main() {
    cin >> n;

    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        if(dict.find(str) == dict.end()){
            dict[str] = 1;
        }else{
            dict[str]++;
        }
    }

    for(it=dict.begin(); it!=dict.end(); it++){
        cout << it->first << " ";
        printf("%.4f\n", it->first, (float)it->second/n*100);
    }
    return 0;
}