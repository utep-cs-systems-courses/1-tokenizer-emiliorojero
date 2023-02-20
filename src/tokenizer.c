#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

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

char* copy_str(char* inStr, short len){

  char * words = (char *)malloc(len * sizeof(char*));
  int i = 0;
  while(i < strlen(inStr) && i < len){
    *(words + i) = *(inStr + i);
    i += 1;
  }
  *(words + i) = '\0';
  return words;
}

char** tokenize(char* s){

  char** arr = malloc((count_words(s) + 1) * sizeof(char*));
  char* start = word_start(s);
  char* end = word_terminator(s);
  int i = 0;
  printf("words*sizeof(char*): %d\n", (count_words(s)+1)*sizeof(char*));
  printf("spaces created %d\n", count_words(s)+1);
  printf("sizeof(char): %d\n", sizeof(char));
  printf("sizeof(char*): %d\n", sizeof(char*));
  printf("sizeof(arr): %d\n", sizeof(arr));
  printf("arr* %d\n", sizeof(*arr));
  //printf("arr** %d\n", sizeof());
  while(i < count_words(s)){
    int dif = end - start;
    printf("dif: %d\n", dif);
    *(arr + i) = copy_str(start, (end - start));
    start = word_start(end);
    end = word_terminator(end);
    i += 1;
  }
  *(arr + i) = '\0';
  return arr;
  
}

void print_tokens(char** tokens){

  printf("tokens: %d\n", sizeof(tokens));
  printf("*tokens: %d\n", sizeof(*tokens));
  printf("**tokens: %d\n", sizeof(**tokens));
  printf("sizeof(char): %d\n", sizeof(char));
  printf("sizeof(char*): %d\n", sizeof(char*));
  printf("sizeof(char**): %d\n", sizeof(char**));
  printf("size of array: %d\n", (int)(sizeof(*tokens) / sizeof(**tokens)));
	
  
}
