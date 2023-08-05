#include "StudentNode.h"

StudentNode::StudentNode(){
    fullName = " "; 
    country = " "; 
    city = " "; 
    gender = ' '; 
    gpa = 999.99; 
    next = NULL; 
} 
StudentNode::StudentNode(const string f, const string c, const string cy, const string g, const float gp, StudentNode * n){
    fullName = f; 
    country = c; 
    city = cy; 
    gender = g; 
    gpa = gp; 
    next = n; 
}
StudentNode::StudentNode(const StudentNode & copy){
    fullName = copy.fullName; 
    country = copy.country; 
    city = copy.city; 
    gender = copy.gender; 
    gpa = copy.gpa; 
}
StudentNode::~StudentNode(){
    
} 

string StudentNode::getFullName() const{
    return fullName; 
} 
string StudentNode::getCountry() const{
    return country; 
} 
string StudentNode::getCity() const{
    return city; 
}
string StudentNode::getGender() const{
    return gender; 
} 
float StudentNode::getGpa() const{
    return gpa; 
} 
StudentNode * StudentNode::getNext() const{
    return next; 
} 

void StudentNode::setFullName(const string f){
    fullName = f; 
} 
void StudentNode::setCountry(const string c){
    country = c; 
} 
void StudentNode::setCity(const string cy){
    city = cy; 
} 
void StudentNode::setGender(const string g){
    gender = g; 
}
void StudentNode::setGpa(const float gp){
    gpa = gp; 
} 
void StudentNode::setNext(StudentNode * n){
    next = n; 
} 

void StudentNode::print() const{
    //cout << endl; 
    cout << fullName << "," << country << "," << city << "," << gender << "," << gpa << endl; 
}