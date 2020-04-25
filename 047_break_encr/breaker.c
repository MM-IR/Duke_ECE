#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int findMaxIndex(int arr[]){
  int maxi = 0;
  int index = -1;
  for(int i = 0; i<26;i++){
    if(arr[i]>maxi){
      maxi = arr[i];
      index = i;
    }
  }
  return index;
}


int getKey(FILE *f){
  int alp[26];
  char c;
  int idx;
  while((c=fgetc(f))!=EOF){
    if(isalpha(c)){
      alp[c-'a']++;
    }
  }
  idx = findMaxIndex(alp);
  return (idx+22)%26;      
}

int main(int argc, char ** argv){
  if (argc!=2){
    fprintf(stderr,"%d command line argument!",argc);
    exit(EXIT_FAILURE);
  }
  FILE * f = fopen(argv[1],"r");
  if (f == NULL){
    fprintf(stderr,"fail to open the file");
    exit(EXIT_FAILURE);
  }
  int key = getKey(f);
  printf("key is found %d",key);
  fclose(f);
  return key;
}
