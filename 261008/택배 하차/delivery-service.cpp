#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <climits>
#define D 0
using namespace std;

int N, M;

int grid[60][60];

struct Box{
    int k;
    int h, w;
    int r, c;
    bool alive;
};

Box box[105];

void Print(){
    if(!D) return;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }cout << endl;

    // for(int i=1; i<=M; i++){
    //     if(!box[i].alive) continue;
    //     printf("%d: %d %d\n", i, box[i].r, box[i].c);
    // }
}

void Input(){
    cin >>  N >> M;

    for(int i=1; i<=M; i++){ //인덱스 1~M
        int k, h, w, c;
        cin >> k >> h >> w >> c;
        box[i] = {k, h, w, 1, c, true};
    }
}

bool CheckBox(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(grid[i][j]) return true;
        }
    }

    return false;
}


void Grave(int bid){
    auto [k, h, w, r, c, alive] = box[bid];

    int next_row = r + h;
    int tar_row = r;

    while(next_row <= N){
        bool can_move = true;

        for(int col=c; col<c+w; col++){
            if(grid[next_row][col] != 0){
                can_move = false;
                break;
            }
        }

        if(can_move){
            next_row++;
            tar_row++;
        }else{
            break;
        }
    }

    for(int row=r; row<r + h; row++){
        for(int col=c; col<c+w; col++){
            grid[row][col] = 0;
        }
    }

    box[bid].r = tar_row;
    for(int row=tar_row; row<tar_row + h; row++){
        for(int col=c; col<c+w; col++){
            grid[row][col] = bid;
        }
    }
}

void Left(){
    vector<int> left_bid(N+1, -1);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(grid[i][j] != 0){
                left_bid[i]=grid[i][j]; //row의 가장 왼쪽 택배 인덱스를 기록
                break;
            }
        }
    }



    // cout << "tmp: ";
    // for(int i=1; i<=N; i++){
    //     cout << left_bid[i] << " ";
    // }cout << endl;

    int row = 1;
    int tar_bid = -1;
    int tar_num = INT_MAX;
    while(row <= N){
        int tmp_bid = left_bid[row]; //지금 행의 맨 왼쪽 택배 인덱스
        int r = box[tmp_bid].r; //그 택배 인덱스의 좌상단 행
        int h = box[tmp_bid].h; 

        if(r != row){ //1. 지금 행이 이 택배의 좌상단 행이 아닌경우
            row++;
            continue;
        }
        
        //2. 지금 행이 좌상단인 경우 -> 택배의 모든 행이 맨 왼쪽에 있는 칸인지 검사
        bool flag = true;
        for(int l=r; l<r + h; l++){ //행 검사
            if(left_bid[l] != tmp_bid){
                flag = false;
            }
        }

        if(flag){
            row += h;
            if(box[tmp_bid].k < tar_num){
                tar_num = box[tmp_bid].k;
                tar_bid = tmp_bid;
            }
        }else{
            row++;
        }
    }
    // printf("left out: id(%d), k(%d)\n", tar_bid, tar_num);
    cout << tar_num << endl;

    //빼기
    box[tar_bid].alive = false;
    for(int r=box[tar_bid].r; r<box[tar_bid].r + box[tar_bid].h; r++){
        for(int c=box[tar_bid].c; c<box[tar_bid].c + box[tar_bid].w; c++){
            grid[r][c] = 0;
        }
    }
}

void Right(){
    vector<int> right_bid(N+1, -1);

    for(int i=1; i<=N; i++){
        for(int j=N; j>0; j--){
            if(grid[i][j] != 0){
                right_bid[i]=grid[i][j]; //row의 가장 왼쪽 택배 인덱스를 기록
                break;
            }
        }
    }

    // cout << "tmp: ";
    // for(int i=1; i<=N; i++){
    //     cout << right_bid[i] << " ";
    // }cout << endl;

    int row = 1;
    int tar_bid = -1;
    int tar_num = INT_MAX;
    while(row <= N){
        int tmp_bid = right_bid[row]; //지금 행의 맨 오른쪽 택배 인덱스
        int r = box[tmp_bid].r; //그 택배 인덱스의 상단 행
        int h = box[tmp_bid].h; 

        if(r != row){ //1. 지금 행이 이 택배의 상단 행이 아닌경우
            row++;
            continue;
        }
        
        //2. 지금 행이 좌상단인 경우 -> 택배의 모든 행이 맨 오른쪽에 있는 칸인지 검사
        bool flag = true;
        for(int l=r; l<r + h; l++){ //행 검사
            if(right_bid[l] != tmp_bid){
                flag = false;
            }
        }

        if(flag){
            row += h;
            if(box[tmp_bid].k < tar_num){
                tar_num = box[tmp_bid].k;
                tar_bid = tmp_bid;
            }
        }else{
            row++;
        }
    }
    // printf("right out: id(%d), k(%d)\n", tar_bid, tar_num);
    cout << tar_num << endl;

    //빼기
    box[tar_bid].alive = false;
    for(int r=box[tar_bid].r; r<box[tar_bid].r + box[tar_bid].h; r++){
        for(int c=box[tar_bid].c; c<box[tar_bid].c + box[tar_bid].w; c++){
            grid[r][c] = 0;
        }
    }
}

void Graving(){
    vector<int> ord;
    vector<int> visited(M+1, 0);

    for(int i=N; i>0; i--){
        for(int j=1; j<=N; j++){
            if(grid[i][j] != 0){
                if(!visited[grid[i][j]]){
                    ord.push_back(grid[i][j]);
                    visited[grid[i][j]]=1;
                }
            }
        }
    }

    // for(int x:ord) cout << x << " ";

    for(int x:ord){
        // printf("%d: \n", x);
        Grave(x);
    }
}

int main() {
    Input();

    for(int i=1; i<=M; i++){
        Grave(i);
        // Print();
    }

    Print();


    //반복
    while(1){
        if(!CheckBox()) break;

        Left(); //왼쪽 하차(빼기)
        Print();
        Graving(); //아래부터 차례대로 중력 작용
        Print();

        if(!CheckBox()) break;
        Right();
        Print();
        Graving();
        Print();
    }
    
    return 0;
}