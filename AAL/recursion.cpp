#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <ctime>
#include <fstream>


using namespace std;
struct Node {
	Node(int r, int c, int h) : row(r), col(c), height(h) {}
	int row;
	int col;
	int height;
	bool operator<(const Node& n1) const {
		return height > n1.height;
	}
};

class BetterSolution {
public:
	priority_queue<Node> nodesQueue;
	vector<vector<bool> > visited;
	int result;
	int numberVisited;
	BetterSolution() {
		result = 0;
		numberVisited = 0;
	}
	void checkNeighbor(int r, int c, vector<vector<int> >& heights, int& baseHeight) {

		visited[r][c] = true;
		numberVisited += 1;
		if (heights[r][c] >= baseHeight) {
			Node newBoundary(r, c, heights[r][c]);
			nodesQueue.push(newBoundary);
			return;
		}
		else {
			result += baseHeight - heights[r][c];
			if (r - 1 >= 0 && !visited[r - 1][c]) checkNeighbor(r - 1, c, heights, baseHeight);//up
			if (c + 1 < visited[0].size() && !visited[r][c + 1]) checkNeighbor(r, c + 1, heights, baseHeight);//right
			if (r + 1 < visited.size() && !visited[r + 1][c]) checkNeighbor(r + 1, c, heights, baseHeight);//down
			if (c - 1 >= 0 && !visited[r][c - 1]) checkNeighbor(r, c - 1, heights, baseHeight);//left
		}
	}

	int trapRainWater(vector<vector<int>>& heights) {
		result = 0;
		numberVisited = 0;
		visited.clear();
		if (heights.size() == 0) return 0;
		int r = heights.size();
		int c = heights[0].size();
		int total = r*c;
		for (int i = 0; i < r; i++) {
			vector<bool> oneRow(c, false);
			visited.push_back(oneRow);
			oneRow.clear();
		}


		for (int i = 0; i < c; i++) {
			Node topNode(0, i, heights[0][i]);
			Node bottomNode(r - 1, i, heights[r - 1][i]);
			nodesQueue.push(topNode);
			nodesQueue.push(bottomNode);
			visited[0][i] = true;
			visited[r - 1][i] = true;
			numberVisited += 2;
		}

		for (int i = 1; i < r - 1; i++) {
			Node leftNode(i, 0, heights[i][0]);
			Node rightNode(i, c - 1, heights[i][c - 1]);
			nodesQueue.push(leftNode);
			nodesQueue.push(rightNode);
			visited[i][0] = true;
			visited[i][c - 1] = true;
			numberVisited += 2;
		}
		while (numberVisited < total) {
			Node base = nodesQueue.top();
			nodesQueue.pop();
			int r0 = base.row;
			int c0 = base.col;
			if (r0 - 1 >= 0 && !visited[r0 - 1][c0]) checkNeighbor(r0 - 1, c0, heights, base.height);//up
			if (c0 + 1 < c && !visited[r0][c0 + 1]) checkNeighbor(r0, c0 + 1, heights, base.height);//right
			if (r0 + 1 < r && !visited[r0 + 1][c0]) checkNeighbor(r0 + 1, c0, heights, base.height);//down
			if (c0 - 1 >= 0 && !visited[r0][c0 - 1]) checkNeighbor(r0, c0 - 1, heights, base.height);//left
		}
		return result;

	}
};
