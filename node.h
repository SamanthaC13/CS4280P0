//#ifdef NODES_H
//#define NODES
struct node_t{
//	char[20][] words;
	int wordCount;
	int keyValue;
	struct node_t* left;
	struct node_t* right;
};
//#endif
