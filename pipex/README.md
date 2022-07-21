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

dup2는 새 fd의 값을 fd2로 지정한다. 만일 fd2가 열려 있으면 fd2를 닫은 후 복제한다.

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

---
