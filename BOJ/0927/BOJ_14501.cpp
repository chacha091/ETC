#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int bottomUpDp(vector<pi>& counsel, int n){
    vector<int> dp(n+1);

    for(int i=0; i<n; i++){
        for(int j=i+counsel[i].first; j<=n; j++){
            dp[j] = max(dp[i] + counsel[i].second, dp[j]);
        }
    }

    return dp[n];
}

int topDownDp(vector<pi>& counsel, int n){
    vector<int> dp(n+1);

    for(int i=0; i<n; i++){
        if(i + counsel[i].first > n){
            dp[i] = dp[i+1];
        }
        else{
            dp[i] = max(dp[i], dp[i + counsel[i].first] + counsel[i].second);
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    vector<pi> counsel(n, {0,0});

    for(int i=0; i<n; i++){
        cin>>counsel[i].first>>counsel[i].second;
    }    

    cout<<bottomUpDp(counsel, n);

    return 0;
}