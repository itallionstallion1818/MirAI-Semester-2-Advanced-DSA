#include<iostream>
#include<stack>
using namespace std;
using ll = long long;

// Tuple class to store the state of the decoded string segments
class Tuple{
    public:

    string s;   // The substring of alphabets encountered
    ll len;      // Total length of the decoded string up to this point (after multiplication)
    ll si;       // Starting index/length of the decoded string before this substring was added

    Tuple(){
        s="";
        len=0;
        si=0;
    }

};

string DecodeatIndex(string str,int k){

    stack<Tuple> s;
    ll len=0;
    Tuple t;

    for(int i=0;i<str.size();i++){

        // If the encountered element is an alphabet 
        if(isalpha(str[i])){
            t.s+=str[i];
            len++;

            // If the temporary length becomes equal to value of K, return the current element
            if(len==k){
                return string(1,str[i]);

            }
        }

        // If the encountered character is a digit
        else{
            ll digit= str[i]-'0';
            len*=digit;
            t.len=len;
            s.push(t);

            if(len>k){
                break;
            }
            t.s="";
            t.si=len;

        }
    }
    // Iterate through the stack to find the character at index k
    // We use the property that the string is periodic due to the digit multipliers
    while(!s.empty()){
        // Get the last segment added before the length exceeded or reached k
        Tuple t=s.top();
        s.pop();
        string str = t.s;
        ll si=t.si;
        ll strlen= t.s.length();
        
        // Reduce k using the modulo operator to find its equivalent position 
        // in the string before the last multiplication occurred
        if (k % (si + strlen) == 0) k = si + strlen;
        else k = k % (si + strlen);

        // If the reduced k falls within the alphabet substring 'str' of this segment
        if(k>si){
            return string(1,str[k-si-1]);
        }
    }
    return "";
}

int main() {

    string s="leet2code3";
    int k=34;

    string ans=DecodeatIndex(s,k);
    cout<<"ANSWER:  "<<ans<<endl;
    
    return 0;
}