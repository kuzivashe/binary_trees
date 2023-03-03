#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
  * print_t - stores recursively each level in an array of strings
  *
  * @tree: pointer to the node to print
  * @offset: offset the print
  * @depth: depth of the node
  *@s: Buffer
  *
  * Return: length of printed tree after process
  */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, i;

	if(!tree)
		return (0);

	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	
	for(i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if(depth && is_left)
	{
		for(i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if(depth && !is_left)
	{
		for(i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}
