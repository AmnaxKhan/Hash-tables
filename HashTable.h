#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <cstdlib>

#include "StudentList.h"

using namespace std;

class HashTable
{
 public:
  // Constructors
  HashTable(int size);
  HashTable(const HashTable & ht);
  ~HashTable();

  // Methods
  void Insert(string key, string country, string city, string gender, float gpa);
  bool Search(string key);
  void Delete(string key, string country, string city, string gender, float gpa);
  bool Update(string key, string country, string city, string gender, float gpa, float newgpa); 
  void Print();
  void printStat(); 

 private:
  // Private methods
  int Hash(string key);

  // Private data
  //count, size,collisions and hashtable
  int Size;
  StudentList *Table;
  int count; 
  int collisions; 
};

#endif