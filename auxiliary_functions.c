#include "header.h"
#include <string.h>
/**
 * print_char - prints a single character
 * @a: character to be printed
 * Return: 1, for the amount of characters printed
 */
int print_char(int a)
{
	write(1, &a, 1);
	return (1);
}
/**
 * print_string - prints a string from _printf
 * @a: pointer to string
 * Return: length of string
 */
int print_string(char *a)
{
	int length;

	if (a == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	length = _strlen(a);

	write(1, a, length);
	return (length);
}

/**
 * print_int - Prints integer 'i' in base 10.
 * @i: integer to be printed in base 10
 *
 * Return: the amount of chars the number
 * takes in the standard output.
 */
int print_int(int i)
{
	int i_copy = i;
	char output[] = "           ";
	/* digits are filled from least significant; from right to left here. */
	int char_limit = 11;
	/*
	 * integer limit is 2,417,483,647, so we only need 10 digits, and a
	 * minus sign if needed.
	 */
	int index;
	int char_count;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	for (index = char_limit - 1; i;)
	{
		int digit = i % 10;

		if (digit < 0)
			digit *= -1;
		output[index] = '0' + digit;
		/*
		 * ('i % 10' will always be between -10 and 10 here)
		 * If 'i' is negative, 'i % 10' also give a negative char,
		 * so we have to turn it posivite to avoid non-digit chars.
		 */
		i /= 10;
		index--;
	}
	if (i_copy < 0)
		output[index] = '-';
	else
		index++;
	/* move one more index to the left if minus sign is needed. */
	char_count = char_limit - index;
	/* this also counts minus sign */
	write(1, &(output[index]), char_count);
	return (char_count);
}
/**
 * print_default - prints edge case that does not apply in switch case
 * @a: pointer to character to be printed
 * Return: amount of character printed
 */
int print_default(char a)
{
	write(1, "%", 1);
	write(1, &a, 1);
	return (2);
}
/**
 * print_percent - prints percent sign
 * Return: 1, for the one percent printed
 */
int print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

