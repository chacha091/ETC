#include <iostream>

using namespace std;

int getGen(int n){
    for(int i=1; i<n; i++){ //자연수이므로 1부터 시작, 
                            //생성자는 분해합보다 무조건 작으므로 n-1까지
        int sum = i;
        int tmp = i;

        while(tmp){
            sum += (tmp % 10);
            tmp /= 10;
        }
        if(sum==n){
            return i;
        }

    }
    return 0;
}

int main(){
    int n;
    cin>>n;

    cout<<getGen(n);
    
    return 0;
}