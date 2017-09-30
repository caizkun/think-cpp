// summary for segment tree

// A complele binary tree whose node stores the information within an interval
// Useful for finding extreme values within an interval

class SegmentTreeNode {
public:
    int val;        // special value like max, min, ...
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int val) {  // constructor
        this->start = start;
        this->end = end;
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    ~SegmentTreeNode();
    // add your method
};


//>>>>>>>> Complexity

// build    O(n)
// modify   O(logn)
// query    O(logn)


// Bewloe we take the segment tree with val = max(start, end) as example

// 1. build a segment tree
SegmentTreeNode * build(vector<int> &A, int start, int end) {
    if (start > end) return NULL;
    if (start == end) {
        return new SegmentTreeNode(start, end, A[start]);
    }
    SegmentTreeNode *node = new SegmentTreeNode(start, end, A[start]);
    int mid = start + (end - start) / 2;
    node->left = build(A, start, mid);
    node->right = build(A, mid+1, end);
    if (node->left != NULL) {
        node->val = max(node->val, node->left->val);
    }
    if (node->right != NULL) {
        node->val = max(node->val, node->right->val);
    }
    return node;
}


// 2. query
int query(SegmentTreeNode *root, int start, int end) {
    if (root == NULL) return -1;
    if (start > root->end || end < root->start) return -1;
    
    if (start == root->start && end == root->end) {
        return root->max;
    }
    
    int rootMid = root->start + (root->end - root->start) / 2;
    if (end <= rootMid) {
        return query(root->left, start, end);
    } else if (start > rootMid) {
        return query(root->right, start, end);
    } else {
        int leftMax = query(root->left, start, rootMid);
        int rightMax = query(root->right, rootMid + 1, end);
        return max(leftMax, rightMax);
    }
}

// modify
void modify(SegmentTreeNode *root, int index, int value) {
    if (root == NULL) return;
    if (index < root->start || index > root->end) return;
    
    if (index == root->start && index == root->end) {
        root->max = value;
        return;
    }
    
    int rootMid = root->start + (root->end - root->start) / 2;
    if (index <= rootMid) {
        modify(root->left, index, value);
    } else {
        modify(root->right, index, value);
    }
    root->max = max(root->left->max, root->right->max);
    return;
}


