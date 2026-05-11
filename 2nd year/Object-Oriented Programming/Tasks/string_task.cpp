#include <iostream>
#include <string>
#include <cstring>

//Find a string in a sentence using characters in an array and a string variable.

using namespace std;

int main() {
    char sentence[1000], word[100];
    cout << "How many characters will the sentence have? ";
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading n
    cout << "Enter a sentence: ";
    for (int i = 0; i < n; i++) {
        cin.get(sentence[i]);
    }
    sentence[n] = '\0'; // Null-terminate the sentence
    cout << "Enter a word to search: ";
    cin >> word;
    //the word has to exist obviously
    // create a temporary string to be filled then we compare it to the word we are looking for
    int pos, key = 0;
    char temp[100];
    for (char c : sentence) {
    if (c == ' ')
      continue; // to ignore spaces
    }
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ') {
            temp[key] = '\0'; // null-terminate the temp string
            if (strcmp(temp, word) == 0) {
                pos = i - key; // pos of the word found
                break;
            }
            key = 0; // Reset key for the next word
        } else {
            temp[key++] = sentence[i]; // Add character to temp
        }
    }
    // Check the last word in the sentence
    while (temp[key] != '\0') {
        temp[key] = '\0'; // Null-terminate the temp string
    }
        if (strcmp(temp, word) == 0) {
            pos = strlen(sentence) - key; // Position of the found word
        }
        if (pos >= 0) {
            pos = n-pos; // Adjust position to be from the start of the sentence
            cout << "The word exists in the sentence at position: " << pos << endl;
        } else {
            cout << "The word does not exist in the sentence." << endl;
        }
    return 0;
}