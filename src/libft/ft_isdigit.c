/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:13:48 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/01 16:07:47 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// 	printf("%d", isdigit(0));
// 	printf("%d", isdigit(48));
// 	printf("%d", isdigit(57));
// 	printf("%d", isdigit(55));
// 	printf("%d", isdigit(15));
// 	printf("%d", isdigit(-12));
// 	printf("%d", isdigit(64));
// 	printf("\n");
// 	printf("%d", ft_isdigit(0));
// 	printf("%d", ft_isdigit(48));
// 	printf("%d", ft_isdigit(57));
// 	printf("%d", ft_isdigit(55));
// 	printf("%d", ft_isdigit(15));
// 	printf("%d", ft_isdigit(-12));
// 	printf("%d", ft_isdigit(64));
// 	printf("\n");
// }
