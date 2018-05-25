#include <stdio.h>
#include <stdlib.h>

#define SIZE 9
#define DEBUG 1

FILE *file;
int result[SIZE*3];

int checkLine(int lineNum);
int checkColumn(int columnNum);
int checkSubgrid(int subgridNum);
int checkSudoku(int array[SIZE]);

int main(int argc, char const *argv[]) {

  if(argc != 2)
  {
    fprintf(stderr, "Usage: problema1.out <file name>\n");
    return -1;
  }
  if (file = fopen(argv[1], "r"))
  {
    int i;
    for (i = 0; i < SIZE; i++)
    {
      //
      if (DEBUG)
        printf("%d\n", i+1);
      //
      // lines
      if (checkLine(i))
        result[i] = 1;
      else
        result[i] = 0;
      // columns
      if (checkColumn(i))
        result[i+SIZE] = 1;
      else
        result[i+SIZE] = 0;
      // subgrid
      if (checkSubgrid(i))
        result[i+(SIZE*2)] = 1;
      else
        result[i+(SIZE*2)] = 0;
      //
      if (DEBUG)
        printf("\n");
      //
    }
    fclose(file);
  }
  else
  {

    fprintf(stderr, "File %s not found!\n", argv[1]);
    return -1;
  }

  int i;
  for (i = 0; i < SIZE*2; i++)
  {
    if (!result[i]){
      printf("Invalid solution!\n");
      return 0;
    }
  }
  printf("Valid solution!\n");
  return 0;
}

int checkLine(int lineNum)
{
  //size of line is 19
  int i, line[SIZE], position = (lineNum * 19);
  fseek(file, position, SEEK_SET);
  for (i = 0; i < SIZE; i++)
    fscanf(file, "%d", &line[i]);
  //
  if (DEBUG)
  {
    printf("line: ");
    for (i = 0; i < SIZE; i++)
      printf("%d ", line[i]);
    printf("\n");
  }
  //
  return checkSudoku(line);
}

int checkColumn(int columnNum)
{
  int column[SIZE], i;
  for (i = 0; i < SIZE; i++)
  {
    //columnNum * 2 because of empty spaces
    int position = (i * 19) + (columnNum * 2);
    fseek(file, position, SEEK_SET);
    fscanf(file, "%d", &column[i]);
  }
  //
  if (DEBUG)
  {
    printf("column: ");
    for (i = 0; i < SIZE; i++)
      printf("%d ", column[i]);
    printf("\n");
  }
  //
  return checkSudoku(column);
}

int checkSubgrid(int subgridNum)
{
  int i, subgrid[SIZE], position = (subgridNum % 3) * 6;;
  if (subgridNum >= 3 && subgridNum < 6)
    position = (3 * 19) + (subgridNum % 3) * 6;
  else if (subgridNum >= 6)
    position = (6 * 19) + (subgridNum % 3) * 6;
  for (i = 0; i < SIZE; i++)
  {
    if (i == 3)
      position += 13;
    if (i == 6)
      position += 13;
    fseek(file, position + (i * 2), SEEK_SET);
    fscanf(file, "%d", &subgrid[i]);
  }
  //
  if (DEBUG)
  {
    printf("subgrid: ");
    for (i = 0; i < SIZE; i++)
      printf("%d ", subgrid[i]);
    printf("\n");
  }
  //
  return checkSudoku(subgrid);
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
