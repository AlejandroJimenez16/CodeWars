#include <stdbool.h>

int i;
bool is_uppercase(const char *source){
  i = 0;
  while(source[i] != '\0'){
    if (!((source[i] >= 'A' && source[i] <= 'Z') || (source[i] >= 'a' && source[i] <= 'z'))){
      i++;
      continue;
    }
    if(!(source[i] >= 'A' && source[i] <= 'Z')){
      return false;
    }
    i++;
  }
  return true;
}