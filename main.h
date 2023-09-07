#ifndef main_h
#define main_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int _putzar(char c);
int _putz(const char *str);
int _stricomp(char *s1, char *s2);
char *_strdupp(char *str);
char *_strcate(char *dest, char *src);
ssize_t _getline(char **buffer, size_t *LTD);
ssize_t _readline(int fd, char **buffer, size_t *LTD);

#endif
