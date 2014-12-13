all:
	@gcc -c *.c
	@gcc -o ex01 *.o -L libft -lft

ex00: all

re: fclean all

clean:
	@rm *.o 2> /dev/null

fclean: clean
	@rm ex01 2> /dev/null
