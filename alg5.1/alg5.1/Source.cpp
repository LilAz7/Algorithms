#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string plaintext;
    int key;

    cout << "Введите текст для шифрования: ";
    getline(cin, plaintext);

    cout << "Введите ключ (целое число от 1 до 25): ";
    cin >> key;

    string ciphertext = plaintext;

    for (int i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
            }
            else {
                ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
            }
        }
    }

    cout << "Зашифрованный текст: " << ciphertext << endl;

    return 0;
}
