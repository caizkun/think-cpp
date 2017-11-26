// summary for tree

// Able to write a TreeNode class
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

//>>>>>>>>>>> Depth-First Traversal & Breadth(Level)-First Traversal

// 1. Pre-order Traversal
void preorder_traverse(TreeNode *root, vector<int> &vals) {
    if (root == NULL) return;
    stack<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        root = nodes.top();
        nodes.pop();
        vals.push_back(root->val);  // or do something
        if (root->right != NULL) {
            nodes.push(root->right);
        }
        if (root->left != NULL) {
            nodes.push(root->left);
        }
    }
    return;
}

// 2. In-order Traversal
void inorder_traverse(TreeNode *root, vector<int> &vals) {
    if (root == NULL) return;
    stack<TreeNode *> nodes;
    while (root != NULL || !nodes.empty()) {
        if (root != NULL) {
            nodes.push(root);
            root = root->left;
        } else {
            root = nodes.top();
            nodes.pop();
            vals.push_back(root->val);  // or do something
            root = root->right;
        }
    }
    return;
}

// 3. Post-order Traversal
void postorder_traverse(TreeNode *root, vector<int> &vals) {
    if (root == NULL) return;
    stack<TreeNode *> nodes;
    TreeNode *prev = NULL;  // for later check
    while (root != NULL || !nodes.empty()) {
        if (root != NULL) {
            nodes.push(root);
            root = root->left;
        } else {
            TreeNode *curr = nodes.top();   // needs a new pointer
            if (curr->right != NULL && prev != curr->right) {   // check if processed
                root = curr->right;
            } else {
                vals.push_back(curr->val);  // or do something
                prev = curr;
                nodes.pop();
            }
        }
    }
    return;
}

// 4. Breadth-First Traversal
void level_traverse(TreeNode *root, vector<int> &vals) {
    if (root == NULL) return;
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        root = nodes.top();
        nodes.pop();
        vals.push_back(root->val);
        if (root->left != NULL) {
            nodes.push(root->left);
        }
        if (root->right != NULL) {
            nodes.push(root->right);
        }
    }
    return;
}


// difference between traverse and divide & conquer
// traverse:            taking notes while trasversing the tree
// divide & conquer:    making decision based on the notes passed from subtrees









