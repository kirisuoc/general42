/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousill <ecousill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:09:01 by ecousill          #+#    #+#             */
/*   Updated: 2024/09/24 14:35:07 by ecousill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	printf(YELLOW"\n****************************************************************************\n"RESET);
	printf(YELLOW"\n		---------- Test **BONUS** libft.a ----------\n\n"RESET);
	printf(YELLOW"\n****************************************************************************\n\n"RESET);

	// Función para imprimir el contenido del nodo
	void print_list(t_list *node)
	{
		while (node != NULL)
		{
			printf(BLUE"	Node content: %s\n"RESET, (char *)node->content);
			node = node->next;
		}
	}

//1 - ft_lstnew
	printf(RED"1 ft_lstnew\n"RESET);

	// Crear contenido para el nuevo nodo
	char	*content = "Hello, World";

	//Crear un nuevo nodo con el contenido
	t_list	*node = ft_lstnew(content);

	//Verificar si el nodo se creó correctamente
	if (node != NULL)
	{
		// Imprimir el contenido del nodo
		print_list(node);
		printf("\n\n");

		// Liberar la memoria del nodo
		free(node);
	}
	else
		printf(RED"Failed to create a new node.\n\n"RESET);

//2 - ft_lstadd_front
	printf(RED"2 ft_lstadd_front\n"RESET);

	t_list	*head = NULL; // Inicialmente la lista está vacía
	t_list	*new_node1 = ft_lstnew(ft_strdup("First"));
	t_list	*new_node2 = ft_lstnew(ft_strdup("Second"));
	t_list	*new_node3 = ft_lstnew(ft_strdup("Third"));
	t_list	*new_node4 = ft_lstnew(ft_strdup("Fourth"));

	// Añadir nodos al principio de la lista
	ft_lstadd_front(&head, new_node1);
	ft_lstadd_front(&head, new_node2);
	ft_lstadd_front(&head, new_node3);
	ft_lstadd_front(&head, new_node4);

	// Imprimir la lista
	print_list(head);
	printf("\n\n");

//3 - ft_lstsize
	printf(RED"3 ft_lstsize\n"RESET);

	int	lst_size = ft_lstsize(head);

	// Imprimir la lista
	printf(BLUE"	Tamaño de la lista: %d"RESET, lst_size);
	printf("\n\n");

//4 - ft_lstlast
	printf(RED"4 ft_lstlast\n"RESET);

	t_list	*last_node = ft_lstlast(head);

	print_list(last_node);
	printf("\n\n");

//5 - ft_lstadd_back
	printf(RED"5 ft_lstadd_back\n"RESET);

	t_list	*new_node5 = ft_lstnew(ft_strdup("Added to the end of the list 1"));
	t_list	*new_node6 = ft_lstnew(ft_strdup("Added to the end of the list 2"));

	// Añadir nodos al final de la lista
	ft_lstadd_back(&head, new_node5);
	ft_lstadd_back(&head, new_node6);

	// Imprimir la lista
	print_list(head);
	printf("\n\n");

//6 - ft_lstdelone
	printf(RED"6 ft_lstdelone\n"RESET);

	void	del_content(void *content)
	{
		free(content);
	}

	t_list	*temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		ft_lstdelone(temp, del_content); //Libera el nodo actual
	}

	printf("	Use the command 'valgrind --leak-check=full -s ./a.out' \n\tto check if there's any leak.\n\n");

//7 - ft_lstdelone
	printf(RED"7 ft_lstclear\n"RESET);

//8 - ft_lstiter
	printf(RED"8 ft_lstiter\n"RESET);

//9 - ft_lstmap
	printf(RED"9 ft_lstmap\n"RESET);

	return (0);
}
