SRC_DIR := src
FT_FD := ft_fd
FT_IS := ft_is
FT_LST := ft_lst
FT_MEM := ft_mem
FT_STR := ft_str
FT_TO := ft_to
PRINTF := ft_printf
GNL := get_next_line
NAME = libft.a

SRCS := $(SRC_DIR)/$(FT_FD)/ft_putchar_fd.c \
        $(SRC_DIR)/$(FT_FD)/ft_putendl_fd.c \
        $(SRC_DIR)/$(FT_FD)/ft_putnbr_fd.c \
        $(SRC_DIR)/$(FT_FD)/ft_putstr_fd.c \
        $(SRC_DIR)/$(FT_IS)/ft_isalnum.c \
        $(SRC_DIR)/$(FT_IS)/ft_isalpha.c \
        $(SRC_DIR)/$(FT_IS)/ft_isascii.c \
        $(SRC_DIR)/$(FT_IS)/ft_isdigit.c \
        $(SRC_DIR)/$(FT_IS)/ft_isprint.c \
        $(SRC_DIR)/$(FT_MEM)/ft_bzero.c \
        $(SRC_DIR)/$(FT_MEM)/ft_calloc.c \
        $(SRC_DIR)/$(FT_MEM)/ft_memchr.c \
        $(SRC_DIR)/$(FT_MEM)/ft_memcmp.c \
        $(SRC_DIR)/$(FT_MEM)/ft_memcpy.c \
        $(SRC_DIR)/$(FT_MEM)/ft_memmove.c \
        $(SRC_DIR)/$(FT_MEM)/ft_memset.c \
        $(SRC_DIR)/$(FT_STR)/ft_split.c \
        $(SRC_DIR)/$(FT_STR)/ft_strchr.c \
        $(SRC_DIR)/$(FT_STR)/ft_strdup.c \
        $(SRC_DIR)/$(FT_STR)/ft_striteri.c \
        $(SRC_DIR)/$(FT_STR)/ft_strjoin.c \
        $(SRC_DIR)/$(FT_STR)/ft_strlcat.c \
        $(SRC_DIR)/$(FT_STR)/ft_strlcpy.c \
        $(SRC_DIR)/$(FT_STR)/ft_strlen.c \
        $(SRC_DIR)/$(FT_STR)/ft_strmapi.c \
        $(SRC_DIR)/$(FT_STR)/ft_strncmp.c \
        $(SRC_DIR)/$(FT_STR)/ft_strnstr.c \
        $(SRC_DIR)/$(FT_STR)/ft_strrchr.c \
        $(SRC_DIR)/$(FT_STR)/ft_strtrim.c \
        $(SRC_DIR)/$(FT_STR)/ft_substr.c \
        $(SRC_DIR)/$(FT_TO)/ft_atoi.c \
        $(SRC_DIR)/$(FT_TO)/ft_itoa.c \
        $(SRC_DIR)/$(FT_TO)/ft_tolower.c \
        $(SRC_DIR)/$(FT_TO)/ft_toupper.c \
        $(SRC_DIR)/$(PRINTF)/src/ft_format_parser.c \
        $(SRC_DIR)/$(PRINTF)/src/ft_print_hex.c \
        $(SRC_DIR)/$(PRINTF)/src/ft_printf_utils.c \
        $(SRC_DIR)/$(PRINTF)/src/ft_printf.c \
        $(SRC_DIR)/$(GNL)/src/get_next_line.c \
        $(SRC_DIR)/$(GNL)/src/get_next_line_utils.c

SRCB := $(SRC_DIR)/$(FT_LST)/ft_lstadd_back.c \
        $(SRC_DIR)/$(FT_LST)/ft_lstadd_front.c \
        $(SRC_DIR)/$(FT_LST)/ft_lstclear.c \
        $(SRC_DIR)/$(FT_LST)/ft_lstdelone.c \
        $(SRC_DIR)/$(FT_LST)/ft_lstiter.c \
        $(SRC_DIR)/$(FT_LST)/ft_lstlast.c \
        $(SRC_DIR)/$(FT_LST)/ft_lstmap.c \
        $(SRC_DIR)/$(FT_LST)/ft_lstnew.c \
        $(SRC_DIR)/$(FT_LST)/ft_lstsize.c \

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${SRCB:.c=.o}

LIBC = ar rcs
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

bonus: ${OBJS} ${BONUS_OBJS}
	${LIBC} ${NAME} ${OBJS} ${BONUS_OBJS}


re: fclean all
