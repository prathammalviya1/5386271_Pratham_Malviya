#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

MinHeap* createHeap(int capacity) {
    MinHeap *h = malloc(sizeof(MinHeap));
    h->data = malloc(sizeof(int) * (capacity + 1));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void heapifyUp(MinHeap *h, int idx) {
    while (idx > 1 && h->data[idx] < h->data[idx / 2]) {
        swap(&h->data[idx], &h->data[idx / 2]);
        idx /= 2;
    }
}

void heapifyDown(MinHeap *h, int idx) {
    int smallest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;
    if (left <= h->size && h->data[left] < h->data[smallest]) smallest = left;
    if (right <= h->size && h->data[right] < h->data[smallest]) smallest = right;
    if (smallest != idx) {
        swap(&h->data[idx], &h->data[smallest]);
        heapifyDown(h, smallest);
    }
}

void insert(MinHeap *h, int val) {
    h->size++;
    h->data[h->size] = val;
    heapifyUp(h, h->size);
}

int extractMin(MinHeap *h) {
    int root = h->data[1];
    h->data[1] = h->data[h->size];
    h->size--;
    heapifyDown(h, 1);
    return root;
}

int getMin(MinHeap *h) {
    return h->data[1];
}

int findIndex(MinHeap *h, int val) {
    for (int i = 1; i <= h->size; i++) {
        if (h->data[i] == val) return i;
    }
    return -1;
}

void deleteValue(MinHeap *h, int val) {
    int idx = findIndex(h, val);
    if (idx == -1) return;
    h->data[idx] = h->data[h->size];
    h->size--;
    heapifyUp(h, idx);
    heapifyDown(h, idx);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
     int Q, type, val;
    scanf("%d", &Q);
    MinHeap *h = createHeap(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &val);
            insert(h, val);
        } else if (type == 2) {
            scanf("%d", &val);
            deleteValue(h, val);
        } else if (type == 3) {
            printf("%d\n", getMin(h));
        }
    }
    return 0;
}
