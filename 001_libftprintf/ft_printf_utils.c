/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:22:37 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/02/03 12:54:36 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptf_printf_check(char *ptr)
{
	while (*ptr)
	{
		if (*ptr != '%')
			ptr++;
		else
		{
			ptr++;
			while (*ptr && !(*ptr == 'c' || *ptr == 's' || *ptr == 'p'
					|| *ptr == 'd' || *ptr == 'i' || *ptr == 'u' || *ptr == 'x'
					|| *ptr == 'X' || *ptr == '%'))
			{
				if (ft_isdigit(*ptr) || *ptr == '.' || *ptr == '-'
					|| *ptr == '+' || *ptr == ' ' || *ptr == '#')
					break ;
				ft_putstr_fd("unknown conversion type character '", 1);
				ft_putchar_fd(*ptr, 1);
				ft_putstr_fd("' in format [-Werror=format=]", 1);
				return (1);
			}
			ptr++;
		}
	}
	return (0);
}

t_ftprintf	*ft_ptf_lstnew(void)
{
	t_ftprintf	*ptr;

	ptr = (t_ftprintf *)malloc(sizeof(t_ftprintf));
	if (!ptr)
		return (NULL);
	ptr->str = (char *)ft_calloc(3, sizeof(char));
	ptr->count = 0;
	ptr->fcs_minus = 0;
	ptr->fcs_plus = 0;
	ptr->fcs_space = 0;
	ptr->fcs_hash = 0;
	ptr->fcs_zero = 0;
	ptr->fcs_fw = 0;
	ptr->fcs_pcs = 0;
	ptr->fcs_pcs_len = 0;
	ptr->fcs_conv_spc = 0;
	ptr->ival = 0;
	ptr->uval = 0;
	ptr->xval = 0;
	return (ptr);
}

int	ft_ptf_clean(t_ftprintf *lst)
{
	if (!lst)
		return (0);
	free(lst->str);
	lst->str = NULL;
	lst->count = 0;
	lst->fcs_minus = 0;
	lst->fcs_plus = 0;
	lst->fcs_space = 0;
	lst->fcs_hash = 0;
	lst->fcs_zero = 0;
	lst->fcs_fw = 0;
	lst->fcs_pcs = 0;
	lst->fcs_pcs_len = 0;
	lst->fcs_conv_spc = 0;
	free(lst);
	lst = NULL;
	return (-1);
}

char	*ft_ptf_str_join(char *s1, char *s2)
{
	char	*s1_join_s2;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s1_join_s2 = (char *)ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (!s1_join_s2)
		return (NULL);
	ft_memcpy(s1_join_s2, s1, len_s1);
	free(s1);
	s1 = NULL;
	ft_memcpy((s1_join_s2 + len_s1), s2, len_s2);
	return (s1_join_s2);
}

char	*ft_str_toupper(char *sval)
{
	int	i;

	i = 0;
	while (sval[i])
	{
		sval[i] = ft_toupper(sval[i]);
		i++;
	}
	return (sval);
}
