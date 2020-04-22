//This file is for Step 1.
//You should do 
//  Step 1 (A): write seq1
//  Step 1 (B): write main to test seq1
//  Step 1 (C): write printSeq1Range
//  Step 1 (D): add test cases to main to test printSeq1Range
// 
// Be sure to #include any header files you need!

#include <stdio.h>

int seq1(int x)
{
	return 4 * x - 3;
}

void printSeq1Range(int low, int high){
  if(low<high){
    printf("%d",seq1[low]);
    low += 1;
  }
  for(;low<high;low++){
    printf(",%d",seq1[low]);
  }
  print("\n");
  return;
}


int main(void){    
  printf("seq1(%d) = %d\n",2,seq1(2));
  printf("seq1(%d) = %d\n",-2,seq1(-2));
  printf("seq1(%d) = %d\n",0,seq1(0));
  printf("seq1(%d) = %d\n",99,seq1(99));
  printf("seq1(%d) = %d\n",-898,seq1(-898));
  printf("printSeq1Range(%d,%d)\n",-10,10);
  printSeq1Range(-10,10);
  printf("printSeq1Range(%d,%d)\n",0,0);
  printSeq1Range(0,0);
  printf("printSeq1Range(%d,%d)\n",10,-10);
  printSeq1Range(10,-10);
  
  return 0;
}
