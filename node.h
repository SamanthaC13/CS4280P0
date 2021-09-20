#ifdef NODES_H
#define NODES_H
typedef struct node_t{
//	char[20][] words;
	int wordCount;
	int keyValue;
	node_t* left;
	node_t* right;
} node_t;
#endif
