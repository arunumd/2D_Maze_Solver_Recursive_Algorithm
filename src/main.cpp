/**
 * @file main.cpp
 * @author Arun Kumar Devarajulu <arun89@terpmail.umd.edu>, University of Maryland
 * @license This project is released under the MIT License
 * @copyright Copyright 2012 Arun Kumar Devarajulu. All rights reserved.
 * @date March 17, 2019
 * @brief Implementation file for 2d maze navigation problem using recursive algorithm
 */

#include "../include/recursion.h"
#include <iostream>

/**
  * @brief The 'main' function creates an object of the Maze class and then invokes the 'Action'
  * function. Later it displays the result of the 'Action' function using the 'Spawn' function
  * derived from the same 'Maze' class
  * @param 0 if program was successful
  */
int main() {
    Maze Navigator;
    auto status = Navigator.Action();
    Navigator.Spawn(status);
    return 0;
}
