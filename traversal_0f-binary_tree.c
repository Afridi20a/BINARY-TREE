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

//function of pre order traversal
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Leaf count function
int countLeaf(struct node *root)
{
    // Tree empty
    if(root == NULL)
    {
        return 0;
    }

    // Leaf node
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    // Left subtree + Right subtree
    return countLeaf(root->left) + countLeaf(root->right);
}

//function of post order traversal
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

//function of in order traversal
void inOrder(struct node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct node *p = create_node(4);
    struct node *p1 = create_node(1);
    struct node *p2 = create_node(6);
    struct node *p3 = create_node(5);
    struct node *p4 = create_node(2);

    //                  4
    //                 / \
    //                1   6
    //               / \  
    //              5   2

    // linking the root with the node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("pre orderd binary traversal\n");
    preOrder(p);
    printf("\npost orderd binary traversal\n");
    postOrder(p);
    printf("\nin orderd binary traversal\n");
    inOrder(p);
    printf("\n");
    printf("%d ",countLeaf(p));
    return 0;
}
