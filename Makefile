.PHONY : NAME all real-all clean fclean re

MAKEFLAGS += --no-print-directory

NAME = so_long
CC = cc
CFLAGS = -g3 -Werror -Wextra -Wall -Iinclude -I/usr/include -Imlx_linux
LDFLAGS = -Lmlx-linux -Lmlx -Imlx -L/usr/lib -lX11 -lXext -lm -lz -Llibft
LIB = libft/libft.a
MLX = mlx-linux/libmlx.a

SRCS_DIR = src
SRCS =	$(SRCS_DIR)/all_free.c \
		$(SRCS_DIR)/error_manage.c \
		$(SRCS_DIR)/fill_map.c \
		$(SRCS_DIR)/map_content.c \
		$(SRCS_DIR)/map.c \
		$(SRCS_DIR)/set_mlx.c \
		$(SRCS_DIR)/shape_map.c \
		$(SRCS_DIR)/so_long.c \
		$(SRCS_DIR)/user_actions.c \
		$(SRCS_DIR)/tmp.c

OBJ_DIR = obj
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

HEADER_DIR = include
HEADER = $(HEADER_DIR)/so_long.h

SRCS_LIB = $(shell make -s -C libft print_src)
HEADER_LIB = $(shell make -s -C libft print_header)

all : $(LIB) check-build

check-build :
	@if [ -f "$(NAME)" ] \
		&& [ -z "$$(find "$(OBJ_DIR)" -type f -newer "$(NAME)")" ] \
		&& [ -z "$$(find libft \( -name "*.c" -o -name "*.h" -o -name "Makefile" \) -newer "$(LIB)")" ] \
		&& [ -z "$$(find "$(SRCS_DIR)" -name "*.c" -newer "$(NAME)")" ] \
		&& [ -z "$$(find "$(HEADER_DIR)" -name "*.h" -newer "$(NAME)")" ] \
		&& [ -z "$$(find . -name "Makefile" -newer "$(NAME)")" ]; then \
		echo "✅👌 So_long déjà compilé ! 👌✅"; \
	else \
		$(MAKE) real-all; \
	fi

real-all : $(LIB) $(OBJ_DIR) $(OBJS) $(NAME)

$(OBJ_DIR) :
	@mkdir -p $@

$(OBJS) : $(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c Makefile $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(LIB) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) $(LDFLAGS) -o $(NAME)
	@echo "🎊🥳 Programme so_long compilé !! 🥳🎊"

$(LIB) : $(addprefix libft/, $(SRCS_LIB) $(HEADER_LIB)) libft/Makefile
	@echo "🎶📳 Appel libft 📳🎶"
	@$(MAKE) -C libft

$(MLX) :
	@echo "🎶📳 Appel MLX 📳🎶"
	@$(MAKE) -s -C mlx-linux > /dev/null 2>&1

clean :
	@rm -rf $(OBJ_DIR)
	@echo "💨🧹 Nettoyage objets 🧹💨"

fclean : clean
	@$(MAKE) fclean -C libft
	@$(MAKE) clean -C mlx-linux > /dev/null 2>&1
	@rm -rf $(NAME)
	@echo "🫧🧽 Tout est clean !!🧽🫧"

re : fclean all