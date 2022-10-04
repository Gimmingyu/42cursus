# Philosophers

<br />

## Necessary Concept

<br />

### Process

<br />

프로세스란 단순히 실행 중인 프로그램이라고 생각할 수 있다.

사용자가 작성한 프로그램이 OS에 의해 메모리를 할당받아 실행중인 상태가 되면 이것을 프로세스라고 한다.

프로세스는 프로그램에 사용되는 데이터와 메모리 등의 자원, 그리고 스레드로 구성된다.

<br />

### Thread

<br />

스레드란 프로세스 내에서 실제로 작업을 수행하는 주체를 의미한다.

모든 프로세스에는 한 개 이상의 스레드가 존재하여 작업을 수행한다.

또한, 두 개 이상의 스레드를 가지는 프로세스를 멀티스레드 프로세스라고 한다.

CPU 점유의 기본 단위이며, 스레드 간에는 코드, 데이터 파일을 공유한다.

분류를 크게 다음과 같이 나눌 수 있다.

---

### Kernel Level Thread : 커널 내에 있는 스레드를 의미.

<br />

커널 스레드는 `가장 가벼운 커널 스케줄링 단위`이다.

하나의 프로세스는 적어도 하나의 커널 스레드를 가지게 된다.

커널 영역에서 스레드 연산을 수행하게 된다.

커널이 스레드를 관리하기 때문에 커널에 종속적이다.

프로그래머 요청에 따라 스레드를 생성하고 `스케줄링하는 주체가 커널`이면 커널 레벨 스레드라고 한다.

프로세스의 스레드들을 몇몇 프로세서에 한꺼번에 디스패치 할 수 있기 때문에 멀티 프로레서 환경에서 매우 빠르게 동작한다.

스레드 별 I/O 작업이 끝날 때 까지 다른 스레드를 사용해 다른 작업을 진행할 수 있다.

커널이 각 스레드를 개별적으로 관리할 수도 있고, 커널 제공이라 안정적이다.

그러나 스케줄링과 동기화를 위해 `커널을 호출하는데 무겁고 오래걸린다.`

또한 사용자 모드에서 커널 모드로의 전환이 빈번하게 이뤄지면 성능 저하가 발생할 수 밖에 없고,

자원을 더 많이 소비하는 경향이 있다.

<br />

---

### User Level Thread : #include <thread> 혹은 import를 통해 스레드를 이용하는 것을 의미

<br />

사용자 영역에서 스레드 연산을 수행하고, 그 때문에 운영체제에 투명하다.

스레드의 기능을 제공하는 라이브러리를 활용하는 방식이다.

운영체제에서 스레드를 지원할 필요도 없고, 스케줄링 결정이나 동기화를 위해 커널을 호출하지 않기 때문에

인터럽트가 발생할 때 커널 레벨 스레드보다 오버헤드가 적다.

사용자 영역 스레드에서 행동을 하기 때문에 컨텍스트 스위칭이 없을 거라는 것을 알 수 있다.

커널은 사용자 레벨 스레드의 존재조차 모르기 때문에 성능이 좋을 수 밖에 없다.

단, 스레드 중 하나라도 IO 작업에서 블록이 걸리면 전체 스레드가 블록될 수 있다.

<br />

---

<br />

이 때, 커널 레벨 스레드는 다시 3가지 방법으로 나뉜다.

<br />

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F9959C13E5AE77BE92B14E6" />

<br />

#### a. Pure user-level

커널 스레드 1개당 사용자 스레드 n개로, 1:n 방식을 의미한다.

이 케이스의 경우, 커널은 사용자 스레드가 100개가 있어도 전혀 모르기 때문에 사용자 스레드에서 I/O가 하나라도 발생하면

해당 프로세스는 I/O가 풀릴 때 까지 영원히 block된다.

<br />

#### b. Pure Kernel-level

n개의 커널 스레드가 n개의 사용자 스레드를 담당하는 1:1 방식.

