/**
 * @file recursion.cpp
 * @author Arun Kumar Devarajulu <arun89@terpmail.umd.edu>, University of Maryland
 * @license This project is released under the MIT License
 * @copyright Copyright 2012 Arun Kumar Devarajulu. All rights reserved.
 * @date March 17, 2019
 * @brief Source file for Maze navigation problem
 */

#include "../include/recursion.h"
#include <iostream>
#include <utility>
#include <array>

void Maze::Spawn(std::array<std::string, 6> board) {
    for (auto &item : board) {
        std::cout << item << std::endl;
    }
}

const std::pair<int, int> Maze::Scan() {
    std::cout << "Do you know where is the location of node 'S' ?\n"
                 "Please type 'Y' for Yes and 'N' for No below :\n"
              << std::endl;
    char input = 'A';
    std::cin >> input;
    switch (input) {
        case 'Y':
        case 'y': {
            int z1, z2, temp;
            z1 = -1;
            z2 = -1;
            std::cout << "Please enter the x - coordinate and then the"
                         " y - coordinate for 'S' below" << std::endl;
            while (std::cin >> temp) {
                if (std::cin.fail() || temp < 0 || temp >= grid_.size()) {
                    std::cout << "Please enter valid co-ordinates within"
                                 " the scope of the maze" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                } else if (temp >= 0 && temp < grid_.size()) {
                    if (z1 == -1) z1 = temp;
                    else if (z2 == -1) z2 = temp;
                } else break;
                if (z1 != -1 && z2 != -1 && grid_[z2][z1] != 'S') {
                    std::cout << "'S' was not found in that location" << std::endl;
                    z1 = -1;
                    z2 = -1;
                }
                if (temp != -1 && z1 != -1 && z2 != -1 && grid_[z2][z1] == 'S')
                    break;
            }
            return std::make_pair(z2, z1);
        }
        default: {
            for (int i = 0; i <= 6; i++) {
                for (std::string::size_type j = 0; j < grid_[i].size(); ++j) {
                    if (grid_[i][j] == 'S' || grid_[i][j] == 's') {
                        return std::make_pair(i, j);
                    }
                }
            }
            break;
        }
    }
    return std::make_pair(-1, -1);
}

bool Maze::Check(const std::array<std::string, 6> board, int a, int b) {
    if (a < board[1].size() && a >= 0 && b < board[1].size() && b >= 0) {
        if (board[a][b] == '#' || board[a][b] == '+') {
            return false;
        } else if (board[a][b] == '.' ||
                   board[a][b] == 'S' ||
                   board[a][b] == 'G') {
            return true;
        }
    }
    return false;
}

std::array<std::string, 6> Maze::Play(std::array<std::string, 6> board, int a, int b) {
    if (board[a][b] == 'G' || board[a][b] == 'g') {
        board[0][0] = 'S';
        return board;
    }
    if (board[a][b] == '.' || board[a][b] == 'S') board[a][b] = '+';
    if (Check(board, a + 1, b)) return Play(board, a + 1, b);
    if (Check(board, a - 1, b)) return Play(board, a - 1, b);
    if (Check(board, a, b + 1)) return Play(board, a, b + 1);
    if (Check(board, a, b - 1)) return Play(board, a, b - 1);
    return grid_;
}

std::array<std::string, 6> Maze::Action() {
    auto member = Scan();
    if (member.first < 0 || member.second < 0 || member.first > grid_.size() ||
        member.second > grid_.size()) {
        std::cout << "The start position could not be found anywhere in the array."
                     " Hence the program could not find a valid path for the "
                     "following grid !" << std::endl;
        return grid_;
    } else {
        auto status = Play(grid_, member.first, member.second);
        if (status != grid_) {
            std::cout << "A valid path exists. The path is shown below !" << std::endl;
            return status;
        } else {
            std::cout << "A valid path was not found for the current maze below !" << std::endl;
            return status;
        }
    }
}
