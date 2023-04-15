#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // ����� ��� ����������
    std::string plaintext = "Hello, mirea";

    // ������� ������
    std::map<char, char> substitution_table = {
      {'a', 'z'},
      {'b', 'y'},
      {'c', 'x'},
      {'d', '2'},
      {'e', 'v'},
      {'f', 'u'},
      {'H', '3'},
      {'y', 'b'},
      {'z', 'a'}
    };

    // ���������� ������
    std::string ciphertext = "";
    for (char c : plaintext) {
        if (substitution_table.count(c) > 0) {
            ciphertext += substitution_table[c];
        }
        else {
            ciphertext += c;
        }
    }

    // ����� �������������� ������
    std::cout << "������������� �����: " << ciphertext << std::endl;

    return 0;
}