#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

pi solution(int n, int x, vector<int>& visitor){
    int cnt_visit = 0;
    int cnt_period = 1;
    
    for(int i=0; i<x; i++){
        cnt_visit += visitor[i];
    }
    int max_visit = cnt_visit;

    for(int i=x; i<n; i++){
        cnt_visit += visitor[i] - visitor[i-x];

        if(cnt_visit > max_visit){
            max_visit = cnt_visit;
            cnt_period = 1;
        }
        else if(cnt_visit == max_visit){
            cnt_period ++;
        }
    }

    return {max_visit, cnt_period};
}


int main(){
    int n, x;

    cin>>n>>x;

    vector<int> visitor(n, 0);

    for(int i=0; i<n; i++){
        cin>>visitor[i];
    }

    pi ans = solution(n, x, visitor);

    if(ans.first==0){
        cout<<"SAD";
        return 0;
    }

    cout<<ans.first<<'\n'<<ans.second;

    return 0;
}