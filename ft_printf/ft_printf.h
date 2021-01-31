#ifndef _FT_PRINTF_H_
#define _FT_PRINTF_H_
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
int letter_uxX(char **line, char **p_temp, unsigned long long value, char the_tpye);
int letter_di(char **line, char **p_temp, unsigned long long value);
int letter_p(char **line, char **p_temp, unsigned long long value);
int letter_s(char **line, char **p_temp, unsigned long long value);
int letter_c_percent(char **line, char **p_temp, unsigned long long value);
int inter_type(char **line, char **p_temp, unsigned long long value, char the_tpye);
int complete_final(char **line, int *p_my_case, char **p_temp);
int flag_precise(char **line, char **p_temp,char *str, int *p_i);
int case_changed(char **line, char **p_temp, int *p_my_case);
int star(char **line, char **p_temp, char *buf, int my_case);
int not_star(char **line, char *str, char **p_temp, int *p_i);
int free_ret_zero(char **p, char *s1, char *s2);
char *precision_int(char **line, int plus, int size, int lenth);
char *no_precision_int(char **line, int plus, int size, int lenth);
char *ten_big_hex(char *str);
char *ten_small_hex(char *str);
int ft_printf(const char *str, ...);
int what_my_case(char c, int now_case);
char *make_string(char **final, char the_type);
char *case_c(char **final);
char *case_s(char **final);
char *case_p(char **final);
char *case_percent(char **final);
char *case_d(char **final);
char *case_i(char **final);
char *case_u(char **final);
char *case_x(char **final);
char *case_X(char **final);
#endif
