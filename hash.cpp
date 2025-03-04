#include <iostream>
#include <string>
#include <cmath>
#include "hash.h"


/*
3/4/25

things left to do: 

Write in the README file of what the code does. Make sure it passes all the gradescope test cases

*/
using namespace std;


HashTable::HashTable(int sizeK) { // creates the hash table 

    // initialize hash table size 
    
    tableSize = sizeK; 


    //***  NOTES ****  */

    // uses the private variable item** table, to create the array of lists
    // how is it able to acces it in hash table when it is a private variable?
    // the constructor is able to access all variables in the HashTable class, however, 
    // if it were called in main, it would need to create an object, and setter and getter methods would be needed

    // END NOTES 

    table = new item*[tableSize]; // initializes the slots, the slots are the new items. 
    // The number of slots is determined by the table size


    for (int i = 0; i < tableSize; i++) {

        table[i] = nullptr; // in the beginning, each slot is pointing to null 

    } 
}
     
// Destructor: Free memory, to free up space after the constructor was used ?? 


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

    int index = hashFunction(text); // index is equal to the result of the hash function 

    item* newItem = new item(text); // pointer that points to the new item in the list, and that new item is the string input
    newItem->next = table[index]; // the new item points 
    table[index] = newItem;

       }

       //void removeItem(int key); 
       //string searchTable(int key); 

void HashTable::printTable(){


    //
    //  ***** FOR GRADESCOPE MAKE SURE TO UNCOMMENT THIS: needs to print only the first five to pass the tests 
    /*
    for (int i = 0; i < 5; i++) { // loop to go through each slot 

        printf("Slot %d: ", i);  // prints the current slot i 

        item* currentWord = table[i]; // we create a new temp item, that will be equal to the item at index i 

        // example if table[0] = "apple", it sets temp = "apple"

        while (currentWord) { // checks if the current word is not null 

          

           cout << currentWord->key << " "; // prints the word 

            currentWord = currentWord->next; // sets the currentWord, to the word that next is pointing to 
        }

        printf("\n");  // End of chain
    }
    */

    for (int i = 0; i < tableSize; i++) { // loop to go through each slot 

        printf("Slot %d: ", i);  // prints the current slot i 

        item* currentWord = table[i]; // we create a new temp item, that will be equal to the item at index i 

        // example if table[0] = "apple", it sets temp = "apple"

        while (currentWord) { // checks if the current word is not null 

           cout << currentWord->key << " "; // prints the word 

            currentWord = currentWord->next; // sets the currentWord, to the word that next is pointing to 
        }

        printf("\n");  // End of chain
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

    // if it starts with A or a, then return 0 
    if (ascii == lowerCaseA || ascii == upperCaseA) {

        return 0;

    } else if (ascii > lowerCaseA && ascii < lowerCaseZ ) { // checks if the first letter is lower case 

        // subtract the ascii by ascii of 'a' 

        int hashValue = ascii - lowerCaseA; 

        return hashValue % tableSize;

    }

    else if (ascii > upperCaseA && ascii < upperCaseZ ) { // checks if the first letter is upper case 

        // subtract the ascii by ascii of 'A' 

        int hashValue = ascii - upperCaseA; 

        return hashValue % tableSize;

    } 
     
    return 1; 
}

    void HashTable::printSlotLengths() {

        for (int i = 0; i < tableSize; i++){

            int count = 0;

            printf("Slot %d: ", i); 

            item* temp = table[i];

            while (temp) {

                 count++;

               temp = temp->next;  

            }

            cout << count << endl;
    }

   // return 1;

}

    // function to compute and print the standard deviation of the slot lengths

void HashTable::computeStandardDeviation() {

    double sum = 0, mean, variance = 0, stddev;

    int* slotLengths = new int[tableSize];

    for (int i = 0; i < tableSize; i++) { 

        int count = 0;

        item* temp = table[i];

        while (temp) {

            count++;
            temp = temp->next;

        }

        slotLengths[i] = count;
        sum += count;

    }

    mean = sum / tableSize;

    for (int i = 0; i < tableSize; i++) {

        variance += pow(slotLengths[i] - mean, 2);

    }

    variance /= tableSize;
    stddev = sqrt(variance);


   // printf("d%", stddev); 

    cout << stddev << endl;


    delete[] slotLengths;

}



