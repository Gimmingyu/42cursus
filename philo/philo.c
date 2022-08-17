/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimmingyu <gimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:26:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/08/18 00:27:46 by gimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_finished(t_philo *philo)
{
	int	i;

	while (!philo->checker->finish)
	{
		if (philo->checker->cnt && \
			philo->checker->finished_eat_cnt == philo->condition->number_of_philos)
		{
			philo->checker->finish = TRUE;
			break ;
		}
		i = -1;
		while (++i < philo->condition->number_of_philos)
		{
			if (get_time() - philo[i].checker->eat_time \
				>= philo->condition->time_to_die)
				{
					print_status(DIED);
					philo->checker->finish = TRUE;
					break ;
				}
			usleep(100);
		}
		usleep(100);
	}
}

void	process(t_philo *philo)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (++i < philo->condition->number_of_philos)
	{
		res = pthread_create(&philo[i].p_thread, NULL, NULL, &philo[i]);
		if (res)
			exit_error("phread create error\n");
		usleep(100);
	}
	is_finished(philo);
	i = -1;
	while (++i < philo->condition->number_of_philos)
		pthread_join(philo[i].p_thread, NULL);
}

int	main(int ac, char **av)
{
	t_condition	*condition;
	t_checker	*checker;
	t_philo		*philo;

	condition = validator(ac, av);
	checker = init_checker();
	philo = init_philo(condition, checker);
	process(philo);
	return (0);
}

처음에 validator에서 예외처리 다 해주고, 
들어온 인자로 condition이라는 구조체를 만든다.
그리고 init_checker 함수로 checker 구조체를 만든다.
checker 구조체는 시작시간과 다 먹는 시간, 끝났는지 여부와 
몇 번 식사했는지 + 몇 번 완료했는지의 카운트를 들고 있는다.

phil 객체는 condition과 checker를 포함하는 구조체이며,
p_thread를 멤버 변수로 가진다. 
thread_id또한 가지고 있고, 왼쪽과 오른쪽의 아이디도 저장한다.

이 구조체들을 통해 process를 진행한다. 
처음 프로세스를 진행하면 철학자의 수 만큼 진행하면서 
스레드를 새로 만든다. 
