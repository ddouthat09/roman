/*
 * Implementation of "libroman.a"
 * Implements public symbols defined in "roman.h"
 * Implements the following private functions:
 */
int getRomanNumeral(int a);
int getArabicNumeral(char r);
/*
 * Compiler and OS includes
 */
#include <ctype.h>
#include <string.h>
/*
 * typedef's and #define's
 */
#define R "MDCLXVI"
/*
 * Local symbols visible only in this file
 */
static int A[sizeof(R)-1] = {1000, 500, 100, 50, 10, 5, 1};

int getRomanNumeral(int a)
{
  switch (a) {
  case 1000:
    return 'M';
    break;
  case 500:
    return 'D';
    break;
  case 100:
    return 'C';
    break;
  case 50:
    return 'L';
    break;
  case 10:
    return 'X';
    break;
  case 5:
    return 'V';
    break;
  case 1:
    return 'I';
    break;
  default:
    return -1;
    break;
  }
}
int getArabicNumeral(char r)
{
  char* work;
  if (!( work = strchr(R,toupper(r)) )) return -1;
  return A[work-R];
}

