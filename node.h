#ifdef NODES_H
#define NODES_H
typedef struct node
{
	char[20][] words;
	int wordCount;
	int keyValue;
	struct node* left;
	struct node* right;
} node;
#endif
