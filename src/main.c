#include <errno.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "roman.h"

int main(void)
{
  char* line = NULL;
  size_t linecap = 0;
  int num;
  int op1;
  int op2;
  int out;
  char* work;

  puts("At any input prompt, RETURN exits this program\n");
  while (1) {
    while (1) {
      fputs("Enter first operand-> ", stdout);
      num = getline(&line, &linecap, stdin);
      if (( work = strchr(line, '\n') )) *work = '\0';
      if (num < 0) {
        fprintf(stdout, "Error: %s\n", strerror(errno));
        return EXIT_FAILURE;
      }
      else if (num < 2) return EXIT_SUCCESS;
      else if (( op1 = rom_Roman2Arabic(line) ) < 0 ) {
        char bad = (char)(-op1);
        printf("Invalid character ('%c' '\\x%x')\n", bad, bad);
        continue;
      } else {
        printf("Input: \"%s\" converts to %d\n", line, op1);
        break;
      }
    }
    while (1) {
      fputs("Enter second operand-> ", stdout);
      num = getline(&line, &linecap, stdin);
      if (( work = strchr(line, '\n') )) *work = '\0';
      if (num < 0) {
        fprintf(stdout, "Error: %s\n", strerror(errno));
        return EXIT_FAILURE;
      }
      else if (num < 2) return EXIT_SUCCESS;
      else if (( op2 = rom_Roman2Arabic(line) ) < 0 ) {
        char bad = (char)(-op2);
        printf("Invalid character ('%c' '\\x%x')\n", bad, bad);
        continue;
      } else {
        printf("Input: \"%s\" converts to %d\n", line, op2);
        break;
      }
    }
    int done = 0;
    while (!done) {
      fputs("Operation: (a)dd, (s)ubtract, (m)ultiply, (d)ivide-> ", stdout);
      num = getline(&line, &linecap, stdin);
      if (num < 0) {
        fprintf(stdout, "Error: %s\n", strerror(errno));
        return EXIT_FAILURE;
      }
      else if (num < 2) return EXIT_SUCCESS;
      else {
        switch (tolower(*line)) {
        case 'a':
          out = op1 + op2;
          done = 1;
          break;
        case 's':
          out = op1 - op2;
          if (out > 0) done = 1;
          else {
            puts("Cannot represent result\n");
            goto CONTINUE;
          }
          break;
        case 'm':
          out = op1*op2;
          done = 1;
          break;
        case 'd':
          out = op1/op2;
          if (out > 0) done = 1;
          else {
            puts("Cannot represent result\n");
            goto CONTINUE;
          }
          break;
        default:
          puts("Unsupported input\n");
          break;
        }
      }
    }
    printf("Result: %d %s\n\n", out, rom_Arabic2Roman(out));
CONTINUE:
    continue;
  }
  //return EXIT_SUCCESS;
}

