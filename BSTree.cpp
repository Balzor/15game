//
// Created by b9050880 on 16/10/2019.
//

#include <sstream>
#include "BSTree.h"

void BSTree::Print(){
    if(this->root == nullptr){
        std::cout << "{}" << std::endl;
    } else{
        std::cout << BSTree::SubTreeAsString(this->root) << std::endl;
    }
}


std::string vecToString(vector<int>* v) {
    vector<int> a = * v;
    std::stringstream ss;
    for(size_t i = 0; i < a.size(); i++)
    {
        if(i != 0){
            ss << ",";
        }
        ss <<  a[i];
    }
    std::string s = ss.str();
    return s;
}


std::string BSTree::SubTreeAsString(TreeNode* node){
    std::string leftStr;
    if (node->left == nullptr) {
        leftStr = "()";
    } else {
        leftStr = SubTreeAsString(node->left);
    }
    std::string rightStr;
    if (node->right == nullptr) {
        rightStr = "()";
    } else {
        rightStr = SubTreeAsString(node->right);
    }
    std::string result;
    result = "{" + vecToString(node->data) + ", " + leftStr + ", " + rightStr + "}";
    return result;
}

// Insert a new value into the tree
void BSTree::Insert(vector<int> *val) {
    this->Insert(val, this->root);
}

// Insert a new value into the subtree starting at node
void BSTree::Insert(vector<int>* val, TreeNode*& node) {

    if(node == nullptr){
        // Case: node is a nullptr
        // Make a new TreeNode for it to point to
        node = new TreeNode(val);
    } else{
        if(val < node->data){
            // Case: val is < node's data
            this->Insert(val, node->left);
        } else if(val > node->data){
            // Case: val is > node's data
            this->Insert(val, node->right);
        } else{
            // Case: val is equal to node's data
            std::cout << "Warning: Value already exists, so nothing will be done." << std::endl;
        }
    }
}