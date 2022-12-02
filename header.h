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
extern char **environ;
char *read_line(void);
char **split_input(char *line, char *delimiter);
int execute(char *line, char **arguments, char **env);
void print_prompt1(void);
void print_prompt2(void);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _env(char *line, char **env);
int X(char *line);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *get_path(char **tokens);
char *_strpbrk(char *s, char *accept);
char **split_dirs(char *path);
void free_grid(char **grid);
char *_strdup(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
#endif
