#ifndef LEETCODESANDBOX_TREENODE_H
#define LEETCODESANDBOX_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void createTree(TreeNode* node, int i, std::vector<std::string>& arr) {
    if (node != nullptr) {
        if (2 * i + 1 < arr.size()) {
            if (arr[2 * i + 1] == "null")
                node->left = nullptr;
            else
                node->left = new TreeNode(stoi(arr[2 * i + 1]));
            createTree(node->left, 2 * i + 1, arr);
        }


        if (2 * i + 2 < arr.size()) {
            if (arr[2 * i + 2] == "null")
                node->right = nullptr;
            else
                node->right = new TreeNode(stoi(arr[2 * i + 2]));
            createTree(node->right, 2 * i + 2, arr);
        }
    }
}


TreeNode* createBinaryTree(std::vector<std::string>& arr) {
    if (arr.size() == 0)
        return nullptr;
    TreeNode *head = new TreeNode(stoi(arr[0]));
    createTree(head, 0, arr);
    return head;
}


#endif //LEETCODESANDBOX_TREENODE_H
