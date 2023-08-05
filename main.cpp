#include <iostream>
#include <fstream>

#include "StudentNode.h"
#include "HashTable.h"


void readFile(const string filename, HashTable &hash) {
    // open file, check if failed
    ifstream din;
    din.open(filename.c_str());

    if (din.fail()) {
        cout << "Error; file " << filename << " could not be opened" << endl;
        return;
    }

    // declare local temp. class variables for reading data
    string fullName;
    string country; 
    string city; 
    string Gender; 
    string GPA; 
    
    int numOfStudents = 0; 
    while (!din.eof()) {
        //4 delimited get lines and then a regular getline
        //int num = stoi(str) to convert string to integer 
        //stof is from string to float
        getline(din, fullName, ','); 
        getline(din, country, ','); 
        getline(din, city, ','); 
        getline(din, Gender, ','); 
        getline(din, GPA); 
        
        hash.Insert(fullName, country, city, Gender, stof(GPA)); 
        
        
        numOfStudents++; 
    }
    din.close();
}

int main()
{
    HashTable hash(120); 
    bool programExit = false; 
    readFile("student-database.txt", hash); 
    while(programExit == false){
        cout << "---------------------------------------" << endl; 
        cout << "Welcome to the Student Database" << endl; 
        cout << "---------------------------------------" << endl; 
        cout << "Choose one of the following: " << endl; 
        cout << "1. Insert " << endl; 
        cout << "2. Delete " << endl; 
        cout << "3. Update " << endl; 
        cout << "4. Search " << endl; 
        cout << "5. Print " << endl; 
        cout << "6. Exit " << endl; 
        cout << "---------------------------------------" << endl; 
        
        int userInput; 
        cin >> userInput; 
        
        string fullName; 
        string Country; 
        string city; 
        string gender; 
        string GPA; 
        string newgpa; 
        //float gpa; 
        cin.ignore(); 
        switch (userInput){
            case 1: 
                cout << "Enter full name: " << endl;
                getline(cin, fullName); 
                cout<< "Enter country: " <<endl; 
                getline(cin, Country); 
                cout << "Enter city: " << endl; 
                getline(cin, city); 
                cout << "Enter gender (F/M): " << endl;
                getline(cin, gender); 
                cout << "Enter gpa: " << endl; 
                getline(cin, GPA); 
                hash.Insert(fullName, Country, city, gender, stof(GPA)); 
                break; 
            case 2: 
                cout << "Enter full name: " << endl;
                getline(cin, fullName); 
                cout<< "Enter country: " <<endl; 
                getline(cin, Country); 
                cout << "Enter city: " << endl; 
                getline(cin, city); 
                cout << "Enter gender (F/M): " << endl;
                getline(cin, gender); 
                cout << "Enter gpa: " << endl; 
                getline(cin, GPA); 
                hash.Delete(fullName, Country, city, gender, stof(GPA)); 
                break; 
            case 3: 
                cout << "Enter full name: " << endl;
                getline(cin, fullName); 
                cout<< "Enter country: " <<endl; 
                getline(cin, Country); 
                cout << "Enter city: " << endl; 
                getline(cin, city); 
                cout << "Enter gender (F/M): " << endl;
                getline(cin, gender); 
                cout << "Enter old gpa: " << endl; 
                getline(cin, GPA); 
                cout << "Enter updated gpa: "; 
                getline(cin, newgpa); 
                if(hash.Update(fullName, Country, city, gender, stof(GPA), stof(newgpa))==true){
                    cout << "Student gpa has been updated!" << endl;
                }
                else{
                    cout << "Update failed. " << endl; 
                }
                break; 
             
            case 4: 
                cout << "Enter full name: " << endl;
                getline(cin, fullName);
                if(hash.Search(fullName) == true){
                    cout << "Student found. " << endl; 
                }
                else{
                    cout << "Student Not found" << endl; 
                }
            break; 
            case 5: 
                hash.Print(); 
                break; 
            case 6: 
                programExit = true; 
                hash.printStat(); 
                return 0; 
                break; 
            default: 
                cout << "This is not an option. Please try again. " << endl;
                break; 
        }
    }
    return 0;
}
