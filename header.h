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
char *read_line(void);
char **split_input(char *line);
int execute(char **arguments);
void print_prompt1(void);
void print_prompt2(void);
#endif
