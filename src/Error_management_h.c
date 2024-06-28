/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management_h.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:38:36 by abhudulo          #+#    #+#             */
/*   Updated: 2024/06/28 08:38:50 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(const char *error_message)
{
	time_t		t;
	struct tm	*tm;
	char		date[64];
	FILE		*log;

	t = time(NULL);
	tm = localtime(&t);
	strftime(date, sizeof(date), "%c", tm);
	log = fopen("error_log.txt", "a");
	if (log)
	{
		fprintf(log, "[%s] Error encountered: %s. Exiting...\n",
			date, error_message);
		fclose(log);
	}
	fprintf(stderr, "Error encountered: %s. Exiting...\n", error_message);
	exit(EXIT_FAILURE);
}
