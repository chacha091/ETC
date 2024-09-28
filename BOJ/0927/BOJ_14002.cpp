#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> setDp(vector<int>& arr, int n){
    vector<int> dp(n, 0);
    dp[0]=1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return dp;
}

vector<int> makeLis(vector<int>& arr, int n){
    vector<int> dp = setDp(arr, n);

    vector<int> ans;

    int len = -1;

    for(int i=0; i<n; i++){
        len = max(len, dp[i]);
    }

    for(int i=n-1; i>=0; i--){
        if(dp[i]==len){
            ans.push_back(arr[i]);
            len--;
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
    
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n, 0);

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> lis = makeLis(arr, n);

    cout<<lis.size()<<'\n';
    
    for(int i : lis){
        cout<<i<<" ";
    }

    return 0;
}