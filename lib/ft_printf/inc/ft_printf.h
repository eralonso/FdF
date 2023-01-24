/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:13:19 by eralonso          #+#    #+#             */
/*   Updated: 2023/01/24 18:49:53 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<libft.h>
# include	<stdarg.h>

# define B10 (char *)"0123456789"
# define BL16 (char *)"0123456789abcdef"
# define BU16 (char *)"0123456789ABCDEF"
# define FL (char *)"-0123456789.#+ "
# define FT (char *)"cspdiuxX"

typedef unsigned long long	t_ull;
typedef long long int		t_lli;
typedef unsigned char		t_uc;

typedef struct s_flags {
	size_t	width;
	size_t	wdot;
	t_uc	dot:1;
	t_uc	dash:1;
	t_uc	zero:1;
	t_uc	hastag:1;
	t_uc	space:1;
	t_uc	plus:1;
}			t_flags;

typedef struct s_info {
	va_list	args;
	int		bytes;
	char	*str;
	char	c;
	t_uc	err:1;
	int		fd;
}			t_info;

typedef struct s_manager {
	t_info	*info;
	t_flags	*flags;
}			t_manager;

/*------------------------------->Main function<-------------------------*/
int		ft_printf(int fd, char const *format, ...);

/*------------------------------->Init functions<------------------------*/
t_info	*ft_init_info(int fd, char *str);
t_flags	*ft_init_flags(void);
void	ft_reset_flags(t_flags *flags);

/*------------------------------->Format checker<------------------------*/
void	ft_formatize(t_manager *stack, char *str);
void	ft_format_checker(t_manager *stack, char fmt);

/*-------------------------------->Flags checker<------------------------*/
int		ft_flags_checker(t_flags *flags, char *str);
//|
//|--> Utils
int		ft_min_width(t_flags *flags, char *str);
int		ft_accuracy(t_flags *flags, char *str);
void	ft_flag_selector(t_flags *flags, char fmt);

/*------------------------------------>Utils<----------------------------*/
//|
//|---> Free
int		ft_free_error(t_manager *stack);
//|
//|---> Char
void	ft_char_fl(char c, t_manager *stack);
void	ft_putnchar(char c, int n, t_manager *stk);
//|
//|---> String
void	ft_str_fl(char *str, t_manager *stack);
void	ft_putnstr(char *str, int n, t_manager *stk);
//|
//|---> Int and Unsigned int
void	ft_int_fl(t_lli nbr, t_manager *stack);
//|
//|---> Hexadecimal
void	ft_hex_fl(unsigned int nbr, t_manager *stack, char fmt, char *hex);
//|
//|---> Numbers Utils
void	ft_putnbr_base(t_lli nbr, char *base, t_lli len, t_manager *stk);
size_t	ft_nbr_size(t_lli nbr, t_lli len);
//|
//|---> Pointer
void	ft_ptr_fl(t_ull ptr, t_manager *stack);
size_t	ft_size_ptr(t_ull ptr);
//|
//|---> Percent or unrecognized format
void	ft_ofmt_fl(char c, t_manager *stack);
#endif
