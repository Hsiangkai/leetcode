#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
  int i;
  int j;
  char c;
  char *lcp;

  if (strsSize == 0 || strs == NULL)
    return "";

  for (i = 0; ; i++) {
    c = strs[0][i];
    if (c == '\0')
      break;

    for (j = 1; j < strsSize; j++) {
      if (c != strs[j][i])
	break;
    }

    if (j != strsSize)
      break;
  }

  lcp = malloc (sizeof (char) * (i + 1));
  strncpy (lcp, strs[0], i);
  lcp[i] = '\0';

  return lcp;
}

int main(void)
{
  char *lcp;
  char *data[] = {"", "leetcode", "leetc"};

  lcp = longestCommonPrefix(NULL, 0);
  printf ("%s\n", lcp);
  return 0;
}
