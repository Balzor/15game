//
// Created by b9050880 on 16/10/2019.
//

#include <sstream>
#include "BSTree.h"
//#include<bits/stdc++.h>


void TreeNode::Print(){
//    if(this->node == nullptr){
//        std::cout << "{}" << std::endl;
//    } else{
        std::cout << TreeNode::SubTreeAsString(this) << std::endl;
//    }
}


std::string vecToString(const vector<int>& v) {
    std::stringstream ss;
    for(size_t i = 0; i < v.size(); i++)
    {
        if(i != 0){
            ss << ",";
        }
        ss <<  v[i];
    }
    std::string s = ss.str();
    return s;
}


std::string TreeNode::SubTreeAsString(TreeNode* node){
    //left
    std::string leftStr;
    if (node->left == nullptr) {
        leftStr = "()";
    } else {
        leftStr = SubTreeAsString(node->left);
    }
    //right
    std::string rightStr;
    if (node->right == nullptr) {
        rightStr = "()";
    } else {
        rightStr = SubTreeAsString(node->right);
    }
    //up
    std::string upStr;
    if(node->up==nullptr){
        upStr="()";
    }else {
        upStr = SubTreeAsString(node->up);
    }
    //down
    std::string downStr;
    if(node->down==nullptr){
        downStr="()";
    }else {
        downStr = SubTreeAsString(node->down);
    }

    std::string result;
    result = "{" + vecToString(node->data) + ", left:[" + leftStr + "], right:[" + rightStr + "], up:[" + upStr + "], down:[" + downStr + "]}";
    return result;
}

// Insert a new value into the tree
//TreeNode* TreeNode::Insert(const vector<int>& val, Direction dir) {
//    return this->Insert(val, this, dir);
//}

// Insert a new value into the subtree starting at node
TreeNode* TreeNode::Insert(const vector<int>& val, TreeNode*& node, Direction dir) {
    if(node == nullptr){
        // Case: node is a nullptr
        // Make a new TreeNode for it to point to
        node = new TreeNode(val);
        return node;
    } else{
        if(val == node->data){
            std::cout << "Warning: Value already exists, so nothing will be done." << std::endl;
        }else{
            switch (dir)
            {
                case LEFT:
                    return Insert(val, node->left, dir);

                case RIGHT:
                    return Insert(val, node->right, dir);

                case UP:
                    return Insert(val, node->up, dir);

                case DOWN:
                    return Insert(val, node->down, dir);

                default:
                    std::cout << "unexpected error try again"<<std::endl;
                    break;
            }
        }
    }
    return nullptr;
}
