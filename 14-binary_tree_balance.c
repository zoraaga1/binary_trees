#include "binary_trees.h"

/**
 * height_recursion - function that calculates the height using recursion
 *
 * @tree: node to find recursion
 * Return: the number of height nodes
 */

size_t height_recursion(const binary_tree_t *tree)
{
	size_t left_count = 0, right_count = 0;

	if (tree->left)
		left_count = height_recursion(tree->left);
	if (tree->right)
		right_count = height_recursion(tree->right);
	return ((left_count > right_count) ? left_count + 1 : right_count + 1);
}

/* binary_tree_functions.c */

/* ... (previous code) */

/**
 * binary_tree_is_perfect - Returns if the tree is perfect
 * @tree: is the node from which to get the node
 *
 * Return: 1 if is perfect, 0 if doesn't
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left_height = height_recursion(tree->left);
    size_t right_height = height_recursion(tree->right);

    if (binary_tree_is_full(tree) && left_height == right_height)
        return (1);

    return (0);
}
