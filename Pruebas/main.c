#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Declaración de la función (prototipo)
void encontrarTarget(int nums[], int v, int target, int *num1, int *num2);

int main() {
    int nums[MAX] = {2, 7, 11, 15};
    int v = 4;
    int numero1;
    int numero2;
    int target = 9;

    encontrarTarget(nums, v, target, &numero1, &numero2);
    printf("[%d - %d]\n", numero1, numero2);

    return 0;
}

void encontrarTarget(int nums[], int v, int target, int *num1, int *num2) {
    for (int i = 0; i < v; i++) {
        for (int j = i + 1; j < v; j++) { // incrementa j
            if (nums[i] + nums[j] == target) {
                *num1 = i;
                *num2 = j;
                return; // salir de la función al encontrar
            }
        }
    }
}
