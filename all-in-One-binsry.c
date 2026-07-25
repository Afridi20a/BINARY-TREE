#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// create node
struct node *create_node(int data) 
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// function of in order traversal
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// FUNCTION FOR BST SEARCH
struct node *search(struct node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        return root;
    }
    else if (root->data > target)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}

// FUNCTION FOR INSERTION
struct node *insert(struct node *root, int key)
{
    if(root == NULL)
    {
        return create_node(key);
    }

    if(key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        // Duplicate value found
        printf("Duplicate value %d is not allowed!\n", key);
        return root;
    }

    return root;
}

//funstion for cheak the tree is BST
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

// Find the minimum node (Inorder Successor)
struct node *minValueNode(struct node *root)
{
    if(root == NULL || root->left == NULL)
    {
        return root;
    }

    return minValueNode(root->left);
}

// Delete a node from BST
struct node *deleteNode(struct node *root, int key)
{
    // Base Case
    if(root == NULL)
    {
        return NULL;
    }

    // Search in Left Subtree
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    // Search in Right Subtree
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    // Node Found
    else
    {
        // Case 1: Leaf Node
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: Only Left Child
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Only Right Child
        else if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 4: Two Children
        else
        {
            struct node *succ = minValueNode(root->right);

            // Copy successor's data
            root->data = succ->data;

            // Delete the successor node
            root->right = deleteNode(root->right, succ->data);
        }
    }

    return root;
}

int main()
{
    struct node *p = create_node(5);
    struct node *p1 = create_node(3);
    struct node *p2 = create_node(6);
    struct node *p3 = create_node(1);
    struct node *p4 = create_node(4);

    //                  5
    //                 / \
    //                3   6
    //               / \  
    //              1   4

    // linking the root with the node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("inorder traversal\n");
    inOrder(p);
    printf("\n");

    printf("%d ", isBST(p));
    printf("\n");

    struct node *result = search(p, 6);
    if (result != NULL)
    {
        printf("Found : %d\n", result->data);
    }
    else
    {
        printf("Not Found\n");
    }
    insert(p, 7);
    inOrder(p);
    deleteNode(p,7);
    printf("\n");
    inOrder(p);
    return 0;
}