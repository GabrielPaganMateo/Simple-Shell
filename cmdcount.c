#include "header.h"
/**
 * cmdcount - counts the amount of commands executed in the shell
 * Return: count
 */
int cmdcount(void)
{
	static int count;

	count++;
	return (count);
}
