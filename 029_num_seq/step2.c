//This file is for Step 2.
//You should do 
//  Step 2 (A): write seq2
//  Step 2 (B): write main to test seq2
//  Step 2 (C): write sumSeq2
//  Step 2 (D): add test cases to main to test sumSeq2
// 
// Be sure to #include any header files you need!

#include <stdio.h>

int seq2(int x)
{
	/* seq2(n+1) - seq2(n) = 2*n + 4
	 * seq2(0) = 1
	 * => seq2(n) = n*(n-1) + 4*n + 1
	 */
  return x*x + 3*x + 1;
}

int sumSeq2(int low, int high){
  int ans = 0;
  for(;low<high;low++){
    ans += seq2(low);
  }
  return ans;
}

    
int main(void){
  printf("seq2(%d) = %d\n",-121,seq2(-121));
  printf("seq2(%d) = %d\n",0,seq2(0));
  printf("seq2(%d) = %d\n",109,seq2(109));
  printf("")  

