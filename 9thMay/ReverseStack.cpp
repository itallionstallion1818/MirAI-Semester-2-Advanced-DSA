#include<iostream>
#include<stack>
using namespace std;

// Helper function to insert an element at the bottom of the stack
void putinposition(stack<int>&s,int topE){
    // Base Case: If the stack is empty, we've reached the bottom
    if(s.empty()){
        s.push(topE);
        return;
    }

    // Recursive Step:
    // 1. Hold the current top element
    int top=s.top();
    s.pop();
    
    // 2. Recursively call to reach the bottom
    putinposition(s,topE);
    
    // 3. Once topE is at the bottom, push the held elements back on top
    s.push(top);
}

// Main recursive function to reverse the stack
void reverseStack(stack<int> &s){
    // BASE CASE: If stack is empty, nothing to reverse
    if(s.empty()){
        return;
    }

    // 1. Pop the top element and store it (topE)
    int topE=s.top();
    s.pop();
    
    // 2. Recursively reverse the remaining stack
    reverseStack(s);
    
    // 3. Insert the stored element (topE) at the bottom of the reversed stack
    putinposition(s,topE);
}

int main(){
    // Initializing a stack with some values
    stack<int>s;
    s.push(1);   // Bottom
    s.push(222); 
    s.push(33);  
    s.push(0);   // Top

    // Displaying the original stack (using a copy to preserve 's')
    stack<int>s1=s;
    cout << "ORIGINAL STACK (Top to Bottom):" << endl;
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }

    // Reversing the stack in-place using recursion
    reverseStack(s);
    
    cout<<endl;
    cout<<"REVERSED STACK (Top to Bottom):"<<endl;
    // Displaying the reversed stack
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}