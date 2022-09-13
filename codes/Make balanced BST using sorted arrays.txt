class Solution {
public:
    vector<int> working;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        working = nums;
        return buildTree(lo, hi);
    }
    TreeNode* buildTree(int lo, int hi){
        TreeNode* root;
        if(lo <= hi){
            int mid = ceil((float)(lo + hi) / 2);
            root = new TreeNode(working[mid]);
            root->left = buildTree(lo, mid - 1);
            root->right = buildTree(mid + 1, hi);
        }else{
            return NULL;
        }
        return root;
    }
};

