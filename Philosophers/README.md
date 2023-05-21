Philosophers
============
[subject.pdf](./en.subject.pdf)   
식사하는 철학자 문제   
철학자들을 각각의 쓰레드 혹은 프로세스로 생성한다   
철학자의 수와 식기(자원)의 수는 동일하다   
철학자가 먹을 때 식기는 2개가 필요하다   
철학자들은 이하의 상태 중 하나를 따른다   
1. 식기을 잡는다(점유한다)   
2. 일정 시간동안 먹는다   
3. 일정 시간동안 잔다   
4. 일어나면 식기를 잡기 전까지 생각한다
5. 일정 시간동안 먹지 못하면 죽는다   
   
철학자들의 상태가 변할 때마다 상황을 출력해줘야한다   
죽은 철학자가 발생할 경우 다른 모든 철학자들은 출력을 멈추고 프로그램 종료   
철학자끼리는 서로의 상황을 알아서는 안 된다   

추가 인자로 number_of_times_each_philosopher_must_eat 가 들어올 수 있다   
>  이 경우 모든 철학자가 이 값만큼 먹은 경우 프로그램을 종료한다.   
   
./philo_N number_philosopher time_to_die time_to_eat time_to_sleep \[number_of_times_each_philosopher_must_eat\]   
   
공통적인 구현방식
------
   
#main   
>  인자가 유효한지 검사   
>  각종 초기화   
>  thread.c 혹은 fork.c에 구현된 start_philo 함수 호출   
   
#start_philo
>  must_eat 이 존재하는 경우 모든 철학자의 먹은 횟수를 감시하는 mornitor_eat 준비한다   
>  각 철학자(routine)를 준비한다   
>  철학자가 자는 도중에 스스로를 감시할 수 없기에 각 철학자를 감시하는 각각의 mornitor를 준비한다   
   
   
[philo_one](./philo_one)
---------
철학자 사이에 식기가 하나씩 존재   
thread(pthread)와 mutex로 구현   
   
[philo_two](./philo_two)
---------
식기는 공용으로 존재   
thread(pthread)와 semaphore로 구현   
   
[philo_three](./philo_three)
---------
process로 구현하기에 공유 자원을 semaphore로 변형해준 부분 존재   
process(fork)와 semaphore로 구현   
   
