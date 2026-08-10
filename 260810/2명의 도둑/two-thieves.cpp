#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n, m, c;
int weight[10][10];
vector<int> v;
int max_value;
int max_value_1, max_value_2;
int ans;

pair<int, int> weight_value_sum(){
    int ws = 0;
    int vs = 0;
    for(int num:v){
        ws += num;
        vs += pow(num, 2);
    }
    return {ws, vs};
}

void get_max_sum(int x, int y, int right){
    if(y == right){
        int weight = weight_value_sum().first;
        int value = weight_value_sum().second;
        if(weight <= c){
            max_value = max(max_value, value);
        }
        return;
    }

    v.push_back(weight[x][y]);
    get_max_sum(x, y+1, right); //포함
    v.pop_back();

    get_max_sum(x, y+1, right); //미포함
}

void steal(int x1, int y1, int x2, int y2){
    max_value = 0; 
    get_max_sum(x1, y1, y1+m);
    max_value_1 = max_value;
    max_value = 0;
    get_max_sum(x2, y2, y2+m);
    max_value_2 = max_value;

    //cout << max_value_1 << " " << max_value_2 <<" " ;
    //cout << max_value_1 + max_value_2 << endl;
    ans = max(ans, max_value_1 + max_value_2);
}

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }

    //도둑 1,2가 훔칠 영역 골라주기
    for(int i=0; i<n; i++){
        for(int j=0; j+m-1<n; j++){
            for(int a=i; a<n; a++){
                if(a == i){
                    for(int b=j+m; b+m-1<n; b++){
                        //printf("%d %d, %d %d\n", i, j, a, b);
                        steal(i, j, a, b);
                    }
                }
                else{
                    for(int b=0; b+m-1<n; b++){
                        //printf("%d %d, %d %d\n", i, j, a, b);
                        steal(i, j, a, b);
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}