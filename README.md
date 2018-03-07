# Best-First Robot Navigation

### Students
Christine Anderson
  * <Id number>
  * ander384@mail.chapman.edu

Paul Harnack
  * 1818051
  * harna100@mail.chapman.edu

### Build and Running
* Run `make` to build and run using the included `linsteadTest.txt`
* Run `make build` to just build
* After building, to run `./main <inputfile>`
* It is also possible to run only a specific search `./main <inputfile> <searchToRun>`
	* 1- Case 1: Euclidean distance from N to goal
	* 2- Case 2: Manhattan distance to the goal
	* 3- Case 3: Euclidean with a global cost function
	* 4- Case 4: Manhattan distance with a global cost function
* Run `make clean` to remove all built artifacts


### Problem Description
A robot represented as a point moves in a regular two-dimensional `NxN` grid (e.g., `N = 100`). Each point of the grid is either "free" or "forbidden" (obstacle). From any position `(i,j)` in the grid the robot can reach each of the 4 adjacent positions `(i,j-1), (i,j+1), (i-1,j), (i+1,j)`, if it is not forbidden. A navigation problem consists of finding a path in the grid (sequence of adjacent free points) that connects a given initial position to a given goal position. Each move has a cost of 1.

