/* Name:Samantha Craig
   Class:CS4280
   Project 0
*/
# include<stdio.h>
#include<stdlib.h>
#include"node.h"
int main(int argc, char**argv){
    struct nodes node;
         char* string;
         if(argc==1)
         {
                 string=(char*)scanf("%s",string);
                 *(node.words[0])=string;
         /*      node.left=NULL;
                 node.right=NULL;
                 node.wordCount=1;
                 node.keyValue=string[0];*/
         }
         /*else
         {
                 FILE* input=argv[1];
                 while(string!=EOF)
                 {
                         string=fscanf(input,"%s");
                         root.words[0]=string;
                         root.left=NULL;
                         root.right=NULL;
                         root.wordCount=1;
                         root.keyValue=string[0];
                 }
              }*/
//      printf("\n%s-%d",node.words[0],node.keyValue);
}
