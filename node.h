//#ifdef NODES_H
//#define NODES
struct word_t{
	char* word;
	struct word_t* nextWord;
};
struct node_t{
	int wordCount;
	char keyValue;
	struct node_t* left;
	struct node_t* right;
	struct word_t* wordList;
};
//#endif
