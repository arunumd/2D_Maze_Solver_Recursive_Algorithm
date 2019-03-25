/**
 * @file recursion.h
 * @author Arun Kumar Devarajulu <arun89@terpmail.umd.edu>, University of Maryland
 * @license This project is released under the MIT License
 * @copyright Copyright 2012 Arun Kumar Devarajulu. All rights reserved.
 * @date March 17, 2019
 * @brief Header file for Maze navigation problem
 */

#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <utility>
#include <array>

/*!
 * The Maze class solves the problem of navigation from a start point denoted
 * by 'S' to a goal point denoted by 'G' in a configuration space with obstacles
 * denoted by '#' and free space denoted by '.'. A valid path between 'S' and 'G'
 * cannot pass through the obstacles '#' and it must always pass through '.'. If
 * a valid path was not found, then the class returns the input grid with a message
 * that a valid path could not be found.
 */
class Maze {
public:
    /*! Constructor for the Maze class initializes the maze with the desired state*/
    Maze() : grid_{{"S#####", ".....#", "#.####", "#.####", "...#.G", "##...#"}} {}

    /*! Default destructor for the Maze class*/
    ~Maze() = default;

    /**
     * @brief The 'Spawn' function simply takes in an array of type std::array and then prints
     * all its elements to the console using std::cout using a range-based for loop
     * @param board An input array of type std::array which gives all the functionalities
     * of a standard C++ array along with some range based iterators and easy copy and return.
     * The array 'board' has the board state for the Maze problem.
     */
    void Spawn(std::array<std::string, 6> board);

    /**
     * @brief Initially the 'Scan' function prompts the user to enter 'X' and 'Y' co-ordinates
     * for start node 'S' and makes verification checks in the maze for the existance of 'S'.
     * If there exists an 'S' in the user given location, it returns an std::pair of that location.
     * Otherwise if the user does not know the location of the start node 'S', then the
     * function scans the whole configuration space and identifies the location of node 'S'
     * and returns the location as an std::pair(y, x) in the array. If the node 'S' was not
     * found anywhere in the configuration space, then the function simply returns an
     * std::pair(-1, -1)
     * @return a pair of (y, x) intercepts for the identified location of node 'S'
     * @return a pair of (-1, -1) if the node 'S' is not found in the configuration space
     */
    const std::pair<int, int> Scan();

    /**
     * @brief The 'Play' function applies four orthogonal moves to the current node after
     * checking whether they are legal moves or not (not in obstacle space and not
     * beyond boundary of array). After every recursion it checks if the new node
     * is goal node, denoted as 'G'. If it is goal node, then the function returns
     * the board with valid path. If not, the function returns the initial state of the maze
     * @param board An array of board state which has the start node, goal node and
     * intermediate nodes (configuration space).
     * @param a Y - intercept for current node in the 2d array
     * @param b X - intercept for current node in the 2d array
     * @return board if a valid path was found
     * @return grid if a valid path does not exist
     */
    std::array<std::string, 6> Play(std::array<std::string, 6> board, int a, int b);

    /**
     * @brief The 'Check' function verifies whether the current location is a legal move
     * or not. To be more precise, it checks the following : if the intercepts 'a' and 'b'
     * are outside the boundaries of the board; and whether there is an obstacle '#' in the
     * current location and returns 'false' if any of these two conditions is true. Otherwise
     * if the current location has either 'S', '.' or 'G', it returns 'true'. This function
     * is useful for making an informed recursion with the 'play' function
     * @param board The current state of grid with start location, end location,
     * obstacles and free space
     * @param a Y - intercept for current node in the 2d array
     * @param b X - intercept for current node in the 2d array
     * @return 'true' if current location is in obstacle-free space
     * @return 'false' if current location is in obstacle space or if outside of
     * configuration space
     */
    bool Check(std::array<std::string, 6> board, int a, int b);

    /**
     * @brief The 'Action' function triggers the game-play by fetching the possible location of
     * start node 'S' from the 'Scan' function. If there exists a valid location other than (-1, -1)
     * then the function attempts to identify a path from start node 'S' to goal node 'G'. If after
     * exploiting all recursive path solvers, the function does not find a valid path, it displays a
     * message stating '\textit{A valid path was not found for the current maze below !}'. Otherwise,
     * the function displays a message '\textit{The start position could not be found anywhere in
     * the array}'
     * @return board with valid path if a valid path was found
     * @return grid without path if a valid path was not found
     */
    std::array<std::string, 6> Action();

private:
    /*! Container initialization for holding our 2d maze*/
    const std::array<std::string, 6> grid_;
};

#endif //RECURSION_H
