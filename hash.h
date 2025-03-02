#include <iostream>
#include <string>
#include <cmath>
#include <cstring> // check if this one is allowed 

#ifndef hash_h  
#define hash_h

// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

//int hash_function(string text);

struct item { // this is the same as Node 

    string key;  // the value from the hash function

    item* next;  // pointer that points to the next item of the list 

    // when we point to item, we are talking about the string 

    item(string k) : key(k), next(nullptr) {} 
   

};



class HashTable { // hash class

    private:

     int tableSize; // given by the first line of the input, changes depending on the input file
     item** table;

   

    public:
 
    


    HashTable(int sizeK);// initializes a hash table object when it gets created, implement in cpp 
        //int tableSize; 

        ~HashTable(); 
        //hash();

        //bool isEmpty() const;


       int hashFunction(string text); // this was already provided
       void insertItem(string text); 
       void removeItem(int key); 
       string searchTable(int key); 
       void printTable();



};

#endif
//HashTable* createHashTable(int size);  // this will make a hash table with the size that was found in main 
