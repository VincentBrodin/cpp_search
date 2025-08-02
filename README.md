# Maze Solver (C++)

This is a simple C++ program that solves ASCII mazes.
The mazes are represented as text files where:

* `#` represents walls
* (space) represents open paths
* `S` is the start point
* `E` is the end point

The solver finds a path from `S` to `E` through the open spaces.

## Features

* Reads ASCII map files as input
* Finds and outputs a solution path from start (`S`) to end (`E`)
* Supports multiple maps in one run
* Uses CMake for easy building

## How to Build and Run

1. Clone the repo:

   ```bash
   git clone https://github.com/VincentBrodin/cpp_search.git
   cd cpp_search
   ```

2. Create and enter the build directory:

   ```bash
   mkdir build
   cd build
   ```

3. Run CMake and compile:

   ```bash
   cmake ..
   make
   ```

4. Run the solver with one or more map files:

   ```bash
   ./bin/app [PATH_TO_MAP_A] [PATH_TO_MAP_B] ...
   ```

## Example

```bash
./bin/app ../maps/maze1.txt ../maps/maze2.txt
```

Each map file should contain a maze made of `#`, spaces, and exactly one `S` and one `E`.

Great website for creating ascii maps: [www.asciiart.eu](https://www.asciiart.eu/ascii-maze-generator)
