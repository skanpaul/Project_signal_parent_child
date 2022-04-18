/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:09:38 by sorakann          #+#    #+#             */
/*   Updated: 2022/04/18 16:38:39 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
void init_struc_sigaction(t_data *d)
{
	// -------------------- PARENT ---------------------------------------	
	
	// parent: SIGINT	
	d->sa_sigint_parent.sa_handler = &handler_signal_parent;	// SA_HANDLER	
	sigemptyset(&d->sa_sigint_parent.sa_mask);				// SA_MASK
	sigaddset(&d->sa_sigint_parent.sa_mask, SIGINT);		// -
	sigaddset(&d->sa_sigint_parent.sa_mask, SIGQUIT);		// -	
	d->sa_sigint_parent.sa_flags = SA_RESTART;				// SA_FLAG
	
	// parent: SIGQUIT	
	d->sa_sigquit_parent.sa_handler = SIG_IGN;

	// -------------------- CHILD ----------------------------------------	

	// child: SIGINT
	d->sa_sigint_child.sa_handler = &handler_signal_child;	// SA_HANDLER	
	sigemptyset(&d->sa_sigint_child.sa_mask);				// SA_MASK
	sigaddset(&d->sa_sigint_child.sa_mask, SIGINT);			// -
	sigaddset(&d->sa_sigint_child.sa_mask, SIGQUIT);		// -	
	d->sa_sigint_child.sa_flags = SA_RESTART;				// SA_FLAG
	
	// child: SIGQUIT
	d->sa_sigquit_child.sa_handler = SIG_IGN;

	// ------------------------------------------------
}

/* ************************************************************************** */
void	handler_signal_parent(int sig_code)
{
	if (sig_code == SIGINT)
	{
		write(1, MSG_PARENT_SIGINT, strlen(MSG_PARENT_SIGINT));
	}
	
	if (sig_code == SIGQUIT)
	{
		write(1, MSG_PARENT_SIGQUIT, strlen(MSG_PARENT_SIGQUIT));	
	}
}

/* ************************************************************************** */
void	handler_signal_child(int sig_code)
{
	if (sig_code == SIGINT)
	{
		write(1, MSG_CHILD_SIGINT, strlen(MSG_CHILD_SIGINT));
	}
	
	if (sig_code == SIGQUIT)
	{
		write(1, MSG_CHILD_SIGQUIT, strlen(MSG_CHILD_SIGQUIT));	
	}
}

/* ************************************************************************** */
void link_signal_parent(t_data *d)
{
	sigaction(SIGINT, &d->sa_sigint_parent, NULL);		// [ctrl-C]: SIGINT
	sigaction(SIGQUIT, &d->sa_sigquit_parent, NULL);	// [ctrl-\]: SIGQUIT
}

/* ************************************************************************** */
void link_signal_child(t_data *d)
{
	sigaction(SIGINT, &d->sa_sigint_child, NULL);		// [ctrl-C]: SIGINT
	sigaction(SIGQUIT, &d->sa_sigquit_child, NULL);	// [ctrl-\]: SIGQUIT
}

/* ************************************************************************** */