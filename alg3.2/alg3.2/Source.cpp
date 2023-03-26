#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class MaxBinaryHeap {
private:
    std::vector<T> heap;

    void sift_up(int index) {
        int parent_index = (index - 1) / 2;
        while (index > 0 && heap[parent_index] < heap[index]) {
            std::swap(heap[parent_index], heap[index]);
            index = parent_index;
            parent_index = (index - 1) / 2;
        }
    }

    void sift_down(int index) {
        int left_child_index = index * 2 + 1;
        int right_child_index = index * 2 + 2;
        int largest_child_index = index;
        if (left_child_index < heap.size() && heap[left_child_index] > heap[largest_child_index]) {
            largest_child_index = left_child_index;
        }
        if (right_child_index < heap.size() && heap[right_child_index] > heap[largest_child_index]) {
            largest_child_index = right_child_index;
        }
        if (largest_child_index != index) {
            std::swap(heap[index], heap[largest_child_index]);
            sift_down(largest_child_index);
        }
    }

public:
    MaxBinaryHeap() {}

    MaxBinaryHeap(std::vector<T> const& values) : heap(values) {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            sift_down(i);
        }
    }

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    T const& find_max() const {
        if (empty()) {
            throw std::out_of_range("heap is empty");
        }
        return heap[0];
    }

    void insert(T const& value) {
        heap.push_back(value);
        sift_up(heap.size() - 1);
    }

    void delete_max() {
        if (empty()) {
            throw std::out_of_range("heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        sift_down(0);
    }

    void merge(MaxBinaryHeap const& other) {
        std::vector<T> merged_heap(heap.size() + other.heap.size());
        std::merge(heap.begin(), heap.end(), other.heap.begin(), other.heap.end(), merged_heap.begin(), std::greater<T>());
        heap = std::move(merged_heap);
    }
};