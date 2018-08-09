#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t
{
	int key;
	struct node_t* parent;
	struct node_t* left;
	struct node_t* right;
}node;

node *min(node* root)
{
	node* min_node = root;
	if(root == NULL)
		return NULL;
	while(min_node->left != NULL)
		min_node = min_node->left;
	return min_node;//return the min position
}

node *max(node* root)
{
	node* max_node = root;
	if(root == NULL)
		return NULL;
	while(max_node->right != NULL)
		max_node = max_node->right;
	return max_node;
}

node *search(node* root, int k)
{
	node *current = root;
	if(root == NULL)
		return NULL;
	while(1)
	{
		if(current->key == k)
			break;
		else if(current->key > k)
			current = current->left;
		else current = current->right;

		if(current == NULL)
			break;
	}
	return current;
}

//find the right most number of the left side tree
node* predecessor(node* root, int k)
{
	if(root == NULL)
		return NULL;
	node* target = search(root, k);
	if(target != NULL)
	{
		if(target->left != NULL)
			target = max(target->left);
		else
		{
			while(1)
			{
				if(target->parent == NULL)
				{
					target = target->parent;
					break;
				}
				else if(target == target->parent->right)
				{
					target = target->parent;
					break;
				}
				else if(target == target->parent->left)
					target = target->parent;
			}
		}
	}
	return target;
}

node* successor(node* root, int k)
{
  if (root == NULL)
      return NULL;
  node* target = search(root, k);
  if (target != NULL)
	{
    if (target->right != NULL)
        target = min(target->right);
    else
		{
      while (1)
			{
        if (target->parent == NULL) {
          target = target->parent;
          break;
        }
				else if (target == target->parent->left)
				{
          target = target->parent;
          break;
        }
				else if (target == target->parent->right)
          target = target->parent;
      }
    }
  }
    return target;
}

node *insert(node* root, int k)
{
	node* current = root;
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->key = k;
		return root;
	}
	while(1)
	{
		if(current->key == k)
		{
			current = NULL;
			break;
		}
		else if(current->key > k)
		{
			if(current->left != NULL)
				current = current->left;
			else
			{
				node* new_node = (node*)malloc(sizeof(node));
				new_node->key = k;
				new_node->parent = current;
				new_node->left = NULL;
				new_node->right = NULL;
				current->left = new_node;
				current = current->left;
				break;
			}
		}
		else if(current->key < k)
		{
			if(current->left != NULL)
				current = current->right;
			else
			{
				node* new_node = (node*)malloc(sizeof(node));
				new_node->key = k;
				new_node->parent = current;
				new_node->left = NULL;
				new_node->right = NULL;
				current->right = new_node;
				current = current->right;
				break;
			}
		}
	}
	return current;
}

int delete_node(node* root, int k)
{
	if(root == NULL)
		return -1;
	node* target = search(root, k);
	if(target == NULL)
		return -1;
	//Case1: the node is leaf node
	if(target->left == NULL && target->right == NULL)
	{
		if(target != root)
		{
			if(target == target->parent->right)
				target->parent->right = NULL;
			else
				target->parent->left = NULL;
		}
		else
			root = NULL;
		free(target);
	}
	//Case2: the node has only one child
	//Case2.1: only one left child
	else if(target->left != NULL && target->right == NULL)
	{
		if(target == root)
		{
			node* predecessor_node = predecessor(root, k);
			if(predecessor_node == NULL)
				return -1;
			target->key = predecessor_node->key;
			if(predecessor_node->left == NULL && predecessor_node->right == NULL)
			{
				if(target->right == predecessor_node)
					target->right = NULL;
				else
					predecessor_node->parent->left = NULL;
			}
			else
			{
				predecessor_node->parent->right = predecessor_node->left;
				predecessor_node->left->parent = predecessor_node->parent;
			}
			free(predecessor_node);
		}
		else
		{
			target->left->parent = target->parent;
			if (target == target->parent->left)
					target->parent->left = target->left;
			else
					target->parent->right = target->left;
		}
	}
	//Case2.2 the node onlyhas a right child
	else if(target->left == NULL && target->right != NULL)
	{
		if(target == root)
		{
			node* successor_node = successor(root, k);
      if (successor_node == NULL)
        return -1;
			target->key = successor_node->key;
			if(successor_node->left == NULL && successor_node->right == NULL)
			{
				if(target->right == successor_node)
					target->right = NULL;
				else successor_node->parent->left = NULL;
			}
			else
			{
				successor_node->parent->left = successor_node->right;
        successor_node->right->parent = successor_node->parent;
			}
			free(successor_node);
		}
		else
		{
			 target->right->parent = target->parent;
			 if (target == target->parent->left)
			 	 target->parent->left = target->right;
			 else
			   target->parent->right = target->right;
		}
	}
	//Case3: this node has two children
	else if (target->left != NULL && target->right != NULL) {
      node* successor_node = successor(root, k);
      if (successor_node == NULL)
        return -1;
      // Replace the number first.
      target->key = successor_node->key;
      // Case 3.1: successor does not have any child.
      if (successor_node->left == NULL && successor_node->right == NULL)
			{
        if (target->right == successor_node)
            target->right = NULL;
        else
            successor_node->parent->left = NULL;
      }
      // Case 3.2: successor only have right child.
      else
			{
        successor_node->parent->left = successor_node->right;
        successor_node->right->parent = successor_node->parent;
      }
      free(successor_node);
    }
    if (root == NULL)
        return 1;
    return 0;
}

node *modify(node* root, int src, int dst)
{
	if(root == NULL)
		return NULL;
	//ensure the src exists and dst does not exist
	node* source = search(root, src);
	node* destination = search(root, dst);
	if(source == NULL)
	{
		printf("The source number %d dose not exist. \n", src);
		return NULL;
	}
	if(destination != NULL)
	{
		printf("The destination number %d already exist. \n", dst);
		return NULL;
	}
	delete_node(root, src);
	insert(root, dst);
	return source;
}

void print_tree_inorder(node* root)
{
	if(root != NULL)
	{
		print_tree_inorder(root->left);
		printf("%d ", root->key);
		print_tree_inorder(root->right);
	}
}

int main() {

	return 0;
}
