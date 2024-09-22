#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int main(){
    int n, cnt=0;
    vector<pi> v;

    cin>>n;
    v.assign(n, {0, 0});
    
    //끝나는 시간을 기준으로 문제를 푸므로 끝나는 시간을 first로 입력
    for(int i=0; i<n; i++){
        cin>>v[i].second>>v[i].first;   
    }

    sort(v.begin(), v.end());   //끝나는 시간 오름차순 정렬

    int finish_time=0;

    for(int i=0; i<n; i++){
        if(finish_time > v[i].second){
            continue;
        }
        finish_time = v[i].first;
        cnt++;
        
    }
    cout<<cnt;
    
    return 0;
}