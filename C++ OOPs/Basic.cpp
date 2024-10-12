#include<iostream>
using namespace std;

class Student
{
     // If we not define access modifier then by default will be private.
    string name;
    int age;

    public:
    void set_name(string name1){ // Setter
        name = name1;
    }
    
    void set_age(int age1){
        if(age1 > 18 && age1 < 70){
            age = age1;
        }
        else{
            cout << "invalid age" << endl;
        }
    }

    string get_name(int password){ // Getter, if password is correct then it will return name.
        if(password == 123){
            return name;
        }
        return "";
    }

    int get_age(){
        return age;
    }
};

int main(){
    Student s1;
    // s1.name = "john"; // if public then access is direct.
    // s1.age = 30;

    // Student s2;
    // s2.name = "brok";
    // s2.age = 32;

// if Access modifier are private then GETTER, SETTER used to get and set the data.

s1.set_name("sachin");
s1.set_age(2);

cout << s1.get_age() << endl;
cout << s1.get_name(123) << endl;
   
}