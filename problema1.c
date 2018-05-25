#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

FILE *file;
int result[SIZE];

int checkColumn(int columnNum);
int checkSudoku(int array[SIZE]);

int main(int argc, char const *argv[]) {

  if(argc != 2)
  {
    fprintf(stderr, "usage: problema1.out <file name>\n");
    return -1;
  }
  if (file = fopen(argv[1], "r"))
  {
    int i;
    for (i = 0; i < SIZE; i++)
    {
      if (checkColumn(i))
        result[i] = 1;
      else
        result[i] = 0;
    }
    fclose(file);
  }
  else
  {

    fprintf(stderr, "%s not found\n", argv[1]);
    return -1;
  }

  int i;
  for (i = 0; i < SIZE; i++)
  {
    if (!result[i]){
      printf("Invalid solution\n");
      return 0;
    }
  }
  printf("Valid solution\n");
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
  }
  return checkSudoku(column);
}

int checkSudoku(int array[SIZE])
{
  int i, count[SIZE] = {0};
  for(i = 0; i < SIZE; i++)
  {
    if (count[array[i]] != 1)
      count[array[i]]++;
    else
      return 0;
  }
  return 1;
}





























//
