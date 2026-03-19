class Solution {
  public:

    // Helper struct to carry info upward through the post-order traversal
    struct Info {
        bool isBST;
        int  size;
        int  minVal;
        int  maxVal;
    };

    int ans = 0; // tracks the global maximum BST size

    Info postorder(Node* node) {
        // Base case: null node is a valid BST of size 0.
        // Sentinels: minVal=INT_MAX, maxVal=INT_MIN so that any real
        // node value automatically satisfies the BST comparison.
        if (node == nullptr)
            return {true, 0, INT_MAX, INT_MIN};

        Info left  = postorder(node->left);
        Info right = postorder(node->right);

        // Current subtree is a valid BST if:
        //   1. Both children are valid BSTs
        //   2. node->data is strictly greater than left subtree's max
        //   3. node->data is strictly less than right subtree's min
        if (left.isBST && right.isBST
                && node->data > left.maxVal
                && node->data < right.minVal) {

            int size = left.size + right.size + 1;
            ans = max(ans, size);

            // Propagate the true value range of this subtree upward
            return {
                true,
                size,
                min(left.minVal,  node->data),   // leftmost value in subtree
                max(right.maxVal, node->data)     // rightmost value in subtree
            };
        }

        // Not a BST — propagate failure.
        // minVal/maxVal are set to extremes so any ancestor also fails the check.
        return {false, 0, INT_MIN, INT_MAX};
    }

    int largestBst(Node* root) {
        ans = 0;
        postorder(root);
        return ans;
    }
};
