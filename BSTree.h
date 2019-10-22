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
    vector<int> data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* up;
    TreeNode* down;

    // constructor
	TreeNode(const vector<int>& data) : data(data), left(nullptr), right(nullptr),down(nullptr),up(nullptr) {};

public:

    void Print();
    static TreeNode* Insert(const vector<int>& val, TreeNode*& node, Direction dir);
    static bool ifNodeExists(TreeNode* node, const vector<int>& val);

    //https://stackoverflow.com/questions/20511347/a-good-hash-function-for-a-vector
    static std::size_t hash(std::vector<int> const& vec) {
        std::size_t seed = vec.size();
        for(auto& i : vec) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }

private:
    static string SubTreeAsString(TreeNode *node);


};
#endif //INC_15GAME_BSTREE_H
