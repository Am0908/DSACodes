int diameter(struct Node* tree)
{
    // base case where tree is empty
    if (tree == NULL)
        return 0;

    // get the height of left and right sub-trees
    int lheight = height(tree->lchild);
    int rheight = height(tree->rchild);

    // get the diameter of left and right sub-trees
    int ldiameter = diameter(tree->lchild);
    int rdiameter = diameter(tree->rchild);

    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1

    return max(lheight + rheight + 1,
               max(ldiameter, rdiameter));
}
