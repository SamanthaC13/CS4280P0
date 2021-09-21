//includes functino declarations for a functions in tree.c
struct node_t* buildTree(char*,int);
struct node_t* addNode(struct node_t*,char*);
void printPreorder(struct node_t*,char*);
void printInorder(struct node_t*,char*);
void printPostorder(struct node_t*,char*);
void traversePreorder(struct node_t*,FILE*,int);
void traverseInorder(struct node_t*,FILE*,int);
void traversePostorder(struct node_t*,FILE*,int);
