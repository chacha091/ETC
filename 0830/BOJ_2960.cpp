#include <iostream>
#include <vector>

using namespace std;

int getPrime(int n, int k){
    vector<bool> is_prime(n+1, true);
    int cnt = 0;

    for(int i=2; i<=n; i++){
        if(!is_prime[i]){   //이미 지워진 수
            continue;
        }

        for(int j=i; j<=n; j+=i){
            if(!is_prime[j]){
                continue;
            }

            if((++cnt) == k){
                return j;
            }

            is_prime[j]=false;
        }
    }
    return -1;
}

int main(){
    int n,k,cnt;
    cin>>n>>k;

    cout<<getPrime(n, k);
    
    return 0;
}