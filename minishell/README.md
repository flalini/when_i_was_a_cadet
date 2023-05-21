minishell
=========
shell 만들어보기   
[subject.pdf](./en.subject.pdf)

필요기능   

커맨드   
echo (with option -n)   
cd (with only relative or absolute path)   
pwd   
export   
unset   
env (without any options and any arguments)   
exit   
   
'', "", 리다이렉션, |, 환경변수, ctrl-C, ctrl-D, ctrl-\   
   
srcs
-----------
프로그램 시작, 초기화, 메인 루프, 커맨드 실행을 담당하는 main.c를 제외한 모든 파일은 각 서브 디렉토리로   

## main.c
>	main   
>	입출력 검사 후 t_minishell 초기화   
   
>	wait_for_command   
>	shell의 메인   
>	signal 처리 후   
>	입력 받아서 parsing   
>	커맨드 실행   
   
>	exec_commands   
>	파싱 된 커맨드 토큰들 처리   
>	   
>	반복문으로 토큰들이 전부 처리 될 때까지 진행   
>	인자 전처리는 utils/command_process* 에서   
>	리다이렉션은 utils/redirect.c 에서   
>	파이프 처리 하고   
>	지정된 커맨드이면 commands에 구현된 함수들로   
>	아니면 해당 커맨드를 utils/exec에 구현된 함수로   
   
## commands
>	필요 커맨드들 구현   
   
## parsing
>	커맨드 파싱   
   
## env
>	환경변수 처리를 위한 함수들 구현   
   
## utils   
>	그 이외의 각종 구현   
