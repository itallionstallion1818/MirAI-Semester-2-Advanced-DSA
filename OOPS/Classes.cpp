#include<iostream>
using namespace std;

class Car{
    // Private
    private:
    int price;
    public:
        char * name;
        // int price;
        int model;

    // Default Constructor;
    Car(){
        name=NULL;
    }

    // Parameterized Constructor
    Car(char *n,int p,int m){
        cout<<"Inside the parameterised constructor-1"<<endl;
        name= new char[strlen(n)+1];
        strcpy(name,n);
        price=p;
        model=m;
    }

    Car(Car &X){
        cout<<"Inside the copy constructor"<<endl;
        name=new char[strlen(X.name)];
        strcpy(name,X.name);
        price=X.price;
        model=2015;
    }

    // Car(char *n,int p){
    //     cout<<"Inside parameterised constructor-2"<<endl;
    //     strcpy(name,n);
    //     price=p;
    // }

    // Example of a parameterised constructor
    // Car(string s){
    //     strcpy(name,"MARUTI");
    //     price=10000;
    //     model=2026;
    // }


    // Setters
    void setPrice(int p){
        if(p<0){
            price=0;
            cout<<"Invalid value of price."<<endl;
        }
        else{
            price=p;

        }
    }

    // GETTER
    int getprice(){
        cout<<"Inside a getter function";
        return price;
    }


    void print(){
        cout<<"THE NAME: "<<name<<endl;
        cout<<"THE PRICE: "<<price<<endl;
        cout<<"THE MODEL: "<<model<<endl;

    }

    //Destructor
    ~Car(){
        cout<<"Inside the destructor"<<endl;
    }

    
};

int main(){
        Car A("BMW",5000000,2026);
        A.print();
        cout<<endl;
        // 1 Car B=A;
        // 2 Car B(A);
        // A.price=300000;
        // Car C;
        // C.setPrice(10000);
        Car B=A;
        
        // cout<<C.getprice()<<endl;
        B.name[0]='X';

        A.print();
        cout<<"PRINTING B: "<<endl;
        B.print();
        // B.price=3000;
        // B.print();


    return 0;
}