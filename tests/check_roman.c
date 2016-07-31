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

START_TEST(test_rom_Roman2Arabic_CDXCIX)
{
  int a = rom_Roman2Arabic("CDXCIX");
  ck_assert_int_eq(a,499);
}
END_TEST

START_TEST(test_rom_Roman2Arabic_MCMXXXVI)
{
  int a = rom_Roman2Arabic("MCMXXXVI");
  ck_assert_int_eq(a,1936);
}
END_TEST

START_TEST(test_rom_Roman2Arabic_MMCMXCIX)
{
  int a = rom_Roman2Arabic("MMCMXCIX");
  ck_assert_int_eq(a,2999);
}
END_TEST

START_TEST(test_rom_Roman2Arabic_IIII)  //technically illegal but still works
{
  int a = rom_Roman2Arabic("IIII");
  ck_assert_int_eq(a,4);
}
END_TEST

START_TEST(test_rom_Roman2Arabic_XXXX)  //technically illegal but still work
{
  int a = rom_Roman2Arabic("XXXX");
  ck_assert_int_eq(a,40);
}
END_TEST

START_TEST(test_rom_Roman2Arabic_CCCC)  //technically illegal but still work
{
  int a = rom_Roman2Arabic("CCCC");
  ck_assert_int_eq(a,400);
}
END_TEST

START_TEST(test_rom_Roman2Arabic_qCCC)  //returns negative of invalid character
{
  int a = rom_Roman2Arabic("qCCC");
  ck_assert_int_eq(a,-'q');
}
END_TEST

START_TEST(test_rom_Roman2Arabic_CqCC)  //same as above but detected at next
{
  int a = rom_Roman2Arabic("CqCC");
  ck_assert_int_eq(a,-'q');
}
END_TEST

START_TEST(test_rom_Roman2Arabic_VV)  //technically illegal but still work
{
  int a = rom_Roman2Arabic("VV");
  ck_assert_int_eq(a,10);
}
END_TEST

START_TEST(test_rom_Roman2Arabic_LL)  //technically illegal but still work
{
  int a = rom_Roman2Arabic("LL");
  ck_assert_int_eq(a,100);
}
END_TEST

START_TEST(test_rom_Roman2Arabic_DD)  //technically illegal but still work
{
  int a = rom_Roman2Arabic("DD");
  ck_assert_int_eq(a,1000);
}
END_TEST

START_TEST(test_rom_Arabic2Roman_1)
{
  char* a = rom_Arabic2Roman(1);
  ck_assert_str_eq(a,"I");
}
END_TEST

START_TEST(test_rom_Arabic2Roman_2)
{
  char* a = rom_Arabic2Roman(2);
  ck_assert_str_eq(a,"II");
}
END_TEST

START_TEST(test_rom_Arabic2Roman_3)
{
  char* a = rom_Arabic2Roman(3);
  ck_assert_str_eq(a,"III");
}
END_TEST

START_TEST(test_rom_Arabic2Roman_4)
{
  char* a = rom_Arabic2Roman(4);
  ck_assert_str_eq(a,"IV");
}
END_TEST

START_TEST(test_rom_Arabic2Roman_9)
{
  char* a = rom_Arabic2Roman(9);
  ck_assert_str_eq(a,"IX");
}
END_TEST

START_TEST(test_rom_Arabic2Roman_49)
{
  char* a = rom_Arabic2Roman(49);
  ck_assert_str_eq(a,"XLIX");
}
END_TEST

START_TEST(test_rom_Arabic2Roman_99)
{
  char* a = rom_Arabic2Roman(99);
  ck_assert_str_eq(a,"XCIX");
}
END_TEST

START_TEST(test_rom_Arabic2Roman_499)
{
  char* a = rom_Arabic2Roman(499);
  ck_assert_str_eq(a,"CDXCIX");
}
END_TEST

START_TEST(test_rom_Arabic2Roman_999)
{
  char* a = rom_Arabic2Roman(999);
  ck_assert_str_eq(a,"CMXCIX");
}
END_TEST

START_TEST(test_rom_Arabic2Roman_1999)
{
  char* a = rom_Arabic2Roman(1999);
  ck_assert_str_eq(a,"MCMXCIX");
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
  tcase_add_test(tc_core, test_rom_Roman2Arabic_CDXCIX);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_MCMXXXVI);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_MMCMXCIX);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_IIII);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_XXXX);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_CCCC);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_qCCC);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_CqCC);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_VV);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_LL);
  tcase_add_test(tc_core, test_rom_Roman2Arabic_DD);
  tcase_add_test(tc_core, test_rom_Arabic2Roman_1);
  tcase_add_test(tc_core, test_rom_Arabic2Roman_2);
  tcase_add_test(tc_core, test_rom_Arabic2Roman_3);
  tcase_add_test(tc_core, test_rom_Arabic2Roman_4);
  tcase_add_test(tc_core, test_rom_Arabic2Roman_9);
  tcase_add_test(tc_core, test_rom_Arabic2Roman_49);
  tcase_add_test(tc_core, test_rom_Arabic2Roman_99);
  tcase_add_test(tc_core, test_rom_Arabic2Roman_499);
  tcase_add_test(tc_core, test_rom_Arabic2Roman_999);
  tcase_add_test(tc_core, test_rom_Arabic2Roman_1999);

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
