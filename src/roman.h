#if !defined(ROMAN_H_INCLUDED)
#define ROMAN_H_INCLUDED
/*
 * Definitions of public symbols available to users of "libroman.a"
 */
char*               //Roman number string result
rom_Arabic2Roman(   //convert an Arabic positional number to Roman number
    int a);         //Arabic number to convert

int                 //Arabic number result
rom_Roman2Arabic(   //convert Roman number string to Arabic positional number
    char* r);       //Roman number string to convert

#endif //!defined(ROMAN_H_INCLUDED/
