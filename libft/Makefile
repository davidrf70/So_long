NAME			= 	libft.a
SRC_DIR			=	src/
INCLUDE_DIR		= 	include/
OBJ_DIR			=	objs/

FILES			=	ft_lstadd_back ft_lstlast ft_lstclear ft_lstnew ft_strjoin ft_strlen get_next_line get_next_line_utils ft_itoa
# SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS			=	$(addprefix $(SRC_DIR), $(addsuffix .o, $(FILES)))

INCLUDE			=	-I $(INCLUDE_DIR)
CFLAGS			=	-Werror -Wall -Wextra -g
RM				=	rm -f

# Target: object file for each source file
%.o		:	%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# This rule execute 'ar' that needs object files (OBJS).
# To get <file>.o execute above rule (%.o:%.c) for every file, before command 'ar' (dependency OBJS)
$(NAME)	:	$(OBJS)
			ar rcs  $(NAME) $(OBJS)

# Executed if 'make' is invoked with no rule name (ej: make) 
all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re