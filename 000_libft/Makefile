# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 11:50:59 by ecantu-p          #+#    #+#              #
#    Updated: 2025/12/09 11:15:33 by ecantu-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC = cc

CFLAGS := -Wall -Werror -Wextra -c

CFILES := \
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
	 ft_putnbr_fd.c

OFILES := $(CFILES:.c=.o)

LFILES := \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstiter.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstmap.c

OLFILES := $(LFILES:.c=.o)

all: $(NAME) link_list bonus

$(NAME): $(OFILES)
	@echo
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "	Creating library achive. Adding lbtf object files"
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo
	ar crs $(NAME) $(OFILES)
	@echo
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "		Done with libc files. Continuing with link list files."

link_list: $(OLFILES)
	@echo
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "	Updating library archive. Adding link-list object files"
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo
	ar crs $(NAME) $(OLFILES)
	@echo
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "		Done creating Library."
clean:
	@echo "********************************************************************"
	@echo "	Cleaning library. Removing object files"
	@echo "********************************************************************"
	@echo
	rm -f $(OFILES) $(OLFILES)
	@echo
	@echo "********************************************************************"
	
fclean: clean 
	@echo "********************************************************************"
	@echo "	Cleaning library. Removing libft.a"
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

bonus:
	
.c.o:
	@echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "Compiling '*.c' file, creating function oject file."
	@echo 
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all link_list clean fclean re
