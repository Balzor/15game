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
    size_t data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* up;
    TreeNode* down;

    // constructor
	TreeNode(const size_t & data) : data(data), left(nullptr), right(nullptr),down(nullptr),up(nullptr) {};

public:

    void Print();
    static TreeNode* Insert(const size_t& val, TreeNode*& node, Direction dir);
    static bool ifNodeExists(TreeNode* node, const size_t& val);

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
