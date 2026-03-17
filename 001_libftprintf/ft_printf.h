/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:14:49 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/02/04 17:43:38 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../000_libft/libft.h"
# include <limits.h>
# include <stdarg.h>

typedef struct s_ftprintf
{
	char			*str;
	unsigned int	count;
	int				fcs_minus;
	int				fcs_plus;
	int				fcs_space;
	int				fcs_hash;
	int				fcs_zero;
	unsigned int	fcs_fw;
	int				fcs_pcs;
	unsigned int	fcs_pcs_len;
	char			fcs_conv_spc;
	signed int		ival;
	unsigned int	uval;
	unsigned int	xval;
}					t_ftprintf;

// ft_printf library functions
int					ft_printf(const char *fmt, ...);

// ft_printf utils
t_ftprintf			*ft_ptf_lstnew(void);
int					ft_ptf_clean(t_ftprintf *lst);
char				*ft_ptf_str_join(char *s1, char *s2);
char				*ft_str_toupper(char *sval);
int					ft_ptf_printf_check(char *ptr);

// ft_printf utils configurator and flags selection
unsigned int		ft_ptf_flags_case(char **ptr, va_list ap);
void				ft_ptf_check_zero(t_ftprintf *data, char **ptr);
void				ft_ptf_check_precision(t_ftprintf *data, char **ptr);
void				ft_ptf_check_flags(t_ftprintf *data, char **ptr);
unsigned int		ft_ptf_case(char **ptr, t_ftprintf *data, va_list ap);

// ft_printf support functions
char				*ft_ptf_ptohex(size_t n);
char				*ft_ptf_unitohex(unsigned int n);
char				*ft_ptf_uitoa(unsigned int n);
unsigned int		ft_ptf_char(t_ftprintf *data, unsigned char cval);
unsigned int		ft_ptf_hex(t_ftprintf *data, unsigned int xval, char hex);
unsigned int		ft_ptf_int(t_ftprintf *data, signed int ival);
unsigned int		ft_ptf_ptr(t_ftprintf *data, size_t uval);
unsigned int		ft_ptf_str_wrt(t_ftprintf *data, char *sval);
unsigned int		ft_ptf_str(t_ftprintf *data, char *sval);
unsigned int		ft_ptf_uint(t_ftprintf *data, unsigned int uval);

// ft_ptf_int_utils functions
char				*ft_ptf_int_fw(t_ftprintf *data, unsigned int len,
						char *sval_tmp);
char				*ft_ptf_int_minus(t_ftprintf *data, char *sval);
char				*ft_ptf_int_pcs(t_ftprintf *data, unsigned int len,
						char *sval);
void				ft_ptf_int_sign_case(t_ftprintf *data, int sign, int ival);
char				*ft_ptf_int_sval(t_ftprintf *data, char **sval,
						signed int ival, int *sign);
#endif
