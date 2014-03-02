#include <stdlib.h>
#include <stdio.h>

int xor_files(char *a_path){
  FILE *original;
  int a, b;

  if(!(original = fopen(a_path, "rb"))){
    return -1;
  }

  a = getc(original);
  b = getc(stdin);

  while(b != EOF){
    if(a == EOF){
      a = 0;
    }

    fputc(a ^ b, stdout);

    a = getc(original);
    b = getc(stdin);
  }

  fclose(original);
  return 0;
}

int main(int argc, char* argv[]){
  if(argc != 2){
    fprintf(stderr, "Invalid number of arguments supplied to %s: %i\n", argv[0], argc - 1);
    return 1;
  }

  if(xor_files(argv[1])){
    fprintf(stderr, "Error while xoring files\n");
    return 2;
  }

  return 0;
}
