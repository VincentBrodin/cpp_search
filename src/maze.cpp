#include "maze.h"

#include <iostream>
#include <memory>
#include <print>
#include <string>
#include <vector>

#include "utils.h"

namespace maze {

Tile char_to_tile(const char ch) {
	switch (ch) {
		case ' ':
			return TILE_PATH;
		case '#':
			return TILE_WALL;
		case 'S':
			return TILE_START;
		case 'E':
			return TILE_END;
		default:
			return TILE_UNKOWN;
	}
}

char tile_to_char(const Tile tile) {
	switch (tile) {
		case TILE_PATH:
			return ' ';
		case TILE_WALL:
			return '#';
		case TILE_START:
			return 'S';
		case TILE_END:
			return 'E';
		default:
			return '?';
	}
}

Node::Node(int x, int y, Tile tile) {
	this->x = x;
	this->y = y;
	this->tile = tile;
	this->from = nullptr;
}

void Maze::add_row(const std::string row_str) {
	grid.push_back({});
	auto& row = grid.back();
	int y = grid.size() - 1;
	for (int x = 0; x < row_str.length(); x++) {
		Tile tile = char_to_tile(row_str[x]);
		auto node = std::make_shared<Node>(x, y, tile);

		if (tile == TILE_START) {
			start = node;
		} else if (tile == TILE_END) {
			end = node;
		}

		row.push_back(node);
	}
}

void Maze::print() {
	for (int y = 0; y < grid.size(); y++) {
		auto& row = grid[y];
		for (int x = 0; x < row.size(); x++) {
			auto& node = row[x];
			std::cout << tile_to_char(node->tile);
		}
		std::cout << '\n';
	}
	std::flush(std::cout);
}

bool Maze::in_grid(int x, int y) {
	return utils::in_range(0, y, (int)grid.size() - 1) &&
		   utils::in_range(0, x, (int)grid[y].size() - 1);
}

std::shared_ptr<Node> Maze::get_node(int x, int y) {
	if (in_grid(x, y)) {
		return grid[y][x];
	}
	return nullptr;
}

std::vector<std::shared_ptr<Node>> Maze::get_neighbours(
	std::shared_ptr<Node> node) {
	int x = node->x;
	int y = node->y;
	auto vec = std::vector<std::shared_ptr<Node>>{};
	if (in_grid(x + 1, y)) {
		vec.push_back(get_node(x + 1, y));
	}
	if (in_grid(x - 1, y)) {
		vec.push_back(get_node(x - 1, y));
	}
	if (in_grid(x, y + 1)) {
		vec.push_back(get_node(x, y + 1));
	}
	if (in_grid(x, y - 1)) {
		vec.push_back(get_node(x, y - 1));
	}

	return vec;
}

bool Maze::solve() {
	auto& node = start;
	while (node != nullptr) {
		auto neighbours = get_neighbours(node);
		for (int i = 0; i < neighbours.size(); i++) {
			auto& neighbour = neighbours[i];
			if (neighbour->tile == TILE_END) {
				neighbour->from = node;
				return true;
			}
			if (neighbour->tile != TILE_PATH || neighbour->from != nullptr) {
				continue;
			}

			neighbour->from = node;
			queue.enqueue(neighbour);
		}

		if (queue.is_empty()) {
			std::println("EMPTY");
			return false;
		}

		node = queue.dequeue();
	}
	std::println("NULLPTR");
	return false;
}

}  // namespace maze
