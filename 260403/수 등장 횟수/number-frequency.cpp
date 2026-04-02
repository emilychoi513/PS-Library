#include <iostream>
#include <unordered_map>
using namespace std;

const int MAX_N = 100000;

int n, m;
int arr[MAX_N];
unordered_map<int, int> umap;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if(umap.find(arr[i]) == umap.end()){
            umap.insert({arr[i], 1});
        }else{
            umap[arr[i]] = umap[arr[i]] + 1;
        }
    }


    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        cout << umap[num] << " ";
    }

    return 0;
}
