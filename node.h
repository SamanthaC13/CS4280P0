struct word_t{
//Structure for the word nodes that include one word and a pointer to the next word in the list of words 
//in each tree node
	char* word;
	struct word_t* nextWord;
};
struct node_t{
//Structure of each tree node that includes a left and right child and starting pointer for the word nodes
	int wordCount;
	char keyValue;
	struct node_t* left;
	struct node_t* right;
	struct word_t* wordList;
};
