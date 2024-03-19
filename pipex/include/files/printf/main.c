 
int	main(void)
 {
	int s;
	void *j;
	unsigned int u;
	char *c;
	char f;
	
	c = "hola que tal";
	j = c;
	s = -568;
	f = 'f';
	u = 4864;
	
	

 	ft_printf("\n%i\n", ft_printf("%p", "test"));
	ft_printf("\neste es la prueba de caracteres %s\n",c);
	ft_printf("\neste es la prueba de caracteres %u\n",u);
	ft_printf("\neste es la prueba de caracteres %c\n",f);
	ft_printf("\neste es la prueba de caracteres% %p\n",j);

	return (0);
 }