#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <iostream> 
#include "StudentNode.h"
using namespace std; 

class StudentList{
    public: 
    StudentList(); 
    StudentList(const StudentList & copy); 
    ~StudentList(); 
    
    //insert, delete, update, search, and print methods.
    void insertNode(const string f, const string c, const string cy, const string g, const float gp);
    void deleteNode(const string f, const string c, const string cy, const string g, const float gp);
    bool updateGPA(const string f, const string c, const string cy, const string g, const float gp, const float newgpa);  
    bool search(const string f) const;
    void printAll() const; 
    int getCollisions() const; 
    
    private: 
    StudentNode * head; 
    int collisions; 
}; 

#endif