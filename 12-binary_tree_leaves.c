#include "binary_trees.h"

/**
  * binary_tree_leaves - count the leaves in a binary tree
  * @tree: pointer to the root node of the tree to count
  * the number of leaves
  *
  * A NULL pointer is not a leaf
  * Return: if a tree is NULL return 0. Addition of both sides
  */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right;

	left = right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	return (left + right);
}
