// Problem Statement Link - https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
    stack<int> stackNewest, stackOldest;
private:
    void shiftStacks() {
        if (stackOldest.empty()) 
        {
            while (!stackNewest.empty())
            {
              stackOldest.push(stackNewest.top());
              stackNewest.pop();
            }
        }
    }
public:
    /** Initialize your data structure here. */
    // MyQueue() {
    //     stackNewest = new stack<int>();
    //     stackOldest = new stack<int>();
    // }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stackNewest.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shiftStacks();
        int x = stackOldest.top();
        stackOldest.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        shiftStacks(); 
        return stackOldest.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stackOldest.empty() && stackNewest.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */