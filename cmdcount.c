#include "header.h"
/*
 *
 */
int cmdcount()
{
	static int count = 0;
	count++;
	return (count);
}
