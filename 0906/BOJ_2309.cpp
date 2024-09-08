#include <iostream>
#include <vector>
#include <algorithm>    //sort함수

using namespace std;
const int CNT=9;

void sol(vector<int> &height){
    int sum=0;

    for(int i=0; i<CNT; i++){   //9명의 키의 합
        sum+=height[i];
    }

    for(int i=0; i<CNT; i++){   //2명 제외 7명의 키의 합이 100이 되는지 확인
        for(int j=i+1; j<CNT; j++){
            if(sum-height[i]-height[j] == 100){
                height.erase(height.begin() + j);   //j번째 난쟁이 삭제
                height.erase(height.begin() + i);   //i번째 난쟁이 삭제
                //뒤에 있는 j번째 인덱스부터 삭제해야 함

                return;
            }
        }
    }
}


int main(){
    vector<int> height(CNT);

    for(int i=0; i<CNT; i++){
        cin>>height[i];
    }

    sol(height);    //오름차순 정렬

    sort(height.begin(), height.end());

    for(auto it:height){
        cout<<it<<'\n';
    }
    
    return 0;
}