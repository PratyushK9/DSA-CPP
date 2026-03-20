class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        
        Node* curr = root;
        
        while (curr) {
            if (curr->data == key) {
                
                // Finding predecessor 
                if (curr->left) {
                    Node* temp = curr->left;
                    while (temp->right) {
                        temp = temp->right;
                    }
                    pre = temp;
                }
                
                // finding successor
                if (curr->right) {
                    Node* temp = curr->right;
                    while (temp->left) {
                        temp = temp->left;
                    }
                    suc = temp;
                }
                
                break;
            }
            else if (key < curr->data) {
                suc = curr;          // potential successor
                curr = curr->left;
            }
            else {
                pre = curr;          // potential predecessor
                curr = curr->right;
            }
        }
        
        return {pre, suc};
    }
};
