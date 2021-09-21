/*Samantha Craig
 * CS4280 P0
 * tree.c
 */
#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"node.h"
void printNode(struct node_t*);
struct node_t* root;
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
	struct node_t* temp;
        while(fscanf(input,"%s",word)!=EOF)
        {
		if(root==NULL)
		{
			root=addNode(root,word);
		}	
		else
		{
			temp=addNode(root,word);
			fprintf(stderr,"\n%c",root->keyValue);
		}
        }
        fclose(input);
	fprintf(stderr,"%c",root->keyValue);
	printPreorder(root);		
	return root;
}
struct node_t* addNode(struct node_t* nodePointer,char* word)
{
	char firstLetter=word[0];
	fprintf(stderr,"\nfirstletter=%c",firstLetter);
	if(nodePointer==NULL)
	{
                nodePointer=malloc(sizeof(struct node_t));
		nodePointer->words[0]=word;
                nodePointer->keyValue=word[0];
                nodePointer->wordCount=1;
                nodePointer->left=NULL;
                nodePointer->right=NULL;
		fprintf(stderr,"***Created Node***");	
                return nodePointer;         
	}
        if(firstLetter<nodePointer->keyValue)
        {                 
		fprintf(stderr,"\nGoing to the left<-");
          	nodePointer->left=addNode(nodePointer->left,word);
		printNode(nodePointer);
        }
        else if(firstLetter>nodePointer->keyValue)
        {
                fprintf(stderr,"\nGoing to the right->",firstLetter);
                nodePointer->right=addNode(nodePointer->right,word);
		printNode(nodePointer);
	}
	return nodePointer;
	//if(firstLetter==nodePointer->keyValue)
	//if(strcmp(firstLetter,nodePointer->keyValue)==0)
	
	//	printf("\nAdding word to words in node");
	//	printf("%d",nodePointer->wordCount);
	//	nodePointer->words[nodePointer->wordCount]=word;
	//	nodePointer->wordCount+=1;
}
void printNode(struct node_t* nodeP)
{
	fprintf(stderr,"\nKey:%c",nodeP->keyValue);
	fprintf(stderr,"\nLeft:%u",nodeP->left);
	fprintf(stderr,"\nRight:%u",nodeP->right);
}
void printPreorder(struct node_t* nodeP)
{
	if(nodeP!=NULL)
	{
		fprintf(stderr,"\n%c",nodeP->keyValue);
		printPreorder(nodeP->left);
		printPreorder(nodeP->right);
	}
	
}
/*
	//FILE* output;
	if(nodePointer==NULL)
	{
	//	fclose(output);
		return;
	}	
	//output=fopen(filename,"a");
	int i;
	for(i=0;i<nodePointer->wordCount;i++)
	{
		printf("%*c%d:%-9s ",level*2,nodePointer->keyValue, level,nodePointer->words[i]);
	//	fprintf(output,"%*c%d:%-9s",level*2,nodePointer->keyValue,nodePointer->words[i]);
	}
	printPreorder(nodePointer->left,level+1,filename);
	printPreorder(nodePointer->right,level+1,filename);
}
void printInorder(struct node_t* root,int level)
{


}
void printPostorder(struct node_t* root,int level)
{



}*/
