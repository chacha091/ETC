#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(const int &x1, const int &x2){
        if(abs(x1) == abs(x2)){
            return x1>x2;
        }
        return abs(x1) > abs(x2);   //true일 때 swap
    }
};


int main(){
    int n,x;
    cin>>n;

    priority_queue<int ,vector<int>, cmp> heap;

    while (n--){
        cin>>x;

        if(x==0){
            if(heap.empty()){  //x가 비었다면 0 출력
                cout<<"0\n";
                continue;
            }

            cout<<heap.top()<<"\n";
            heap.pop();
        }

        else{
            heap.push(x);
        }
    }

    return 0;
}