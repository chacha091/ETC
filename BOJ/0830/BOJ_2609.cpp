#include <iostream>

using namespace std;

int getGcd(int a, int b){
    while(b){   //b==0, a가 최대공약수
        a %= b;
        swap(a,b);  //a가 b보다 작아지기 때문에 swap해줘야 함
    }
    return a;
}

int main(){
    int a,b;
    cin>>a>>b;

    int gcd = getGcd(a,b);
    int lcm = a * b / gcd;

    cout<<gcd<<'\n'<<lcm;

    return 0;
}