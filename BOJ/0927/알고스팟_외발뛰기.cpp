#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> check;
int n;

int dp(int x, int y){
    //벗어남
    if(x>=n || y>=n){
        return 0;
    }
    //끝 도착
    if(x == n-1 && y == n-1){
        return 1;
    }
    //탐색 중
    //이미 방문했음
    if(check[x][y] != -1){
        return check[x][y];
    }
    check[x][y] = (dp(x + board[x][y], y) || dp(x, y + board[x][y]));

    return check[x][y];
}

int main(){
    int c;
    cin>>c;

    while(c--){
        cin>>n;

        board.assign(n, vector<int> (n, 0));
        check.assign(n, vector<int> (n, -1));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>board[i][j];
            }
        }

        int result = dp(0, 0);
        
        if(result){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}