1:1 방식이기에 병렬성은 좋으나 효율성 면에서 다소 떨어진다고 한다.

<br />

#### c. Combined

커널 스레드와 사용자 스레드를 혼합하여 사용하는 방식이다.

위의 두 방식의 장점을 혼합한 방식이라고 생각할 수 있다.

<br />

---

### Mutex

<br />

프로세스 간 메세지를 전송하거나, 공유 메모리를 통해 공유된 자원에 여러 개의 프로세스가 동시에 접근하면 Critical Section문제가 발생할 수 있다.

이를 해결하기 위해 데이터를 한 번에 하나의 프로세스만 접근할 수 있도록 제한을 두는 동기화(Process Synchronization) 방식을 취해야한다.

동기화 도구로 대표적으로 뮤텍스와 세마포어가 있다.

뮤텍스는 공유된 자원의 데이터 혹은 임계 영역등에 하나의 Process 혹은 Thread 가 접근하는 것을 막아준다.

이는 동기화 대상이 하나라는 것을 뜻한다.

임계구역을 가진 스레드들의 실행시간(런타임)이 서로 겹치지 않고 각각 단독으로 실행(상호배제)되도록 하는 기술이다.

> Critical Section(임계구역) : 여러 프로세스가 데이터를 공유하며 수행될 때, 각 프로세스에서 공유 데이터를 접근하는 프로그램 코드 블록.

<br />

한 프로세스에 의해 소유될 수 있는 Key를 기반으로 한 상호배제 기법이고, Key에 대응되는 어떤 객체(Object)가 있으며,

이 객체를 소유한 스레드/프로세스만이 공유자원에 접근할 수 있다.

다중 프로세스들의 공유 리소스에 대한 접근을 조율하기 위해 동기화 또는 Lock을 사용함으로써 뮤텍스 객체를

두 스레드가 동시에 사용할 수 없게 된다.

<br />

---

### Multi Threading

<br />

일반적으로 하나의 프로세스는 하나의 스레드를 가지고 작업을 수행하게 된다.

멀티 스레드는 말 그대로 하나의 프로세스 내에서 둘 이상의 스레드가 동시에 작업을 수행하는 것을 의미한다.

멀티 프로세스와는 엄연히 다르고, 멀티 프로세스는 여러 개의 CPU를 사용하여 여러 프로세스를 동시에 수행하는 것을 의미한다.

멀티 프로세스는 각 프로세스가 독립적인 메모리를 가지고 별도로 실행되지만,

멀티 스레드는 각 스레드가 자신이 속한 프로세스의 메모리를 공유한다는 점이 다르다.

멀티 스레드는 각 스레드가 자신이 속한 프로세스의 메모리를 공유하므로, 시스템 자원의 낭비가 적다.

또한, 하나의 스레드가 작업을 할 때 다른 스레드가 별도의 작업을 할 수 있어서 사용자와의 응답성도 좋아진다.

<br />

<img src="https://user-images.githubusercontent.com/55486644/98101609-cf512100-1ed5-11eb-89b7-4b5c89751b6f.png" />

<br />

---

### Context Switching

<br />

컴퓨터에서 동시에 처리할 수 있는 최대 작업 수는 CPU의 코어 수와 같다.

만약 CPU 코어 수보다 더 많은 스레드가 실행되면, 각 코어가 정해진 시간 동안 여러 작업을 번갈아가며 수행하게 된다.

이 때 스레드가 교체될 때 스레드 간에 컨텍스트 스위칭이 일어난다.

현재까지의 작업 상태나 다음 작업에 필요한 각종 데이터를 저장하고 읽어오는 작업을 말한다.

당연히 컨텍스트 스위칭에 필요한 시간이 커지면 효율이 떨어지게 된다.

오히려 많은 양의 단순한 계산은 싱글 스레드로 동작하는 것이 더 효율적일 수 있다.

<br />

---

### Thread Group

<br />

스레드 그룹이란 서로 관련이 있는 스레드를 하나의 그룹으로 묶어 다루기 위한 장치이다.

