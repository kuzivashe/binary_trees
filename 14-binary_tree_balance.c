#include "binary_trees.h"

int custom_binary_tree_height(const binary_tree_t *tree);

/**
  * binary_tree_balance - measures the balance factor of a binary tree
  * @tree: pointer to the root node of the tree to measure
  * the balance factor
  *
  * Return: if tree is NULL return 0
  */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = custom_binary_tree_height(tree->left);
	right = custom_binary_tree_height(tree->right);
	return (left - right);
}

/**
  * custom_binary_tree_height - measure the height of the tree
  * from a given node
  * @tree: pointer to node of tree to measure
  *
  * Return: -1 if NULL or height of tree
  */
int custom_binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (-1);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left = custom_binary_tree_height(tree->left) + 1;
	right = custom_binary_tree_height(tree->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}
