// summary for segment tree

// A complele binary tree whose node stores the information within an interval
// Useful for finding extreme values within an interval

class SegmentTreeNode {
public:
    int val;        // special value like max, min, ...
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end) {  // constructor
        this->start = start;
        this->end = end;
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


// 1. build a segment tree

SegmentTreeNode * build(int start, int end) {
    // write your code here
    if (start > end) return NULL;
    SegmentTreeNode *root = new SegmentTreeNode(start, end);
    if (start == end) return root;
    int mid = (start + end) / 2;
    root->left = build(start, mid);
    root->right = build(mid + 1, end);
    return root;
}
