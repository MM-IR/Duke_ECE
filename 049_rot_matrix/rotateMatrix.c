#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define COL 10
#define ROW 10

void printMat(char mat[][10], int i){
  for (int j = ROW - 1; j >= 0; j--){
    putchar(mat[j][i]);
  }
  putchar('\n');
}

void readline(char * str, FILE * file){
  char ch[12];
  if(fgets(ch,12,file)==NULL){
    goto error;
  }
  if (strchr(ch,'\0')-ch != 11){
    goto error;
  }
  memcpy(str,ch,10*sizeof(char));
  return;
  
 error:
  fprintf(stderr,"The file doen't satisfy the requirements\n");
  exit(EXIT_FAILURE);
    
}  
  
int main(int argc,char** argv){
  if (argc!=2){
    fprintf(stderr,"The number of the command line arguments is %d\n",argc);
    exit(EXIT_FAILURE);
  }
  FILE * f;
  if((f=fopen(argv[1],"r"))==NULL){
    fprintf(stderr,"File is failed to be opened!\n");
    exit(EXIT_FAILURE);
  }
  char mat[ROW][COL];
  for(int i = 0; i < ROW; i++){
    readline(mat[i],f);
  }
  if(fgetc(f)!=EOF){
    fprintf(stderr,"File doen't satisfy the requirements\n");
    exit(EXIT_FAILURE);
  }
  for(int i = 0;i < COL; i++){
    printMat(mat,i);
  }
  fclose(f);
  return 0;
}
    