스레드 그룹은 다른 스레드 그룹을 포함할 수도 있으며, 이렇게 포함된 스레드 그룹은 트리 형태로 연결된다.

이 때 스레드는 자신이 포함된 스레드 그룹이나 그 하위 그룹에는 접근할 수 있지만, 다른 그룹에는 접근할 수 없다.

이렇게 스레드 그룹은 접근할 수 있는 범위를 제한하는 보안상으로도 중요한 역할이 있다.

<br />

---

### Thread Pool

<br />

여러 개의 스레드를 pool에 저장해놓고 대기하여 필요할 때 마다 사용하는 것.

<br />

---

### Process Synchronization

공유 데이터에 두 개 이상의 프로세스가 동시에 접근하면 data inconsistency가 발생할 수 있다.

데이터의 consistency(일관성)을 유지하기 위한 메커니즘이 동기화이다.

즉, 실행 순서를 보장해야한다는 뜻이다.

생산자-소비자 예시를 보자. counter의 초기 값을 5라고 상정하자.

```c
// counter++ machine과 counter-- machine은 각각 atornically(원자적으로)하게 행해져야 한다.
while (true) {
    while (count == SOME_NUMBER)
        ;
    buffer[in] = next_produced;
    in = (in + 1) % SOME_NUMBER;
    count++;
}

while (true) {
    while (count == SOME_NUMBER)
        ;
    next_consumed = buffer[out];
    out = (out + 1) & BUFFER_SIZE;
    count--;
}

```

이 때 count가 5라는 가정을 하여 병행하게 실행하면 기대값인 6 대신 4, 5, 6이 된다.

```c
register1 = count // register1 = 5
register1 = register1 + 1 // count = 6, interrupt
count = register1 // resume, count = 6

register2 = count // register2 = 5
register2 = register2 -  1 // register2 = 4, interrupt
count = register2 // count = 4
```

count를 6으로 할당한 상황에서 컨텍스트 스위치가 일어나서 register2의 코드가 실행된다.

count가 4인 상황에서 다시 한 번 resume되어 count는 기대값인 5 대신 6으로 할당받게 된다.

위와 같은 상황이 바로 `경쟁 상황`이다. 이렇듯 data inconsistency가 발생할 수 있는 문제들을

`임계구역 문제(The Critical-Section Problem)`라고 말하는데,

이를 해결하기 위한 3가지 요구 조건이 있다.

1. 상호 배제 : 한 프로세스가 c.s에 들어오면 다른 프로세스는 c.s에 들어가면 안된다.
2. 진행 : c.s에서 실행되는 프로세스가 없는 상황에서 c.s에 들어가고 싶어하는 녀석이 있다면, 그 프로세스가 무한정 기다리게 해서는 안된다.
3. 한정된 대기 : 비록 (1)에서 밀린 어떤 프로세스가 밀렸다 할지라도, 언젠가는 그 경쟁에서 이겨서 들어갈 수 있도록 보장해야 한다.

<br />

---

### CPU Scheduler

<br />

멀티프로그래밍의 목적은 CPU 이용률을 최대화하는 것이다.

CPU 스케줄러는 CPU가 유휴상태가 될 때마다 Ready Queue에 있는 프로세스를 하나 선택한다.

선택 절차는 스케줄러에 의해 선택된다.

일반적으로 스케줄링은 다음과 같은 때에 일어난다.

1. Running → Waiting 상태 : ( ex. I/O 요청, 자식프로세스 종료 - wait() 요청을 통해 종료 )
2. Running → Terminate 상태 : ( ex. 부모프로세스의 종료 )
3. Running → Ready 상태 : ( ex. 인터럽트 발생 )
4. Waiting → Ready 상태 : ( ex. I/O 완료 )

스케줄링에는 비선점/선점 스케줄링이 있다.

<br />

---

#### 비선점 스케줄링

<br />

