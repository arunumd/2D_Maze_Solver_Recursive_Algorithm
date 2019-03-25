[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# 2D_Maze_Solver_Recursive_Algorithm
This project is related to finding a valid path between start node 'S' and a goal node 'G' in a 2D array using C++11. 
The algorithm is based on multiple recursions to identify a valid path. If after exploitation of all recursive calls the algorithm doesn't find a path, 
then the algorithm returns the initial state of the maze. Otherwise it returns a valid path in the maze.

# Assumptions
 - You have a C++ 14 compiler on your Mac/ Ubuntu/ Windows
 - You are running a computer with Windows/ Ubuntu/ Mac
 - You have the CMake build system with a minimum version 3.13, installed on your machine (Ubuntu/ Mac)
 - If you are using a Windows, then you have CMake GUI and MinGW Compiler
 - If you are using a Windows, you know how to configure and generate cmake files from the CMake GUI

# Author
Arun Kumar Devarajulu - University of Maryland, College Park

# Build and Run
If you are using a windows computer then do the following in your command prompt after 
doing configure and generate steps in your CMake GUI:
```
git clone https://github.com/arunumd/2D_Maze_Solver_Recursive_Algorithm.git
cd 2D_Maze_Solver_Recursive_Algorithm
mkdir build
cd build
make.exe
```

**Note** : If for some reason the make.exe in the above steps fails, then you have to identify the valid path and name of your
make.exe from your MinGW compiler

If you are using a Mac or Linux then copy paste the following commands on your terminal:
```
git clone https://github.com/arunumd/2D_Maze_Solver_Recursive_Algorithm.git
cd ~/2D_Maze_Solver_Recursive_Algorithm
mkdir build
cd build
cmake.. && make
```