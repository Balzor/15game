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
    vector<int> * data1;
//    int data;
    vector<int> * data;
    TreeNode* left;
    TreeNode* right;

    // constructor
    TreeNode(vector<int> * data): data(data), left(nullptr), right(nullptr) {}
    //TreeNode(vector<int> *data1):data1(data1),left(nullptr),right(nullptr){}
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