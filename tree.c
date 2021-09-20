/*Samantha Craig
 * CS4280 P0
 * tree.c
 */
#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
//#include"node.h"
struct node_t* root=NULL;
struct node_t* buildTree(char* filename)
{
	FILE* input;
	struct node_t* root;
	input=fopen(filename,"r");
        if(input == NULL)
        {
        	printf("Error opening the file.Aborting the program\n");
                exit(1);
        }
        char word[20];
	struct node_t* currentNode;
        while(fscanf(input,"%s",word)!=EOF)
        {
		if(root==NULL)
		{
        		root=addNode(root,word);
		}
		else
		{
			currentNode=addNode(root,word);
		}
        }
        fclose(input);		
	return root;
}
struct node_t* addNode(struct node_t* nodePointer,char* word)
{
	char firstLetter=word[0];
	struct node_t *currentNode;
	if(nodePointer==NULL)
	{
		printf("\n%c",firstLetter);
                nodePointer=malloc(sizeof(node_t));
                nodePointer->keyValue=word[0];
                nodePointer->wordCount=1;
                nodePointer->left=NULL;
                nodePointer->right=NULL;
                return nodePointer;         
	}
        if(firstLetter<nodePointer->keyValue)
        {                 
		printf("\n%c<-",firstLetter);
          	currentNode=addNode(nodePointer->left,word);
        }
        if(firstLetter>nodePointer->keyValue)
        {
                 printf("\n%c->",firstLetter);
                 currentNode=addNode(nodePointer->right,word);
	}
}
