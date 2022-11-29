#include "header.h"
/**
 *print_prompt1-function to print dollar sign
 */
void print_prompt1(void)
{
	write(1, "$ ", 2);
}
/**
 *print_prompt2-function to print arrow sign
 */
void print_prompt2(void)
{
	write(1, "> ", 2);
}
