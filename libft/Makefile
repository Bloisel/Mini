NAME	=   libft.a
SRCS	=	ft_atoi.c \
			ft_bzero.c \
			ft_atoi_long_long.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strcmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_striteri.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_itoa_ptf.c \
			ft_printf.c \
			ft_printf_redirect.c \
			ft_putchar_fd_ptf.c \
			ft_putnbr_base_fd2_ptf.c \
			ft_putnbr_base_fd_ptf.c \
			ft_putnbr_fd_ptf.c \
			ft_putnbr_unsigned_fd_ptf.c \
			ft_swap.c \
			ft_convert_base.c \
			ft_putstr_fd_ptf.c \
			ft_strrchr_ptf.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lst_sort.c \
			ft_lstclear.c \
			ft_dup_lst.c \
			ft_new_node.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstsize.c \
			ft_lstnew.c \
			ft_lstsize.c
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .

.c.o :
	@echo "${_BOLD}${_BLUE}Making libft > ${_END}${_YELLOW}${<:.c=.o}${_END}"
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): flag_use ${OBJS}
	@echo "${_BOLD}✅ ${_IGREEN}libft > *.o Done${_END}"
	@echo "${_BOLD}${_BLUE}=====================================================================${_END}"
	@${LIBC} $(NAME) $(OBJS)
	@echo "${_BOLD}✅ ${_IGREEN}Done${_END}"

all: $(NAME)

bonus: $(NAME) $(OBJS_B)
	${LIBC} $(NAME) $(OBJS_B)
    
fclean: clean
	@$(RM) $(NAME) $(bonus)
	@sleep 0.5

clean:
	@$(RM) -f $(OBJS) $(OBJS_B)
    
re: fclean all

flag_use:
	@echo "${_BOLD}${_BLUE}Making > ${_END}${_YELLOW}libft.a${_END}"
	@echo "${_BOLD}${_BLUE}======================= LIBFT FLAGS USE =============================${_END}"
	@echo "${_BOLD}${_BLUE}\t\t    ${_RED} ${FLAGS}${_END}"
	@echo "${_BOLD}${_BLUE}=====================================================================${_END}"

.PHONY: all bonus clean fclean re .c.o

# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m