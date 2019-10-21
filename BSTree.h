//
// Created by b9050880 on 16/10/2019.
//

#ifndef INC_15GAME_BSTREE_H
#define INC_15GAME_BSTREE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

struct TreeNode{
    // member vars
//    int data;
    vector<int> data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* up;
    TreeNode* down;


    // constructor
	TreeNode(const vector<int>& data) : data(data), left(nullptr), right(nullptr),down(nullptr),up(nullptr) {};

public:
//    TreeNode():root(nullptr){}
//    explicit TreeNode(TreeNode* rootNode): root(rootNode) {}

    void Print();
    //TreeNode* Insert(const vector<int>& val, Direction dir);
    static TreeNode* Insert(const vector<int>& val, TreeNode*& node, Direction dir);
private:
//    TreeNode* root;
    static string SubTreeAsString(TreeNode *node);

};

//class BSTree {
//public:
//    BSTree():root(nullptr){}
//    explicit BSTree(TreeNode* rootNode): root(rootNode) {}
//
//    void Print();
//    TreeNode* Insert(const vector<int>& val, Direction dir);
//
//private:
//    TreeNode* root;
//    static string SubTreeAsString(TreeNode *node);
//    TreeNode* Insert(const vector<int>& val, TreeNode*& node, Direction dir);
//};

#endif //INC_15GAME_BSTREE_H
