//#ifdef NODES_H
//#define NODES
struct node_t{
	int wordCount;
	char keyValue;
	struct node_t* left;
	struct node_t* right;
	char* words[];
};
//#endif
