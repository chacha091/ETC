#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    queue<int> card;
    int t;

    cin>>n;

    for(int i=1; i<=n; i++){
        card.push(i);
    }

    while(card.size()>1){
        card.pop();

        t = card.front();
        card.push(t);

        card.pop();
    }
    
    cout<<card.front();
    
    return 0;
}