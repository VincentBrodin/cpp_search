#ifndef MAZE_H
#define MAZE_H

#include <memory>
#include <vector>

#include "queue.h"

namespace maze {
enum Tile {
	TILE_PATH,
	TILE_WALL,
	TILE_START,
	TILE_END,
	TILE_UNKOWN,
};

struct Node {
	int x, y;
	Tile tile;
	std::shared_ptr<Node> from;
	Node(int x, int y, Tile tile);
};

class Maze {
   private:
	utils::Queue<std::shared_ptr<Node>> queue;
	std::vector<std::vector<std::shared_ptr<Node>>> grid;
	std::shared_ptr<Node> start;
	std::shared_ptr<Node> end;


bool in_grid(int x, int y);
	std::shared_ptr<Node> get_node(int x, int y);
	std::vector<std::shared_ptr<Node>> get_neighbours(std::shared_ptr<Node> node);

   public:
	Maze() = default;
	~Maze() = default;

	void add_row(const std::string row_str);
	void print();
	bool solve();
};
}  // namespace maze
#endif /* MAZE_H */
