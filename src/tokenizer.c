#include <string.h>
#include <ctype.h>
#include <stdio.h>

int space_char(char c){
  if(isspace(c))
    return 1;
  return 0;
}

int non_space_char(char c){
  if(!isspace(c))
    return 1;
  return 0;
}

char* word_start(char *s){
  int i = 0;
 
  while(i < strlen(s) && space_char(*(s+i))){
    i += 1;
  }
  return s+i;
}

char* word_terminator(char *word){
  int i = 0;
  while(i < strlen(word) && space_char(*(word+i)))
    i += 1;
  
  while(i < strlen(word) && non_space_char(*(word+i))){
    printf("imprimiendo %c\n", *(word+i));
    i += 1;
  }
  return word+i;
}

int count_words(char *s){
  char* start = word_start(s);
  char* end = word_terminator(s);
  int count = 1;
  while(*end != '\0'){
    start = word_start(end);
    end = word_terminator(end);
    count += 1;    
  }
  return count;
}

