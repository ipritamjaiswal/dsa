/* Implementation of binary tree */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Tree;

void create_tree(Tree *curr, Tree *new) {
    if (new->data <= curr->data) {
        if (curr->left == NULL) {
            curr->left = new;
        } else {
            create_tree(curr->left, new);
        }
    }
    else {
        if (curr->right == NULL) {
            curr->right = new;
        } else {
            create_tree(curr->right, new);
        }
    }
}

// Inorder traversal: left, root, right
void inorder(Tree *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if (root->left != NULL) {
        inorder(root->left);
    }
    printf("%d ", root->data);
    if (root->right != NULL) {
        inorder(root->right);
    }
}

// Preorder traversal: root, left, right
void preorder(Tree *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("%d ", root->data);
    if (root->left != NULL) {
        preorder(root->left);
    }
    if (root->right != NULL) {
        preorder(root->right);
    }
}

// Postorder traversal: left, right, root
void postorder(Tree *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if (root->left != NULL) {
        postorder(root->left);
    }
    if (root->right != NULL) {
        postorder(root->right);
    }
    printf("%d ", root->data);
}