/*
In this I have used array to represent a HEAP
The left child of the parent is at 2*parentIdx and the right child is at 2*parentIdx+1
And for the child parent is that childIdx/2

NOTE: THE FOLLOWING CODE IS FOR 1-BASED INDEXING
      FOR 0-BASED INDEXING LEFT CHILD = 2*i+1 AND RIGHT CHILD = 2*i+2
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Heap {
    private:
        int arr[9999];
        int size = 0;

    public:
        void insert(int n){ // O(log n)
            size++;
            int idx=size;
            arr[idx]=n;
            while(idx>1){
                int parent = idx/2;
                if(arr[parent]<arr[idx]){
                    swap(arr[idx],arr[parent]);
                    idx=parent;
                } else {
                    return ;
                }
            }
        }

        void remove(){ // O(log n)
            /*
            Deletion is happening in constant amount of time 
            but the swapping of root with the new root is taking log n
            */
            if(size==0){
                cout<<"Heap is empty!"<<endl;
                return;
            }
            // replacing the root with the rightmost child (deletion)
            arr[1]=arr[size--]; // this is constant

            // take root to correct position
            int i=1;
            while(i<size){ // but this is taking log n
                int leftIndex = 2*i;
                int rightIndex = 2*i+1;
                if(leftIndex<size && arr[leftIndex] > arr[i]){
                    swap(arr[leftIndex],arr[i]);
                    i=leftIndex;
                } else if (rightIndex < size && arr[rightIndex] > arr[i]){
                    swap(arr[rightIndex],arr[i]);
                    i=rightIndex;
                } else {
                    return;
                }
            }
        }

        int top(){ // O(1)
            return arr[1];
        }

        int getSize(){ // O(1)
            return size;
        }

        void print(){ // O(n)
            for(int i=1;i<=size;i++){
                cout<< arr[i] << " ";
            }
            cout<<endl;
        }

};

void heapify(vector<int>& arr, int i,int n) {
    int largest = i;

    int left = 2 * i;       // left child
    int right = 2 * i + 1;  // right child

    // agar left child exist karta hai aur bada hai
    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }

    // agar right child exist karta hai aur sabse bada hai
    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    // agar koi child parent se bada nikla
    if (largest != i) {
        swap(arr[i], arr[largest]);  // parent aur bada child ko swap karo
        heapify(arr, largest, n);       // jahan swap hua waha phir se heapify karo
    }
}

void buildHeap(vector<int>& arr){ // O(n*log n)
    /*
    ham log leaf nodes ko check nahi karte
    kyuki uska koi child nhi hota so by default already wo heap hota hai
    leaf nodes n/2+1 -> n tk rehte hain (1 based index)
    toh internal nodes 1 -> n/2 tk rehte hain
    */
   int n = arr.size()-1;
    for(int i=n/2;i>0;i--){ // O(n)
        heapify(arr,i,n); // O(log n)
    }
}

void printHeap(vector<int>& arr){
    for(int i = 1; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(vector<int> &arr){
    buildHeap(arr);
    int size = arr.size() - 1;
    while(size>1){
        swap(arr[1],arr[size--]);
        heapify(arr,1,size);
    }
}

int main(){
    vector<int> arr = {-1,54,53,55,52,50};
    cout<<"Before heapSort the array is"<<endl;
    printHeap(arr);

    heapSort(arr);
    
    cout<<"The array after heapSort is: "<<endl;
    printHeap(arr);
    return 0;
}