Time-slice가 없는 스케줄링
CPU를 사용중인 프로세스가 자율적으로 반납하도록 하는 형식
따라서 프로세스가 자율적으로 CPU를 반납하는 시점에서 사용한다.

<br />

<img src="https://t1.daumcdn.net/cfile/tistory/998E6C405C7AC10302" />

<br />

---

#### 선점 스케줄링

<br />

낮은 우선순위를 가진 프로세스보다 높은 우선순위를 가진 프로세스가 CPU를 선점하는 방식
OS가 스케줄링의 알고리즘에 따라 적당한 프로세스에게 CPU를 할당하고, 필요시에는 회수하는 방식
일반적으로 3, 4번 시점에서 사용하지만, 상황에 따라 1, 2에서도 스케줄링이 가능하다.

<br />

<img src="https://t1.daumcdn.net/cfile/tistory/993815445C7AC10303" />

<br />

일반적인 시스템에서 CPU 스케줄링 알고리즘의 목적은 다음과 같다.

1. No starvation : 각각의 프로세스들이 오랜 시간동안 CPU를 할당받지 못하는 상황이 없도록 한다.
2. Fairness : 각각의 프로세스에 공평하게 CPU를 할당해준다.
3. Balance : Keeping all parts of the system busy

<br />

---

## Allowed Functions

<br />

### pthread_create

<br />

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(start_routine)(void *), void *arg);
```

<br />

스레드는 프로세스 내에서 고유한 스레드 id로 구분하게 되는데, 이 스레드 id를 나타내는 데이터 아입이 `pthread_t`이다. 

`pthread_t`는 운영체제마다 다르게 구현되어 있기 때문에 다양한 데이터 타입으로 구현할 수 있도록 허용된다. 

### @Params

<br />

#### thread

pthread_create 성공시 생성된 스레드의 스레드 id가 `thread`가 가리키는 버퍼에 담긴다.

<br />

#### attr

스레드의 속성을 설정하는 매개변수, NULL을 넣으면 디폴트 속성값이 들어간다. (NULL이 아닌 경우=UserMode/KernelMode, StackSize...)

<br />

#### start_routine, arg

pthread_create에 의해 새로 생성된 스레드가 수행할 함수. 매개변수로 arg를 받을 수 있다.

<br />

---

### pthread_join

<br />

```c
int pthread_join(pthread_t thread, void **value_ptr);

// 성공시 0, 그 외에는 오류를 나타내는 오류 번호를 반환
```

<br />

특정 스레드가 종료될 때까지 기다렸다가 그 스레드의 반환값 포인터를 받는 함수. 

종료된 스레드의 자원도 해제해주는 역할을 하므로 pthread_detach와 동시에 쓰일 수 없다. 

실패할 경우 좀비 스레드가 되고, 이 좀비스레드는 자원을 소모해서 더 이상 스레드를 생성할 수 없게 된다.

<br />

### @Params

<br />

#### thread

종료를 기다릴 스레드의 id

<br />

#### value_ptr

인자가 NULL인 경우를 제외하면 종료를 기다린 스레드의 반환 값, 즉 start_routine의 반환값을 받을 수 있다.

<br />

---

### pthread_detach

<br />

```c
int pthread_detach(pthread_t thread);
```

<br />

`pthread_create()`로 생성한 스레드가 종료될 때 스레드 자원을 회수해주는 함수.

특정 스레드를 분리한다. 스레드가 독립적으로 동작하기를 원할 때 사용한다. 

`pthread_detach()`를 사용하지 않아도 `pthread_create()`에 attr 옵션을 주면 스레드 종료시에 자원회수가 가능하다.

때에 따라 `pthread_detach()` 함수가 실행되기 전에 스레드가 종료될 수 있어서 attr을 통해 자원을 해제하는 방법이 좀 더 안전할 수 있다.

attr을 사용하지않고 `pthread_create()`만 사용하면 스레드가 끝나도 자원이 자동으로 해제되지 않는다. 

`pthread_join()`을 같이 사용해야 자원이 해제된다. 

그러나 `pthread_detach()`는 `pthread_join()`를 사용하지 않아도 **자동으로 자원을 해제한다**.

`pthread_detach()`와 `pthread_join()`를 동시에 사용할 수는 없다. 

<br />

---

### usleep

<br />

```c
int usleep(unsigned int microseconds);
// 성공시 0, 그 외에는 -1
```

<br />

`usleep`함수는 인자로 받은 마이크로초가 경과하거나 프로세스에 신호가 전달될 때 까지 프로세스의 실행을 일시 중단한다. 

sleep함수는 프로세스를 중지하는 단위가 마이크로초가 아닌 초 단위라는 점만 다르고 이외는 동일하다.

<br />

> Microsecond : 100만분의 1초

<br />

---

### gettimeofday

<br />

```c
int gettimeofday(struct timeval *tp, struct timezone *tzp);
// 성공시 0, 그 외에는 -1

