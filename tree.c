/*Samantha Craig
 * CS4280 P0
 * tree.c
 * Resources Used:
 * 	https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal_in_c.htm
 */
#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"node.h"
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
		}
        }
	if(root==NULL)
	{
		fprintf(stderr,"Input file was empty. Aborting Program");
		return root;
	}	
        fclose(input);
	printPreorder(root,"output.preorder");
	printInorder(root,"output.inorder");
	printPostorder(root,"output.postorder");	
	return root;
}
struct node_t* addNode(struct node_t* nodePointer,char* word)
{
	char firstLetter=word[0];
	if(nodePointer==NULL)
	{
                nodePointer=malloc(sizeof(struct node_t));
		nodePointer->wordList=malloc(sizeof(struct word_t));
		nodePointer->wordList->word=word;
		nodePointer->wordList->nextWord=NULL;
                nodePointer->keyValue=word[0];
                nodePointer->wordCount=1;
                nodePointer->left=NULL;
                nodePointer->right=NULL;	
                return nodePointer;         
	}
        if(firstLetter<nodePointer->keyValue)
        {                 
          	nodePointer->left=addNode(nodePointer->left,word);
        }
        else if(firstLetter>nodePointer->keyValue)
        {
                nodePointer->right=addNode(nodePointer->right,word);
	}
	else if(firstLetter==nodePointer->keyValue)
	{
		int i;
		struct word_t* wordP;
		wordP=nodePointer->wordList;
		for(i=0;i<nodePointer->wordCount;i++)
		{
			if(strcmp(word,nodePointer->wordList->word)==0)
			{
				break;
			}
			wordP=nodePointer->wordList->nextWord;
		}
		if(i==(nodePointer->wordCount-1))
		{
			struct word_t* temp;	
			temp=malloc(sizeof(struct word_t));
			temp->word=word;
			temp->nextWord=NULL;
			wordP->nextWord=temp;
			nodePointer->wordCount+=1;
		}
		return nodePointer;
	}
	return nodePointer;
}
void printPreorder(struct node_t* nodeP,char* filename)
{
	FILE* output;
	output=fopen(filename,"aw");
	if(output==NULL)
	{
		fprintf(stderr,"PreOrder Output file failed to open. Aborting Program.");
		exit(1);
	}
	traversePreorder(nodeP,output);
	fclose(output);
}
void traversePreorder(struct node_t* nodeP,FILE* output)
{
	if(nodeP!=NULL)
	{
		fprintf(output,"\n%c",nodeP->keyValue);
		traversePreorder(nodeP->left,output);
		traversePreorder(nodeP->right,output);
	}
	
}
void printInorder(struct node_t* nodeP,char* filename)
{
	FILE* output;
	output=fopen(filename,"w");
	if(output==NULL)
	{
		fprintf(stderr,"Inorder Output file failed to open. Aborting Program");
		exit(1);
	}
	traverseInorder(nodeP,output);
	fclose(output);
}
void traverseInorder(struct node_t* nodeP,FILE* output)
{
	if(nodeP!=NULL)
	{
		traverseInorder(nodeP->left,output);
		fprintf(output,"\n%c",nodeP->keyValue);
		traverseInorder(nodeP->right,output);
	}	
}
void printPostorder(struct node_t* nodeP,char* filename)
{
	FILE* output;
	output=fopen(filename,"w");
	if(output==NULL)
	{
		fprintf(stderr,"PostOrder Output file failed to open. Aborting Program");
		exit(1);
	}
	traversePostorder(nodeP,output);
	fclose(output);
}
void traversePostorder(struct node_t* nodeP,FILE*output)
{
	if(nodeP!=NULL)
	{
		traversePostorder(nodeP->left,output);
		traversePostorder(nodeP->right,output);
		fprintf(output,"\n%c",nodeP->keyValue);
	}
} 
