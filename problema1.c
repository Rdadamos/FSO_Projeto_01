#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

FILE *file;
int checkColumn(int columnNum);

int main(int argc, char const *argv[]) {

  if(argc != 2)
  {
    fprintf(stderr, "usage: problema1.out <file name>\n");
    return -1;
  }
  if (file = fopen(argv[1], "r"))
  {
    checkColumn(0);
    fclose(file);
  }
  else
  {

    fprintf(stderr, "%s not found\n", argv[1]);
    return -1;
  }

  return 0;
}

int checkColumn(int columnNum)
{
  int column[SIZE], i;
  for (i = 0; i < SIZE; i++)
  {
    int position = (i * 19) + (columnNum * 2);
    fseek(file, position, SEEK_SET);
    fscanf(file, "%d", &column[i]);
    printf("%d\n", column[i]);
  }
  return 0;
}
