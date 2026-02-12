#include "../minishell.h"

int array_length(char **array)
{
  int counter;
  counter = 0;
  while (array[counter])
  {
    counter++;
    if (array[counter] == NULL)
      break;
  }
  return counter;
}