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

// +++++++++++++++++++++++++++++++++++++++++++++++++ static data memeber ++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// class Customer{
//     string name;
//     int balance;
//     static int total_customer; // this is class attribute, we can also access this with only use of class without object

//     public:

//     Customer(string name, int balance){
//         this->name = name;
//         this->balance = balance;
//         total_customer++;
//     }

//     static void accessStatic(){ // Can only access static data member
//         cout << total_customer << endl;
//     }

//     void display(){
//         cout << name <<endl;
//         cout << balance << endl;
//         cout << total_customer << endl;
//     }
// };
// int Customer::total_customer = 0; // always intialize here 

// int main(){
//     Customer A1("sachin", 1000);
//     Customer A2("hardik", 2000);
//     A1.display();
//     A2.display(); 
//     // Customer::total_customer = 5; // we can do that but we have to make this variable public.
//     Customer::accessStatic();  // only class can access these static function.
//     // this code is also example of encapsulation and abstraction 
// }

//+++++++++++++++++++++++++++++++++++++++ Access modifier ++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// class Human{
//     private:
//     int a;
//     protected:
//     int b;
//     public:
//     int c;

//     void display(){
//         a = 10;
//         b = 20; 
//         c = 30;
//         cout << a << b << c;
//     }
// };
// int main(){
//     Human Obj1;
//     // Obj1.a = 10; // error
//     // Obj1.b = 10  // error
//     // Obj1.c = 10; // ok
//     Obj1.display();
// }

// +++++++++++++++++++++++++++++++++++++++++++++++++++ inheritance +++++++++++++++++++++++++++++++++++++++++++++++++++++++

// // Base class or parent class
// class Human{ 
//     // private:
//     // protected:
//     public:
//     string name;
//     int age;

//     public:

//     void settter(string name, int age ){
//         this->name = name;
//         this->age = age;
//     }
//     void display(){
//         cout << name << " " << age;
//     }
// };

// // Derived class or child class
// class Student: protected Human{
//     public:
//     int roll_no;
// };

// int main(){
//     Student S1;
//     // S1.roll_no = 5;
//     // S1.name = "sachin";
//     // S1.age = 2;
// }


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// class Human{ 
//     private:
//     string religion, color;

//     protected:
//     string name;
//     int age;  
// };

// class Student: protected Human{
//     protected:
//     int roll_no, weight;

//     public:
//     Student(string name, int age, int roll_no, int weight){
//         this->name = name;
//         this->age =age;
//         this->roll_no = roll_no;
//         this->weight = weight;
//     }

//     public:
//     void display(){
//         cout << name << " age is " << age << " roll no. is " << roll_no << " weight is " << weight;
//     }
// };

// int main(){
//     Student S1("john", 33, 44, 100);
//     S1.display();
   
// }

// ++++++++++++++++++++++++++++++++++++++++++++++++ Single Inheritance +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// class Human{
//     protected:
//     string name;
//     int age;

//     public:
//     Human(string name, int age){
//         this->name = name;
//         this->age = age;
//     }

//     void display(){
//         cout << name << " " << age;
//     }
// };
// class Student: public Human{
//     int roll_no, fees;

//     public:
//     Student(string name, int age, int roll_no, int fees):Human(name, age){ // always first parnet class constructor will be called then child class construtor will be called.
//         this->roll_no = roll_no;
//         this->fees = fees;
//     }

//     void display(){
//         cout << name << " " << age << " " << roll_no<<" "<< fees;
//     }
// };

// int main(){
//     Student S1("jhon", 30, 94, 2000);
//     S1.display();
// }

// ++++++++++++++++++++++++++++++++++++++++++++++++ multilevel Inheritance +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class Person{

    protected:
    string name;
};
class Employe: public Person{
    protected:
    int salary;
};

class Manager: public Employe{
    protected:
    string department;

    public:
    Manager(string name, int salary, string department){
        this->name = name;
        this->salary = salary;
        this->department = department;
    }

    void display(){
        cout << "my name is " << name << " and my salary is " << salary<< " of department " << department;
    }
};

int main(){
    Manager A1("sachin", 100000, "IT");
    A1.display();
    
}

