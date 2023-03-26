#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Входные данные - массив длин канатов
    vector<int> ropes = { 2, 3, 5, 7, 10 };

    // Создаем приоритетную очередь (минимальная куча)
    priority_queue<int, vector<int>, greater<int>> pq;

    // Заполняем кучу начальными значениями
    for (int rope : ropes) {
        pq.push(rope);
    }

    // Считаем общие затраты на связывание канатов
    int total_cost = 0;
    while (pq.size() > 1) {
        // Извлекаем два самых коротких каната из кучи
        int rope1 = pq.top();
        pq.pop();
        int rope2 = pq.top();
        pq.pop();

        // Считаем затраты на связывание двух канатов и добавляем их в общие затраты
        int cost = rope1 + rope2;
        total_cost += cost;

        // Добавляем связанный канат в кучу
        pq.push(cost);
    }

    // Выводим результат
    cout << "Порядок связывания канатов: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    cout << "Суммарные затраты: " << total_cost << endl;

    return 0;
}