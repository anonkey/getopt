
CC = clang
CFLAGS = -Wall -Wextra -Werror
ifeq ($(DEBUG), 1)
	CFLAGS += -ggdb3
endif
INCDIRS = include

INCFLAGS = $(foreach T, $(INCDIRS), -I ./$(T))
NAME = getopt
LIBS = ft

INCFLAGS += $(foreach T, $(LIBS), -I ./lib/lib$(T)/include)
LIBDIRS = $(foreach T, $(LIBS), ./lib/lib$(T))
LIBDIRS_FLAGS = $(foreach T, $(LIBDIRS), -L $(T))
LIBFLAGS = $(foreach T, $(LIBS), -l$(T))
LIBDEPS = $(foreach T, $(LIBS), lib/lib$(T)/lib$(T).a)

SRC = src/ft_bf.c \
src/ft_getopt.c \
src/ft_putgetopt.c \
src/main.c \
src/t_getopt.c \

OBJ = $(SRC:.c=.o)

all: make_  $(NAME)

make_:
	$(foreach T, $(LIBDIRS), make -C $(T))

fclean_:
	$(foreach T, $(LIBDIRS), make -C $(T) fclean)

$(NAME): $(OBJ) $(LIBDEPS)
	$(CC) $(CFLAGS) $(INCFLAGS) $(LIBDIRS_FLAGS) $(LIBFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(INCFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: fclean_ clean
	rm -rf $(NAME)

re: fclean_ fclean all

.PHONY: make_ fclean_ clean fclean all re
