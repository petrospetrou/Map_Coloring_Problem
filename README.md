
# Graph Coloring Project

## Introduction
This project involves implementing a graph coloring algorithm in C. Developed as part of a university course in Data Structures and Algorithms course, it demonstrates proficiency in implementing algorithms in C to solve a complex problem: coloring a graph using the least number of colors without adjacent nodes sharing the same color.

## Project Structure
- `main.c`: The main entry point of the program, handling file reading, graph initialization, and function calls for graph coloring.
- `testing.txt`: Contains the needed data to execute the program.

## Features
- **Graph Initialization**: Constructs a graph using a two-dimensional array to create an adjacency matrix.
- **Graph Coloring**: Implements a graph coloring algorithm to color the graph with the minimum number of colors.
- **File Handling**: Reads input data from a file to construct the graph.

## Challenges
- Automated adjacency matrix implementation.
- Reading and storing file data into arrays.
- Compatibility issues with different operating systems, specifically a Segmentation Fault encountered in CentOS 7.

## Usage
1. Compile the program using a C compiler, for instance: `gcc main.c -o graphcoloring`.
2. Run the compiled program: `./graphcoloring`.
3. The program will read the input file, initialize the graph, and apply the coloring algorithm.

## Contributing
As this project is part of a university assignment, it is not open for external contributions.

## License
All rights reserved. This project is proprietary and is not licensed for use, reproduction, or distribution.
