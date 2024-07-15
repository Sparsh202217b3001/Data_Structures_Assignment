#include <stdio.h>

// Function prototype for tower of hanoi function
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);

// Recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    char from_rod, to_rod, aux_rod;

    // Input number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Input names of rods
    printf("Enter the name of source rod: ");
    scanf(" %c", &from_rod); // Note: space before %c is used to consume newline character

    printf("Enter the name of destination rod: ");
    scanf(" %c", &to_rod);

    printf("Enter the name of auxiliary rod: ");
    scanf(" %c", &aux_rod);

    printf("\nTower of Hanoi solution for %d disks:\n", n);
    towerOfHanoi(n, from_rod, to_rod, aux_rod);

    printf("\n");
    return 0;
}
