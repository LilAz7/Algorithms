#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

const int MAX_SIZE = 7;
const int MAX_VALUE = 10;

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int nearestNeighbor(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int tour[MAX_SIZE];
    bool visited[MAX_SIZE];
    int start = 0;
    int totalDistance = 0;

    for (int i = 0; i < size; i++) {
        tour[i] = -1;
        visited[i] = false;
    }

    tour[0] = start;
    visited[start] = true;

    for (int i = 1; i < size; i++) {
        int nearest = -1;
        int minDistance = INT_MAX;

        for (int j = 0; j < size; j++) {
            if (!visited[j] && matrix[start][j] < minDistance) {
                minDistance = matrix[start][j];
                nearest = j;
            }
        }

        tour[i] = nearest;
        visited[nearest] = true;
        start = nearest;
        totalDistance += minDistance;
    }

    totalDistance += matrix[tour[size - 1]][0];

    cout << "Tour: ";
    for (int i = 0; i < size; i++) {
        cout << tour[i] << " ";
    }
    cout << endl;

    return totalDistance;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE] = {
        {0, 3, 2, 7, 5, 4, 1},
        {3, 0, 5, 4, 6, 8, 2},
        {2, 5, 0, 9, 8, 7, 3},
        {7, 4, 9, 0, 2, 6, 5},
        {5, 6, 8, 2, 0, 3, 7},
        {4, 8, 7, 6, 3, 0, 1},
        {1, 2, 3, 5, 7, 1, 0},
    };
    int size = 7;

    cout << "Graph matrix:" << endl;
    printMatrix(matrix, size);

    int tourDistance = nearestNeighbor(matrix, size);
    cout << "Tour distance: " << tourDistance << endl;

    return 0;
}