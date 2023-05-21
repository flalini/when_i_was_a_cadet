/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:06:14 by ijang             #+#    #+#             */
/*   Updated: 2021/03/09 19:33:42 by ijang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

# define ERR1 0
# define ERR2 1
# define ERR3 2
# define ERR4 3
# define ERR5 4
# define ERR6 5
# define ERR7 6
# define ERR8 7

# define ERRMESSAGE1 "There must be 5 or 6 arguments.\n"
# define ERRMESSAGE2 "The arguments must consist only of numbers.\n"
# define ERRMESSAGE3 "This program can only handle the number of "
# define ERRMESSAGE4 "\"unsigned int types of ranges\".\n"
# define ERRMESSAGE5 "There must be at least two philosophers.\n"
# define ERRMESSAGE6 "I can't handle this number in my ability.\n"
# define ERRMESSAGE7 "Allocation fail!\n"
# define ERRMESSAGE8 "pthread_create fail!\n"
# define ERRMESSAGE9 "semaphore init fail!\n"

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

# define SEMNAMEF "mysemfork"
# define SEMNAMEW "mysemwrite"
# define SEMNAMEE "mysemeat"

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
	sem_t			*write_s;
	unsigned int	**monitor_eat;
	uint64_t		start_time;
}				t_condition;

typedef struct	s_philosopher
{
	int				start;
	int				num;
	uint64_t		last_eat;
	sem_t			*fork_s;
	unsigned int	eat_count;
	int				alive;
	t_condition		*con;
	pthread_t		routine_ph;
	sem_t			*eat_s;
	int				lock;
}				t_philosopher;

typedef struct	s_sems
{
	sem_t			*fork_s;
	sem_t			*write_s;
	sem_t			**eat_s;
}				t_sems;

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
int				alloc_all(t_philosopher **philos, t_sems *sems,
					t_condition *con);
int				init_condition(t_condition *con, int argc, char **argv);

/*
** UTILS
*/
void			clear_all(t_philosopher *p, t_condition *c,
					t_sems *m);
int				err_check(int *error, int result);
void			*fl_malloc(void **to_malloc, size_t size, size_t len);
uint64_t		get_time(void);
void			ft_usleep(uint64_t millis);
size_t			ft_strlen(char *str);
int				put_error(int i);
void			put_dead(t_condition *con, unsigned int num);
void			put_message(t_condition *con, unsigned int philo, int type);
int				ft_sem_open(sem_t **sem, char *name, int value);
int				free_err(void *to_free);
char			*ft_strcpy(char *dst, char *src);
char			*make_sem_name(char *name, int num);

#endif
