#include "holberton.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: the string to check
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * errors - prints Error and exits with status 98
 */
void errors(void)
{
	char *err = "Error\n";
	int i = 0;

	while (err[i])
	{
		_putchar(err[i]);
		i++;
	}
	exit(98);
}

/**
 * print_result - prints the result array
 * @res: array of integers
 * @len_res: length of result
 */
void print_result(int *res, int len_res)
{
	int start = 0;

	while (start < len_res && res[start] == 0)
		start++;

	if (start == len_res)
		_putchar('0');
	else
	{
		for (; start < len_res; start++)
			_putchar(res[start] + '0');
	}
	_putchar('\n');
}

/**
 * multiply - multiplies two positive numbers
 * @num1: first number as string
 * @num2: second number as string
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, len_res, i, j, carry, n1, n2, *res;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len_res = len1 + len2;
	res = malloc(sizeof(int) * len_res);
	if (!res)
		exit(98);

	for (i = 0; i < len_res; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			carry += res[i + j + 1] + (n1 * n2);
			res[i + j + 1] = carry % 10;
			carry /= 10;
		}
		res[i + j + 1] += carry;
	}

	print_result(res, len_res);
	free(res);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		errors();

	multiply(argv[1], argv[2]);
	return (0);
}
