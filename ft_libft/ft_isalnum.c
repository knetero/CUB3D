/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:41:40 by gghaya            #+#    #+#             */
/*   Updated: 2022/10/29 12:57:19 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalnum(int x)
{
	if (ft_isdigit(x) || ft_isalpha(x))
		return (1);
	return (0);
}
