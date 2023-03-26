#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // ������� ������ - ������ ���� �������
    vector<int> ropes = { 2, 3, 5, 7, 10 };

    // ������� ������������ ������� (����������� ����)
    priority_queue<int, vector<int>, greater<int>> pq;

    // ��������� ���� ���������� ����������
    for (int rope : ropes) {
        pq.push(rope);
    }

    // ������� ����� ������� �� ���������� �������
    int total_cost = 0;
    while (pq.size() > 1) {
        // ��������� ��� ����� �������� ������ �� ����
        int rope1 = pq.top();
        pq.pop();
        int rope2 = pq.top();
        pq.pop();

        // ������� ������� �� ���������� ���� ������� � ��������� �� � ����� �������
        int cost = rope1 + rope2;
        total_cost += cost;

        // ��������� ��������� ����� � ����
        pq.push(cost);
    }

    // ������� ���������
    cout << "������� ���������� �������: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    cout << "��������� �������: " << total_cost << endl;

    return 0;
}