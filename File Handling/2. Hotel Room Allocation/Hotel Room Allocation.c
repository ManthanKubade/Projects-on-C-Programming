#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int roomNo;
    int checkout;
} Room;

Room heap[MAX];
int size = 0;

/* Swap */
void swap(Room *a, Room *b) {
    Room temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify Up */
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].checkout > heap[i].checkout) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/* Heapify Down */
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].checkout < heap[smallest].checkout)
        smallest = left;

    if (right < size && heap[right].checkout < heap[smallest].checkout)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

/* Insert Room */
void allocateRoom(int roomNo, int checkout) {
    heap[size].roomNo = roomNo;
    heap[size].checkout = checkout;
    size++;
    heapifyUp(size - 1);
    printf("Room %d allocated till time %d\n", roomNo, checkout);
}

/* Free Earliest Room */
void freeRoom() {
    if (size == 0) {
        printf("No rooms to free\n");
        return;
    }

    printf("Room %d freed at time %d\n",
           heap[0].roomNo, heap[0].checkout);

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

/* Display Heap */
void display() {
    if (size == 0) {
        printf("No occupied rooms\n");
        return;
    }

    printf("Current Occupied Rooms:\n");
    for (int i = 0; i < size; i++) {
        printf("Room %d -> Checkout %d\n",
               heap[i].roomNo, heap[i].checkout);
    }
}

/* Main */
int main() {
    int choice, roomNo, checkout;

    while (1) {
        printf("\n1.Allocate Room\n2.Free Room\n3.Display\n4.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Room Number & Checkout Time: ");
            scanf("%d %d", &roomNo, &checkout);
            allocateRoom(roomNo, checkout);
            break;

        case 2:
            freeRoom();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
