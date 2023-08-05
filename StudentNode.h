#ifndef STUDENTNODE_H
#define STUDENTNODE_H

#include <iostream>
using namespace std; 

class StudentNode{
    public: 
    StudentNode(); 
    StudentNode(const string f, const string c, const string cy, const string g, const float gp, StudentNode * n); 
    StudentNode(const StudentNode & copy);
    ~StudentNode(); 
    
    string getFullName() const; 
    string getCountry() const; 
    string getCity() const; 
    string getGender() const; 
    float getGpa() const; 
    StudentNode * getNext() const; 
    
    void setFullName(const string f); 
    void setCountry(const string c); 
    void setCity(const string cy); 
    void setGender(const string g); 
    void setGpa(const float gp); 
    void setNext(StudentNode * n); 
    
    void print() const; 
    
    private: 
    string fullName; 
    string country; 
    string city; 
    string gender; 
    float gpa; 
    StudentNode * next; 
}; 

#endif