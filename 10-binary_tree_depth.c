#include "binary_trees.h"

/**
  * binary_tree_depth - measures the depth of a node
  * in a binary tree
  * Depth is measured from the parent node going down
  * @tree: pointer to the node to measure the depth
  *
  * Return: if tree is NULL return 0
  */
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (0);

	return (binary_tree_depth(node->parent) + 1);
}
