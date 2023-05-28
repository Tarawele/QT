#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

class TreeNode {
public:
    TreeNode(int depth) {
        data = reinterpret_cast<size_t>(this);
        if (depth == 0) {
            left = 0;
            right = 0;
            data = 1;
        } else {
            left = new TreeNode(depth - 1);
            right = new TreeNode(depth - 1);
        }
    }
    void readTree() {
        cout << data << endl;
        if (left) {
            cout << "left: ";
            left->readTree();
        }
        if (right) {
            cout << "right: ";
            right->readTree();
        }
    }
    ~TreeNode() {
        cout << "deleted : " << data << endl;
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
    TreeNode* left;
    TreeNode* right;
    size_t data;
};

//void createTree(TreeNode* currentNode, int depth) {
//    static int dataSource = 1;
//    if (depth < 2) {
//        currentNode->data = ++dataSource;
//        currentNode->left = new TreeNode(depth);
//        currentNode->right = new TreeNode();
//    } else {
//        currentNode->data = ++dataSource;
//        currentNode->left = new TreeNode();
//        createTree(currentNode->left, depth -1);
//        currentNode->right = new TreeNode();
//        createTree(currentNode->right, depth -1);
//    }
//}

void readTree(TreeNode* currentNode) {
;
}

int main(void) {
    TreeNode* root = new TreeNode(2);
    root->readTree();
//    createTree(root, 2);
//    readTree(root);
    delete root;
    return 0;
}
