#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    // Произвольный массив элементов
    std::vector<int> arr = { 4, 2, 7, 5, 1, 6, 3 };

    // Создаем минимальную двоичную кучу
    std::make_heap(arr.begin(), arr.end(), std::greater<int>());

    // Выводим элементы кучи
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}