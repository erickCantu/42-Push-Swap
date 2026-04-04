# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 11:50:59 by ecantu-p          #+#    #+#              #
#    Updated: 2026/02/04 17:43:03 by ecantu-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC = cc

CFLAGS := -Wall -Werror -Wextra -c

SRC := ../000_libft/

CFILES_LIBFT := \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstiter.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstmap.c

OFILES_LIBFT := $(addprefix $(SRC), $(CFILES_LIBFT:.c=.o))

CFILES_PRINTF := \
	ft_printf.c \
	ft_printf_utils.c \
	ft_printf_utils_case.c \
	ft_ptf_ptohex.c \
	ft_ptf_unitohex.c \
	ft_ptf_uitoa.c \
	ft_ptf_char.c \
	ft_ptf_hex.c \
	ft_ptf_int.c \
	ft_ptf_int_utils.c \
	ft_ptf_ptr.c \
	ft_ptf_str_wrt.c \
	ft_ptf_str.c \
	ft_ptf_uint.c 

OFILES_PRINTF := $(CFILES_PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OFILES_LIBFT) $(OFILES_PRINTF)
	@echo
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "	Creating library achive. Adding libftprintf object files"
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo
	ar crs $(NAME) $(OFILES_LIBFT) $(OFILES_PRINTF)
	@echo
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "	Done with libftprintf files. Continuing with link list files."

bonus: re all
	@echo
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "	Creating bonus library achive."
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo
	

clean:
	@echo "********************************************************************"
	@echo "	Cleaning library. Removing object files"
	@echo "********************************************************************"
	@echo
	rm -f $(OFILES_LIBFT) $(OFILES_PRINTF)
	@echo
	@echo "********************************************************************"
	
fclean: clean 
	@echo "********************************************************************"
	@echo "	Cleaning library. Removing libftprintf.a"
	@echo "********************************************************************"
	@echo
	rm -f $(NAME)
	@echo
	@echo "********************************************************************"
	@echo "	Library cleaned."
	@echo "********************************************************************" 

re: fclean all
	@echo "--------------------------------------------------------------------"
	@echo "	   	Library cleaned and  recreated"
	@echo "--------------------------------------------------------------------"
	
$(SRC)%.o: $(SRC)%.c
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "Compiling '*.c' file, creating function oject file."
	@echo 
	$(CC) $(CFLAGS) $< -o $@

%.o: %.c
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "Compiling '*.c' file, creating function oject file."
	@echo 
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all clean fclean re bonus
