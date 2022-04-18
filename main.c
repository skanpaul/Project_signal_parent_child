/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/04/18 16:51:05 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	pid_t fk_pid;
	t_data d;

	fk_pid = fork();
	init_struc_sigaction(&d);
		
	// ------------------- FORK ERROR ---------------------
	if (fk_pid == FORK_ERROR)
		return (ERROR);

	// ------------------- PARENT ------------------------
	if (is_parent(fk_pid))
	{
		link_signal_parent(&d);
		printf("PARENT[%d]> signal linked\n", getpid());
		
		wait(NULL);	
		printf("PARENT> has terminated\n");
	}
	
	// --------------------- CHILD ------------------------
	if (fk_pid == FORK_CHILD)
	{
		link_signal_child(&d);
		printf("CHILD[%d]> signal linked\n", getpid());
		
		while (1) {sleep(1);}
		printf("CHILD> has terminated\n");		
	}

	// ---------------------------------------------------
	return (0);
}