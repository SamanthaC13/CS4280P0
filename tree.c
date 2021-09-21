/*Samantha Craig
 * CS4280 P0
 * tree.c
 * Resources Used:
 * 	https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal_in_c.htm
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"
#include"node.h"
struct node_t* root;
struct node_t* buildTree(char* inputFilename)
{
 	char* outputFilename;
	outputFilename=malloc(sizeof(char)*50);
	strcpy(outputFilename,inputFilename);
	if (strstr(inputFilename,".")!=NULL)
	{
		if(strstr(inputFilename,".fl2021")==NULL)
		{
			printf("Error! You have entered an incorrect file extension for input file please use an input file with the extension .f2021.\nAborting the Program");
			exit(1);
		}
	}
	else
	{
		inputFilename= strcat(inputFilename,".f2021");
	}
	FILE* input;
	root=NULL;
	input=fopen(inputFilename,"r");
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
	if(outputFilename==NULL)
	{
		strcpy(outputFilename,"output");
	}
	char* preFile=malloc(sizeof(char)*50);
	char* inFile=malloc(sizeof(char)*50);
	char* postFile=malloc(sizeof(char)*50);
	strcpy(preFile,outputFilename);
	strcpy(inFile,outputFilename);
	strcpy(postFile,outputFilename);
	strcat(preFile,".preorder");
	strcat(inFile,".inorder");
	strcat(postFile,".postorder");
	printPreorder(root,preFile);
	printInorder(root,inFile);
	printPostorder(root,postFile);	
	free(outputFilename);
	free(preFile);
	free(inFile);
	free(postFile);
	return root;
}
struct node_t* addNode(struct node_t* nodePointer,char* word)
{
	char firstLetter=word[0];
	if(nodePointer==NULL)
	{
                nodePointer=malloc(sizeof(struct node_t));
		nodePointer->wordList=malloc(sizeof(struct word_t));
		nodePointer->wordList->word=malloc(sizeof(char)*25);
		strcpy(nodePointer->wordList->word,word);
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
		int i=0;
		struct word_t* wordP;
		wordP=nodePointer->wordList;
		while(wordP!=NULL)
		{
			if(strcmp(word,wordP->word)==0)
			{
				break;
			}
			wordP=wordP->nextWord;
			i++;
		} 
		if(i==nodePointer->wordCount)
		{
			wordP=nodePointer->wordList;
			for(i=0;i<(nodePointer->wordCount-1);i++)
			{
				wordP=wordP->nextWord;
			}
			struct word_t* temp;	
			temp=malloc(sizeof(struct word_t));
			temp->word=malloc(sizeof(char)*25);
			strcpy(temp->word,word);
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
	output=fopen(filename,"w");
	if(output==NULL)
	{
		fprintf(stderr,"PreOrder Output file failed to open. Aborting Program.");
		exit(1);
	}
	traversePreorder(nodeP,output,0);
	fclose(output);
	free(filename);
}
void traversePreorder(struct node_t* nodeP,FILE* output,int level)
{
	if(nodeP!=NULL)
	{
		struct word_t* temp;
		temp=nodeP->wordList;
		fprintf(output,"\n%*c%d:%c  ",level*2,' ',level,nodeP->keyValue);
		while(temp!=NULL)
		{
			fprintf(output,"-%s",temp->word);
			temp=temp->nextWord;
		}
		traversePreorder(nodeP->left,output,level+1);
		traversePreorder(nodeP->right,output,level+1);
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
	traverseInorder(nodeP,output,0);
	fclose(output);
	free(filename);
}
void traverseInorder(struct node_t* nodeP,FILE* output, int level)
{
	if(nodeP!=NULL)
	{
		traverseInorder(nodeP->left,output,level+1);
		struct word_t* temp;
		temp=nodeP->wordList;
		fprintf(output,"\n%*c%d:%c  ",level*2,' ',level,nodeP->keyValue);
		while(temp!=NULL)
		{
			fprintf(output,"-%s",temp->word);
			temp=temp->nextWord;
		}
		traverseInorder(nodeP->right,output,level+1);
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
	traversePostorder(nodeP,output,0);
	fclose(output);
	free(filename);
}
void traversePostorder(struct node_t* nodeP,FILE*output,int level)
{
	if(nodeP!=NULL)
	{
		traversePostorder(nodeP->left,output,level+1);
		traversePostorder(nodeP->right,output,level+1);
		struct word_t* temp;
		temp=nodeP->wordList;
		fprintf(output,"\n%*c%d:%c  ",level*2,' ',level,nodeP->keyValue);
		while(temp!=NULL)
		{
			fprintf(output,"-%s",temp->word);
			temp=temp->nextWord;
		}
	}
} 
