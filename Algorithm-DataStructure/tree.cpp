// summary for tree

// Able to write a TreeNode class
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
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

// A general method for writing depth-first traversal
class Guide {
public:
    int operation;
    TreeNode *node;
    
    Guide(int operation, TreeNode *node) {
        this->operation = operation;    // 0: visit, 1: print;
        this->node = node;
    }
};

void postorder_traverse(TreeNode *root, vector<int> &vals) {
    stack<Guide> path;
    path.push(Guide(0, root));
    while (!path.empty()) {
        Guide curr = path.top();
        path.pop();
        if (curr.node == nullptr) continue;
        
        if (curr.operation == 1) {
            vals.push_back(curr.node->val);
        } else {
            // push guide in the reverse order
            
            // post-order
            path.push(Guide(1, curr.node));
            path.push(Guide(0, curr.node->right));
            path.push(Guide(0, curr.node->left));
            
            // in-order
            path.push(Guide(0, curr.node->right));
            path.push(Guide(1, curr.node));
            path.push(Guide(0, curr.node->left));
            
            // pre-order
            path.push(Guide(0, curr.node->right));
            path.push(Guide(0, curr.node->left));
            path.push(Guide(1, curr.node));
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

// another form: process level by level
void level_traverse(TreeNode *root, vector<int> &vals) {
    if (root == NULL) return;
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        int size = nodes.size();
        for (int i = 0; i < size; ++i) {
            root = nodes.front();
            nodes.pop();
            vals.push_back(root->val);
            if (root->left != NULL) {
                nodes.push(root->left);
            }
            if (root->right != NULL) {
                nodes.push(root->right);
            }
        }
    }
    return;
}



// difference between traverse and divide & conquer
// traverse:            taking notes while trasversing the tree
// divide & conquer:    making decision based on the notes passed from subtrees









