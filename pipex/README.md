# Pipex

사용 가능 함수

```
◦ open
◦ close
◦ read
◦ write
◦ malloc
◦ free
◦ dup2
◦ execve
◦ fork
◦ perror
◦ strerror
◦ exit
```

---

### dup, dup2

dup, dup2는 파일 서술자(fd) 복제 함수이다.

duplicate를 떠올리면 이해가 쉽다.

```c
#include <unistd.h>

int	dup(int fd);
int	dup2(int fd, int fd2);

```

dup은 전달받은 fd 값을 가장 낮은 fd로 복제하여 반환한다.

성공 시 새 fd, 실패시 -1을 반환한다.

dup2는 새 fd2의 값을 fd로 지정한다. 만일 fd2가 열려 있으면 fd2를 닫은 후 복제한다.

역시 성공시 fd, 실패시 -1 반환.

---

### execve

[<참고 출처 링크>](https://www.it-note.kr/157)

execve 함수는 filename의 실행코드를 현재 프로세스에 적재하고 기존 실행코드와 교체하여 새로운 기능으로 실행한다.  
즉, 현재 실행되는 프로그램의 기능은 없어지고 filename 프로그램을 메모리에 loading하여 처음부터 실행한다.

```c
#include <unistd.h>

int	execve(const char *path, char *const argv[], char *const envp[]);

// example...
char *argv[]   = { "./show_envp", "HTTP", NULL};
char *envp[]   = { "HTTP=badayak.com", NULL};

execve( "./show_envp", argv, envp);
```

path는 디렉토리 포함 전체 파일명, argv는 \*argv 인수목록, envp는 환경 설정 목록이다.

execve를 호출하면 일어나는 프로세스의 변화는 다음과 같다.

```
- signal 설정이 default로 변경.
- mmap(2)으로 생성 memory mapping이 보존되지 않는다.
- shared memory 영역에 대한 access가 해제된다.
- message queue descriptor가 close된다.
- named semaphore가 close된다.
- timer가 보존되지 않는다.
- opendir로 open된 directory stream이 close된다.
- memory lock이 보존되지 않는다.
- atexit(3), on_exit(3)로 등록된 exit handler가 해제된다.
- 모든 thread가 사라진다.
- aio_read(3)/aio_write(3)과 같은 async I/O 동작이 취소된다.
- 일반 file descriptor는 close되지 않는다.
```

#### memory map: 메모리의 내용을 파일이나 디바이스에 대응하기 위해서 사용하는 시스템 호출.

각각의 프로세스는 프로세스마다 다른 프로세스와 중복되지 않는 주소 공간을 가지게 된다.

프로세스 메모리는 기본적으로 다른 프로세스와 메모리와 공유되지 않는다.

이것은 프로세스의 데이터를 보호하기 위해서 반드시 필요한 기능이긴 하지만

다른 프로세스와 특정 데이터를 공유하기 위해서는 귀찮은 기능이 되기도 한다.

이 때문에 IPC를 사용하게 된다. mmap은 메모리의 특정 영역을 파일로 대응시킬수 있도록 도와준다.

파일을 시스템 전역적인 객체이므로 다른 프로세스에서 접근가능하도록 할 수 있으며,

이러한 mmap의 특징때문에 IPC 용도로 사용가능하다.

---

### fork

현재 실행되는 프로세스의 복사본 프로세스를 생성한다.

```c
#include <unistd.h>

pid_t	fork(void);
```

fork 함수를 실행하는 프로세스가 부모 프로세스가 되고, 새롭게 생성되는 프로세스는 자식 프로세스가 된다.

자식 프로세스는 부모 프로세스의 메모리를 그대로 복사해서 받게 된다.

fork 호출 이후 코드부터는 각자의 메모리를 사용해서 실행된다.

fork 함수 성공시, 부모 프로세스는 자식 프로세스의 pid값을 반환받는다.

자식 프로세스에서는 0을 반환받고, 실패시 -1을 반환받는다.

---

### pipe

프로세스는 메모리가 독립적으로 존재하기 때문에, 메모리를 프로세스간 통신을 하는 것은 불가능하다.

fork()를 이용하여 server 혹은 client 에서 생성된 프로세스들은 프로그램 내에서 프로세스끼리

데이터를 주고받을 방법이 없다는 뜻인데, 이에 대한 해결책이 pipe이다.

하나의 파이프에 대한 두 개의 fd를 생성하고, 이를 프로세스들이 공유하게 한다.

fd[0]: 함수 호출 후 fd[0]에 데이터를 입력 받을 수 있는 fd가 담긴다.(pipe 출구)
fd[1]: 함수 호출 후 데이터를 출력할 수 있는 fd가 담긴다. (pipe 입구)

```c
#include <unistd.h>

int	pipe(int fd[2]);
```

성공시 0, 실패시 -1

---

### unlink

```c
#include <unistd.h>

int	unlink(const char *pathname);
```

파일을 삭제하는 system call 함수이다. 정확하게는 unlink는 hard link의 이름을 삭제하고

hard link가 참조하는 count를 1 감소시킨다.

hard link의 참조 count가 0이 되면, 실제 파일의 내용이 저장되어 있는 disk space를 free하여

OS가 다른 파일을 위해서 사용할 수 있도록 한다.

따라서 hard link를 생성하지 않은 파일은 바로 disk space를 해제하여 사실상 파일 삭제한다.

그러나 open(2)으로 파일이 열려진 상태에서 unlink(2)를 호출하여

hard link 참조 count가 0이 되어도 directory entry에서 파일 이름 등의 정보는 삭제되지만

disk space는 해제되지 않는다.

OS는 hard link 참조 count가 0이고 file open 참조 count가 0일 때에

파일의 내용이 저장된 disk space를 해제한다.

---

### wait, waitpid

[<참고 출처 링크>](https://codetravel.tistory.com/30)

```c
#include <sys/wait.h>

pid_t	wait(int *statloc);
```

성공시 pid 반환, 실패시 -1 반환.

fork() 함수가 실행되고, 리턴값을 받는 순간부터 2개의 프로세스가 동작을 하게 된다.

부모 프로세스 입장에서는 자식 프로세스가 살아있는지 없는지 알 수 있는 방법이 없으므로

커널에서 시그널을 통해 부모 프로세스에게 알려준다.

즉, 부모 프로세스가 자식 프로세스의 종료 상태를 얻고싶을 때 wait()함수를 사용한다.

wait() 함수는 아래와 같이 동작한다.

1. 자식 프로세스가 동작 중이면 호출 차단이 차단되기 때문에 상태를 얻어올 때까지 대기

2. wait() 함수 호출자가 시그널을 받을 때까지 대기

3. 자식 프로세스가 종료된 상태라면 즉시 호출이 반환되어 상태를 얻음, 이 때 wait() 함수는 자식 프로세스의 프로세스 ID를 반환

4. 자식 프로세스가 없다면 호출이 즉시 반환되며, 에러값을 반환

특이사항으로는 자식 프로세스가 여러 개일 경우 하나라도 종료되면 리턴을 받아오며,

자식프로세스의 종료 상태를 statloc에 담는다.

```c
#include <sys/wait.h>

pit_t	waitpid(pid_t pid, int *stat_loc, int options);
```

waitpid 함수는 wait 함수처럼 자식 프로세스를 기다릴 때 사용한다.

하지만 waitpid는 자식 프로세스가 종료될 때 까지 차단되는 것을 원하지 않을 경우 옵션을 사용하여 차단을 방지할 수 있다.

또한 기다릴 자식 프로세스를 지정이 가능하다.

wait은 하나의 자식 프로세스가 종료되면 바로 리턴을 받아왔으나, waitpid는 지정이 가능하다는 점이 가장 큰 차이점이다.

pid 인자를 통해서 기다릴 자식 프로세스를 지정할 수 있는데, 상세하게는 다음과 같다.

---

#### pid_t pid

> pid == -1

임의의 자식 프로세스 기다림.

> pid == 0

waitpid를 호출한 프로세스의 그룹 pid와 같은 프로세스 그룹 id를 가진 프로세스를 기다림.

> pid < -1

프로세스 그룹 id가 pid의 절댓값과 같은 자식 프로세스를 기다림.

> pid > 0

프로세스 id가 pid인 자식 프로세스를 기다림.

#### waitpid 함수의 오류(-1)은 지정한 pid의 프로세스 또는 프로세스 그룹이 없는 경우에 발생하며,

#### pid가 자식 프로세스가 아닐 때 발생한다.

---

#### int \*stat_loc

> 자식 프로세스가 정상적으로 종료

return : 프로세스 id

statloc : 하위 8비트를 참조하여 자식 프로세스 exit에 넘겨준 인자값을 얻을 수 있다.

> 자식 프로세스가 비정상적으로 종료

return : 프로세스 id

statloc : 비정상 종료 이유를 WTERMSIG 매크로를 사용하여 구할 수 있다.  
\*\* WIFSIGNALED(statloc) 매크로가 true를 반환.

> waitpid 함수 오류

return : -1

statloc

1. ECHILD : 호출자의 자식 프로세스가 없는 경우.
2. EINTR : 시스템 콜이 인터럽트 되었을 때.

---

#### int options

options로 사용가능한 상수

1. WCONTINUED : 중단되었다가 재개된 자식 프로세스의 상태를 받음
2. WNOHANG :

기다리는 PID가 종료되지 않아서 즉시 종료 상태를 회수 할 수 없는 상황에서 호출자는 차단되지 않고 반환값 0을 받음.

3. WUNTRACED : 중단된 자식 프로세스의 상태를 받음.

---

```c

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	int		stat_loc;
	pid_t	pid;
	pid_t	child_pid;

	pid = fork();
	if (pid == -1)
		response_error("Error\n", 1);
	if (pipe(fd) == -1)
		response_error("Error\n", 1);
	if (pid == 0)
	{
		printf("I am child process\n");
		printf("In child process, pid is %d\n", pid);
		for (int i = 0; i < 10; i++)
			printf("child, %d\n", i);
	}
	else if (pid == -1)
		printf("fork error\n");
	else
	{
		child_pid = wait(&stat_loc);
		printf("I am parent process\n");
		printf("In parent process, pid is %d\n", pid);
		printf("Executed child process id is %d\n", child_pid);
		for (int i = 10; i < 20; i++)
			printf("parent, %d\n", i);
	}
	return (0);
}

```

---

```c
int	main(int ac, char **av, char **env)
{
	int		fd[2];
	int		stat_loc;
	pid_t	pid;
	pid_t	child_pid;

	pid = fork();
	if (pid == -1)
		response_error("Error\n", 1);
	if (pipe(fd) == -1)
		response_error("Error\n", 1);
	if (pid == 0)
	{
		printf("I am child process\n");
		printf("In child process, pid is %d\n", pid);
		for (int i = 0; i < 10; i++)
			printf("child, %d\n", i);
	}
	else if (pid == -1)
		printf("fork error\n");
	else
	{
		printf("I am parent process\n");
		printf("In parent process, pid is %d\n", pid);
		child_pid = waitpid(pid, &stat_loc, WCONTINUED);
		// child_pid = waitpid(pid, &stat_loc, WNOHANG);
		// child_pid = wait(&stat_loc);
		for (int i = 10; i < 20; i++)
			printf("parent, %d\n", i);
		printf("Executed child process id is %d\n", child_pid);
	}
	return (0);
}
```

### access

```c
#include <unistd.h>

int access(const char *pathname, int mode);
```

프로세스가 지정한 파일이 존재하는지, 읽거나 쓰거나 실행이 가능한 지 확인하는 함수.
만일 지정한 파일이 심볼릭 링크라면 링크의 원본을 체크한다.

#### Param

pathname : 파일이나 디렉토리 전체 이름

mode : 검사할 내용

\*\*mode로 들어갈 수 있는 mask 값

- R_OK : 파일 존재 여부, 읽기 권한 여부
- W_OK : 파일 존재 여부, 쓰기 권한 여부
- X_OK : 파일 존재 여부, 실행 권한 여부
- F_OK : 파일 존재 여부

#### Return

- 0 : 파일이 존재한다.
- -1: mode 에 대해 하나 이상 거절되었거나 에러가 있음

```c
int	main(int ac, char **av, char **env)
{
	char	*pathname = "./infile";
	int		mode = R_OK | W_OK;
	if (access(pathname, mode) == 0)
		printf("READ && WRITE POSSIBLE\n");
	else
		printf("READ || WRITE IMPOSSIBLE\n");
	return (0);
}
```
