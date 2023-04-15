#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string plaintext;
    int key;

    cout << "������� ����� ��� ����������: ";
    getline(cin, plaintext);

    cout << "������� ���� (����� ����� �� 1 �� 25): ";
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

    cout << "������������� �����: " << ciphertext << endl;

    return 0;
}