struct timeval 
{
    long    tv_sec;     // 1970년 1월 1일부터의 초수
    long    tv_usec;    // 및 마이크로 세컨드 수
}

struct timezone
{
    int tz_minuteswest; // 그리니지로부터 서방향에의 편차 (?)
    int tz_dsttime;     // 서머타임 보정의 타입
}

```

<br />

`gettimeofday`는 `time(2)`와 매우 비슷하지만 마이크로초 단위의 시간까지 되돌려준다. 

첫번째 인자 `timeval tp`는 현재 시스템 시간을 저장하기 위한 구조체이다.

두 번째 인자 `timezone tzp`는 타임존을 설정하기 위해서 사용된다. 

현재 timezone 구조체는 사용되지 않고 있으며 앞으로도 지원되지 않는다고 한다. 

복잡하게 할 필요없이 NULL로 설정하면 된다. 

<br />

---

### pthread_mutex_init

<br />

지정된 속성으로 뮤텍스를 초기화한다. 뮤텍스는 fast, recursive, error checking의 세 가지중 하나를 선택할 수 있으며, 

기본값은 fast이다. 성공하면 0, 실패하면 에러값을 리턴한다. 

<br />

```c
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
```

<br />

### @Params

<br />

#### mutex

<br />

초기화할 뮤텍스 객체이다. 

<br />

#### attr

<br />

초기화할 뮤텍스의 속성을 지정할 수 있다. NULL을 주면 기본 속성을 사용 가능.

<br />

---

### pthread_mutex_destroy

<br />

뮤텍스를 제거한다. 뮤텍스는 `pthread_mutex_init()`으로 생성된 뮤텍스이다.

뮤텍스를 제거하려면 그 뮤텍스는 반드시 `unlock` 상태여야한다. 성공하면 0, 실패하면 에러값을 리턴.

<br />

```c
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

<br />

---

### pthread_mutex_lock, pthread_mutex_unlock

<br />

뮤텍스를 잠그고 사용할 수 있을 때까지 차단한다. (unlock은 잠금을 해제)

만약 이미 뮤텍스가 잠겨있다면, 잠금이 풀릴 때까지 대기했다가 뮤텍스를 획득한다. 

두 함수 모두 성공하면 0을 리턴하고 실패하면 에러값을 리턴한다. 

<br />

```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```

<br />

---

### sem_open

<br />

세마포어를 초기화하고 여는 함수이다.

<br />

```c
sem_t   *sem_open(const char *name, int oflag, ...);
```

<br />

### @Params

<br />

#### name

<br />

name으로 세마포어 객체에 이름을 지정할 수 있다.

<br />

#### oflag

<br />

세마포어를 생성하는지 혹은 접근만 가능한지 여부를 설정하는 값.

oflag의 값은 다음 값으로 구성된다. 

<br />

O_CREAT

<br />

존재하지 않는 경우 세마포어를 생성한다. 이 플래그는 추가적으로 2 개의 인수를 필요로 하는데, 

