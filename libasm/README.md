libasm
============
[subject.pdf](./en.subject.pdf)   
특정 함수들을 어셈블리어로 재구현   
>  64bit 어셈블리어 작성   
>  호출 규약을 따를것   
>  Intel syntex   
>  nasm 을 이용해서 어셈블   
   
구현 목록
-------
>  ft_strlen   
>  ft_strcpy   
>  ft_strcmp   
>  ft_write   
>  ft_read   
>  ft_strdup
>  >  malloc 사용 가능   
   
보너스 함수들
----------
```c
typedef struct  s_list
{
    void            *data;
    struct s_list   *next;
}               t_list;
```
리스트 사용시 위 구조체를 기준으로 구현할것    
>  ft_atoi_base (like the one in piscine)
>  >  int ft_atoi_base(char \*str, char \*base)
>  >  "0123456789"가 아닌 base 기준으로 atoi 하는 함수   
>  >  base 제약
>  >  >  길이 2이상   
>  >  >  +, -, ' ' 불가    
>  >  >  중복문자 불가   
>  
>  ft_list_push_front (like the one in piscine)
>  >  void ft_list_push_front(t_list \*\*begin_list, void \*data)   
>  >  새 t_list를 할당하여   
>  >  data를 연결시키고   
>  >  next에 begin_list 가 가리키는 t_list 포인터 연결   
>  >  begin_list가 할당된 t_list 주소 가리키도록 연결   
>  
>  ft_list_size (like the one in piscine)
>  >  int ft_list_size(t_list \*begin_list)   
>  >  begin_list 부터의 요소의 개수를 반환   
>  >  data를 연결시키고   
>  >  next에 begin_list 가 가리키는 t_list 포인터 연결   
>  >  begin_list가 할당된 t_list 주소 가리키도록 연결   
>  
>  ft_list_sort (like the one in piscine)
>  >  void ft_list_sort(t_list \*\*begin_list, int (\*cmp)())
>  >  cmp 함수를 이용하여 begin_list 정렬   
>  
>  ft_list_remove_if (like the one in piscine)
>  >  void ft_list_remove_if(t_list \*\*begin_list, void \*data_ref, int (\*cmp)(), void (\*free_fct)(void \*))   
>  >  begin_list부터 시작하는 모든 요소를 data_ref와 cmp로 비교
>  >  비교 결과 0이 나오는 요소를 지운다   
>  >  요소를 지울 때 그 요소의 데이터는 free_fct으로 지워야 한다   
