#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int item;
    struct Node* left;
    struct Node* right;
};
typedef struct Node node;
void insert(node **tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->item = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->item)
    {
        insert(&(*tree)->left,val);
    }
    else if(val > (*tree)->item)
    {
        insert(&(*tree)->right,val);
    }
}
void DisplayInorder(node *tree)
{
    if(tree)
    {
        DisplayInorder(tree->left);
        printf("%d\n",tree->item);
        DisplayInorder(tree->right);
    }
}
int main()
{
    node *root;
    node *tmp;
    root  = NULL;
    // inserting with random input
    insert(&root,9);
    insert(&root,4);
    insert(&root,15);
    insert(&root,6);
    insert(&root,12);
    insert(&root,17);
    insert(&root,2);
    printf("Display Inorder\n");
    DisplayInorder(root);
    return 0;

}