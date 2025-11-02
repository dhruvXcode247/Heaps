#include<iostream>
using namespace std;

class maxHeap {
    int *arr;
    int size;
    int total_size;

    public:
    maxHeap(int n) {
        arr=new int[n];
        size=0;
        total_size=n;
    }
    //INSERT INTO THE HEAP
    void insert(int value) {
        // if heap size is available or not
        if (size==total_size) {
            cout << "Heap Overflow:";
            return;
        }
        arr[size]=value;
        int index=size;
        size++;
        // compare it with its parent
        while (index>0 && arr[index]>arr[(index-1)/2]) {
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        };

        cout << arr[index] << "is inserted into the heap";
    }
    void print() {
        for (int i=0;i<size;i++) {
            cout << arr[i] << " ";
            cout << endl;
        }
    }
     void heapify (int index) {
        int largest=index;
        int left= 2*index+1 ;
        int right=2*index+2 ;

        if (left<size && arr[left]>arr[largest]) {
            largest=left;
        }
        if (right<size && arr[right]>arr[largest]) {
            largest=right;
        }
        if (largest!=index) 
        {
            swap(arr[index],arr[largest]);
            heapify(largest);
        }
    }
    void Delete() {
        // if heap size is available or not
        if (size==0) {
            cout << "Heap Underflow:";
            return;
        }
        cout << arr[0] << "deleted from the heap";
        arr[0]=arr[size-1];
        size--;
        if (size==0) return;
        heapify(0);
    }
};

int main() {
    maxHeap h1(6);
    h1.insert(6);
    h1.insert(4);
    h1.insert(14);
    h1.Delete();
    h1.print();
    h1.insert(114);
    h1.insert(24);
    h1.insert(1);
    h1.insert(10);
    h1.Delete();
    h1.print();
    return 0;
}