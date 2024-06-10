NAME = minishell

LIBFTNAME = libft.a
LIBFTPATH = ./libft/

SRCS = srcs/main.c \
		srcs/utils/init_dta.c \
		srcs/prompt.c \
		srcs/redirect.c \
		srcs/exe/buildin/ft_exit.c \
		srcs/exit/ft_free.c \
		srcs/exit/error_pars_pipe.c \
		srcs/utils/pars_utils.c \
		srcs/utils/pars_utils_2.c \
		srcs/utils/pars_utils_3.c \
		srcs/utils/pars_utils_4.c \
		srcs/utils/execute_utils.c \
		srcs/utils/main_utils.c \
		srcs/pars/print_tab.c \
		srcs/pars/pars_nickname.c \
		srcs/pars/pars_equal.c \
		srcs/pars/pars_quote.c \
		srcs/pars/pars_single_quote.c \
		srcs/pars/pars_replace_equal.c \
		srcs/pars/pars_pipe.c \
		srcs/pars/pars_getenv.c \
		srcs/pars/pars_hdoc.c \
		srcs/pars/pars_hdoc_2.c \
		srcs/pars/pars_hdoc_3.c \
		srcs/pars/pars_lst_to_tab.c \
		srcs/pars/pars_existing_arg.c \
		srcs/pars/pars_historic.c \
		srcs/pars/pars_space_spe_char.c \
		srcs/pars/take_env.c \
		srcs/pars/init_triple_tab.c \
		srcs/signal/handle_signal.c \
		srcs/exe/execute_pipe.c \
		srcs/exe/execute_redir.c \
		srcs/exe/rd_cmd.c \
		srcs/exe/r_redirection.c \
		srcs/exe/buildin/ft_cd.c \
		srcs/exe/buildin/ft_echo.c \
		srcs/exe/buildin/ft_env.c \
		srcs/exe/buildin/ft_export.c \
		srcs/exe/buildin/ft_minishell.c \
		srcs/exe/buildin/ft_pwd.c \
		srcs/exe/buildin/ft_unset.c \

INCLUDE = include/minishell.h \

OBJS		= $(SRCS:.c=.o)
CC			=gcc 
DEBUG		=-g -O0
FLAGS		=-Wall -Werror -Wextra
LDFLAGS		=-L/Users/$(USER)/.brew/opt/readline/lib
CPPFLAGS	=-I/Users/$(USER)/.brew/opt/readline/include
INCS		= .

.c.o :
	@echo "${_BOLD}${_BLUE}Making minishell > ${_END}${_YELLOW}${<:.c=.o}${_END}"
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

all: $(NAME)

${NAME}: flag_use ${OBJS}
	@echo "${_BOLD}✅ ${_IGREEN}minishell > *.o Done${_END}"
	@make -C ${LIBFTPATH}
	${_STATUS1}
	@mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${_DONE}
	${_STATUS2}
	@${CC}${FLAGS} ${CPPFLAGS} ${LDFLAGS} -lreadline ${OBJS} ${LIBFTNAME} -o ${NAME}
	${_DONE}
	${_PRINTART1}
	${_USAGE}

clean:
	${_STATUS3}
	@rm -rf *.o
	${_DONE}
	@sleep 0.5

fclean: clean
	${_STATUS4}
	@make fclean -C ${LIBFTPATH}
	${_DONE}
	${_STATUS5}
	@rm -rf $(OBJS) $(LIBFTNAME) $(NAME)
	${_DONE}
	@sleep 1

mclean: clean
	${_STATUS6}	
	@rm -rf $(OBJS) $(LIBFTNAME) $(NAME)
	${_DONE}

norm:
	${_PRINTART2}
	@norminette ${SRCS} ${INCLUDE}

git_add:
	${_STATUS7}	
	@git add ${SRCS} ${INCLUDE} ${LIBFTPATH}*.c ${LIBFTPATH}*.h ${LIBFTPATH}Makefile Makefile
	${_DONE}
	@git status | grep modif

git_push:
	${_STATUS8}	
	@git commit -m "Autopush Makefile"
	${_DONE}
	${_STATUS9}	
	@git push origin master
	${_DONE}

git_master: git_add git_push

nbline:
	@echo "Nombre de ligne :"
	cat **/*.c **/*.h | wc -l 

