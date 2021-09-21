//extern struct node_t* root;
struct node_t* buildTree(char*);
struct node_t* addNode(struct node_t*,char*);
void printPreorder(struct node_t*,char*);
void printInorder(struct node_t*,char*);
void printPostorder(struct node_t*,char*);
void traversePreorder(struct node_t*,FILE*);
void traverseInorder(struct node_t*,FILE*);
void traversePostorder(struct node_t*,FILE*);
