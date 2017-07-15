#include <stdio.h>
#include <stdlib.h>

struct data {
  int index;
  int value;
};

static int compare (const void *a1, const void *a2)
{
  int num1 = ((struct data *)a1)->value;
  int num2 = ((struct data *)a2)->value;

  return num1 - num2;
}

int *twoSum (int *nums, int numSize, int target)
{
  int *indices;
  int i, j;
  int sum;
  struct data *buffer;

  /* convert to processing buffer */
  buffer = malloc (sizeof (struct data) * numSize);
  for (i = 0; i < numSize; i++) {
    buffer[i].index = i;
    buffer[i].value = nums[i];
  }

  indices = malloc (sizeof (int) * 2);
  qsort (buffer, numSize, sizeof(struct data), compare);

  i = 0;
  j = numSize - 1;
  while (i < j) {
    sum = buffer[i].value + buffer[j].value;
    if (sum > target) {
      j--;
    } else if (sum < target) {
      i++;
    } else {
      indices[0] = buffer[i].index;
      indices[1] = buffer[j].index;
      break;
    }
  }
  free (buffer);

  return indices;
}

int main (void)
{
  int *answer;
  int nums[] = {3, 2, 4};
  int target = 6;

  answer = twoSum (nums, 3, target);
  printf ("%d %d\n", answer[0], answer[1]);

  free (answer);

  return 0;
}
