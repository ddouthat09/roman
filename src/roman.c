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
 * Last, extra value in array A is to catch string terminator; it returns
 * zero for terminator to assure that it is less than any valid value
 */
static int A[sizeof(R)] = {1000, 500, 100, 50, 10, 5, 1, 0};

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
  char* work = strchr(R,toupper(r));
  return work?A[work-R]:-1;
}
char* rom_Arabic2Roman(int a)
{
  return NULL;
}
int rom_Roman2Arabic(char* r)
{
  int out = 0;
  int current = 0;
  int last = 1000;
  for (char* work = r; *work; ++work) {
    int this = getArabicNumeral(*work);
    int next = getArabicNumeral(*(work+1));
    if (this > last) {
      current = this - current;
    } else {
      current += this;
    }
    last = this;
    if (this > next) {
      out += current;
      current = 0;
    }
  }
  return out;
}

