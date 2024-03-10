/*Name : Fatma nazeih Hanfy Mahmoud
ID : 20230284 
Chiper : Baconian Cipher
E-mail : fatmanazeih37@gmail.com */

#include <iostream>
#include <string>
#include<iomanip>
#include <cmath>
using namespace std;

// Function prototypes
int cipher();
int decipher();
int main() {
    // Variable to store user choice
    int choice;

    do {
        // make the user choose between ciphering or deciphering
        cout << "Do you want to cipher(1) or decipher(2) a message? ";
        cin >> choice;

        // Ignore the newline character left in the input 
        cin.ignore();

        if (choice == 1) {
            cipher(); // Call the cipher function
        } else if (choice == 2) {
            decipher(); // Call the decipher function
        } else {
            cout << "Error: Invalid choice " << endl;
            cout << "Re-enter a choice (1 or 2): ";
            cin.clear(); // Clear the error flag
            cin.ignore(); // Discard incorrect input
            string input; //string if the user entered a string to store
            getline(cin, input); // to read everything the user will enter 
        }
    } while (choice != 1 && choice != 2); // Keep looping until a valid choice is made
    return 0;
}


// Function to encrypt a message using Baconian Cipher
int cipher() {
    // Arrays to store normal alphabet and Baconian cipher
    char normal[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string cipher[] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba",
     "aabbb", "abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb",
     "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb", "bbaaa", "bbaab"};

    string message;
    //empty array to store the message after being ciphered
    string new_message = "";

    // make the user enter the message
    cout << "Enter the message: ";
    // to read every digit the user will enter
    getline(cin, message);

    // Iterate through each character in the message
    int n = message.length();
    for (int i = 0; i < n; ++i) {
        char digit = toupper(message[i]); // Convert character to uppercase
        if (isalpha(digit)) {
            // Search for the character in the normal alphabet array
            for (int j = 0; j < 26; ++j) {
                if (normal[j] == digit) {
                    // Append the corresponding Baconian cipher to the new message
                    new_message += cipher[j] + " ";
                    break;
                }
            }
        } else if (isdigit(digit) || ispunct(digit)) {
            // Append digits and punctuation marks as they are
            new_message += digit;
            new_message += " ";
        } else {
            // Append spaces for non-alphabetic characters
            new_message += " ";
        }
    }

    // Display the encrypted message
    cout << "The encrypted message is: " << new_message << endl;

    return 0;
}

// Function to decrypt a message encrypted using Baconian Cipher
int decipher() {
    // Arrays to store normal alphabet and Baconian cipher
    char normal[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string cipher[] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba",
     "aabbb", "abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb",
     "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb", "bbaaa", "bbaab"};

    string message;
    //empty array to store the message after being ciphered
    string new_message = "";

    // make the user enter the encrypted message
    cout << "Enter the encrypted message: ";
    // to read every digit the user will enter
    getline(cin, message);

    // Iterate through each character in the encrypted message
    int n = message.length();
    string group = ""; // empty string to store 5 digits and search on them
    for (int i = 0; i < n; ++i) {
        if (isalpha(message[i])) {
            group += message[i]; // Add the character to the group
            if (group.length() == 5) {
                // If the group is complete, search for the corresponding character in the normal alphabet array
                for (int j = 0; j < 26; ++j) {
                    if (group == cipher[j]) {
                        // Append the corresponding normal alphabet character to the new message
                        new_message += normal[j];
                        break;
                    }
                }
                group = ""; // Reset the group for the next set of characters
            }
        } else {
            // Append non-alphabetic characters as they are
            new_message += message[i];
        }
    }

    // Display the decrypted message
    cout << "The decrypted message is: " << new_message << endl;

    return 0;
}
