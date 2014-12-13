all:
	@gcc -c *.c
	@gcc -o ex00 *.o -L libft -lft

ex00: all

re: fclean all

clean:
	@rm *.o 2> /dev/null

fclean: clean
	@rm ex00 2> /dev/null
