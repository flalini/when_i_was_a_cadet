ft_containers
=========
containers 일부 만들어보기   
[subject.pdf](./en.subject.pdf)
   
https://cplusplus.com/reference/stl/   
레퍼런스 기준 C++98 기준 함수와 오버로드들 전부 동작하도록 구현   
get_allocator는 예외   
namespace는 ft로 통일   

List   
Vector  
Map   
Stack   
Queue     
   
List
-----------

## ListIterator, ReverseListIterator, ConstListIterator, ConstReverseListIterator
> utils에 선언된 양방향 링크드리스트인 Node를 이용하여 Iterator 구현

## List
> Node타입 멤버변수 \_first \_last 를 만들어어둠   
> 추가, 초기화, 정리를 위한 맴버 함수를 만들어둠   
> 필요한 함수들 구현   
   
## Queue, Stack
> List를 이용해 구현   
   
## Vector
> ListIterator와는 오버로드가 동일하지 않은 부분이 존재하여 Iterator부터 다시 만들게 됨   
   
## Tree
> Map을 위한 이진트리   
   
## Map
> Key와 Value가 존재하고 Compare 또한 존재해야하기에 Tree를 이용해 새로 만들게 됨    
