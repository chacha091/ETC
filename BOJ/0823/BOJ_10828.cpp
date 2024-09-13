#include <iostream>
// #include <vector>
#include <stack>

using namespace std;

#define MAX_SIZE 10000

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    
    stack<int> s;
    // vector<int> arr(MAX_SIZE); //스택 선언
    // int top=-1;

    string cmd;
    int x;

    while (n--)
    {
        cin>>cmd; //명령어 입력
        
        //push: 스택에 x 삽입
        if(cmd == "push"){
            cin>>x;
            s.push(x);
            // arr[++top] = x;
        }

        //pop: 스택에서 top 원소 삭제 후 출력
        else if(cmd == "pop"){
            if(s.empty()/*top == -1*/){
                cout<<"-1\n";
            }
            else{
                cout<<s.top()<<'\n';
                s.pop();
                //cout<<arr[top--]<<'\n';
            }
        }

        //size: 스택 크기 출력
        else if(cmd == "size"){
            cout<<s.size()<<'\n';
            //cout<<top + 1<<'\n';
        }
        
        //empty: 스택이 비어있는지 확인
        else if(cmd == "empty"){
            cout<<s.empty()<<'\n';
            //cout<<(top == -1)<<'\n';
        }

        //top: 스택의 top 출력
        else if(cmd == "top"){
            if(s.empty()/*top==-1*/){
                cout<<"-1\n";
            }
            else{
                cout<<s.top()<<'\n';
                //cout<<arr[top]<<'\n';
            }
        }

    }
    
}