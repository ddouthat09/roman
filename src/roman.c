/*
 * Implementation of "libroman.a"
 * Implements public symbols defined in "roman.h"
 * Implements the following private function:
 */
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
 * Last, extra value in array A is to catch terminator of R; it returns
 * zero for terminator to assure that it is less than any valid value
 */
static int A[sizeof(R)] = {1000, 500, 100, 50, 10, 5, 1, 0};
/*
 * Name: getArabicNumeral -- find decimal value corresponding to a Roman numeral
 * Input: r -- the character to be evaluated
 * Process: Find the address (work) of r in string R
 * Return: value at offset in array A corresponding to that in string R or -1
 *         if input r was not found in string R
 */
int getArabicNumeral(char r)
{
  char* work = strchr(R,toupper(r));
  return work?A[work-R]:-1;
}
static struct {
  int val;      //decimal value at this break point
  char* rom;    //Roman equivalent of val
  int sz;       //size of rom
} coder[] = { //breakpoints for shifts of Roman representation
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
#define CODER (sizeof(coder)/sizeof(coder[0]))  //number of elements in coder
static char* buf;   //build Roman string here
static int bufsize; //current size of buf
#define BUFSTEP 10  //increase buf by these increments
/*
 * Name: rom_Arabic2Roman -- find Roman string from Arabic notation decimal
 * Input: a -- Decimal to be converted
 * Process: Find the largest val in coder array that is less than or equal to
 *          input a. Subtract that value from a and add the corresponding string
 *          rom to buf, expanding buf as needed. Repeat until a is zero. Then
 *          terminate the string in buf.
 * Return: Roman string built in buf or empty string if can't expand buf
 */
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
/*
 * Name: rom_Roman2Arabic -- find Arabic decimal from Roman string
 * Input: r -- Roman number string to be converted
 * Process: Scan input string r. Get value of this Roman numeral and the next.
 *          if an input character is invalid, return negative of bad character
 *          If this is greater than last, set current to this - last to handle
 *          subtractive prefixing of Roman numerals. Else, cumulate this into
 *          current to pick up possible repeated Roman numerals. If this is
 *          larger than next, any repeating sequence is over so cumulate current
 *          into out, reset current to zero and continue scanning.
 * Return: out -- cumulated result at completion of scan
 */
int rom_Roman2Arabic(char* r)
{
  int out = 0;      //accumulator for final result
  int current = 0;  //accumulator for intermediate results
  int last = 1000;  //Arabic value of last Roman numeral
  for (char* work = r; *work; ++work) {
    int This = getArabicNumeral(*work);
    int next = getArabicNumeral(*(work+1));
    if (This < 0) return -(*work);
    if (next < 0) return -(*(work+1));
    if (This > last) { //Roman subtractive token pair?
      current = This - last; //yes, do the subtraction
    } else {
      current += This;  //nope, just cumulate
    }
    last = This;
    if (This > next) {
      out += current;
      current = 0;
    }
  }
  return out;
}
