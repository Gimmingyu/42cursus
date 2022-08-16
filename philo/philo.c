/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:26:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/16 16:31:21 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thr_fn(void *arg)
{
	pthread_mutex_t	mutex_lock;
	int				i;

	i = 0;
	// c.s 시작
	pthread_mutex_init(&mutex_lock, NULL);
	pthread_mutex_lock(&mutex_lock);
	while (i < 3)
	{
		printf("%s\n", arg);
		printf("i = %d\n", i);
		i++;
	}
	// c.s 끝
	pthread_mutex_unlock(&mutex_lock);
	return (NULL);
}

// 철학자의 수, 철학자의 수명, 밥을 먹는데 걸리는 시간, 밥을 먹어야하는 횟수
int	main(int ac, char **av)
{
	int				status;
	pthread_t		*thread1 = malloc(sizeof(pthread_t));
	pthread_t		*thread2 = malloc(sizeof(pthread_t));
	pthread_mutex_t	mutex_lock;
	t_timeset		*set;

	set = validator(ac, av);
	// mutex 초기화, NULL을 주면 기본 옵션
	// 스레드를 만듬 ...
	pthread_create(thread1, NULL, thr_fn, "Thread1 : ");
	pthread_create(thread2, NULL, thr_fn, "Thread2 : ");
	pthread_join(*thread1, (void *)&status);
	pthread_join(*thread2, (void *)&status);
	free(set);
	return (0);
}
