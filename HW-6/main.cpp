//
//  main.cpp
//  HW 6 - Polymorphism
//
//  Created by Pansy Ng on 11/6/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//Parent class: Person
class Person{
//private instance variables
private:
    string name;
    int age;
    string gender;
public:
    //Contructor
    Person(){
        name = "unknown";
        age = -1;
        gender = "unknown";
    }
    //Overloaded Constructor
    Person(string n, int a, string g){
        setName(n);
        setAge(a);
        setGender(g);
    }
    
    //Getter
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getGender(){
        return gender;
    }
    
    //Setter
    void setName(string n){
        if(n != ""){
            name = n;
        }
        else{
            cout << "cannot be empty" << endl;
            name = "unknown";
        }
    }
    void setAge(int a){
        if(a >= 0 && a <= 125){
            age = a;
        }
        else{
            cout << "invalid age" << endl;
            age = 0;
        }
    }
    void setGender(string g){
        if(g != ""){
            gender = g;
        }
        else{
            cout << "cannot be empty" << endl;
            gender = "unknown";
        }
    }
    
    //pure virtual function
    virtual string IDNumber() = 0;
    
    //virtual function
    virtual void print(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Employee;
//Child 1 class: Student
class Student: public Person{
//private instance variable
private:
    string major;
    int studentNumber;
    friend class Employee;
public:
    //Constructor
    Student(string n, int a, string g, string m, int sn): Person(n, a, g){
        setStudentNumber(sn);
        setMajor(m);
    }
    
    string getMajor(){
        return major;
    }
    
    void setMajor(string m){
        if(m != ""){
            major = m;
        }
        else{
            cout << "invalid major name" << endl;
            major = "unknown";
        }
    }
    
    
    string IDNumber()override{
        return to_string(studentNumber);
    }
    
    int getStudentNumber(){
        return studentNumber;
    }
    
    void setStudentNumber(int sn){
        if(sn > 0){
            studentNumber = sn;
        }
        else{
            cout << "invalid student number" << endl;
            studentNumber = 0;
        }
    }
    
    bool isEqual(Student& t){
        return (studentNumber == t.studentNumber);
    }
    
    void print() override{
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Gender: " << getGender() <<endl;
        cout << "Major: " << getMajor() << endl;
        cout << "Student Number: " << studentNumber << endl;
        
    }
    bool isSameNumber(Employee& e);
};


//Child 2 class: Employee
class Employee: public Person{
//private instance variables
private:
    int employeeNumber;
    string department;
public:
    Employee(int en, string d, string n, int a, string g): Person(n, a, g){
        setEmployeeNumber(en);
        setDepartment(d);
        
    }
    int getEmployeeNumber(){
        return employeeNumber;
    }
    void setEmployeeNumber(int e){
        if(e > 0)
            employeeNumber = e;
        else{
            cout << "invalid employee number" << endl;
            employeeNumber = 0;
        }
    }
    string IDNumber() override{
        return to_string(employeeNumber);
    }
    
    string getDepartment(){
        return department;
    }
    void setDepartment(string d){
        if(d != "")
            department = d;
        else{
            cout << "invalid department name" << endl;
            department = "unknown";
        }
    }
    friend bool Student::isSameNumber(Employee& e);
    
    bool isEqual(Student& s){
        return department == s.major;
    }
    void print() override{
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Gender: " << getGender() <<endl;
        cout << "Department: " << getDepartment() << endl;
        cout << "Employee Number: " << getEmployeeNumber() << endl;
        
    }
    
};
bool Student:: isSameNumber(Employee& e){
    return e.employeeNumber == studentNumber;
}

//GrandChild class: StudentHelper
class StudentHelper: public Student, public Employee{
private:
    int workHours;
public:
    StudentHelper(string n, int a, string g, string m, int sn, string d, int en, int w):Student(n, a, g, m, sn), Employee(en, d, n, a, g){
        setWorkHours(w);
    }

    int getWorkHours(){
        return workHours;
    }
     
    void setWorkHours(int w){
        if(w > 0){
            workHours = w;
        }
        else{
            cout << "invalid work hours" << endl;
            workHours = 0;
        }
    }
    
    string IDNumber()override {
        string num = to_string(getStudentNumber()) + ", " + to_string(getEmployeeNumber());
        return num;
    }
    
    void print() override{
        Student::print();
        cout << "Department: " << getDepartment() << endl;
        cout << "Employee Number: " << getEmployeeNumber() << endl;
        cout << "Hours worked: " << getWorkHours() << endl;
    }
};


//Driver
int main(int argc, const char * argv[]) {
    //Functional Positive Testing
    Student s1 = Student("Peter", 21, "male", "computer science", 1111);
    Employee e1 = Employee(3111, "Admission Office", "Jacky", 47, "female");
    StudentHelper sh1 = StudentHelper("Jacky", 21, "female", "mathematics", 1113, "Student Housing", 3112, 23);
    
    //Functional Negative Testing
    Student s2 = Student("", -1, "", "", -1);
    Employee e2 = Employee(-1, "", "", -1, "");
    StudentHelper sh2 = StudentHelper("", -1, "", "", -1, "", -1, -1);
    
    //public method
    Student s4 = Student("Jenny", 18, "female", "economics", 1110);
    Student s3 = Student("Peter", 21, "male", "computer science", 1111);
    s1.print();
    cout << s1.IDNumber() << endl;
    e1.print();
    cout << e1.IDNumber() << endl;
    sh1.print();
    cout << sh1.IDNumber() << endl;
    if (s1.isEqual(s3)){
        cout << "same student number" << endl;
    }

    if(s1.isSameNumber(e1)){
        cout << "same number" << endl;
    }
    else{
        cout << "different number" <<endl;
    }
    
    s1.setMajor("Classic");
    s1.getMajor();
    s1.setStudentNumber(4352);
    s1.getStudentNumber();
    e1.setDepartment("Fiscal Services");
    e1.getDepartment();
    e1.setEmployeeNumber(3412);
    e1.getEmployeeNumber();
    sh1.setWorkHours(32);
    sh1.getWorkHours();
}
