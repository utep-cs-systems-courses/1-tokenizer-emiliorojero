#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

int main(){
  char str[100];
  while(strcmp(str, "quit")){
    printf("Enter string to copy or \"quit\" to finish execution.\n$");
    scanf("%s", str);
    printf("%s\n", str);
    char* c = word_terminator(str);
    printf("%c\n", *c);
  }
}
