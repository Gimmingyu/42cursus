/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:31:23 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/26 17:55:56 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		philo->checker->is_finished = TRUE;
		exit_error("Fork error");
	}
	if (pid)
	{
		waitpid(pid, NULL, WNOHANG);
	}
	else
	{
		philo->checker->is_finished = TRUE;
		philo->checker->start_at = 9999;
		printf("philo id = %d\n", philo->checker->id);
		printf("pointer of philo = %p\n", philo);
	}
}

// void	philo_sleep(t_philo *philo)
// {
// 	;
// }

// void	philo_think(t_philo *philo)
// {
// 	;
// }

/**
 * 메인 프로세스에서 철학자의 수 만큼 스레드 생성.
 * 각 스레드에서 fork() 실행 -> (n번째 스레드)부모 프로세스와 그 자식 프로세스로 나뉨.
 * 각 부모 프로세스에서 식사를 하고 자식 프로세스에서 검사..?
 * 부모 프로세스(각 스레드)끼리는 상태 공유 가능
 * 자식 프로세스끼리는 상태 공유가 불가능. 누가 포크를 집고 있는지 아닌지 어떻게 알게 할 것인가?
 * 포크를 두 개 집었다면 fork()하고 식사-수면, 정상적으로 끝나면 프로세스 종료하면서 세마포어 두 개 늘려줌
 * 
*/