/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:27:26 by ijang             #+#    #+#             */
/*   Updated: 2021/03/10 19:11:15 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define ERRMESSAGE1 "There must be 5 or 6 arguments.\n"
# define ERRMESSAGE2 "The arguments must consist only of numbers.\n"
# define ERRMESSAGE3 "This program can only handle the number of "
# define ERRMESSAGE4 "\"unsigned int types of ranges\".\n"
# define ERRMESSAGE5 "There must be at least two philosophers.\n"
# define ERRMESSAGE6 "I can't handle this number in my ability.\n"
# define ERRMESSAGE7 "Allocation fail!\n"
# define ERRMESSAGE8 "pthread_create fail!\n"

# define TYPEF 0
# define TYPEE 1
# define TYPES 2
# define TYPET 3
# define TYPED 4

# define STATEMESSAGEF " has taken a fork\n"
# define STATEMESSAGEE " is eating\n"
# define STATEMESSAGES " is sleeping\n"
# define STATEMESSAGET " is thinking\n"
# define STATEMESSAGED " died\n"

typedef struct	s_condition
{
	unsigned int	philo_num;
	uint64_t		to_die;
	uint64_t		to_eat;
	uint64_t		to_sleep;
	unsigned int	must_eat;
	int				end_process;
	pthread_t		monitor_e_ph;
	pthread_t		*monitor_ph;
	pthread_mutex_t	*write_m;
	unsigned int	**monitor_eat;
	uint64_t		start_time;
}				t_condition;

typedef struct	s_philosopher
{
	int				start;
	int				num;
	uint64_t		last_eat;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*last_fork;
	unsigned int	eat_count;
	int				alive;
	t_condition		*con;
	pthread_t		routine_ph;
	pthread_mutex_t	eat_m;
	int				lock;
}				t_philosopher;

typedef struct	s_mutexes
{
	pthread_mutex_t	*fork_m;
	pthread_mutex_t	write_m;
}				t_mutexes;

/*
** THREAD
*/
void			routine(t_philosopher *philo);
void			monitor_eat(t_condition *con);
void			monitor(t_philosopher *philo);
int				start_philo(t_philosopher *philos, t_condition *con);

/*
** INIT
*/
int				alloc_all(t_philosopher **philos, t_mutexes *mutexes,
				t_condition *con);
int				init_condition(t_condition *con, int argc, char **argv);

/*
** UTILS
*/
void			clear_all(t_philosopher *p, t_condition *c,
				t_mutexes *m);
int				err_check(int *error, int result);
void			*fl_malloc(void **to_malloc, size_t size, size_t len);
uint64_t		get_time(void);
void			ft_usleep(uint64_t millis);
size_t			ft_strlen(char *str);
int				put_error(int i);
void			put_dead(t_condition *con, unsigned int num);
void			put_message(t_condition *con, unsigned int philo, int type);

#endif
