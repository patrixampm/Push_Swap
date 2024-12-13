/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeckham <ppeckham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:24:15 by ppeckham          #+#    #+#             */
/*   Updated: 2024/09/30 17:46:18 by ppeckham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

// Structure type for a list node
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Will asign n bytes in memory with null value
void	ft_bzero(void *s, size_t n);

// If the character is alpha-numeric, it returns a 1, in other case it returns 0
int		ft_isalnum(int ch);

// If it is a character in the alphabet, it returns 1, if not, 0 (depends on locale)
int		ft_isalpha(int ch);

// If it is an ASCII character it returns 1, if not, 0
int		ft_isascii(int ch);

// If it is a character between 0 and 9 it returns 1, if not, 0
int		ft_isdigit(int ch);

// If it is a printable character it returns 1, if not, 0
int		ft_isprint(int ch);

// It will asign 'count' bytes in memory with the integer given in 'c'
void	*ft_memset(void *ptr, int c, size_t count);

// It returns the length of a string
int		ft_strlen(const char *str);

// It copies n bytes from a string to another space in memory.
// If there is overlapping, the behaviour is undefined
void	*ft_memcpy(void *dest, const void *src, size_t n);

// It copies n bytes from a string to another space in memory.
// If there is overlapping, it changes the order it copies the bytes, 
// so there is no undefined behaviour
void	*ft_memmove(void *dest, const void *src, size_t n);

// It copies 'size' characters from 'src' to 'dest', adds \0 at the end
// and returns the length of the original length of 'src'
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

// Concatenates 'src' at the end of 'dest', as long as there is enough memory in 'destsize'.
// I wil always leave one byte at the end for \0, if not it truncates the string
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);

// It returns the upper case letter of the lower case letter received (ASCII value).
// If it doesn't receive a lower case letter, it returns the character unchanged
int		ft_toupper(int c);

// It returns the lower case letter of the upper case letter received (ASCII value).
// If it doesn't receive aa upper case letter, it returns the character unchanged
int		ft_tolower(int c);

// It finds the first ocurrence of a character in a string and returns it memory address.
// If it receives \0, it returns its memory address
char	*ft_strchr(const char *str, int c);

// It returns the last ocurrence of a character in a string (memory address)
char	*ft_strrchr(const char *str, int c);

// Compares the characters of two strings until it finds two that are different.
// It returns the difference of their ASCII values, and if the strings are the same
// it returns 0
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// It looks for the memory address of 'value' in a memory block '*ptr'.
// 'num' limits the bytes to be scanned. Type insensitive
void	*ft_memchr(const void *ptr, int value, size_t num);

// It compares the characters of two memory blocks until it finds two different
// characters. It returns their ASCII value difference. If there is no difference
// it returns 0
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

// Looks for 'needle' in 'haystack' and returns the memory address of the first
// character of 'needle'. If it isn't present, 'n' is too small, or we reach
// the end of 'haystack', it returns null
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// Converts numeric characters to integers. It ignores initial spaces and recognizes 
// + or -
int		ft_atoi(const char *str);

// Asigns 'num' elements of 'size' size to a memory block and initializes them to 0
void	*ft_calloc(size_t num, size_t size);

// Generates a copy of 'str'. It always adds \0 to the end
char	*ft_strdup(const char *str);

// It creates a copy of 's' string, starting at 'start' and finishing at 'len'.
// It returns the copy, or null if it fails
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Concatenates 's1' and 's2' and add \0 at the end. First, memory is assigned
char	*ft_strjoin(char const *s1, char const *s2);

// Eliminates all characters from 'set' string from the beginning and the end of 's1'.
// If there is no coincidence, it returns the full 's1' string.
char	*ft_strtrim(char const *s1, char const *set);

// It cuts the 's' string every time 'c' occurs, and saves each segment in a new list 
// without 'c'. It finishes the list with NULL, and returns the memory address of the
// first character of the list
char	**ft_split(char const *s, char c);

// Converts an integer to a string of characters. It returns the string, signed, and
// finished with \0, or NULL if it fails
char	*ft_itoa(int n);

// It applies a function 'f' to each character of 's' and returns the new string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// It applies a function 'f' to each character of 's' but doesn't return anything
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// Writes a character to a file descriptor 'fd'
void	ft_putchar_fd(char c, int fd);

// Writes a string to a file descriptor 'fd'
void	ft_putstr_fd(char *s, int fd);

// Writes a string to a file descriptor and finished it with a \n (new line)
void	ft_putendl_fd(char *s, int fd);

// Writes an integer to a file descriptor 'fd'
void	ft_putnbr_fd(int n, int fd);

// Creates a new node, or the first one of a linked list. Next points to the
// next node of the list and content, to it's own content.
t_list	*ft_lstnew(void *content);

// Adds a new node to the start of a linked list
void	ft_lstadd_front(t_list **lst, t_list *new);

// Returns the number of nodes in a linked list (integer format)
int		ft_lstsize(t_list *lst);

// Returns the last node's memory address in a linked list
t_list	*ft_lstlast(t_list *lst);

// Inserts a new node 'new' at the end of a linked list 'lst'
void	ft_lstadd_back(t_list **lst, t_list *new);

// It deletes and frees the content of a linked list using the function indicated 
// in 'del'. Next is not deleted
void	ft_lstdelone(t_list *lst, void (*del)(void*));

// It deletes and frees a node, and every one after it in a linked list,
// applying a function 'del'
void	ft_lstclear(t_list **lst, void (*del)(void*));

// It iterates through each node of a linked list, applying a function to each one
void	ft_lstiter(t_list *lst, void (*f)(void *));

// It iterates through each node of a linked list aplying a function to each one.
// Returns the new list, or NULL if it fails
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
