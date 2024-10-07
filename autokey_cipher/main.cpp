// Name: Seun Ade
// Date: 9/16/2024
// Purpose: This program will implement the Autokey cipher 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int len, currentkey, i, pos;
char ch, base;

string encrypt(const string &plaintext, int key) {
  string ciphertext = "";
  currentkey = key;
  len = plaintext.size();
  //for (char ch : plaintext) {
  for (i = 0; i < len; i++){
    // setting the base to ensure the shift operation respects the case of the letters
    ch = plaintext[i];
    if (isalpha(ch)) {
      base = islower(ch) ? 'a' : 'A';
      pos = ch - base;
      char encryptedchar = (pos + currentkey) % 26 + base;
      ciphertext += encryptedchar;
      currentkey = pos;
    } 
    else {
      ciphertext += ch;
    }
  }
  return ciphertext;
}
string decrypt(const string &ciphertext, int key) {
  string plaintext = "";
  currentkey = key;
  len = ciphertext.size();

  for (i = 0; i < len; i++){
    char ch = ciphertext[i];
    if (isalpha(ch)){
        base = islower(ch) ? 'a' : 'A';
        pos = ch - base;
        char decryptedchar = (pos - currentkey + 26) % 26 + base;
        plaintext += decryptedchar;
        currentkey = decryptedchar - base;
    }
    else{
        plaintext += ch;
    }
  }
  return plaintext;
}

int main() {

  string text; // text to encrypt or decrypt
  int key;   // number of positions to shift each character
  char choice; // encrypt or decrypt choice

  cout << "---------------------------------------------------------------------------------" << endl;
  cout << "                             AUTO-KEY CIPHER         " << endl;
  cout << "---------------------------------------------------------------------------------" << endl;

  while (true){

    cout << "Enter 'E' to encrypt or 'D' to decrypt, or 'Q'|'S': to quit: ";
    cin >> choice;

    

    if (choice == 'Q' || choice == 'q' || choice == 'S' || choice == 's') {
            cout << "Exiting program..." << endl;
            break;  // Exit the loop
    }
    else if (choice != 'E' && choice != 'D' && choice != 'e' && choice != 'd'){
        cout << "Invalid choice. BYe BYe!." << endl;
        break;
    }

    cin.ignore();
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the key value (0 - 25): ";
    cin >> key;

    key = key % 26; // ensure shift is within range of 0-25

    if (choice == 'e' or choice == 'E') {
        string ciphertext = encrypt(text, key);
        cout << "Cipher text: " << ciphertext << endl;
    } 
    else if (choice == 'd' or choice == 'D') {
        string plaintext = decrypt(text, key);
        cout << "Plain text: " << plaintext << endl;
    }

    cout << "---------------------------------------------------------------------------------" << endl;
  }
  
  return 0;
}


