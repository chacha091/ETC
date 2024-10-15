#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 8;
int n,m;    //재귀함수 구현 시 변수는 전역으로 설정
vector<int> sequence(MAX_N);
vector<bool> is_used(MAX_N);

void printSequence(){
    for(int i = 0; i<m; i++){
        cout<<sequence[i]<<" ";
    }
    cout<<"\n";
}

void backtrack(int cnt){
    if(cnt == m){
        printSequence();
        return;
    }
    for(int i=1; i<=n; i++){
        if(is_used[i]){
            continue;
        }

        is_used[i] = true;
        sequence[cnt] = i;

        backtrack(cnt + 1);
        is_used[i] = false;
    }
}

int main(){
    cin>>n>>m;
    
    backtrack(0);   //cnt가 0~m
    
    return 0;
}