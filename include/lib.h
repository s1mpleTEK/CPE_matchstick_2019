/*
** EPITECH PROJECT, 2019
** lib
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

#include <stdarg.h>
#include <stddef.h>

#define BASE_HEX_L "0123456789abcdef"
#define BASE_HEX_U "0123456789ABCDEF"
#define BASE_OCT "01234567"
#define BASE_DEC "0123456789"
#define BASE_BIN "01"

#define LLUI long long unsigned int

void my_putchar(char);
void my_putstr(char *);
void my_putstr_upper_s(char *);
void my_put_nbr(int, char *);
void my_put_nbr_l(long int, char *);
void my_put_nbr_u(unsigned, char *);
void my_put_nbr_l_u(long unsigned, char *);
void my_put_nbr_llui(long long unsigned int, char *);
void my_printf(char *, ...);
int my_strlen(char *);
void my_swap(int *, int *);
int my_getnbr(char *);
int base_flag_bin(int, char *, va_list);
int base_flag_dec_and_long_dec(int, char *, va_list);
int base_flag_hex(int, char *, va_list);
int base_flag_long_hex(int, char *, va_list);
int base_flag_oct_and_long_oct(int, char *, va_list);
int basic_flag(int, char *, va_list);
int base_flag_pointer(int, char *, va_list);
int base_flag_upper_s(int, char *, va_list);
int my_str_isnum(char const*);
int my_str_isnum_neg(char const*);
void* mem_set(void*, int, size_t);
void* mem_cpy(void*, void*, size_t);
void mem_move(void*, void*, size_t);
int check_h(char*);

#endif /* !LIB_H_ */
