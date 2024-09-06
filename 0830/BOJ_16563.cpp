#include <iostream>
#include <vector>

using namespace std;
const int MAX = 5000000;

vector<int> getPrimes(){
    vector<int> primes(MAX+1, 0);

    for(int i=2; i*i<=MAX; i++){
        if(primes[i] != 0){ //소수가 아니라면 탐색하지 않는다
            continue;
        }

        for(int j=i*i; j<=MAX; j+=i){
            if(primes[j] == 0){
                primes[j]=i;
            }
        }
    }
    return primes;
}

vector<int> getPrimeFactors(int k, vector<int> &primes){
    vector<int> factors;

    while(primes[k] != 0){  //k가 소수가 될 때까지
        factors.push_back(primes[k]);
        k/=primes[k];
    }
    factors.push_back(k);
    return factors;
}

int main(){
    int n,k;
    cin>>n;

    vector<int> primes = getPrimes();

    while(n--){
        cin>>k;

        vector<int> factors = getPrimeFactors(k, primes);

        for(int num : factors){
            cout<<num<<" ";
        }

        cout<<'\n';
    }



    
    return 0;
}