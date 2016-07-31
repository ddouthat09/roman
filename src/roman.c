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
#include <stdlib.h>
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
static struct {
  int val;
  char* rom;
  int sz;
} coder[] = {
  {1,"I",1},
  {4,"IV",2},
  {5,"V",1},
  {9,"IX",2},
  {10,"X",1},
  {40,"XL",2},
  {50,"L",1},
  {90,"XC",2},
  {100,"C",1},
  {400,"CD",2},
  {500,"D",1},
  {900,"CM",2},
  {1000,"M",1}
};
#define CODER (sizeof(coder)/sizeof(coder[0]))
static char* buf;
static int bufsize;
#define BUFSTEP 10
char* rom_Arabic2Roman(int a)
{
  int ndx;
  int sz = 0;
  while (a > 0) {
    for (ndx = CODER; ndx--;) {
      if (a >= coder[ndx].val) break;
    }
    a -= coder[ndx].val;
    if (( sz + coder[ndx].sz + 1 ) >= bufsize) {    //one extra for NUL
      if (!( buf = (char*)realloc(buf, bufsize += BUFSTEP) )) return "";
    }
    strcpy(&buf[sz], coder[ndx].rom);
    sz += coder[ndx].sz;
  }
  buf[sz] = '\0';
  return buf;
}
int rom_Roman2Arabic(char* r)
{
  int out = 0;
  int current = 0;
  int last = 1000;
  for (char* work = r; *work; ++work) {
    int this = getArabicNumeral(*work);
    int next = getArabicNumeral(*(work+1));
    if (this < 0) return -(*work);
    if (next < 0) return -(*(work+1));
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

