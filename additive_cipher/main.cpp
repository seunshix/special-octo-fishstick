// Name: Seun Ade
// Date: 9/16/2024
// Purpose: This program will implement the Additive cipher also known as the
// Caesar cipher or Shift cipher.

#include <iostream>
#include <string>

using namespace std;

string encrypt(const string &plaintext, int shift) {
  string ciphertext = "";
  for (char ch : plaintext) {
    // setting the base to ensure the shift operation respects the case of the
    // letters
    if (isalpha(ch)) {
      char base = islower(ch) ? 'a' : 'A';
      ciphertext += (ch - base + shift) % 26 + base;
      cout << "char base is " << base << endl;;
      cout << "This (ch - base computes to " << (ch - base) << endl;
      cout << "This (ch - base + shift) computes to " << (ch - base + shift)
           << endl;
      cout << "This (ch - base + shift) % 26 computes to " << ((ch - base + shift) % 26) << endl;
      cout << endl;
    } else {
      ciphertext += ch;
    }
  }
  return ciphertext;
}
string decrypt(const string &ciphertext, int shift) {
  string plaintext = "";
  return encrypt(ciphertext, 26 - shift);
}

int main() {

  string text; // text to encrypt or decrypt
  int shift;   // number of positions to shift each character
  char choice; // encrypt or decrypt choice

  cout << "Enter the text: ";
  cin >> text;

  cout << "Enter the shift value (0 - 25): ";
  cin >> shift;

  shift = shift % 26; // ensure shift is within range of 0-25

  cout << "Enter 'E' to encrypt or 'D' to decrypt: ";
  cin >> choice;

  if (choice == 'e' or choice == 'E') {
    string ciphertext = encrypt(text, shift);
    cout << "Cipher text: " << ciphertext << endl;
  } else if (choice == 'd' or choice == 'D') {
    string plaintext = decrypt(text, shift);
    cout << "Cipher text: " << plaintext << endl;
  } else {
    cout << "Invalid choice. Please enter 'E' or 'D'." << endl;
  }

  return 0;
}