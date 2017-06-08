
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <ctime>
#include <fstream>
#include <climits>


using namespace std;
class WorseSolution {
	struct Point {
		int height;
		int level;
		int x;
		int y;
		Point() {}

		Point(int _height, int _level, int _x, int _y)
		{
			height = _height;
			level = _level;
			x = _x;
			y = _y;
		}

		bool operator < (const Point &point)const
		{
			return point.level < level;
		}
	};
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int result = 0;
		if (heightMap.size() == 0 || heightMap[0].size() == 0)
			return result;
		int n = heightMap.size();
		int m = heightMap[0].size();
		int current_level = 0;
		int previous_level = 0;
		int coordinateX = 0;
		int coordinateY = 0;
		priority_queue<Point> pointsQueue;
		vector<vector<Point>> matrix(n, vector<Point>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					Point point(heightMap[i][j], heightMap[i][j], i, j);
					pointsQueue.push(point);
					matrix[i][j] = point;
				}
				else {
					Point newPoint(heightMap[i][j], INT_MAX, i, j);
					matrix[i][j] = newPoint;
				}
			}
		}

		Point u;
		Point v;
		while (!pointsQueue.empty()) {
			u = pointsQueue.top();
			pointsQueue.pop();

			for (int i = 0; i < 4; ++i) {
				coordinateX = u.x + neighbour[i][0];
				coordinateY = u.y + neighbour[i][1];
				if (coordinateX >= 0 && coordinateX < n && coordinateY >= 0 && coordinateY < m) {
					v.height = matrix[coordinateX][coordinateY].height;
					previous_level = matrix[coordinateX][coordinateY].level;
					current_level = max(v.height, min(matrix[coordinateX][coordinateY].level, u.level));
					if (current_level != previous_level) {

						matrix[coordinateX][coordinateY].level = current_level;
						pointsQueue.push(matrix[coordinateX][coordinateY]);
					}
				}
			}
		}

		for (int i = 1; i < n - 1; ++i) {
			for (int j = 1; j < m - 1; ++j) {
				result += (matrix[i][j].level - matrix[i][j].height);
			}
		}
		return result;
	}
private:
	int neighbour[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
};