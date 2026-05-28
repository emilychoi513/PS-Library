#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int n, k;
vector<unordered_set<int>> vs(100000+1);
int arr[100000+1];
int a[100000+1];
int b[100000+1];

void swap(int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    vs[arr[i]].insert(i);
    vs[arr[j]].insert(j);
}

void Print(){
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main() {
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        arr[i] = i;
        vs[i].insert(i);
    }

    for(int i=0; i<k; i++){
        cin >> a[i] >> b[i];
    }
    for(int i=0; i<3*k; i++){
        swap(a[i%k], b[i%k]);
        //Print();
    }

    /*for(int i=1; i<=n; i++){
        unordered_set<int>::iterator it;
        for(it=vs[i].begin(); it!=vs[i].end(); it++){
            cout << *it << " ";
        }cout << endl;
    }*/

    for(int i=1; i<=n; i++){
        cout << vs[i].size() << endl;
    }
    
    return 0;
}