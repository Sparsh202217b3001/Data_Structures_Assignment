#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct node {
    char data;
    struct node *left_child;
    struct node *right_child;
};

struct node* create_node(char data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

struct node* build_tree(char tree[], int index, int max_node) {
    struct node *temp = NULL;

    if (index <= max_node && tree[index] != '\0') {
        temp = create_node(tree[index]);
        temp->left_child = build_tree(tree, 2 * index, max_node);
        temp->right_child = build_tree(tree, 2 * index + 1, max_node);
    }

    return temp;
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf(" %c ", root->data);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left_child);
        postorder(root->right_child);
        printf(" %c ", root->data);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left_child);
        printf(" %c ", root->data);
        inorder(root->right_child);
    }
}

int main() {
    char tree[MAX_NODES];
    int max_node;

    printf("Enter the maximum index of the tree: ");
    scanf("%d", &max_node);

    printf("Enter the elements of the tree (enter '0' for empty nodes):\n");
    for (int i = 1; i <= max_node; i++) {
        printf("Node %d: ", i);
        scanf(" %c", &tree[i]);
    }

    struct node *root = build_tree(tree, 1, max_node);

    if (root == NULL) {
        printf("Error building tree.\n");
        return 1;
    }

    printf("\nPreorder traversal:\n");
    preorder(root);

    printf("\n\nPostorder traversal:\n");
    postorder(root);

    printf("\n\nInorder traversal:\n");
    inorder(root);

    printf("\n");

    return 0;
}