re: fclean all

ree: mclean all
	@sleep 1
	@./${NAME}

reee:
	@./${NAME}

flag_use:
	@echo "${_BOLD}${_BLUE}============================= FLAGS USE =============================${_END}"
	@echo "${_BOLD}${_RED}\t\t      ${FLAGS}${_END}"
	@echo "${_BOLD}${_RED}\t  ${CPPFLAGS}${_END}"
	@echo "${_BOLD}${_RED}\t    ${LDFLAGS}${_END}"
	@echo "${_BOLD}${_RED}\t\t           -lreadline${_END}"
	@echo "${_BOLD}${_BLUE}=====================================================================${_END}"

#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
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
#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

_PRINTART1=@echo "${_BOLD}${_YELLOW}${_L0}\n${_L1}\n${_L2}\n${_L3}\n${_L4}\n${_L5}\n${_L6}\n${_L0}\n${_L7}\n${_L0}\n${_END}"
_L0=$'|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|'
_L1=$'| ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     |
_L2=$'| ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     |
_L3=$'| ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     |
_L4=$'| ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     |
_L5=$'| ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗|
_L6=$'| ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝|
_L7=$'|            |b|l|o|i|s|e|l|  |&|   |a|y|a|s|s|a|y|e|              |

#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

_PRINTART2=@echo "${_BOLD}${_RED}${_L08}\n${_L09}\n${_L10}\n${_L11}\n${_L12}\n${_L13}\n${_L14}\n${_L08}\n${_END}"
_L08=$'|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|'
_L09=$'| ███╗   ██╗ ██████╗ ██████╗ ███╗   ███╗██╗███╗   ██╗███████╗████████╗████████╗███████╗ |
_L10=$'| ████╗  ██║██╔═══██╗██╔══██╗████╗ ████║██║████╗  ██║██╔════╝╚══██╔══╝╚══██╔══╝██╔════╝ |
_L11=$'| ██╔██╗ ██║██║   ██║██████╔╝██╔████╔██║██║██╔██╗ ██║█████╗     ██║      ██║   █████╗   |
_L12=$'| ██║╚██╗██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║╚██╗██║██╔══╝     ██║      ██║   ██╔══╝   |
_L13=$'| ██║ ╚████║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██║ ╚████║███████╗   ██║      ██║   ███████╗ |
_L14=$'| ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝      ╚═╝   ╚══════╝ |

#-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

_USAGE=@echo "${_BOLD}${_RED}\nUsage : ./minishell${_END}"

_DONE=@echo "${_BOLD}✅ ${_IGREEN}Done${_END}"
_STATUS1=@echo "${_BOLD}${_BLUE}Moving libft.a to > ${_END}${_YELLOW}${INCS}/${_END}" && sleep 0.5
_STATUS2=@echo "${_BOLD}${_BLUE}Making > ${_END}${_YELLOW} ${NAME}${_END}" && sleep 0.5
_STATUS3=@echo "${_BOLD}${_BLUE}Removing > ${_END}${_YELLOW}*.o ${LIBFTNAME}${_END}" && sleep 0.5
_STATUS4=@echo "${_BOLD}${_BLUE}fclean >${_END}${_YELLOW}${LIBFTNAME}${_END}" && sleep 0.5
_STATUS5=@echo "${_BOLD}${_BLUE}Removing > ${_END}${_RED}$(LIBFTNAME) ${_GREEN}$(NAME) ${_CYAN}${LIBFTPATH}${_YELLOW} $(OBJS)${_END}" && sleep 0.5
_STATUS6=@echo "${_BOLD}${_BLUE}Removing > ${_END}${_YELLOW} $(OBJS) $(LIBFTNAME) $(NAME) ${_END}" && sleep 0.5
_STATUS7=@echo "${_BOLD}${_BLUE}GIT ADD : ${SRCS} ${INCLUDE} ${LIBFTPATH}*.c ${LIBFTPATH}*.h ${LIBFTPATH}Makefile Makefile misc/* ${_END}" && sleep 0.5
_STATUS8=@echo "${_BOLD}${_BLUE}GIT COMMIT ...${_END}" && sleep 0.5
_STATUS9=@echo "${_BOLD}${_BLUE}GIT PUSH ...${_END}" && sleep 0.5
