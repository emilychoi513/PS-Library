#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
struct Position{
    int x;
    int y;
};

Position pos[100];

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> pos[i].x >> pos[i].y;
    }

    int sum = 0;
    for(int i=1; i<n; i++){
        sum += abs(pos[i].x - pos[i-1].x) + abs(pos[i].y - pos[i-1].y);
    }

    int answer = INT_MAX;
    for(int i=1; i<n-1; i++){
        int tmp = sum;
        tmp -= abs(pos[i].x-pos[i-1].x) + abs(pos[i].x - pos[i+1].x) + abs(pos[i].y - pos[i-1].y) + abs(pos[i].y - pos[i+1].y);
        tmp += abs(pos[i-1].x - pos[i+1].x) + abs(pos[i-1].y - pos[i+1].y);
        //cout << tmp << endl;
        answer = min(answer, tmp);
    }

    cout << answer;
    
    return 0;
}