#include <iostream>
#include <vector>

using namespace std;

const int MAX = 14;
int n, ans;
bool is_queen_in_col[MAX], is_queen_in_left[MAX*2], is_queen_in_right[MAX*2];

void backtrack(int row){
    if(row == n){
        ans++;
        return;
    }

    for(int col = 0; col < n; col++){
        if(!is_queen_in_col[col] && !is_queen_in_left[row + col] && !is_queen_in_right[row - col + n]){

            is_queen_in_col[col]=true;
            is_queen_in_left[row + col]=true;
            is_queen_in_right[row - col + n]=true;

            backtrack(row + 1);

            is_queen_in_col[col]=false;
            is_queen_in_left[row + col]=false;
            is_queen_in_right[row - col + n]=false;
        }
    }
}

int main(){
    cin>>n;

    backtrack(0);

    cout<<ans;
    
    return 0;
}