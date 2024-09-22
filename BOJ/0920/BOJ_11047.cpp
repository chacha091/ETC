#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k, cnt=0;
    vector<int> coin;

    cin>>n>>k;
    coin.assign(n, 0);
    
    for(int i=0; i<n; i++){
        cin>>coin[i];
    }

    while(n--){
        cnt += k/coin[n];
        k %= coin[n];
    }

    cout<<cnt;

    return 0;
}