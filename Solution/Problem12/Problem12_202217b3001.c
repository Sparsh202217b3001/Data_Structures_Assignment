#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert nodes
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        Node* temp = queue[front++];
        if (temp->left == NULL) {
            temp->left = newNode(data);
            break;
        } else {
            queue[rear++] = temp->left;
        }
        if (temp->right == NULL) {
            temp->right = newNode(data);
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

// Function to delete the given deepest node
void deletDeepest(Node* root, Node* d_node) {
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    Node* temp;
    while (front != rear) {
        temp = queue[front++];
        if (temp == d_node) {
            free(d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                free(d_node);
                return;
            } else {
                queue[rear++] = temp->right;
            }
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                free(d_node);
                return;
            } else {
                queue[rear++] = temp->left;
            }
        }
    }
}

// Function to delete an element in binary tree
Node* deletion(Node* root, int key) {
    if (!root) return NULL;
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) return NULL;
        else return root;
    }
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    Node* temp;
    Node* key_node = NULL;
    while (front != rear) {
        temp = queue[front++];
        if (temp->data == key) key_node = temp;
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
    if (key_node != NULL) {
        int x = temp->data;
        key_node->data = x;
        deletDeepest(root, temp);
    }
    return root;
}

// Inorder traversal
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(Node* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Level order traversal
void levelorderTraversal(Node* root) {
    if (!root) return;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
}

// Driver function
int main() {
    Node* root = NULL;
    int num_nodes, data, key;

    // Read number of nodes to insert
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &num_nodes);

    // Insert nodes
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    // Display traversals
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\nInorder traversal: ");
    inorderTraversal(root);
    printf("\nPostorder traversal: ");
    postorderTraversal(root);
    printf("\nLevel order traversal: ");
    levelorderTraversal(root);

    // Read key to delete
    printf("\nEnter the value of the node to delete: ");
    scanf("%d", &key);
    root = deletion(root, key);

    // Display traversals after deletion
    printf("\nInorder traversal after deletion: ");
    inorderTraversal(root);

    return 0;
}
