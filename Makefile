# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 15:49:50 by cyrillef          #+#    #+#              #
#    Updated: 2018/06/02 15:37:21 by kda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC					=	gcc

NAME_ASM			=	asm

NAME_COREWAR		=	corewar

SRCS_ASM_DIR		=	srcs/srcs_asm/

SRCS_ASM			=	main.c \
						op.c \
						error.c \
						parsing_champ.c \
						header.c \
						check_core.c \
						empty_line.c \
						ft_word_tab_asm.c \
						fill_data_tab.c \
						instructions/live.c \
						instructions/ld.c \
						instructions/st.c \
						instructions/add.c \
						instructions/sub.c \
						instructions/and.c \
						instructions/or.c \
						instructions/xor.c \
						instructions/zjmp.c \
						instructions/ldi.c \
						instructions/sti.c \
						instructions/fork.c \
						instructions/lld.c \
						instructions/lldi.c \
						instructions/lfork.c \
						instructions/aff.c \
						check_arguments.c \
						size_function.c \
						check_miss_label.c \
						search_label.c \
						do_cor.c \
						do_function.c \
						type_param.c \
						write_label.c \
						bad_direct_arg.c

SRCS_ASM_FULL		=	$(addprefix $(SRCS_ASM_DIR), $(SRCS_ASM))

SRCS_COREWAR_DIR	=	srcs/srcs_corewar/

SRCS_COREWAR		=	main.c \
						dump.c \
						debug.c \
						op.c \
						sort_champs.c \
						init_data.c \
						manage_args.c \
						get_params.c \
						read_champions.c \
						init_map.c \
						number_to_hex_str.c \
						vm.c \
						check_live.c \
						prepare_next_op.c \
						do_next_op.c \
						display_vm.c \
						display_vm_2.c \
						tty.c \
						error.c \
						cmd/add.c \
						cmd/aff.c \
						cmd/and.c \
						cmd/fork.c \
						cmd/ld.c \
						cmd/ldi.c \
						cmd/lfork.c \
						cmd/live.c \
						cmd/lld.c \
						cmd/lldi.c \
						cmd/or.c \
						cmd/st.c \
						cmd/sti.c \
						cmd/sub.c \
						cmd/xor.c \
						cmd/zjmp.c \
						cmd/ljmp.c \
						cmd/cmd_auxiliary_functions.c \
						cmd/vm_address_management.c \
						cmd/ft_atoi_base.c \
						cmd/colors.c

SRCS_COREWAR_FULL	=	$(addprefix $(SRCS_COREWAR_DIR), $(SRCS_COREWAR))

OBJS_ASM			=	$(SRCS_ASM_FULL:.c=.o)

OBJS_COREWAR		=	$(SRCS_COREWAR_FULL:.c=.o)

CFLAGS				=	-Wall -Wextra -Werror -I./includes/

all:				libft $(NAME_ASM) $(NAME_COREWAR)

%.o : %.c
					@gcc -g -o $@ -c $< $(CFLAGS)
					@echo "\033[K\033[34mCorewar :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NAME_ASM):		$(OBJS_ASM)
					@$(GCC) $(OBJS_ASM) -o $(NAME_ASM) -L./libs/libft -lft
					@echo "\033[K\033[32m===========COREWAR==============\033[0m"
					@echo "\033[34mCompiling\033[0m" [ $(NAME_ASM) ] "\033[K\033[32mSuccessful\033[00m"
					@echo "\033[32m================================\033[00m"

$(NAME_COREWAR):	$(OBJS_COREWAR)
					@$(GCC) $(OBJS_COREWAR) -o $(NAME_COREWAR) -L./libs/libft -lft
					@echo "\033[K\033[32m===========COREWAR==============\033[0m"
					@echo "\033[34mCompiling\033[0m" [ $(NAME_COREWAR) ] "\033[K\033[32mSuccessful\033[00m"
					@echo "\033[32m================================\033[00m"

libft:
					@make -C libs/libft

clean:
					@rm -f $(OBJS_ASM) $(OBJS_COREWAR)
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mCleaning\033[00m  " [ "*.o" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@make -C libs/libft clean

rclean:
					@rm -f $(OBJS_ASM) $(OBJS_COREWAR)
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mCleaning\033[00m  " [ "*.o" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"

fclean:				clean
					@rm -f $(NAME_ASM) $(NAME_COREWAR)
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mRemoving\033[00m  " [ "asm" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mRemoving\033[00m" [ "corewar" ] "\033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@make -C libs/libft fclean

rfclean:			rclean
					@rm -f $(NAME_ASM) $(NAME_COREWAR)
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mRemoving\033[00m  " [ "asm" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"
					@echo "\033[K\033[31m===========COREWAR===========\033[0m"
					@echo "\033[31mRemoving\033[00m" [ "corewar" ] "\033[32mComplete\033[00m"
					@echo "\033[K\033[31m=============================\033[0m"

re:					fclean all

ren:				rfclean all

.PHONY:				all clean fclean re ren libft rclean rfclean
