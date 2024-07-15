#include <stdio.h>
#include <stdlib.h>

#define n 5

void main() {
    int queue[n], ch = 1, front = 0, rear = -1, i, j = 1;

    printf("Queue using Array\n");
    printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");

    while (ch) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (rear < n - 1) {
                    printf("\nEnter number %d: ", j++);
                    scanf("%d", &queue[++rear]);
                } else {
                    printf("\nQueue is Full");
                }
                break;
            case 2:
                if (front > rear) {
                    printf("\nQueue is empty");
                } else {
                    printf("\nDeleted Element is %d", queue[front++]);
                }
                break;
            case 3:
                printf("\nQueue Elements are:\n");
                if (front > rear) {
                    printf("\nQueue is Empty");
                } else {
                    for (i = front; i <= rear; i++) {
                        printf("%d\n", queue[i]);
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice: please see the options");
        }
    }
}
