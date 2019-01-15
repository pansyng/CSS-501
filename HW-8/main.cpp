//
//  main.cpp
//  HW 8 Ski School
//
//  Created by Pansy Ng on 11/29/18.
//  Copyright © 2018 Pansy Ng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Person{
private:
    string name;
    
public:
    Person(){
        name = "unknown";
    }
    Person(string n){
        setName(n);
    }
    string getName(){
        return name;
    }
    void setName(string name){
        this -> name = name;
    }
};
class Student:public Person{
public:
    Student():Person(){
    }
    Student(string name):Person(name){
    }
};
class Instructor:public Person{
public:
    
    Instructor():Person(){
        
    }
    Instructor(string name):Person(name){
        
    }
    vector<Student*> studentList;
};

class Supervisor: public Person{
public:
    Supervisor():Person(){
    }
    Supervisor(string name):Person(name){
    }
    vector<Instructor*> instructorList;
};

class SkiSchool{
private:
    Supervisor* root;
    int instructorWithLeastStudent(){
        int instructorLeast = 0;
        for(int i = 1; i < root -> instructorList.size(); i++){
            if(root -> instructorList[instructorLeast] -> studentList.size() < root -> instructorList[i] -> studentList.size()){
                instructorLeast = i;
            }
        }
        return instructorLeast;
    }
public:
    SkiSchool(){
        root = new Supervisor();
    }
    //insert instructor
    void insertInstructor(Instructor* in){
        root -> instructorList.push_back(in);
    }
    
    //insert student without specifying instructor
    void insertStudent(Student* s){
        //if no instructor, simply just return
        if(root -> instructorList.size() == 0){
            return;
        }
        int num = instructorWithLeastStudent();
        int numberOfStudent = root -> instructorList[num] -> studentList.size();
        // less than 5 per instructor
        if(numberOfStudent < 5){
            root -> instructorList[numberOfStudent] -> studentList.push_back(s);
        }
        //more than 5, up to 8 students per instructor
        else if(numberOfStudent == 5 && numberOfStudent < 8){
            
            for(int i = 0; i < root -> instructorList.size(); i++){
                if(root -> instructorList[i] -> studentList.size() >= 5 && root -> instructorList[i] -> studentList.size() > 8){
                    root -> instructorList[i] -> studentList.push_back(s);
                }
            }
        }
        //more than 8 students per instructor
        else{
            root -> instructorList[numberOfStudent] -> studentList.push_back(s);
        }
        
    }
    //insert student with specifying instructor
    void insertStudent(Student* s, Instructor* in){
        if(findInstructor(in->getName())){
            for(int i = 0; i < root-> instructorList.size(); i++){
                if(root -> instructorList[i] -> getName() == in -> getName()){
                    root -> instructorList[i] -> studentList.push_back(s);
                }
            }
        }
        else{
            cout << "Instructor not found!!" << endl;
        }
    }
    //remove student
    void removeStudent(Student* s){
        for(int i = 0; i < root -> instructorList.size(); i++){
            for(int j = 0; j < root -> instructorList[i] -> studentList.size(); j++){
                if(root -> instructorList[i] -> studentList[j] -> getName() == s -> getName()){
                    root -> instructorList[i] -> studentList.erase(root -> instructorList[i] -> studentList.begin() + j);
                }
            }
        }
    }
    //remove instructor
    void removeInstructor(Instructor *in){
        for(int i = 0; i < root -> instructorList.size(); i++){
            if(root -> instructorList[i] -> getName() == in-> getName()){
                vector<Student*> list1 = root -> instructorList[i] -> studentList;
                root -> instructorList.erase(root -> instructorList.begin() + i);
                for(int j = 0; j < list1.size(); j++){
                    insertStudent(list1[j]);
                }
            }
        }
    }
    //find instructor by instructor's name
    bool findInstructor(string name){
        for(int i = 0; i < root -> instructorList.size(); i++){
            if(root -> instructorList[i] -> getName() == name){
                return true;
            }
        }
        return false;
    }
    //find instructor by student's name
    bool findInstructorByStudentName(string name){
        for(int i = 0; i < root -> instructorList.size(); i++){
            for(int j = 0; j < root -> instructorList[i] -> studentList.size(); j++){
                if(root -> instructorList[i] -> studentList[j] -> getName() == name){
                    return true;
                }
            }
        }
        return false;
    }
    //prints out all teachers with all students under each teacher
    void display(){
        for(int i = 0; i < root -> instructorList.size(); i++){
            cout << "Instructor: " << root -> instructorList[i] -> getName() << endl;
            for(int j = 0; j < root -> instructorList[i] -> studentList.size(); j++){
                cout << "\tStudent: " << root -> instructorList[i] -> studentList[j] -> getName() << endl;
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    cout << "3 teachers, 19 students:" << endl;
    
    SkiSchool s1;
    
    // insert 3 instructor
    Instructor* April = new Instructor("Apil");
    Instructor* Bob = new Instructor("Bob");
    Instructor* Cathy = new Instructor("Cathy");
    s1.insertInstructor(April);
    s1.insertInstructor(Bob);
    s1.insertInstructor(Cathy);
    
    //insert 19 students
    Student* Abgail = new Student("Abgail");
    Student* Bobby = new Student("Bobby");
    Student* Cassey = new Student("Cassey");
    Student* Dominate = new Student("Dominate");
    Student* Eason = new Student("Eason");
    Student* Florence = new Student("Florence");
    Student* Gigi = new Student("Gigi");
    Student* Henry = new Student("Henry");
    Student* Ian = new Student("Ian");
    Student* Joyce = new Student("Joyce");
    Student* Kurt = new Student("Kurt");
    Student* Lawrence = new Student("Lawrence");
    Student* Mike = new Student("Mike");
    Student* Nancy = new Student("Nancy");
    Student* Oliver = new Student("Oliver");
    Student* Penny = new Student("Penny");
    Student* Queenie = new Student("Queenie");
    Student* Rick = new Student("Rick");
    Student* Sam = new Student("Sam");
    s1.insertStudent(Abgail);
    s1.insertStudent(Bobby);
    s1.insertStudent(Cassey);
    s1.insertStudent(Dominate);
    s1.insertStudent(Eason);
    s1.insertStudent(Florence, April);
    s1.insertStudent(Gigi);
    s1.insertStudent(Henry, Bob);
    s1.insertStudent(Ian, April);
    s1.insertStudent(Joyce, Cathy);
    s1.insertStudent(Kurt, Bob);
    s1.insertStudent(Lawrence, April);
    s1.insertStudent(Mike, April);
    s1.insertStudent(Nancy);
    s1.insertStudent(Oliver);
    s1.insertStudent(Penny);
    s1.insertStudent(Queenie);
    s1.insertStudent(Rick);
    s1.insertStudent(Sam);
    
    s1.display();
    

    cout << "Remove one teacher (Bob): " << endl;
    s1.removeInstructor(Bob);
    s1.display();
    

    cout << "Attempt to insert student(Tony) for the teacher (Bob) that was previously removed:" << endl;
    Student* Tony = new Student("Tony");
    s1.insertStudent(Tony, Bob);
    
    

    return 0;
}
