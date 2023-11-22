NAME = libmx.a

SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(addprefix obj/, $(notdir $(SRC_FILES:%.c=%.o)))
INC_FILES = $(wildcard inc/*.h)

CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

MKDIR = mkdir -p
RM = rm -rf

all: clean $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^

$(OBJ_FILES): | obj

obj/%.o: src/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -c $< -o $@ -I inc

obj:
	@$(MKDIR) $@

clean:
	@$(RM) obj

uninstall:
	@$(RM) obj
	@$(RM) $(NAME)

reinstall: uninstall all

.PHONY: all uninstall clean reinstall
