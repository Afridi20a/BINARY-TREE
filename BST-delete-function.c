// deleteNode()

// 1. root == NULL ? → return NULL

// 2. key < root->data ?
//       → Left-এ যাও

// 3. key > root->data ?
//       → Right-এ যাও

// 4. Node পাওয়া গেছে

//    ├── Leaf ?
//    │      free + return NULL
//    │
//    ├── Only Left ?
//    │      temp = left
//    │      free
//    │      return temp
//    │
//    ├── Only Right ?
//    │      temp = right
//    │      free
//    │      return temp
//    │
//    └── Two Children ?
//           successor বের করো
//           data copy করো
//           successor delete করো

// 5. return root





// Find the minimum node (Inorder Successor)
// struct node *minValueNode(struct node *root)
// {
//     if(root == NULL || root->left == NULL)
//     {
//         return root;
//     }

//     return minValueNode(root->left);
// }

// // Delete a node from BST
// struct node *deleteNode(struct node *root, int key)
// {
//     // Base Case
//     if(root == NULL)
//     {
//         return NULL;
//     }

//     // Search in Left Subtree
//     if(key < root->data)
//     {
//         root->left = deleteNode(root->left, key);
//     }

//     // Search in Right Subtree
//     else if(key > root->data)
//     {
//         root->right = deleteNode(root->right, key);
//     }

//     // Node Found
//     else
//     {
//         // Case 1: Leaf Node
//         if(root->left == NULL && root->right == NULL)
//         {
//             free(root);
//             return NULL;
//         }

//         // Case 2: Only Left Child
//         else if(root->right == NULL)
//         {
//             struct node *temp = root->left;
//             free(root);
//             return temp;
//         }

//         // Case 3: Only Right Child
//         else if(root->left == NULL)
//         {
//             struct node *temp = root->right;
//             free(root);
//             return temp;
//         }

//         // Case 4: Two Children
//         else
//         {
//             struct node *succ = minValueNode(root->right);

//             // Copy successor's data
//             root->data = succ->data;

//             // Delete the successor node
//             root->right = deleteNode(root->right, succ->data);
//         }
//     }

//     return root;
// }