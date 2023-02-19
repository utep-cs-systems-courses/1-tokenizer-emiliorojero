#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

int main(){
  char str[100];
  char* p;
  printf("Enter string to copy or \"quit\" to finish execution.\n$");
  scanf("%[^\n]%*c", str);
  printf("%s\n", str);
  while(strcmp(str, "quit")){
    int words = count_words(str);
    printf("%d\n", words);
    printf("Enter string to copy or \"quit\" to finish execution.\n$");
    scanf("%[^\n]%*c", str);
    printf("%s\n", str);
 
  }
}
