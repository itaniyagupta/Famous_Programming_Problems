//

class MinStack {
 private:
    stack<int> s;
    int min;
   public:
    /** initialize your data structure here. */
    MinStack() {
     min = INT_MAX;    
    }
    
    void push(int x) {
     if (x <= min)
        {
            s.push(min);
            min = x;
        }
        s.push(x);
    }
    
    void pop() {
      if (s.top() == min)
        {
            s.pop();
            min = s.top();
            s.pop();
        }
        else
        {
            s.pop();
        }
       
        
    }
    
    int top() {
        return s.top();
          
    }
    
    int getMin() {
     
      return min;
        
//  using two stacks
//        private:
//     stack<int> s1;    
//     stack<int> s2;   //for containing min value at top 
//     public:
//     void push(int x) {
// 	    s1.push(x);
// 	    if(s2.empty() || x<=s2.top()) s2.push(x);	    
//     }
//     void pop() {
// 	    if(s1.top()==s2.top()) s2.pop();
// 	    s1.pop();
//     }
//     int top() {
// 	    return s1.top();
//     }
//     int getMin() {
// 	    return s2.top();
//     }
        
        
        
    }
};