`mode_t mode`, `unsigned int value`가 그것이다. `value`는 `SEM_VALUE_MAX`와 같거나 작은 값을 가져야한다. 

세마포어는 `value`의 값을 초기값으로 설정한다.

<br />

O_EXCL

<br />

만일 `O_EXCL`과 `O_CREAT`가 설정되어 있고, 세마포어의 이름이 존재한다면 `sem_open()`함수는 실행에 실패한다. 

만약 `O_EXCL`는 설정되었고 `O_CREAT`가 설정되지 않은 경우에는 함수 실행에 대한 결과가 정의되지 않는다고 한다.

<br />

이렇게 생성된 세마포어는 `sem_close()`등을 호출하여 세마포어를 닫기 전까지 사용할 수 있다.

<br />

---

### sem_close

<br />

세마포어를 종료한다.

<br />

```c
int sem_close(sem_t *sem);
```

<br />

호출 중인 프로세스가 `sem`이 가리키는 세마포어를 사용하여 종료되도록 지시한다. 

이 함수는 프로세스가 세마포어를 사용하도록 시스템이 할당한 자원을 전부 할당 해제한다.

성공할 경우 0, 아닐 시 -1을 반환한다.

<br />

---

### sem_post

<br />

세마포어의 잠금을 해제한다.

<br />

```c
int sem_post(sem_t *sem);
```

`sem`으로 참조된 세마포어의 잠금을 해제한다.

함수 실행결과 세마포어의 값이 양수인 경우 세마포어가 해제되기를 기다리며, 세마포어의 값이 증가한다.

세마포어의 값이 0인 경우 차단된 스레드중 하나가 `sem_wait()`의 호출로부터 성공적으로 반환하도록 세마포어가 허용된 것이다.

성공할 경우 0을 반환, 그렇지 않으면 -1을 반환한다.

<br />

---

### sem_wait

<br />

세마포어를 잠근다.

<br />

```c
int sem_wait(sem_t *sem);
```

<br />

`sem`으로 참조된 세마포어를 잠근다.

만일 현재 세마포어 값이 0이면 호출하는 스레드는 세마포어를 잠그거나 시그널에 의해서 호출이 중단되기 전까지 `sem_wait()`으로부터 돌아오지 않는다.

함수가 성공적으로 실행되면 세마포어는 잠금 상태가 되고, `sem_post()`로 잠금을 해제하기 전까지 잠금상태를 유지한다.

성공할 경우 0, 실패할 경우 -1을 반환한다.

<br />

---

### sem_unlink

<br />

이름이 명명된 세마포어를 제거한다.

<br />

```c
int sem_unlink(const char *name);
```

<br />

현재 name으로 명명된 세마포어가 어떤 프로세스에 의해 참조되고 있다면, 이 함수는 해당 세마포어에 영향을 미치지 않는다. 

만약 하나 이상의 프로세스가 이 함수를 호출했을 때, 해당 세마포어를 열고 있다면 모든 참조되고 있는 세마포어가 `sem_close()`등에 의해 종료될 때까지 세마포어의 제거는 연기된다. 

성공할 경우 0, 실패 시 -1을 반환한다. 

<br />

---

## Source 

<br />

[참고링크](https://velog.io/@jwoo/Philosophers-%ED%97%88%EC%9A%A9%ED%95%A8%EC%88%98)

[참고링크](https://velog.io/@jwoo/Philosophers-%ED%97%88%EC%9A%A9%ED%95%A8%EC%88%98-pthread)

[참고링크](https://www.joinc.co.kr/w/Site/Thread/Beginning/Mutex)

[참고링크](https://fmyson.tistory.com/394)

[참고링크](https://velog.io/@jongeun/Philosophers-Day-01)

[참고링크](https://velog.io/@jongeun/Philosophers-Day-05)

[참고링크](https://heeonii.tistory.com/14)

[참고링크](http://www.tcpschool.com/java/java_thread_concept)

[참고링크](https://liltdevs.tistory.com)
