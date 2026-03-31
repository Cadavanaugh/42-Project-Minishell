/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universal_helpers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:15:37 by jode-cas          #+#    #+#             */
/*   Updated: 2026/03/31 11:54:42 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	array_length(char **array)
{
	int	counter;

	counter = 0;
	while (array[counter])
	{
		counter++;
		if (array[counter] == NULL)
			break ;
	}
	return (counter);
}

void	display_error(char *str, const char *error_msg)
{
	char	*result;

	result = ft_strjoin(str, error_msg);
	ft_putstr_fd(result, 2);
	free(result);
}

char	is_dir(const char *path, t_ms *shell)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
	{
		if (errno == ENOENT)
			shell->last_status = 127;
		else if (errno == EACCES)
			shell->last_status = 126;
		return (0);
	}
	if (S_ISDIR(path_stat.st_mode))
	{
		return (1);
	}
	else
		return (0);
}

void	builtin_pwd(t_ms *shell)
{
	char	cwd[PATH_MAX];
	char	*cwd_ptr;

	cwd_ptr = getcwd(cwd, sizeof(cwd));
	if (!cwd_ptr)
	{
		perror("minishell: pwd");
		shell->last_status = 1;
	}
	else
	{
		printf("%s\n", cwd_ptr);
		shell->last_status = 0;
	}
}

char	**deep_copy(char **matrix)
{
	char	**copy;
	int		i;

	if (!matrix)
		return (NULL);
	i = 0;
	while (matrix[i])
		i++;
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		copy[i] = ft_strdup(matrix[i]);
		if (!copy[i])
		{
			free_matrix(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
