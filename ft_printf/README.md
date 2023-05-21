ft_printf
=========
[subject.pdf](./en.subject.pdf)   
printf 구현해보는 프로젝트   
사용 언어: C
   
ft_printf.h
-----------
사용된 헤더, 구조체, 함수, 매크로 선언.   
   
#t_form 구조체
>	va_list	va_para   
>	가변인자   
   
>	int		result   
>	return 할 출력 기록   
   
>	int		width;   
>	int		precision;   
>	char	specifier;   
>	char	hhll;   
>	char	ladjust;   
>	char	sign;   
>	char	*padc;   
>	char	hash_flag;   
>	%를 만난 이후 나오는 flag, 길이, pad, 서식자 등 저장   
   
>	size_t	pre_width;   
>	size_t	put_width;   
>	padding 출력, 실제 출력 등의 계산용.   

#t_fraction 구조체   
부동소수처리를 위한 구조체   
>	char		sign;   
   
>	int			exp;   
>	지수   
   
>	int			man_len;   
>	계산 중인 혹은 계산 끝난 가수 길이   
   
>	char		man[DOUBLE_FRAC_MAN_SIZE];   
>	가수 (계산 도중 2진수에서 10진수로 변경)   
>  big integer 방식
   
srcs
----
   
#ft_printf   
>	가변인자 처리 후 문자열 출력하다가 %를 만나는 경우 ft_sub_printf 호출   
   
#ft_sub_printf   
>	flag, width, precision, 자료 size 순서대로 처리해서 t_form에 저장   
>	이후 서식문자에 따라 ft_display_* 호출
   
#ft_display_*   
>  각 서식문자에 맞게 t_form에 따라 동작
   
#ft_dtof
>  t_fraction으로 부동소수 double을 출력할 수 있는 10진 부동소수로 변형
