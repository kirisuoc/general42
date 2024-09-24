#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// Definiciones de códigos de color ANSI
#define RESET		"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"
#define WHITE		"\033[37m"
#define GRAY       "\033[90m"

int	main(void)
{
	printf(YELLOW"\n********************************************************************\n"RESET);
	printf(YELLOW"\n		----------- Test libft.a -----------\n\n"RESET);
	printf(YELLOW"\n********************************************************************\n\n"RESET);

//1 - ft_strlen
	printf(RED"1 ft_strlen\n"RESET);
		const char *str = "La casa es roja";
	if (ft_strlen(str) == strlen(str))
	{
	printf(BLUE"		La longitud de '%s' es: %ld\n"RESET, str, ft_strlen(str));
		// Respuesta esperada
	printf(GREEN"Función orig.:	La longitud de '%s' es: %ld\n\n"RESET, str, strlen(str));
	}
	else
		printf("No coincide con el resultado de la función original.\n\n");

//2 - ft_memcpy
	printf(RED"2 ft_memcpy\n"RESET);
	const char	*src = "Hello, World!";
	char	dest[15];
	ft_memcpy(dest, src, 15);
	printf(BLUE"String orig.:	%s\n"RESET, src);
	printf(GREEN"Nuevo string:	%s\n\n"RESET, dest);

	const int	array[] = {9, 5, 6, 3, 4};
	int		dest1[5];
	ft_memcpy(dest1, array, 32);
	printf(BLUE"Array orig.: ");
	for (size_t i = 0; i < (sizeof(array) / sizeof(array[0])); i++)
		printf(BLUE"%d "RESET, array[i]);
	printf(" <- Si hay desbordamiento es OK (n grande)\n");
	printf(GREEN"Nuevo array: ");
	for (size_t i = 0; i < (sizeof(dest1) / sizeof(dest1[0])); i++)
		printf(GREEN"%d "RESET, dest1[i]);
	printf("\n\n"RESET);

//3 - ft_memset
	printf(RED"3 ft_memset\n"RESET);
	char	buffer[10] = "0123456789";
	int		c = 'c';
	// Llenar 5 bytes del buffer con el valor 200
	ft_memset(buffer, c, 5);
	// Mostrar el contenido de buffer
	printf(BLUE"Llenamos 5 bytes con el caracter %c (ascii %d):	", c, c);
	for (size_t i = 0; i < sizeof(buffer); i++)
		printf("%d ", (unsigned char)buffer[i]);
		// Respuesta esperada
	memset(buffer, c, 5);
	// Mostrar el contenido de buffer
	printf(GREEN"\nFunción original:				");
	for (size_t i = 0; i < sizeof(buffer); i++)
		printf("%d ", (unsigned char)buffer[i]);
	printf("\n\n"RESET);

//4 - ft_bzero
	printf(RED"4 ft_bzero\n"RESET);
	// Llenar el buffer con el valor 200
	ft_bzero(buffer, 3);
	// Mostrar el contenido de buffer
	printf(BLUE"Reseteamos a 0 los 3 primeros bytes:	");
	for (size_t i = 0; i < sizeof(buffer); i++)
		printf("%d ", (unsigned char)buffer[i]);
		// Respuesta esperada
	bzero(buffer, 3);
	// Mostrar el contenido de buffer
	printf(GREEN"\nFunción original:			");
	for (size_t i = 0; i < sizeof(buffer); i++)
		printf("%d ", (unsigned char)buffer[i]);
	printf("\n\n"RESET);

//5 - ft_memmove
	printf(RED"5 ft_memmove\n"RESET);
	char	buffer2[20] = "Hello, World!";
	char	buffer3[20] = "Hello, World!";
	printf(WHITE"  // Solapamiento parcial\n"RESET);
	printf(BLUE"String orig.:			%s\n"RESET, buffer2);
	ft_memmove(buffer2 + 7, buffer2, 8);				// Mueve "Hello, W" a la posición que empieza en el índice 7
	memmove(buffer3 + 7, buffer3, 8);
	printf(CYAN"String solapado por dest:	%s\n"RESET, buffer3);
	printf(GREEN"Func. original:			%s\n\n"RESET, buffer3);

	char	buffer4[20] = "No change";
	char	buffer5[20] = "No change";
	printf(WHITE"  // Copiar 0 bytes\n"RESET);
	printf(BLUE"String orig.:	%s\n"RESET, buffer4);
	ft_memmove(buffer4 + 4, buffer4, 0);				// No debe cambiar nada
	memmove(buffer5 + 7, buffer5, 0);
	printf(CYAN"Nuevo string:	%s\n"RESET, buffer4);
	printf(GREEN"Func. original:	%s\n\n"RESET, buffer5);

//6 - ft_memcmp
printf(RED"6 ft_memcmp\n"RESET);
	char	*stri1 = "A";
	char	*stri2 = "Ab";

	printf(BLUE"			Comparison result: %d\n"RESET, ft_memcmp(stri1, stri2, 65));
	printf(GREEN"Func. original:		Comparison result: %d\n\n"RESET, memcmp(stri1, stri2, 65));

//7 - ft_memchr
	printf(RED"7 ft_memchr\n"RESET);
	char	string3[20] = "Hello, World!";
	int		character = 'o';
	char	*result3 = ft_memchr(string3, character, 5);
	char	*result4 = memchr(string3, character, 5);
	if (result3 != NULL && result4 != NULL && result3 == result4)
	{
		printf(BLUE"			Dest: %s\n"RESET, result3);
		printf(GREEN"Func. original:		Dest: %s\n\n"RESET, result4);
	}
	else if (result3 != result4)
		printf(RED"			Resultados distintos en ft_memchr y memchr.\n\n"RESET);
	else
		printf(RED"			Character not found.\n\n"RESET);

printf("-------------------------------------------------\n\n");

//8 - ft_isalpha
	printf(RED"8 ft_isalpha\n"RESET);
	int	letter = 'G';
	int	letter2 = 'l';
	if (ft_isalpha(letter) && ft_isalpha(letter2))
		printf(BLUE"		La letra %c y la %c sí son caracteres alfabéticos.\n"RESET, letter, letter2);
	else
		printf(RED"		El caracter NO es alfabético.\n"RESET);
		// Respuesta esperada
	printf(GREEN"Resp. esperada:	La letra %c y la %c sí son caracteres alfabéticos.\n\n"RESET, letter, letter2);

//9 - ft_isdigit
	printf(RED"9 ft_isdigit\n"RESET);
	int	digit = '0';
	if (ft_isdigit(digit))
		printf(BLUE"		El caracter %c sí es un dígito.\n"RESET, digit);
	else
		printf(RED"		El caracter NO es un dígito.\n"RESET);
		// Respuesta esperada
	printf(GREEN"Resp. esperada:	El caracter %c sí es un dígito.\n\n"RESET, digit);

//10 - ft_isalnum
	printf(RED"10 ft_isalnum\n"RESET);
	int	alfanum = ' ';
	int	alfanum2 = 'm';
	if (!ft_isalnum(alfanum) && ft_isalnum(alfanum2))
	{
		printf(BLUE"		El caracter '%c' no es alfanumérico.\n"RESET, alfanum);
		printf(BLUE"		El caracter %c sí es alfanumérico.\n\n"RESET, alfanum2);
	}
	else
		printf(RED"		La función no funciona correctamente\n\n"RESET);

//11 - ft_isascii
	printf(RED"11 ft_isascii\n"RESET);
	int	ascii = 2;
	if (ft_isascii(ascii))
		printf(BLUE"		El caracter '%c'(inicio texto) sí es ASCII.\n"RESET, ascii);
	else
		printf(RED"		El caracter NO es ASCII.\n"RESET);
		// Respuesta esperada
	printf(GREEN"Resp. esperada:	El caracter '%c'(inicio texto) sí es ASCII.\n\n"RESET, ascii);

//12 - ft_isprint
	printf(RED"12 ft_isisprint\n"RESET);
	if (ft_isprint(ascii))
		printf(RED"		El caracter '%c' sí es printable.\n"RESET, ascii);
	else
		printf(BLUE"		El caracter NO es printable.\n"RESET);
		// Respuesta esperada
	printf(GREEN"Resp. esperada:	El caracter NO es printable.\n\n"RESET);

printf("-------------------------------------------------\n\n");

//13 - ft_toupper
	printf(RED"13 ft_toupper\n"RESET);
	char	letra = 'f';
	char	mayus = ft_toupper(letra);
	if (isupper(mayus))
	{
		printf(BLUE"		Se ha convertido la letra %c en mayúsculas: %c\n"RESET, letra, mayus);
		printf(GREEN"Resp. esperada:	Se ha convertido la letra f en mayúsculas: F\n\n"RESET);
	}
	else
		printf(RED"La función no funciona correctamente.\n\n"RESET);

//14 - ft_tolower
	printf(RED"14 ft_tolower\n"RESET);
	char	letra2 = 'H';
	char	minus = ft_tolower(letra2);
	if (islower(minus))
	{
		printf(BLUE"		Se ha convertido la letra %c en minúsculas: %c\n"RESET, letra2, minus);
		printf(GREEN"Resp. esperada:	Se ha convertido la letra H en minúsculas: h\n\n"RESET);
	}
	else
		printf(RED"La función no funciona correctamente.\n\n"RESET);
//15 - ft_strchr
	printf(RED"15 ft_strchr\n"RESET);

	char	*string4 = "Hello, World!";
	char	*result5 = ft_strchr(string4, 'l');
	char	*result6 = strchr(string4, 'l');

	if (result5 != NULL && result6 != NULL && result5 == result6)
	{
		printf(BLUE"			Dest: %s\n"RESET, result5);
		printf(GREEN"Func. original:		Dest: %s\n\n"RESET, result6);
	}
	else if (result5 != result6)
		printf(RED"			Resultados distintos en ft_strchr y strchr.\n\n"RESET);
	else
		printf(RED"			Character not found.\n\n"RESET);

//16 - ft_strrchr
	printf(RED"16 ft_strrchr\n"RESET);

	char	*result7 = ft_strrchr(string4, 'l');
	char	*result8 = strrchr(string4, 'l');

	if (result7 != NULL && result8 != NULL && result7 == result8)
	{
		printf(BLUE"			Dest: %s\n"RESET, result7);
		printf(GREEN"Func. original:		Dest: %s\n\n"RESET, result8);
	}
	else if (result7 != result8)
		printf(RED"			Resultados distintos en ft_strchr y strchr.\n\n"RESET);
	else
		printf(RED"			Character not found.\n\n"RESET);

printf("-------------------------------------------------\n\n");

//17 - ft_strlcat
	printf(RED"17 ft_strlcat\n"RESET);
	char	source[] = "5 gatos";
	char	destino[16] = "Hola, tengo ";

	printf(BLUE"		Retorno de ft_strlcat: %zu\n"RESET, ft_strlcat(destino, source, 16));
	printf(GREEN"Func. original: Retorno de strlcat: 19\n"RESET);
	printf(BLUE"		String nuevo: %s\n"RESET, destino);
	printf(GREEN"Func. original: String nuevo: Hola, tengo 5 g\n\n"RESET);

	char	destino1[] = "Hola, tengo ";
	printf(WHITE"  // Size menor que length de dest\n"RESET);

	printf(BLUE"		Retorno de ft_strlcat: %ld\n"RESET, ft_strlcat(destino1, source, 7));
	printf(GREEN"Func. original: Retorno de strlcat: 14 "GRAY"(len_src + size)\n\n"RESET);
	printf(BLUE"		String nuevo: %s\n"RESET, destino1);
	printf(GREEN"Func. original: String nuevo: Hola, tengo "GRAY"(No copia nada de src en dst)\n\n"RESET);

//18 - ft_strlcpy
	printf(RED"18 ft_strlcpy\n"RESET);
	char	str2[] = "Hola, 123456";
	int		size = sizeof(*str2) / sizeof(str2[0]);
	char	copy[size];
	int		length = ft_strlcpy(copy, str2, 1);

	printf(WHITE"  // Solo espacio para el nulo\n"RESET);
	printf(BLUE"		Length of src: %d\n"RESET, length);
	printf(GREEN"Func. original:	Length of src: 12\n"RESET);
	printf(BLUE"		Array final: %s\n"RESET, copy);
	printf(GREEN"Func. original: Array final: \n\n"RESET);

	printf(WHITE"  // Length muy grande\n"RESET);
	length = ft_strlcpy(copy, str2, 50);
	printf(BLUE"		Length of src: %d\n"RESET, length);
	printf(GREEN"Func. original:	Length of src: 12\n"RESET);
	printf(BLUE"		Array final: %s\n"RESET, copy);
	printf(GREEN"Func. original: Array final: Hola, 123456\n\n"RESET);

//19 - ft_atoi
	printf(RED"19 ft_atoi\n"RESET);
	const char	*texto = "   -21474836474585";
	printf(BLUE"		El string '%s' (>int) convertido a número es: %d\n"RESET, texto, ft_atoi(texto));
	printf(GREEN"Func. original:	El string '%s' (>int) convertido a número es: %d\n\n"RESET, texto, atoi(texto));
	const char	*texto2 = "   -+-5325nb";
	printf(BLUE"		El string '%s' convertido a número es: %d\n"RESET, texto2, ft_atoi(texto2));
	printf(GREEN"Func. original:	El string '%s' convertido a número es: %d\n\n"RESET, texto2, atoi(texto2));

//20 - ft_strnstr
	printf(RED"20 ft_strnstr\n"RESET);
	char	*string = "Hola, me llamo Luis";
	char	*needle = "llamo";
	char	*result = ft_strnstr(string, needle, 50);
	char	*result2 = ft_strnstr(string, needle, 4);

	if (result != NULL)
	{
		printf(BLUE"			%s\n"RESET, result);
	}
	else
		printf(RED"No ha habido coincidencias.\n"RESET);
	printf(GREEN"Resultado esperado:	llamo Luis\n\n"RESET);

	if (result2 != NULL)
	{
		printf(RED"			%s\n"RESET, result2);
	}
	else
		printf(BLUE"			No ha habido coincidencias.\n"RESET);
	printf(GREEN"Resultado esperado:	No ha habido coincidencias.\n\n"RESET);

//21 - ft_strncmp
	printf(RED"21 ft_strncmp\n"RESET);
	char	*string1 = "AAB";
	char	*string2 = "AABs";

	printf(BLUE"			Comparison result: %d\n"RESET, ft_strncmp(string1, string2, 4));
	printf(GREEN"Func. original:		Comparison result: %d\n\n"RESET, strncmp(string1, string2, 4));

//22 - ft_calloc
	printf(RED"22 ft_calloc\n"RESET);
	char	*array1;
	char	*array2;
	int		identical = 1;

	array1 = ft_calloc(4, 5);
	array2 = calloc(4, 5);

	for (size_t i = 0; i < 20; i++)
	{
		if (array1[i] != array2[i])
		{
			identical = 0;
			break ;
		}
	}
	free(array1);
	free(array2);
	if (identical)
		printf(BLUE"Los bloques de memoria son iguales con ft_calloc y calloc.\n\n"RESET);
	else
		printf(RED"Los bloques de memoria son diferentes con ft_calloc y calloc.\n\n"RESET);

//23 - ft_strdup
	printf(RED"23 ft_strdup\n"RESET);
	char	*original = "Hols, qué pasaaaaa";
	char	*duplicate = ft_strdup(original);
	char	*duplicate2 = strdup(original);

	if (duplicate == NULL)
		return 1;		// Error al duplicar la cadena
	printf(CYAN"		Original:  %s\n"RESET, original);
	if (ft_strncmp(duplicate, duplicate2, 15) == 0)
	{
		printf(BLUE"		Duplicado: %s\n"RESET, duplicate);
		printf(GREEN"Func. original: Duplicado: %s\n\n "RESET, duplicate2);
	}
	else
	{
		printf(RED"		ft_strdup y strdup no coindicen. !!!\n"RESET);
		printf(MAGENTA"		Duplicado: %s\n"RESET, duplicate);
		printf(MAGENTA"Func. original: Duplicado: %s\n\n "RESET, duplicate2);
	}
	free(duplicate);
	free(duplicate2);

printf("-------------------------------------------------\n\n");

//24 - ft_substr
	printf(RED"24 ft_substr\n"RESET);
	char	*string5 = "1234567890";
	char	*substring = ft_substr(string5, 2, 4);

	printf(CYAN"		String original:		%s\n"RESET, string5);
	printf(BLUE"		Substring (start 2, len 4):	  %s\n\n"RESET, substring);
	free(substring);

//25 - ft_strjoin
	printf(RED"25 ft_strjoin\n"RESET);
	char	*string6 = "HOlaaa ";
	char	*string7 = "Hola";
	char	*joinedstring = ft_strjoin(string6, string7);
	printf(BLUE"		Unimos '%s' con '%s': %s\n\n"RESET, string6, string7, joinedstring);
	free(joinedstring);

//26 - ft_putchar_fd
	printf(RED"26 ft_putchar_fd\n"RESET);
	write(1, "\t\t"BLUE, 7);
	ft_putchar_fd('h', 1);
	printf(RESET"	<-- stdout\n");
	write(1, "\t\t"MAGENTA, 8);
	ft_putchar_fd('h', 2);
	printf(RESET"	<-- stderr\n");
	write(1, "\n\n", 2);

//27 - ft_putstr_fd
	printf(RED"27 ft_putstr_fd\n"RESET);
	char	*string01 = "Salida stdout";
	char	*string02 = "Salida stderr";
	write(1, "\t\t"BLUE, 7);
	ft_putstr_fd(string01, 1);
	printf(RESET"	<-- stdout\n");
	write(1, "\t\t"MAGENTA, 7);
	ft_putstr_fd(string02, 2);
	printf(RESET"	<-- stderr\n");
	write(1, "\n\n", 2);


//28 - ft_putendl_fd
	printf(RED"28 ft_putendl_fd\n"RESET);
	write(1, "\t\t"BLUE, 7);
	ft_putendl_fd(string01, 1);
	printf(RESET"	<-- stdout\n");
	write(1, "\t\t"MAGENTA, 7);
	ft_putendl_fd(string02, 2);
	printf(RESET"	<-- stderr\n");
	printf(RESET"				OK si tiene un \\n más que la función anterior.\n");

	write(1, "\n\n", 2);

//29 - ft_putnbr_fd
	printf(RED"29 ft_putnbr_fd\n"RESET);
	write(1, "\t\t"BLUE, 7);
	ft_putnbr_fd(-745, 1);
	printf(RESET"	<-- stdout (-745)\n");
	write(1, "\t\t"MAGENTA, 8);
	ft_putnbr_fd(8458, 2);
	printf(RESET"	<-- stderr (8458)\n");
	write(1, "\n\n", 2);

printf("-------------------------------------------------\n\n");

//30 - ft_strmapi
	printf(RED"30 ft_strmapi\n"RESET);

	char	upper_and_lower(unsigned int index, char c)
	{
		if (index % 2 == 0)
		{
			if (c >= 'a' && c <= 'z')
				return (c - 32);
			else
				return (c);
		}
		else
		{
			if (c >= 'A' && c <= 'Z')
				return (c + 32);
			else
				return (c);
		}
	}

	const char	*string03 = "Hola, me llamo Pepe.";
	char	*newstring_mixed = ft_strmapi(string03, upper_and_lower);

	if (newstring_mixed == NULL)
		printf(RED"Error al asignar memoria con ft_strmapi\n\n"RESET);
	else
	{
		printf(BLUE"		String original:			%s\n"RESET, string03);
		printf(GREEN"		Nuevo string aplicando función:		%s\n\n"RESET, newstring_mixed);
	}

//31 - ft_striteri
	printf(RED"31 ft_striteri\n"RESET);

	void	upper_and_lower2(unsigned int index, char *c)
	{
		if (index % 2 == 0)
		{
			if (*c >= 'a' && *c <= 'z')
				*c = ft_toupper(*c);
		}
		else
		{
			if (*c >= 'A' && *c <= 'Z')
				*c = ft_tolower(*c);
		}
	}
	char	string04[] = "Hola, me llamo Pepe.";
	printf(BLUE"		String antes de modificarlo:		%s\n"RESET, string04);
	ft_striteri(string04, upper_and_lower2);
	printf(GREEN"		String después de modificarlo:		%s\n\n"RESET, string04);

//32 - ft_strtrim
	printf(RED"32 ft_strtrim\n"RESET);

	const char	*string05 = "*4*5Hello, World!*4*****";
	char	*set = "*45";
	char	*trimmed = ft_strtrim(string05, set);

	printf(BLUE"		String a recortar		%s\n"RESET, string05);
	printf(BLUE"		Set:				%s\n"RESET, set);
	printf(GREEN"		Result:				%s\n\n"RESET, trimmed);

//33 - ft_split
	printf(RED"33 ft_split\n"RESET);

	char	*string06 = "////Hola/que//tal/hola/";
	char	delimitador = '/';
	char	**array3 = ft_split(string06, delimitador);

	printf(BLUE"		String original: %s\n"RESET, string06);
	if (array3 == NULL)
	{
		printf("Error al separar la cadena.\n");
		return (1);
	}

	// Imprimir todas las subcadenas resultantes
	for (int i = 0; array3[i] != NULL; i++)
	{
		printf(GREEN"		Subcadena %d: %s\n"RESET, i, array3[i]);
	}

	// Liberar la memoria asignada por ft_split
	for (int i = 0; array3[i] != NULL; i++)
	{
		free(array3[i]); // Liberar cada subcadena
	}
	free(array3); // Liberar el array de punteros
	printf("\n\n");

//34 - ft_itoa
	printf(RED"33 ft_itoa\n"RESET);

	char	*strnumber = ft_itoa(-4545);
	if (strnumber)
	{
		printf(BLUE"		Convertimos el int -4545 en un string:" GREEN"'%s'\n\n"RESET, strnumber);
		free(strnumber);
	}

	printf(YELLOW"\n********************************************************************\n"RESET);
	printf(YELLOW"\n********************************************************************\n\n"RESET);

	return (0);
}
