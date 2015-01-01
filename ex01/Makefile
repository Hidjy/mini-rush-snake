all:
	@gcc -c *.c
	@make -C ../libft/ re
	@gcc -o ex01 *.o -L ../libft -lft

ex01: all

re: fclean all

clean:
	@rm *.o 2> /dev/null

fclean: clean
	@rm ex01 2> /dev/null
