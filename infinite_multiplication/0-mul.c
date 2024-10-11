#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_error - prints error message and exits with status 98
 */
void print_error(void) {
  printf("Error\n");
  exit(98);
}

/**
 * is_digit - checks if a string contains only digits
 * @str: string to check
 * Return: 1 if string contains only digits, 0 otherwise
 */
int is_digit(char *str) {
  for (int i = 0; str[i]; i++) {
    if (!isdigit(str[i])) {
      return (0);
    }
  }
  return (1);
}

/**
 * multiply - Function that multiplies two positive numbers
 * @num1: first number as string
 * @num2: second number as string
 */
void multiply(char *num1, char *num2) {
  int len1 = strlen(num1);
  int len2 = strlen(num2);
  int total_len = len1 + len2;
  int *result = malloc(total_len * sizeof(int));

  if (result == NULL)
    exit(98);

  for (int i = 0; i < total_len; i++) {
    result[i] = 0;
  }

  for (int i = len1 - 1; i >= 0; i--) {
    for (int j = len2 - 1; j >= 0; j--) {
      int mul = (num1[i] - '0') * (num2[j] - '0');
      int sum = mul + result[i + j + 1];

      result[i + j + 1] = sum % 10;
      result[i + j] += sum / 10;
    }
  }

  // Skip zeros at start
  int i = 0;
  while (i < total_len && result[i] == 0)
    i++;

  if (i == total_len) {
    printf("0\n");
  } else {
    for (; i < total_len; i++)
      printf("%d", result[i]);
    printf("\n");
  }

  free(result);
}

/**
 * main - Function that multiplies two positive numbers
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[]) {
  if (argc != 3) {
    print_error();
  }

  if (!is_digit(argv[1]) || !is_digit(argv[2])) {
    print_error();
  }

  multiply(argv[1], argv[2]);

  return (0);
}
