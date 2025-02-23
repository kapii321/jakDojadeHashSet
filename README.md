# City Navigation System

**Overview**

This project implements a navigation system for a rectangular map divided into squares.
The map consists of empty fields (impassable), roads (passable in both directions), and cities (passable like roads). 
Additionally, certain cities are connected by one-way air travel routes.
The system allows users to determine the shortest travel time between cities using road and air connections, with optional route details.

**Features**

- **Custom Data Structures:** Implements a DoubleLinkedList and HashSet instead of standard STL containers.

- **Graph Representation:** Represents the map as a graph where roads and cities act as nodes.

- **Pathfinding Algorithms:** Uses BFS for unweighted shortest paths and Dijkstra’s algorithm for weighted shortest paths with air travel.

- **Memory Management:** Custom implementation of data structures with manual memory handling (smart pointers from the standard library are not used).

**Input Format**

1. First line: w h (width and height of the map).

2. Next h lines: Map representation using:

- . for empty fields (impassable)

- \# for roads (passable)

- \* for cities (passable, starting or ending points of names)

-Letters/numbers for city names (impassable)

3. Next line: k (number of one-way air connections)

4. Next k lines: source destination time (air connections between cities with flight duration in minutes)

5. Next line: q (number of queries)

6. Next q lines: source destination type

- type = 0: Query for shortest time only

- type = 1: Query for shortest time and route

**Output Format**

For each query, output a single line:

- If type = 0: Print the shortest travel time.

- If type = 1: Print the shortest travel time followed by the intermediate cities visited.

Example

Input:
```

20 20
.........GDANSK.....
........*...........
........#...........
........#...........
*##################.
#SZCZECIN.........#.
#.................#.
##................#.
.############*#####.
.#...WARSZAWA.......
.#..................
.#############......
.#...........#......
.#..WROCLAW.##......
.#..*.......*.......
.####.......#KIELCE.
......*##.#########.
.OPOLE..#.*.......#.
........#.KRAKOW..#.
........###########.
0
3
KIELCE KRAKOW 0
KRAKOW GDANSK 0
KRAKOW GDANSK 1
```

Output:
```
5
40
40 KIELCE SZCZECIN
```

**Technologies Used**

- C++ (without STL containers)

- Custom implementations of linked lists and hash sets

- BFS and Dijkstra’s algorithm for pathfinding

**Notes**

- Proper memory management is implemented, ensuring no memory leaks.

- Code readability is prioritized, with well-structured classes and functions.

- No standard smart pointers or string classes are used.

This project effectively simulates a pathfinding system for city navigation while enforcing constraints on data structure usage and memory management.

