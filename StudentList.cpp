#include "StudentList.h"

StudentList::StudentList(){
    head = NULL; 
    collisions = 0; 
}
StudentList::StudentList(const StudentList & copy){
    StudentNode * temp = copy.head;
    while(temp != NULL)
    {
        insertNode(temp->getFullName(), temp->getCountry(), temp->getCity(), temp->getGender(), temp->getGpa());
        temp = temp->getNext();
    }
}
StudentList::~StudentList(){
    StudentNode * temp = head;
    while(temp != NULL)
    {
        head = head->getNext();
        delete temp;
        temp = NULL;
        temp = head;
    }
}

//insert, delete, update, search, and print methods.
void StudentList::insertNode(const string f, const string c, const string cy, const string g, const float gp){
    // StudentNode * temp = new StudentNode(f, c, cy, g, gp, head);
    // head = temp; 
    collisions = 0; 
    StudentNode *curr = head;
    StudentNode *prev = head;
    while(curr != NULL)
    {
        prev = curr;
        curr = curr->getNext();
        collisions++; 
    }
    StudentNode * temp = new StudentNode(f, c, cy, g, gp, head);
    temp->setNext(curr);
    if(curr == head)
        head = temp;
    else
        prev->setNext(temp);
}
int StudentList::getCollisions() const {
    return collisions; 
}
void StudentList::deleteNode(const string f, const string c, const string cy, const string g, const float gp){
    StudentNode *curr = head;
    StudentNode *prev = NULL;

    while(curr != NULL && curr->getFullName() != f)
    {
        prev = curr;
        curr = curr->getNext();
    }
    if(curr != NULL && curr == head) //delete first item
    {
        head = curr->getNext();
    }
    else if(curr != NULL)
    {
        prev->setNext( curr->getNext() );
        //prev->next = prev->next->next;
    }
    delete curr;
    curr = NULL;
}
bool StudentList::updateGPA(const string f, const string c, const string cy, const string g, const float gp, const float newgpa){
    StudentNode * temp = head; 
    //bool found = false; 
    while(temp!=NULL){
        if (temp->getFullName() == f && temp->getCountry() == c && temp-> getCity() == cy && temp->getGender() == g && temp->getGpa() == gp){
            temp->setGpa(newgpa); 
            //cout << "Price has been updated!" << endl; 
            return true; 
        }
        temp = temp->getNext(); 
    }
    // if (found == false){
    //     cout << "This information does not match any meal in the database. Price update failed!"; 
    // }
    return false;
}  
bool StudentList::search(const string f) const{
    StudentNode * temp = head;
    while(temp != NULL && temp->getFullName() != f)
        temp = temp->getNext();
    if(temp != NULL)
        return true;
    else
        return false;
}
void StudentList::printAll() const{
    StudentNode *temp = head; 
     
    while(temp!= NULL){
        temp->print();  
        temp = temp->getNext(); 
    }

}