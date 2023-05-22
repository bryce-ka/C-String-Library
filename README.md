# Custom String Processing Library (C)

This library provides custom implementations of core string processing functions in C. It offers alternative versions of functions found in C's standard string processing library. The functions included in this library are `mystrlen`, `mystrcat`, `mystrcpy`, `mystrcmp`, `mystrstr`, `mystrdup`, and `mystrchr`.

## Authors
- Bryce Anthony
- Lydia Catterall

## Functions

### `size_t mystrlen(const char* string)`
This function calculates the length of a string, excluding the terminating null byte ('\0').

- Parameters:
  - `string`: A pointer to the start of a string.
- Returns:
  - `lenCounter`: The number of characters in the string.

### `char* mystrcat(char* destination, const char* source)`
This function appends the source string to the destination string, overwriting the terminating null byte ('\0') at the end of the destination, and then adds a terminating null byte.

- Parameters:
  - `destination`: A pointer to the string to which the source will be appended.
  - `source`: A pointer to the string to be appended to the destination.
- Returns:
  - `destination`: A pointer to the resulting string with the source appended to the destination.

### `char* mystrcpy(char* destination, const char* source)`
This function copies the string pointed to by source, including the terminating null byte ('\0'), to the buffer pointed to by destination.

- Parameters:
  - `destination`: A pointer to the buffer to which the source will be copied.
  - `source`: A pointer to the string to be copied into the destination.
- Returns:
  - `destination`: A pointer to the resulting string with the source copied into it.

### `int mystrcmp(const char* s1, const char* s2)`
This function compares the two strings `s1` and `s2`.

- Parameters:
  - `s1`: A pointer to the string to be compared to `s2`.
  - `s2`: A pointer to the string to be compared to `s1`.
- Returns:
  - An integer less than, equal to, or greater than zero if `s1` is found to be less than, to match, or be greater than `s2`.

### `char* mystrstr(const char* haystack, const char* needle)`
This function finds the first occurrence of the substring `needle` in the string `haystack`.

- Parameters:
  - `haystack`: A pointer to the string to be searched through for `needle`.
  - `needle`: A pointer to the substring to be searched for in `haystack`.
- Returns:
  - `firstOccurrence`: A pointer to the beginning of the located substring (or NULL if the substring is not found).

### `char* mystrdup(const char* s)`
This function returns a pointer to a new string which is a duplicate of the string `s`.

- Parameters:
  - `s`: A pointer to the string to be duplicated.
- Returns:
  - `dupString`: A pointer to a new string which is a duplicate of `s`.

### `char* mystrchr(const char* s, int c)`
This function returns a pointer to the first occurrence of the character `c` in the string `s`.

- Parameters:
  - `s`: A pointer to the string to be searched through for `c`.
  - `c`: The character to be searched for.
- Returns:
  - `s + i`: A pointer to the first occurrence of the character `c` in string `s`.

