
# 📚 Libft - Your Essential 42 C Library 🚀

Welcome to Libft, your very first project as a 42 student! This library provides a collection of fundamental C functions, including those from `<ctype.h>`, `<stdlib.h>`, `<strings.h>`, and some non-standard functions. Plus, enjoy bonus features like linked list functions!

## 📜 List of Essential Functions 🛠️

### Functions from `<ctype.h>` library 🤖

* [`ft_isascii`](src/ft_is/ft_isascii.c) - Test for ASCII character.
* [`ft_isalnum`](src/ft_is/ft_isalnum.c) - Alphanumeric character test.
* [`ft_isalpha`](src/ft_is/ft_isalpha.c) - Alphabetic character test.
* [`ft_isdigit`](src/ft_is/ft_isdigit.c) - Decimal-digit character test.
* [`ft_isprint`](src/ft_is/ft_isprint.c) - Printing character test (space character inclusive).
* [`ft_tolower`](src/ft_to/ft_tolower.c) - Upper case to lower case letter conversion.
* [`ft_toupper`](src/ft_to/ft_toupper.c) - Lower case to upper case letter conversion.

### Functions from `<stdlib.h>` library 🧠

* [`ft_atoi`](src/ft_to/ft_atoi.c) - Convert ASCII string to integer.
* [`ft_calloc`](src/ft_mem/ft_calloc.c) - Memory allocation.

### Functions from `<strings.h>` library 🧵

* [`ft_bzero`](src/ft_mem/ft_bzero.c) - Write zeroes to a byte string.
* [`ft_memset`](src/ft_mem/ft_memset.c) - Write a byte to a byte string.
* [`ft_memchr`](src/ft_mem/ft_memchr.c) - Locate byte in byte string.
* [`ft_memcmp`](src/ft_mem/ft_memcmp.c) - Compare byte string.
* [`ft_memmove`](src/ft_mem/ft_memmove.c) - Copy byte string.
* [`ft_memcpy`](src/ft_mem/ft_memcpy.c) - Copy memory area.

### Functions from `<string.h>` library 🎵

* [`ft_strlen`](src/ft_str/ft_strlen.c) - Find length of string.
* [`ft_strchr`](src/ft_str/ft_strchr.c) - Locate character in string (first occurrence).
* [`ft_strrchr`](src/ft_str/ft_strrchr.c) - Locate character in string (last occurrence).
* [`ft_strnstr`](src/ft_str/ft_strnstr.c) - Locate a substring in a string (size-bounded).
* [`ft_strncmp`](src/ft_str/ft_strncmp.c) - Compare strings (size-bounded).
* [`ft_strdup`](src/ft_str/ft_strdup.c) - Save a copy of a string (with malloc).
* [`ft_strlcpy`](src/ft_str/ft_strlcpy.c) - Size-bounded string copying.
* [`ft_strlcat`](src/ft_str/ft_strlcat.c) - Size-bounded string concatenation.

### Non-standard functions 🚀

* [`ft_itoa`](src/ft_to/ft_itoa.c) - Convert integer to ASCII string.
* [`ft_substr`](src/ft_str/ft_substr.c) - Extract substring from string.
* [`ft_strtrim`](src/ft_str/ft_strtrim.c) - Trim beginning and end of string with specified characters.
* [`ft_strjoin`](src/ft_str/ft_strjoin.c) - Concatenate two strings into a new string (with malloc).
* [`ft_split`](src/ft_str/ft_split.c) - Split string, with specified character as delimiter, into an array of strings.
* [`ft_strmapi`](src/ft_str/ft_strmapi.c) - Create a new string by modifying string with specified function.

## 💻 Usage

### Requirements 🛠️

The library is written in C language and needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions 🚀

1. **Compiling the library:**

   For all mandatory functions:
   ```bash
   $ make
   ```
   For all bonus functions:
   ```bash
   $ make bonus
   ```
   Cleaning all binary (.o) and executable files (.a):
   ```bash
   $ make clean
   $ make fclean
   ```
## 🧪 Testing

Tested with:

-   [Tripouille/libfTester](https://github.com/Tripouille/libftTester)
-   [ska42/libft-war-machine](https://github.com/ska42/libft-war-machine)
-   [alelievr/libft-unit-test](https://github.com/alelievr/libft-unit-test)
