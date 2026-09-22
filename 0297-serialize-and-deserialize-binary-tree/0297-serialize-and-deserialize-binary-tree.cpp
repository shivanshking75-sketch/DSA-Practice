class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return build(ss);
    }
    TreeNode* build(istringstream& ss) {
        string val;
        getline(ss, val, ',');
        if (val == "#") return nullptr;
        auto node = new TreeNode(stoi(val));
        node->left = build(ss);
        node->right = build(ss);
        return node;
    }
};