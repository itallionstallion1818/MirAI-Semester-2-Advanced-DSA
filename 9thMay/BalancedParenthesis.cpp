#include<iostream>
#include<stack>
using namespace std;

bool isbalanced(string str){
    stack<char>s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('|| str[i]=='[' || str[i]=='{'){
            s.push(str[i]);
        }
        // Checking for circular closing bracket
        if(str[i]==')'){
            // For a circular bracket ')', we check if the stack is not empty 
            // and if the top element is its matching pair '('
            if(!s.empty() && s.top()=='('){
                s.pop();
            }else{
                // If stack is empty or top is not '(', the string is unbalanced
                return false;
            }
        }
        if(str[i]==']'){
            // Case: Closing square bracket ']'
            // Check for non-empty stack and matching opening '['
            if(!s.empty() && s.top()=='['){
                s.pop();
            }else{
                // Mismatch or empty stack means unbalanced
                return false;
            } 
        }
        if(str[i]=='}'){
            // Case: Closing curly brace '}'
            // 1. Check if stack is NOT empty (to avoid underflow)
            // 2. Check if the top of the stack is the matching opening brace '{'
            if(!s.empty() && s.top()=='{'){
                // If matched, remove the opening brace from the stack
                s.pop();
            }else{
                // If stack is empty (no opening brace) or top is a mismatch, it's unbalanced
                return false;
            } 
        }
    }
    // If stack is empty, all brackets were matched correctly
    return s.empty();
}

int main(){
    string s="}}}}";
    if(isbalanced(s)){
        cout<<"BALANCED";
    }
    else{
        cout<<"UNBALANCED";
    }
    return 0;
}