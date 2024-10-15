#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 9;
int k;

vector<char> symbols(MAX);
vector<bool> check(10);     //0~9 사용 가능
vector<int> sequence;

string max_seq = "0";
string min_seq = "9999999999";

void updateAnswer(){
    string num = "";
    for(int i: sequence){
        num += to_string(i);
    }
    max_seq = max(max_seq, num);
    min_seq = min(min_seq, num);

}

void backtrack(int cnt){
    if(cnt == k + 1){
        updateAnswer();
        return;
    }

    for(int i=0; i<=9; i++){
        if(check[i]){
            continue;
        }

        if(cnt == 0 || 
            (symbols[cnt-1] == '>' && sequence[cnt-1] > i) ||
            (symbols[cnt-1] == '<' && sequence[cnt-1] < i)){
            
            sequence.push_back(i);
            check[i] = true;

            backtrack(cnt+1);

            check[i] = false;
            sequence.pop_back();

        }
    }
}

int main(){
    cin>>k;

    for(int i=0; i<k; i++){
        cin>>symbols[i];
    }

    backtrack(0);
    
    cout<<max_seq<<"\n"<<min_seq;
    
    return 0;
}