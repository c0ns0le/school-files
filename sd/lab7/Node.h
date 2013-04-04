#ifndef __NODE_H__
#define __NODE_H__

#include <vector>

enum Color {
  WHITE,
  GRAY,
  BLACK
};

struct Node {
    unsigned int node;
	unsigned int color;
	unsigned int tDesc;
	unsigned int tFin;

	std::vector<int> neigh;
};
#endif
