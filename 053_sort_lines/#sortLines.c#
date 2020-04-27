#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}
#define TEMP_LINE 20
void redirect(char * arg){
  if(freopen(arg, "r", stdin)==NULL){
    fprintf(stderr,"There must be some errors related to the file-x open");
    exit(EXIT_FAILURE);
  }
}



void doSort(){
  char ** str;
  int line_cap = TEMP_LINE;
  int line_size = 0;
  str = malloc(line_cap*sizeof(*str));
  if(!str){
    goto OOM;
  }
  for(;;){
    char * s; //temp char array
    size_t l_cap = 0;
    /* in this case, we have arrived at the end of the file*/
    if(getline(&s,&l_cap,stdin)==-1){
      free(s);
      if (feof(stdin)){
	break;
      }
      fprintf(stderr,"something bad happens!");
      exit(EXIT_FAILURE);
    }
    else{
      if (line_size == line_cap){
	if (line_cap * 2 < line_cap){
	  /* overflow */
	  line_cap ++;
	  if (line_cap==0){
	    fprintf(stderr,"The file has too many lines");
	    exit(EXIT_FAILURE);
	  }
	}
	else{
	  line_cap *= 2;
	}
	str = realloc(str, line_cap*sizeof(*str));
	if(str==NULL){
	  goto OOM;
	}
	str[line_size++] = s;
      }
    }
  }
  sortData(str,line_size);
  for (int i = 0; i < line_size; i++){
    fputs(str[i],stdout);
    free(str[i]);
  }
  free(str);
  return ;
 OOM:
  fprintf(stderr,"Out Of Memory!");
  exit(EXIT_FAILURE);
}
int main(int argc, char ** argv) {
  if (argc>1){
    for (int j = 1;j<argc;j++){
      redirect(argv[j]); //redirect stdin to the file
      doSort();   
    }
  }
  else{
    doSort();
  }
  if(fclose(stdin)==EOF){
    fprintf(stderr,"fail to close the file");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}

// vim: ts=2:sw=2:et
