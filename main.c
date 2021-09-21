/* Name:Samantha Craig
   Class:CS4280
   Project 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "tree.h"
void free_tree(struct node_t*);
int main(int argc, char**argv)
{
	char* filename;                   
	int option=0;
	//This option if the user only entered the Program name without a file
        if(argc==1)
        {
		char string[50];
		FILE* temp;
		option=1;
		temp=fopen("temp.txt","w");
		//Takes in the Keyboard input and writes it to a file I call temp.txt
		while(scanf("%s",string)!=-1)
		{
			fprintf(temp,"%s ",string);
		}
		fclose(temp);
		filename=malloc(sizeof(char)*10);
		strcpy(filename,"temp.txt");
        }
	else
	{
	//This option is for if the user did enter a filename in the command line
		filename=argv[1];
	}
	struct node_t* root;
	//Now the file is sent to tree.c to build the tree with option 1 for the keyboard input and option 0 for the file input it will return the root of the tree
	root=buildTree(filename,option);
	//If the input file is empty then tree.c returns it to here for it to exit
	if(root==NULL)
	{
		exit(1);
	}
	//Sends the root to free the memory allocated for the tree
	free_tree(root);			
}
void free_tree(struct node_t* nodeP)
//This functiom is to free the memory allocated in the tree and in the word nodes included in each tree node
{
	if(nodeP!=NULL)
	{
		//Does a post order traversal of the tree
		free_tree(nodeP->left);
		free_tree(nodeP->right);
		struct word_t* temp;
		temp=nodeP->wordList;
		//goes through the list of word nodes in each tree node and frees them
		while(temp!=NULL)
		{
			temp=temp->nextWord;
			free(temp);
		}
		free(nodeP->wordList->word);
		free(nodeP->wordList);
		//frees the tree node last
		free(nodeP);
	}
}
