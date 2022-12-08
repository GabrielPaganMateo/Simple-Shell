#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdarg.h>
extern char **environ;
char **split_input(char *line, char *delimiter);
int execute(char *line, char **arguments, char **av, char **env, int cmdcount);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _env(char *line, char **env);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *get_path(char **tokens);
char *_strpbrk(char *s, char *accept);
char **split_dirs(char *path);
void free_grid(char **grid);
int _printf(const char *format, ...);
int print_char(int a);
int print_string(char *a);
int print_int(int i);
int print_default(char a);
int print_percent(void);
int cmdcount(void);
char *_strstr(char *haystack, char *needle);
char *add_path(char **tokens, char **dirs);
int builtin(char **tokens, char **env);
int specialcase(char *line, char **av);
#endif
