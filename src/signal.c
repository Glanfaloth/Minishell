/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:38:39 by lanlan            #+#    #+#             */
/*   Updated: 2022/10/15 12:32:36 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status; // Exit status of the last excuted command

/*
Function to handle SIGINT signals for main process

int ioctl(int fildes, unsigned long request, ...);
DESCRIPTION
The ioctl() function manipulates the underlying device parameters of
     special files.  In particular, many operating characteristics of character
     special files (e.g. terminals) may be controlled with ioctl() requests.
     The argument fildes must be an open file descriptor.

     An  ioctl request has encoded in it whether the argument is an “in”
     parameter or “out” parameter, and the size of the argument argp in bytes.
     Macros and defines used in specifying an ioctl request are located in the
     file ⟨sys/ioctl.h⟩.

RETURN VALUES
     If an error has occurred, a value of -1 is returned and errno is set to
     indicate the error.

void rl_replace_line (const char *text, int clear_undo) ¶
Replace the contents of rl_line_buffer with text.
The point and mark are preserved, if possible.

int rl_on_new_line (void)
Tell the update functions that we have moved onto a new (empty) line,
usually after outputting a newline.
*/
void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
