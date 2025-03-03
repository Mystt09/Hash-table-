#include <iostream>
#include <string>
#include "hash.h"
#include <math>

using namespace std;


HashTable::HashTable(int sizeK) {

    tableSize = sizeK; 

    table = new item*[tableSize]; 

    for (int i = 0; i < tableSize; i++) {

        table[i] = nullptr;

    } 
}
     
// Destructor: Free memory
HashTable::~HashTable() {

    for (int i = 0; i < tableSize; i++) {
        item* temp = table[i];

        while (temp) {

            item* next = temp->next;
            delete temp;
            temp = next;

        }

    }
    delete[] table; // Free the array
}
    
void HashTable::insertItem(string text) {

    int index = hashFunction(text); 

    item* newItem = new item(text);
    newItem->next = table[index];
    table[index] = newItem;

       }

       //void removeItem(int key); 
       //string searchTable(int key); 

void HashTable::printTable(){

    for (int i = 0; i < tableSize; i++) {
        printf("Slot %d: ", i);  // Print slot index

        item* temp = table[i];
        while (temp) {
            printf("%d -> ", temp->key);  // Print the key
            temp = temp->next;
        }
        printf("NULL\n");  // End of chain
    }


       }


int HashTable::hashFunction(string text) {
    // Implement your own hash function here

    // get the first char of the letter 
    char letter = text[0];  // stores the first char 

    int ascii = (int)letter; // gets the ascii of that char 

    int lowerCaseA = (int)'a';
    int upperCaseA = (int)'A';

    int lowerCaseZ = (int) 'z';
    int upperCaseZ = (int) 'Z'; 

    //  x > 97 and x < 123 subtract by ascii of 'a' -> 97
    // x > 65 x < 91 subtract by ascii of 'A' -> 65

    if (ascii > lowerCaseA && ascii < lowerCaseZ ) { // checks if the first letter is lower case 

        // subtract the ascii by ascii of 'a' 

        int hashValue = ascii - lowerCaseA; 

        return hashValue % tableSize;

    }

    if (ascii > upperCaseA && ascii < upperCaseZ ) { // checks if the first letter is upper case 

        int hashValue = ascii - upperCaseA; 

        return hashValue % tableSize;

    }
    // check if the ascii is upper or lower case 

    return 1;
}
void HashTable::printSlotLengths() {
    for (int i = 0; i < tableSize; i++){
        int count = 0;
        intem* temp = table[i];
        while (temp) {
             count++;
           temp = temp->next;       
        }
        cout << count << end1;
}
}
// function to compute and print the standard deviation of the slot lengths
void HashTable::computeStandardDeviation() {
    double sum = 0, mean, variance = 0, stddev;
        int* slotLengths = new int[tableSize];

for (int i = 0; i <tableSizes; i++) {
    int count = 0;
    item* temp = table[i];
    while (temp) {
        count++;
      temp = temp->next;
    }
    slotLengths[i] = count;
    sum += count;
}
mean = sum / tableSizes;
for (int i = 0; i < tableSize; i++){
    variance += pow(slotLengths[i] - mean, 2);

}
    variance /= tableSizes;
    stddev = sqrt(variance);

    cout << stddev << end1;
    delete[] slothLengths;
}
