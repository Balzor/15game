//
// Created by b9050880 on 16/10/2019.
//

#ifndef INC_15GAME_BSTREE_H
#define INC_15GAME_BSTREE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode{
    // member vars
//    int data;
    vector<int> * data;
    TreeNode* left;
    TreeNode* right;

    // constructor
	TreeNode(vector<int>* data);
	~TreeNode();
};

class BSTree {
public:
    BSTree():root(nullptr){}
    explicit BSTree(TreeNode* rootNode): root(rootNode) {}

    void Print();
    void Insert(vector<int> *val);

private:
    TreeNode* root;
    static string SubTreeAsString(TreeNode *node);
    void Insert(vector<int> *val, TreeNode*& node);
};

#endif //INC_15GAME_BSTREE_H
