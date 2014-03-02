#include <stdlib.h>
#include <stdio.h>

int xor_files(char *a_path, char *b_path, char *c_path){
  FILE *original, *working, *mask;
  int a, b;

  if(!((original = fopen(a_path, "rb")) &&
     (working = fopen(b_path, "rb")) &&
      (mask = fopen(c_path, "wb")))){
    return -1;
  }

  a = getc(original);
  b = getc(working);

  while(b != EOF){
    if(a == EOF){
      a = 0;
    }

    fputc(a ^ b, mask);

    a = getc(original);
    b = getc(working);
  }

  fclose(original);
  fclose(working);
  fclose(mask);
  return 0;
}

int main(int argc, char* argv[]){
  if(argc != 4){
    fprintf(stderr, "Invalid number of arguments supplied to %s: %i\n", argv[0], argc - 1);
    return 1;
  }

  if(xor_files(argv[1], argv[2], argv[3])){
    fprintf(stderr, "Error while xoring files\n");
    return 2;
  }

  return 0;
}
