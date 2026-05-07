#include<iostream>
using namespace std;


class Student{
    private:
    int studentID;
    string name;
    string address;
    string branch;
    bool isHosteler;

    public:
    //SETTERS
    void setID(int i){
        if(i<0){
            cout<<"Error: ID cannot be negative. Setting ID to 0."<<endl;
            studentID=0;
        }else{
            studentID=i;
        }
        
    }
    void setname(string s){
        name=s;
    }
    void setaddress(string s){
        address=s;
    }
    void setbranch(string s){
        branch=s;
    }
    void Hosteler(bool h){
        isHosteler=h;
    }

    // GETTERS
    int getStudentID(){
        return studentID;
    }
    string getname(){
        return name;
    }
    string getaddress(){
        return address;
    }
    string getbranch(){
        return branch;
    }
    bool Hosteler(){
        return isHosteler;
    }

    // Default Constructor
    Student(){
        cout<<"Default Constructor Called"<<endl;
        studentID=0;
        name="Not Provided";
        address="Not Provided";
        branch="Not Provided";
        isHosteler=false;
    }

    // Parameterised constructor-1;
    Student(int i, string n){
        if(i<0){
            studentID=0;
        }else{
            studentID=i;
        }
        name=n;
        address="Not Provided";
        branch="Not Provided";
        isHosteler=false;
    }

    // Parameterised Constructor-2
    Student(int i, string n,string b){
        if(i<0){
            studentID=0;
        }else{
            studentID=i;
        }
        name=n;
        branch=b;
        address="Not Provided";
        isHosteler=false;
    }

    // Parameterised Constructor-3
    Student(int i, string n,string b, string a,bool h){
        if(i<0){
            studentID=0;
        }else{
            studentID=i;
        }
        name=n;
        branch=b;
        address=a;
        isHosteler=h;
    }

    void displayProfile(){
        cout<<"The student ID is: "<<studentID<<endl;
        cout<<"The student name is: "<<name<<endl;
        cout<<"The student branch is: "<<branch<<endl;
        cout<<"The student address is: "<<address<<endl;
        if(isHosteler){
            cout<<"The student is a Hosteler"<<endl;
        }else{
            cout<<"The student is a Day Scholar"<<endl;
        }
    }


    // Copy Constructor
    Student(Student &X){
        cout<<"Copy Constructor Called";
        studentID=X.studentID;
        name=X.name;
        branch=X.branch;
        address=X.address;
        isHosteler=X.isHosteler;
    }

    ~Student(){
        cout<<"Record for "<<name<<" is being destroyed"<<endl;
    }

};


int main(){
    Student s1;

    s1.setID(-105);
    s1.setname("Raju");
    s1.setbranch("ECE");
    s1.setaddress("Delhi");
    s1.Hosteler(true);

    s1.displayProfile();

    cout<<endl;
    Student s2(120,"Dinker","DATA");
    s2.displayProfile();

    Student s3(113,"Adi","CSE","DELHI",false);
    cout<<endl;
    s3.displayProfile();
    cout<<endl;
    Student s4=s3;

   
    cout<<endl;
    s4.displayProfile();
    return 0;
}