// Problem Statement Link - https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
public:

int *data; 
int nextIndex;
int firstIndex;
int size;
int capacity;
    
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
     
     data = new int[k];
     nextIndex = 0;
     firstIndex = -1; //firstIndex=0;
     size = 0;
     capacity = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
       
        if(isFull())
        {
        return false;
        }

        data[nextIndex] = value;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
       if(isEmpty()){
        return false;
        }
        firstIndex = (firstIndex + 1)%  capacity; // if firstIndex = 0; then capacity +1;
        size--;
      return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
         if(isEmpty()){
         return -1;
         }
    return data[firstIndex];
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
       if(isEmpty()){
         return -1;
        } 
    return data[(nextIndex+capacity-1)%capacity];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
      if(size == capacity){
          return true;
      }
       return false; 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

