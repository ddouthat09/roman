#include <stdio.h>
#include <stdlib.h>

#include <config.h>
#include <check.h>
#include "../src/roman.h"

int getRomanNumeral(int a);
int getArabicNumeral(char r);

START_TEST(test_getRoman1000)
{
  int r = getRomanNumeral(1000);
  ck_assert_int_eq(r,'M');
}
END_TEST

START_TEST(test_getRoman500)
{
  int r = getRomanNumeral(500);
  ck_assert_int_eq(r,'D');
}
END_TEST

START_TEST(test_getRoman100)
{
  int r = getRomanNumeral(100);
  ck_assert_int_eq(r,'C');
}
END_TEST

START_TEST(test_getRoman50)
{
  int r = getRomanNumeral(50);
  ck_assert_int_eq(r,'L');
}
END_TEST

START_TEST(test_getRoman10)
{
  int r = getRomanNumeral(10);
  ck_assert_int_eq(r,'X');
}
END_TEST

START_TEST(test_getRoman5)
{
  int r = getRomanNumeral(5);
  ck_assert_int_eq(r,'V');
}
END_TEST

START_TEST(test_getRoman3)
{
  int r = getRomanNumeral(3);
  ck_assert_int_eq(r,-1);
}
END_TEST

START_TEST(test_getRoman1)
{
  int r = getRomanNumeral(1);
  ck_assert_int_eq(r,'I');
}
END_TEST

START_TEST(test_getArabic_M)
{
  int a = getArabicNumeral('M');
  ck_assert_int_eq(a,1000);
}
END_TEST

START_TEST(test_getArabic_D)
{
  int a = getArabicNumeral('D');
  ck_assert_int_eq(a,500);
}
END_TEST

START_TEST(test_getArabic_C)
{
  int a = getArabicNumeral('C');
  ck_assert_int_eq(a,100);
}
END_TEST

START_TEST(test_getArabic_L)
{
  int a = getArabicNumeral('L');
  ck_assert_int_eq(a,50);
}
END_TEST

START_TEST(test_getArabic_X)
{
  int a = getArabicNumeral('X');
  ck_assert_int_eq(a,10);
}
END_TEST

START_TEST(test_getArabic_V)
{
  int a = getArabicNumeral('V');
  ck_assert_int_eq(a,5);
}
END_TEST

START_TEST(test_getArabic_I)
{
  int a = getArabicNumeral('I');
  ck_assert_int_eq(a,1);
}
END_TEST

START_TEST(test_getArabic_m)
{
  int a = getArabicNumeral('m');
  ck_assert_int_eq(a,1000);
}
END_TEST

START_TEST(test_getArabic_q)
{
  int a = getArabicNumeral('q');
  ck_assert_int_eq(a,-1);
}
END_TEST

START_TEST(test_getArabic_0)
{
  int a = getArabicNumeral('\0');
  ck_assert_int_eq(a,0);
}
END_TEST

START_TEST(test_rom_Roman2Arabic_MM)
{
  int a = rom_Roman2Arabic("MM");
  ck_assert_int_eq(a,2000);
}
END_TEST

START_TEST(test_rom_Roman2Arabic_MCM)
{
  int a = rom_Roman2Arabic("mcm");
  ck_assert_int_eq(a,1900);
}
END_TEST

Suite * roman_suite(void)
{
  Suite *s;
  TCase *tc_core;

  s = suite_create("roman");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_getRoman1000);
  tcase_add_test(tc_core, test_getRoman500);
  tcase_add_test(tc_core, test_getRoman100);
  tcase_add_test(tc_core, test_getRoman50);
  tcase_add_test(tc_core, test_getRoman10);
  tcase_add_test(tc_core, test_getRoman5);
  tcase_add_test(tc_core, test_getRoman3);
  tcase_add_test(tc_core, test_getRoman1);
  tcase_add_test(tc_core, test_getArabic_M);
  tcase_add_test(tc_core, test_getArabic_D);
  tcase_add_test(tc_core, test_getArabic_C);
  tcase_add_test(tc_core, test_getArabic_L);
  tcase_add_test(tc_core, test_getArabic_X);
  tcase_add_test(tc_core, test_getArabic_V);
  tcase_add_test(tc_core, test_getArabic_I);
  tcase_add_test(tc_core, test_getArabic_m);
  tcase_add_test(tc_core, test_getArabic_q);
  tcase_add_test(tc_core, test_getArabic_0);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_MM);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_MCM);
  suite_add_tcase(s, tc_core);

  return s;
}
int main(void)
{
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = roman_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return 0 == number_failed?EXIT_SUCCESS:EXIT_FAILURE;
}
