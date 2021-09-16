class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }

    private:
        stack<int> s1;
        stack<int> s2;
};


//队列----->栈
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        q1 = new queue<int>;
        q2 = new queue<int>;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1->push(x);
        while(!q2->empty())
        {
            q1->push(q2->front());
            q2->pop();
        }
        queue<int> *p = q1;
        q1 = q2;
        q2 = p;

    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = q2->front();
        q2->pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return q2->front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q2->empty();
    }
private:
    queue<int> *q1;
    queue<int> *q2;
};