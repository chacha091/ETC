#include <iostream>
#include <vector>

using namespace std;

void calSum(int n, vector<int>& sum){
    for(int i=1; i<=n; i++){
        sum[i] += sum[i-1];
    }
}

int getSum(int i, int j, const vector<int>& sum){
    return sum[j]-sum[i-1];
}

int main(){
    int n, m, i, j;

    cin>>n>>m;
    vector<int> sum(n+1, 0);

    for(int i=1; i<=n; i++){
        cin>>sum[i];
    }

    calSum(n, sum);

    while(m--){
        cin>>i>>j;

        cout<<getSum(i,j,sum)<<'\n';
    }
    
    return 0;
}