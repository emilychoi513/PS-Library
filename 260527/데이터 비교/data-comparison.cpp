#include <iostream>
#include <unordered_set>
using namespace std;

int n;
int m;
int arr1[100000];
int arr2[100000];
unordered_set<int> s1;
unordered_set<int> s2;

int main() {
    cin >> n;
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        arr1[i] = num;
        s1.insert(num);
    }

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> num;
        arr2[i] = num;
        s2.insert(num);
    }

    for(int i=0; i<m; i++){
        if(s1.find(arr2[i]) != s1.end()){
            cout << 1;
        }else cout << 0;
        cout << " ";
    }

    return 0;
}