/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:00:42 by ski               #+#    #+#             */
/*   Updated: 2022/04/18 16:46:03 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
/* ************************************************************************** */
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>
/* ************************************************************************** */
# define NO_ERROR		0
# define ERROR			1
/* ************************************************************************** */
# define FORK_CHILD		0
# define FORK_ERROR		-1
/* ************************************************************************** */
# define MSG_PARENT_SIGINT		"parent receive SIGINT [ctrl-C]\n"
# define MSG_PARENT_SIGQUIT		"parent receive SIGQUIT [ctrl-\\\n]"
// -------------------------
# define MSG_CHILD_SIGINT		"child receive SIGINT [ctrl-C]\n"
# define MSG_CHILD_SIGQUIT		"child receive SIGQUIT [ctrl-\\\n]"
/* ************************************************************************** */
typedef struct s_data
{
	//--------------------------------
	struct sigaction sa_sigint_parent;	// [ctrl-C]
	struct sigaction sa_sigquit_parent;	// [ctrl-\]
	//--------------------------------
	struct sigaction sa_sigint_child;	// [ctrl-C]
	struct sigaction sa_sigquit_child;	// [ctrl-\]
	//--------------------------------
	
}	t_data;
/* ************************************************************************** */
bool	is_parent(pid_t fk_pid);
/* ************************************************************************** */
void	init_struc_sigaction(t_data *d);
// -------------------------------------------------
void	handler_signal_parent(int sig_code);
void	handler_signal_child(int sig_code);
// -------------------------------------------------
void	link_signal_parent(t_data *d);
void	link_signal_child(t_data *d);
/* ************************************************************************** */
#endif