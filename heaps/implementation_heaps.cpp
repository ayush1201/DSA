#include<iostream>
using namespace std;


class heap{
    public:
     int arr[100];
     int size;

    //constructor.
    heap(){
        arr[0] = -1;
        size = 0;
    } 

    void insert(int val){
        //increase the size of array to insert at end.
        size = size + 1;
        int index = size;
        arr[index] = val;

        //now check for the max heap condition at every parent.
        while(index > 1){
            int parentIndex = index/2;
            if(arr[parentIndex] < arr[index]){
                swap(arr[parentIndex],arr[index]);
                //and update index.
                index = parentIndex;
                //again it will check the condition.
            }
            else{
                //matlab no need to check further parents.
                return;
            }

        }

        

    } 
    void print(){
        //starting from 1 since on index 0 nothing is stored.
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";    
        }cout<<endl;
    } 

    void deleteHeap(){
        if(size == 0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        //step 1
        //copy last node value to root node.
        arr[1] = arr[size];
        //step 2
        //remove last element.
        size--;
        
        //step 3
        //take root node to correct position.
        int i = 1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            //now compare which is greater in left and right.
            if((leftIndex < size) && (arr[leftIndex] > arr[rightIndex])){
                swap(arr[leftIndex],arr[i]);
                //update i.
                i = leftIndex;
            }
            else if((rightIndex < size) && (arr[rightIndex] > arr[leftIndex])){
                swap(arr[rightIndex],arr[i]);
                //update i.
                i = rightIndex;
            }
            else{
                //if already both child nodes are smaller than parent.
                return;
            }
            
        }
    }
    
};

//heapify function
void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[left] > arr[largest]){
        //update largest
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        //update largest.
        largest = right;
    }
    //check if largest is changed means to make heap.
    if(largest != i){
        swap(arr[largest],arr[i]);
        //check further ndes to be get heaped.
        heapify(arr,n,largest);
    }
}

int main(){
    heap h;
    //insertion
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(55);

    h.print();

    //deletion
    h.deleteHeap();
    h.print();

    int arr[6] = {-1,54,55,53,52,51};
    int n = 5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing array after heapify"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}