/* Name:Samantha Craig
   Class:CS4280
   Project 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"node.h"
typedef struct node
{
	//char [20][]words;
	int wordCount;
	int keyValue;
	struct node* left;
	struct node* right;

} node;
void addNode(char*,struct node*);
int main(int argc, char**argv)
{
	FILE* input;
        if(argc==1)
        {
	/*	char string;
		input=stdin;
		FILE* temp;
		temp=fopen("temp.txt","w");
		while(string!=*/
        }
        else
        {
		char*filename=argv[1];
		char* extenstion=".f2021";
		char* period=".";
		if(strstr(filename,".f2021")!=NULL)
		{
			filename=argv[1];
		}
		else if (strstr(filename,period)!=NULL)
		{
			printf("Error! You have entered an incorrect file extension for input file please use an input file with the extension .f2021.\nAborting the Program");
			exit(1);
		}
		else
		{
			filename= strcat(argv[1],".f2021");
		}
		input=fopen(filename,"r");
		if(input == NULL)
		{
			printf("Error opening the file.Aborting the program\n");
			exit(1);
		}
		char word[20];
		struct node* root=NULL;
		while(fscanf(input,"%s",word)!=EOF)
		{	
			addNode(word,root);			
		}
		fclose(input);
	}
}
void addNode(char*word,struct node* root)
{
	char firstLetter=word[0];
	if(root==NULL)
	{
		printf("\n%c",firstLetter);
		root=(node*)malloc(sizeof(node));
		root->keyValue=word[0];
		root->wordCount=1;
		root->left=NULL;
		root->right=NULL;
		return;
	}	
	if(firstLetter<root->keyValue)
	{
		printf("\n%c<-",firstLetter);	
		addNode(word,root->left);	
	}			
	if(firstLetter>root->keyValue)
	{
		printf("\n%c->",firstLetter);
		addNode(word,root->right);		
	}
}
