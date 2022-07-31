class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
    
public:
    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        qfront=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == rear)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size)
            cout<<"queue is full "<<endl;
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        int ans;
        if(qfront == rear)
            return -1;
        else{
            ans = arr[qfront];
            arr[qfront]=0;
            qfront++;
            //to make sure no space is wasted.
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
        }
        return ans;
    }

    int front() {
        // Implement the front() function
        if(qfront == rear)
            return -1;
        else{
            return arr[qfront];
        }
    }
};