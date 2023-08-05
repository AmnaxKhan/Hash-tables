//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "HashTable.h"

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
   Size = size;
   Table = new StudentList[Size];
   collisions = 0; 
   count = 0; 
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable & ht)
{
   Size = ht.Size;
   Table = new StudentList[Size];
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
   Size = 0;
   delete [] Table;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
void HashTable::Insert(string key, string country, string city, string gender, float gpa)
{
   // Find hash index
   int index = Hash(key);

   Table[index].insertNode(key, country, city, gender, gpa);
   count++; 
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::Search(string key)
{
   // Find hash index
   int index = Hash(key);
   
   return Table[index].search(key);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
void HashTable::Delete(string key, string country, string city, string gender, float gpa)
{
   // Find hash index
   int index = Hash(key);
   
   Table[index].deleteNode(key, country, city, gender, gpa);
}
//-----------------------------------------------------------
// Update method
//-----------------------------------------------------------
bool HashTable::Update(string key, string country, string city, string gender, float gpa, float newgpa){
    int index = Hash(key); 
    
    return Table[index].updateGPA(key, country, city, gender, gpa, newgpa); 
} 

//-----------------------------------------------------------
// Primary hash function
//-----------------------------------------------------------
int HashTable::Hash(string key)
{
   long int num = 13;
   for (int i = 0; i < int(key.length()); i++)
      num = ((num * 7 + key[i]) % Size);
      
   return num;
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
   for (int index=0; index<Size; index++)
   {
       cout << index << endl;
      Table[index].printAll();
   }

}
void HashTable::printStat()
{
    //StudentList list; 
    cout << "Count: " << count << endl; 
    cout << "Size: " << Size << endl; 
    int totalCollisions = 0;
    for (int i = 0; i < Size; i++){
        totalCollisions += Table[i].getCollisions();
    }
    cout << "Collisions: " << totalCollisions << endl; 
}