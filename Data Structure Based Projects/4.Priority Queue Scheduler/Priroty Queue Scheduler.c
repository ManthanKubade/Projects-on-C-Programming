#include <stdio.h>
#define MAX 100

typedef struct {
    int id;
    int priority;
} Task;

Task pq[MAX];
int size = 0;

void insertTask(int id, int priority) {
    int i = size++;
    while (i > 0 && pq[(i - 1) / 2].priority < priority) {
        pq[i] = pq[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq[i].id = id;
    pq[i].priority = priority;
}

Task extractMax() {
    Task root = pq[0];
    Task last = pq[--size];

    int i = 0, child;
    while (2 * i + 1 < size) {
        child = 2 * i + 1;
        if (child + 1 < size && pq[child + 1].priority > pq[child].priority)
            child++;

        if (last.priority >= pq[child].priority) break;
        pq[i] = pq[child];
        i = child;
    }
    pq[i] = last;
    return root;
}

void display() {
    for (int i = 0; i < size; i++)
        printf("Task %d | Priority %d\n", pq[i].id, pq[i].priority);
}

int main() {
    insertTask(1, 5);
    insertTask(2, 2);
    insertTask(3, 8);

    display();

    Task t = extractMax();
    printf("\nExecuted Task: %d\n", t.id);

    return 0;
}
