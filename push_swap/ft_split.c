/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:27:21 by mpalacin          #+#    #+#             */
/*   Updated: 2024/03/12 12:29:06 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countwords(char const *s, char c)
{
	size_t	i;
	int		ocurrence;
	int		count;

	i = 0;
	ocurrence = 1;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c && ocurrence == 1)
		{
			ocurrence = 0;
			count++;
		}
		else if (s[i] == c)
			ocurrence = 1;
		i++;
	}
	return (count);
}

void	ft_freesplit(char **split, int j)
{
	int	k;

	k = 0;
	while (k < j)
	{
		free(split[k]);
		k++;
	}
	free(split);
}

int	ft_mallocsplit(char **split, const char *word, int len, int *j)
{
	int	i;

	i = 0;
	split[*j] = malloc((len + 1) * sizeof(char));
	if (!split[*j])
	{
		ft_freesplit(split, *j);
		return (0);
	}
	while (i < len)
	{
		split[*j][i] = word[i];
		i++;
	}
	split[*j][i] = '\0';
	*j += 1;
	return (1);
}

char	**ft_aux(char **split, char const *s, int c)
{
	size_t	i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || s[i] == '\0') && start >= 0)
		{
			if (ft_mallocsplit(split, s + start, i - start, &j) == 0)
				return (NULL);
			start = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_aux(split, s, c));
}
