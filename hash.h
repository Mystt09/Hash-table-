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

    string key;  // the string from the hash function

    item* next;  // pointer that will point to null 

    // the item is a string, with a pointer that points to null, as it acts as a single Node in its single list 


        // initializes the key, to be the string input, and have next point to null 
        item(string k) { this->key = k; this->next = nullptr; }  


};

class HashTable { // hash class

    private:

     int tableSize; // given by the first line of the input, changes depending on the input file
     item** table; // double pointer, an array of pointers that have pointer inside, to point to the next item of the list 

   

    public:
 
    


    HashTable(int sizeK);// initializes a hash table object when it gets created, implemented in cpp 
        //int tableSize; 

        ~HashTable(); // deconstructor 
        //hash();

        //bool isEmpty() const;


       int hashFunction(string text); // this was already provided
       void insertItem(string text); 
       //void removeItem(int key); 
       //string searchTable(int key); 
       void computeStandardDeviation();
       void printSlotLengths();
       void printTable();



};

#endif
//HashTable* createHashTable(int size);  // this will make a hash table with the size that was found in main 
