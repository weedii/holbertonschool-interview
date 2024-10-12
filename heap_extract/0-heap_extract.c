#include "binary_trees.h"

/**
 * tree_size - Calculate the size of a binary tree.
 * @tree: Pointer to the root node.
 * Return: Size of the tree.
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_node_at_index - Retrieves node based its index in level-order traversal.
 * @root: Pointer to the root of the tree.
 * @index: Index of the node to retrieve.
 * Return: Pointer to the node at the given index.
 */
binary_tree_t *get_node_at_index(binary_tree_t *root, size_t index)
{
	binary_tree_t *queue[1024];  /* Array-based queue */
	size_t front = 0, back = 0, i = 0;

	if (!root || index == 0)
		return (root);

	queue[back++] = root;  /* Enqueue root */

	while (front < back)
	{
		binary_tree_t *node = queue[front++];  /* Dequeue */

		if (i == index)
			return (node);

		if (node->left)
			queue[back++] = node->left;
		if (node->right)
			queue[back++] = node->right;

		i++;
	}
	return (NULL);
}

/**
 * heapify_down - Restores the Max-Heap property starting from a node.
 * @node: Pointer to the node to heapify down from.
 */
void heapify_down(heap_t *node)
{
	heap_t *max_child;
	int temp;

	while (node && (node->left || node->right))
	{
		if (node->left && node->right)
			max_child = (node->left->n > node->right->n) ? node->left : node->right;
		else
			max_child = node->left ? node->left : node->right;

		if (node->n < max_child->n)
		{
			temp = node->n;
			node->n = max_child->n;
			max_child->n = temp;
			node = max_child;
		}
		else
			break;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	int value;
	size_t nodes;
	heap_t *last_node, *parent;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	nodes = tree_size(*root);

	last_node = get_node_at_index(*root, nodes - 1);

	if (!last_node)
		return (0);

	(*root)->n = last_node->n;
	parent = last_node->parent;

	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last_node);

	heapify_down(*root);

	return (value);
}
