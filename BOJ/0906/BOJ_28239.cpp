#include <iostream>

using namespace std;
typedef long long ll;
const int MAX = 60;

//10^3 = 1000 ~ 2^10 = 1024
//10^18 ~ 2^60

pair<int, int> sol(ll m){
    // 1. m이 2의 제곱수 -> m을 이진수로 표현 시, 1이 한 개
    for(int i=0; i<MAX; i++){
        if(m == ((ll)1 << i)){  //m이 2의 제곱수인지 확인, 1을 long long형으로 변환(오버플로우 방지)
            return {i-1, i-1};
        }
    }

    // 2. m이 2의 제곱수 X
    int x,y;

    for(x=0; x<MAX; x++){
        if(m & ((ll)1 << x)){
            m -= ((ll)1 << x);
            break;
        }
    }

    for(y=0; y<MAX; y++){
        if(m & ((ll)1 << y)){
            break;
        }
    }
    return {x, y};
}

int main(){
    int n;
    cin>>n;

    ll m;
    while(n--){
        cin>>m;

        pair<int, int> ans = sol(m);

        cout<<ans.first<<' '<<ans.second<<'\n';

    }
    
    return 0;
}