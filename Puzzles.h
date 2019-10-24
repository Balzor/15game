//
// Created by b9050880 on 16/10/2019.
//

#ifndef INC_15GAME_PUZZLES_H
#define INC_15GAME_PUZZLES_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode{
public:
    //https://stackoverflow.com/questions/20511347/a-good-hash-function-for-a-vector
    static std::size_t hash(std::vector<int> const& vec) {
        std::size_t seed = vec.size();
        for(auto& i : vec) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
#endif //INC_15GAME_PUZZLES_H
