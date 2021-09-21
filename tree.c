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
//global variable that holds the root of the tree
struct node_t* buildTree(char* inputFilename,int option)
//Function that reads from a file and builds the tree and sends the tree to be printed
{
	char* outputFilename;
	outputFilename=malloc(sizeof(char)*50);
	if(option==0)
	{//Option used if the user entered there own file input to check if it is correct and add extension if needed
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
			inputFilename= strcat(inputFilename,".fl2021");
			//Adding extension
		}
	}
	FILE* input;
	root=NULL;
	//Opening file either user speicifced or temp.txt with keyboard input
	input=fopen(inputFilename,"r");
	//Error if file does not open
        if(input == NULL)
        {
        	printf("Error opening the file.Aborting the program\n");
                exit(1);
        }
        char word[20];
	struct node_t* temp;
        while(fscanf(input,"%s",word)!=EOF)
        //reading one word at a time from input file
        {
		if(root==NULL)
		//if the root is null them nothing has been created yet so our root will be our first node
		//we will send it to the function addNode 
		{
			root=addNode(root,word);
		}	
		else
		{//Since we already have a root we just need to addNodes and not change the root value
			temp=addNode(root,word);
		}
        }
	if(root==NULL)
	//if root is stil null then the input file is empty  
	{
		fprintf(stderr,"Input file was empty. Aborting Program");
		return root;
	}	
        fclose(input);
	if(option==1)
	//If the user gave no input file then the default output file name is output
	{
		strcpy(outputFilename,"output");
	}
	char* preFile=malloc(sizeof(char)*50);
	char* inFile=malloc(sizeof(char)*50);
	char* postFile=malloc(sizeof(char)*50);
	strcpy(preFile,outputFilename);
	strcpy(inFile,outputFilename);
	strcpy(postFile,outputFilename);
	//Makeing the output files have .preorder, .inorder, and .postorder extensions
	strcat(preFile,".preorder");
	strcat(inFile,".inorder");
	strcat(postFile,".postorder");
	printPreorder(root,preFile);
	//printing the preorder traversal
	printInorder(root,inFile);
	//printing the Inorder traversal
	printPostorder(root,postFile);	
	//printing the postorder traversal
	free(outputFilename);
	free(preFile);
	free(inFile);
	free(postFile);
	return root;
	//returning the root of the tree to main.c
}
struct node_t* addNode(struct node_t* nodePointer,char* word)
//This function uses recursion to create nodes and add them onto the tree
{
	char firstLetter=word[0];
	if(nodePointer==NULL)
	//This condition stops the recursion and triggers the program to create the node
	//The left and right child pointers are set to NULL and the current word is set as the node's first word in it's wordList 
	//the firstLetter of the word is put as the keyValue and the wordCount is set to 1
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
	//If the new words first letter is less than the current node's keyValue then the program calls this function again 
	//sending it the current node's left child
        {                 
          	nodePointer->left=addNode(nodePointer->left,word);
        }
        else if(firstLetter>nodePointer->keyValue)
        //IF the new first letter is greater than the current node's keyValue then the program calls this function again
	//sengin it the current node's right child
	{
                nodePointer->right=addNode(nodePointer->right,word);
	}
	else if(firstLetter==nodePointer->keyValue)
	//If the current first letter and the current node's keyValeu are the same then the word is added on to the word List of the current node
	{
		int i=0;
		struct word_t* wordP;
		wordP=nodePointer->wordList;
		//Before the word is added this loop makes sure that the word does not already appear on the list
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
		//If the word is not on the list a new word node is created and added on to the end of the wordList for the current node
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
//This function opens the file for the preorder traversal and calls the traversePreorder to print the traversal in the output file
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
//This function  preorder traverses the tree and at each node prints out all the words in that node's wordList
{
	if(nodeP!=NULL)
	{
		struct word_t* temp;
		temp=nodeP->wordList;
		fprintf(output,"\n%*c%d:%c-",level*2,' ',level,nodeP->keyValue);
		while(temp!=NULL)
		{
			fprintf(output,"%s ",temp->word);
			temp=temp->nextWord;
		}
		traversePreorder(nodeP->left,output,level+1);
		traversePreorder(nodeP->right,output,level+1);
	}
	
}
void printInorder(struct node_t* nodeP,char* filename)
//This function opens the file for the inorder traversal and calls the traverseInorder to print the traversal in the output file
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
//This function inorder traverses the tree and at each node prints out all the words in that node's wordList
{
	if(nodeP!=NULL)
	{
		traverseInorder(nodeP->left,output,level+1);
		struct word_t* temp;
		temp=nodeP->wordList;
		fprintf(output,"\n%*c%d:%c-",level*2,' ',level,nodeP->keyValue);
		while(temp!=NULL)
		{
			fprintf(output,"%s ",temp->word);
			temp=temp->nextWord;
		}
		traverseInorder(nodeP->right,output,level+1);
	}	
}
void printPostorder(struct node_t* nodeP,char* filename)
//This function opens the file for the postorder traversal and call the traversePostorder to print the traversal in the output file
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
//This function postorder traverses the tree and at each node prints out all the words in that node's wordList
{
	if(nodeP!=NULL)
	{
		traversePostorder(nodeP->left,output,level+1);
		traversePostorder(nodeP->right,output,level+1);
		struct word_t* temp;
		temp=nodeP->wordList;
		fprintf(output,"\n%*c%d:%c-",level*2,' ',level,nodeP->keyValue);
		while(temp!=NULL)
		{
			fprintf(output,"%s ",temp->word);
			temp=temp->nextWord;
		}
	}
} 
