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
};

int main() {
    maxHeap h1(6);
    h1.insert();
    h1.insert();
    h1.insert();
    h1.print();
    h1.insert();
    h1.insert();
    h1.insert();
    h1.insert();
    h1.print();
    return 0;
}