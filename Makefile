NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -lreadline -Ireadline -L$(LFT_F) -lft -I$(LFT_F)
HEADERS = incl/minishell.h incl/execute.h incl/sources.h
LFT_F = libft
FT_DES = ft_destructor

SRC =	minishell.c \
		execute.c \
		parsing.c init_env.c parse_err.c utils_parsing.c dollar_parse.c \
		struct.c \
		builtins.c \
		env.c \
		echo.c \

SRC_F = src/
OBJ_F = obj/
VPATH = $(SRC_F) $(SRC_F)exec/ $(SRC_F)utils/ $(SRC_F)parsing/
OBJ = $(addprefix $(OBJ_F), $(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(FT_DES)
	$(MAKE) -C $(LFT_F)
	$(CC) -o $@ $(OBJ) $(LFLAGS) $(CFLAGS) ./ft_destructor/ft_alloc.a

$(OBJ_F)%.o: %.c $(HEADERS) Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_F)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LFT_F);
	$(MAKE) fclean -C ./ft_destructor

re: fclean
	$(MAKE) -j 12 all

.PHONY:	all clean fclean re bonus