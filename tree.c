/*Samantha Craig
 * CS4280 P0
 * tree.c
 */
#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"node.h"
struct node_t* root=NULL;
struct node_t* buildTree(char* filename)
{
	FILE* input;
	root=NULL;
	input=fopen(filename,"r");
        if(input == NULL)
        {
        	printf("Error opening the file.Aborting the program\n");
                exit(1);
        }
        char word[20];
        while(fscanf(input,"%s",word)!=EOF)
        {
		if(root==NULL)
		{
			printf("root-%c",word[0]);
        		root=malloc(sizeof(struct node_t));
			root->keyValue=word[0];
			root->wordCount=1;
			root->left=NULL;
			root->right=NULL;
		}
		else
		{
			addNode(root,word);
		}
        }
        fclose(input);		
	return root;
}
void addNode(struct node_t* nodePointer,char* word)
{
	char firstLetter=word[0];
	if(nodePointer==NULL)
	{
		printf("\n%c",firstLetter);
                nodePointer=malloc(sizeof(struct node_t));
                nodePointer->keyValue=word[0];
                nodePointer->wordCount=1;
                nodePointer->left=NULL;
                nodePointer->right=NULL;
                return;         
	}
        if(firstLetter<nodePointer->keyValue)
        {                 
		printf("\n%c<-",firstLetter);
          	addNode(nodePointer->left,word);
        }
        if(firstLetter>nodePointer->keyValue)
        {
                 printf("\n%c->",firstLetter);
                 addNode(nodePointer->right,word);
	}
}
