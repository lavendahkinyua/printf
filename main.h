#ifndef MAIN_H
#define MAIN_H

/** ===== C Header Files ===== */
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

/** ===== Structures ===== */

/**
 * struct flag_s - Struct for printf flags
 * @plus: '+' character flag for printing an explicit + sign for positive nums
 * @hash: '#' character for altering the form of the converted value
 */
typedef struct flag_s
{
    char plus;
    char hash;
    char space;
} flag_t;

/**
 * struct spec_s - Struct format
 * @spec: specifier
 * @f: function called for the specifier
 */
typedef struct spec_handler_s
{
    char spec;
    int (*func)(va_list ap, flag_t *flags);
} spec_handler_t;

/** ===== Function Prototypes ===== */
/** DIY printf prototype*/
int _printf(const char *format, ...);

/** String Utility*/
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);
char *_strchr(char *s, char c);

/** String Printers*/
int _putchar(char c);
int _puts(char *s);
void rev_str(char *s);
int _putstr(va_list ap, flag_t *flags);
int _putchr(va_list ap, flag_t *flags);
int _putnpt(va_list ap, flag_t *flags);
int _putprt(va_list ap, flag_t *flags);
int _putadd(va_list ap, flag_t *flags);

/** Converters*/
char *converter(unsigned long int n, int base, int l);

/** Number Utility */
unsigned long int _abs(long int x);
unsigned long int _abs_big(long int x);

/** Number Printers*/
int _putint(va_list ap, flag_t *flags);
int _putbin(va_list ap, flag_t *flags);
int _putoct(va_list ap, flag_t *flags);
int _putuint(va_list ap, flag_t *flags);
int _puthex(va_list ap, flag_t *flags);
int _putheX(va_list ap, flag_t *flags);
int _puthexX(va_list ap, int lower, flag_t *flags);

int (*get_printer(char spec))(va_list, flag_t *);
int is_spec(const char spec);
int is_flag(const char flag);
void set_flag(char flag, flag_t *flags, int *is_set);
int unset_flag(flag_t *flags);

#endif /* MAIN_H **/
