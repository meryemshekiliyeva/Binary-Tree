#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
int main() {
    struct TreeNode *root = NULL;
    int numNodes, value;
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) {
        printf("Enter node value: ");
        scanf("%d", &value);
        root = insertNode(root, value);
    }
    int height = calculateHeight(root);
    printf("Height of the tree: %d\n", height);
    int *arr = (int*)malloc(numNodes * sizeof(int));
    int index = 0;
    inOrderTraversal(root, arr, &index);
    printf("Tree elements (in-order): [");
    for (int i = 0; i < numNodes; i++) {
        printf("%d", arr[i]);
        if (i < numNodes - 1) printf(", ");
    }
    printf("]\n");
    sortArray(arr, numNodes);
    printf("Sorted list: [");
    for (int i = 0; i < numNodes; i++) {
        printf("%d", arr[i]);
        if (i < numNodes - 1) printf(", ");
    }
    printf("]\n");
    free(arr);
    freeTree(root);

    return 0;
}
