/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:15:35 by nimadela          #+#    #+#             */
/*   Updated: 2024/11/25 15:05:27 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;
	void	*cnt;

	res = NULL;
	while (lst)
	{
		cnt = (f(lst-> content));
		if (!cnt)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		temp = ft_lstnew(cnt);
		if (!temp)
		{
			del(cnt);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, temp);
		lst = lst-> next;
	}
	return (res);
}
