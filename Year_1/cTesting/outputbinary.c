#include<stdio.h>

int main() {
  int buffer;
  int store = 1234;
  // Creating a file and storing an int value
  FILE * stream;
  stream = fopen("file.txt", "w");
  fwrite(&store, sizeof(int), 1, stream);
  fclose(stream);

  // Reading value from file
  stream = fopen("file.txt", "r");
  fread(&buffer, sizeof(int), 1, stream);
  printf("Reading high score: %d\n",buffer);
  fclose(stream);

  return(0);
}