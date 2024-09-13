#include <iostream>
#include <vector>

using namespace std;

bool isEmpty(vector<int>& heap){
    return heap.size() == 1;
}

void push(int x, vector<int>& heap){
    int idx = heap.size();  //새로운 값이 추가될 인덱스

    heap.push_back(x);

    //부모와 비교하며 부모 노드보다 자식노드가 더 크다면 swap
    while(idx > 1 && heap[idx] > heap[idx/2]){
        swap(heap[idx], heap[idx/2]);

        //다음 부모 탐색
        idx /= 2;
    }
}

int pop(vector<int>& heap){
    int top = heap[1]; //root

    //가장 마지막 인덱스에 있는 값을 루트에 넣는다
    heap[1] = heap[heap.size()-1];
    heap.pop_back();

    //더 큰 자식 찾기
    int parent = 1, child = 2;
    while(child < heap.size()){
        if(child + 1 < heap.size() && heap[child] < heap[child+1]){  //왼쪽과 오른쪽 자식 비교
            child += 1;
        }

        if(heap[child] > heap[parent]){
            swap(heap[child], heap[parent]);

            //다음 자식 탐색
            parent = child;
            child *= 2;
        }
        else{
            break;
        }
    }
    

    return top;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,x;
    cin>>n;

    vector<int> max_heap;
    max_heap.push_back(0);

    while (n--){
        cin>>x;

        if(x==0){
            if(isEmpty(max_heap)){  //x가 비었다면 0 출력
                cout<<"0\n";
                continue;
            }

            cout<<pop(max_heap)<<"\n";
        }

        else{
            push(x,max_heap);
        }
    }

    return 0;
}