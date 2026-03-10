/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-cas <jode-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:13:46 by jode-cas          #+#    #+#             */
/*   Updated: 2026/03/07 09:54:39 by jode-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void SIGINT_handler()
{
  rl_on_new_line();
  rl_replace_line("", 0);
  printf("\033[2K\r");
  rl_redisplay();
}

void config_terminal_signals()
{
  struct termios original;
  struct termios raw;
	struct sigaction sigint_sa;

  tcgetattr(STDIN_FILENO, &original);
  raw = original;
  raw.c_lflag &= ~(ECHOCTL);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
	sigemptyset(&sigint_sa.sa_mask);
	sigint_sa.sa_handler = &SIGINT_handler;
  sigint_sa.sa_flags = 0;
	sigaction(SIGINT, &sigint_sa, NULL);
}