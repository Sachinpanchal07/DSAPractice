#include<iostream>
using namespace std;

// class Student
// {
//      // If we not define access modifier then by default will be private.
//     string name;
//     int age;

//     public:
//     void set_name(string name1){ // Setter
//         name = name1;
//     }
    
//     void set_age(int age1){
//         if(age1 > 18 && age1 < 70){
//             age = age1;
//         }
//         else{
//             cout << "invalid age" << endl;
//         }
//     }

//     string get_name(int password){ // Getter, if password is correct then it will return name.
//         if(password == 123){
//             return name;
//         }
//         return "";
//     }

//     int get_age(){
//         return age;
//     }
// };

// int main(){
//     Student s1;
//     // s1.name = "john"; // if public then access is direct.
//     // s1.age = 30;

//     // Student s2;
//     // s2.name = "brok";
//     // s2.age = 32;

// // if Access modifier are private then GETTER, SETTER used to get and set the data.

// s1.set_name("sachin");
// s1.set_age(2);

// cout << s1.get_age() << endl;
// cout << s1.get_name(123) << endl;
   
// }



// +++++++++++++++++++++++++++++++++++++++++++++++++ constructor +++++++++++++++++++++++++++++++++++++++++++

// class Customer{
//     string name;
//     int balance;
//     int account_number;
    
//     // +++++++++++++++++ defatult construtor.+++++++++

//      public:
//     Customer(){
//         name = "sachin";
//         balance = 1000;
//         account_number  = 123;
//     }

//     // ++++++++++++  parameterize constructor. +++++++++

//     // Customer(string name, int balance, int account_number){
//     //     this->name = name;
//     //     this->balance = balance;
//     //     this->account_number = account_number;
//     // }

//     // +++++++++++++++ constructor overriding. +++++++++++

//     Customer(string name, int balance){
//         this->name = name;
//         this->balance = balance;
//         account_number = 789; // default value
//     }

//     // ++++++++++++++++ inlilne constructor ++++++++++++++++++++

//     Customer(string a, int b, int c): name(a),balance(b), account_number(c){
//     }

//     // ++++++++++++++ copy constructor ++++++++++++++++++++

//     Customer(Customer &B){ // this '&' symbol is representing the passed by memory address of object.
//         name = B.name;
//         balance = B.balance;
//         account_number = B.account_number;
//     }

//     void display(){
//         cout << name << " " << balance << " " << account_number << endl;
//     }
// };

// int main(){
//     Customer A1;
//     Customer A2("hardik", 2000, 456);
//     Customer A3("parveen", 3000);
//     Customer A4(A3); // copy constructor, copy A3 in A4.
//     Customer A5;
//     A5 = A3; //  copy constructor, copy A4 in A5, by diff method.

//     A1.display();
//     A2.display();
//     A3.display();
//     A5.display(); 
// }

// ++++++++++++++++++++++++++++++++++++++++++++++++ Destructor +++++++++++++++++++++++++++++++++++++++++++++

// class Customer {
//     string name;
//     int *balance;

//     public:
//     Customer(){
//         name = "sachin";
//         balance = new int;
//         *balance = 10;
//         cout << "constructor is called" << endl;
//     }
    
//     ~Customer(){
//         delete balance;
//         cout << "destructor is called" << endl;
//     }
// };

// int main(){
//     Customer A1;
// }

// +++++++++++++++++++++++++++++++++++++++ static data memeber +++++++++++++++++++++++++++++++++++++++

class Customer{
    string name;
    int balance;
    static int total_customer; // this is class attribute, we can also access this with only use of class without object

    public:

    Customer(string name, int balance){
        this->name = name;
        this->balance = balance;
        total_customer++;
    }

    static void accessStatic(){ // Can only access static data member
        cout << total_customer << endl;
    }

    void display(){
        cout << name <<endl;
        cout << balance << endl;
        cout << total_customer << endl;
    }
};
int Customer::total_customer = 0; // always intialize here 

int main(){
    Customer A1("sachin", 1000);
    Customer A2("hardik", 2000);
    A1.display();
    A2.display(); 
    Customer::accessStatic();  // only class can access these static function.
    // this code is also example of encapsulation and abstraction 
}