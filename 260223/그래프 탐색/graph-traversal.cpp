#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int graph[10000 + 1][10000 + 1];
bool visited[10000 + 1];
int cnt;

void DFS(int vertex){
    for(int i=1; i<=n; i++){
        if(graph[vertex][i]==1 && !visited[i]){
            cnt++;
            visited[i] = true;
            DFS(i);
        }
    }
}

int main() {
    cin >> n >> m;

    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }

    DFS(1);
    cout << max(0, cnt-1);

    return 0;
}
