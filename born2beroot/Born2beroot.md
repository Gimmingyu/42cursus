# Born2beroot

**The use of VirtualBox is mandatory.**

**VirtualBox를 사용하십시오.**

**You only have to turn in a signature.txt file at the root of your repository.  
You must paste in it the signature of your machine’s virtual disk.  
Go to Submission and peer-evaluation for more information.**

**당신의 가상 머신 디스크의 서명이 들어 있는 signature.txt만 제출하면 됩니다.  
Submission and peer-evaluation 파트에서 자세한 정보를 확인하세요.**

This project consists of having you set up your first server by following specific rules.

다음 룰을 따라서 당신의 첫 server를 구축하십시오.

Since it is a matter of setting up a server, you will install the minimum of services.

서버를 구축하는 것이기 때문에, 우리는 최소한의 서비스만 설치할 것입니다.

For this reason, a graphical interface is of no use here. It is therefore forbidden to install X.org or any other equivalent graphics server. Otherwise, your grade will be 0.

따라서 X.org나 그 외의 그래픽 인터페이스를 사용할 경우 0점으로 처리됩니다.

---

## Virtual Machine?

```
가상 머신이 무엇인가?

가상 머신은 파티션을 나누지 않고 여러 개의 운영체제를 가동하게 해주는 녀석인데, 파티션을 나눈다는 것은 무슨 뜻일까?

파티션은 하드디스크 용량을 사용자가 필요에 따라 논리(logical)적으로 분할하는 일을 말한다.

예를 들어 윈도우 컴퓨터를 쓸 때 C드라이브, D드라이브가 있는 것을 본 적이 있는데, 용량을 나누어서 독립적인 드라이브 명을 갖게함으로써

여러 개의 드라이브가 생성되는 것처럼 보이게 하는 것이다.

이렇게 파티션을 나누게 되면 동일한 하드디스크에 여러 개의 운영체제를 설치할 수 있다고 한다.

LVM은 리눅스 안에서 하나의 디스크를 여러 파티션으로 분할해서 파일 시스템을 이용해 특정 디렉터리와 연결시켜 사용한다.

```

---

## CentOS와 Debian ?

```
Debian은 Debian 프로젝트가 개발한 자유(Free) 컴퓨터 운영체제라고 한다.

Debian의 특징은 패키지 설치 및 업그레이드의 단순함인데, 일단 인스톨을 한 후 패키지 매니저인 apt update 방식을 이용해서
소프트웨어의 설치나 업데이트에서 다른 패키지와의 의존성 확인, 보안관련 업데이트 등을 자동으로 설정 및 설치해준다.

Debian에 대해서 검색을 해보면 레드헷과 가장 많이 비교가 되는데, Debian은 오픈 소스쪽에 가깝고 레드헷은 상용쪽에 가깝다고 한다.

오픈 소스는 추가 비용없이 소스코드 형식이 제공되고 소스코드를 다른 목적으로 활용하거나 배포가 가능하다.

상용 계열은 반대로 소스코드가 제공되지는 않는다고 한다.

우리가 잘 알고있는 우분투 또한 Debian에서 파생되었다고 하니, 역사가 깊은 운영체제라고 할 수 있겠다.

CentOS는 레드햇 제휴로 개발된 컴퓨터 운영체제라고 한다. 레드햇 엔터프라이즈 기술을 그대로 가져와 사용할 수 있는 것이 장점이라고 하는데,

위에서 말했듯이 무료가 아닌 레드햇을 무료로 배포하는 것이 가능한 것은 GPL 라이센스 때문이라고 하는데... 이 부분은 중요해보이진 않는다.

결론적으로 CentOS는 레드햇 계열이고, Ubuntu는 Debian계열이다. 이번 과제에서는 CentOS와 Debian중 하나를 결정해야 하는데,

둘의 차이점을 정리해보자.
```

---

```
CentOS는 Community Enterprise Operating System의 약자로 회사가 아닌 커뮤니티를 통해 지원이 되는 운영체제이다.

CentOS는 Red Hat이 공개한 RHEL(Red Hat Enterprise Linux)을 그대로 가져와서 배포한 것이다.

따라서 RHEL과 OS 버전, Kernel 버전, 패키지 구성이 똑같다.

서버용 운영체제로 인기가 많고, 서버용으로 리눅스를 운영할 목적인 경우에는 대부분 CentOS를 사용한다고 한다.
```

```
Debian도 온라인 커뮤니티에서 제작이 되었고, Red Hat보다 더 먼저 배포되었다.

Debian에서 파생된 OS(example: Ubuntu)를 Debian 계열이라고 부른다.

Debian은 배포되고 있는 리눅스 중 서버의 안정성이 높고 포함하고 있는 패키지도 많다.

deb이라는 패키지들을 쓰는데 deb을 관리하는 패키지들을 가지고 있어(dpkg, apt 등)

패키지 설치 시 의존성에 걸려있는 패키지들을 자동으로 알려주고 설치하며 설정 파일들을 생성해준다.

커뮤니티에서 자발적으로 만드는 배포판이기 때문에 아무래도 Red Hat 계열에 비해 사후지원이나 배포가 늦다고 한다.

주로 개인 사용자 서버용으로 인기가 높고, 최근에는 지속적으로 업데이트를 해서 Red Hat계열에 비해 성능이 뒤쳐지지는 않는다고 한다.

나는 Debian을 사용하기로 했는데, 개인 사용자에게 인기가 많아 사용법이 널리 퍼져있어 진입 장벽이 낮을거라 생각해서 Debian을 선택했다.
```

---

## [Kernel](<https://ko.wikipedia.org/wiki/%EC%BB%A4%EB%84%90_(%EC%BB%B4%ED%93%A8%ED%8C%85)>)

```
커널은 운영 체제의 핵심 부분이므로, 커널의 역할 역시 운영 체제의 핵심 역할이라 할 수 있다.

커널은 컴퓨터 하드웨어와 프로세스의 보안을 책임진다.

커널은 한정된 시스템 자원을 효율적으로 관리하여 프로그램의 실행을 원활하게 한다. 특히 프로세스에 처리기를 할당하는 것을 스케줄링이라 한다.

일반적으로 커널은 운영 체제의 복잡한 내부를 감추고 깔끔하고 일관성 있는 인터페이스를 하드웨어에 제공하기 위해

몇 가지 하드웨어 추상화(같은 종류의 장비에 대한 공통 명령어의 집합)들로 구현된다고 하는데, 우선은 이 정도만 알고 넘어가도 괜찮을 듯 하다.
```

---

## Apt vs Aptitude?

```
APT (Advanced Package Tool)는 Debian 시스템에 포함된 핵심 도구들의 집합체이다.

이 APT를 준수해 패키지 관리의 목적으로 만들어진 툴이 apt-get, aptitude 등이다.

그런데 실제 리눅스 유저들이 자주 쓰는 커맨드가 여러 툴에 흩어져 있다 보니 유저들이 자주 쓰고 유용한 기능만을 합친 apt가 탄생하게 되었다.

apt를 간단하게 말하면 소프트웨어 패키지를 관리하는 소프트웨어이다.

apt로 우리는 응용 프로그램 설치, 삭제 및 업데이트 등 여러 가지 작업을 처리할 수 있다.

특징으로는 GUI가 없고, 사용자가 패키지를 업그레이드할 때 자동으로 가장 중요한 패키지를 업그레이드하고 가장 덜 중요한 패키지를 남겨둔다는 것이다.
```

```
Aptitude는 apt에 GUI를 추가된 high-level 패키지 매니저이다.

아무래도 apt보다 사용자가 패키지 관리를 보다 편리하게 작업할 수 있고, 주요 패키지 작업 과정을 자동화하여 apt보다 쉽게 작업할 수 있도록 해 준다.

우선 둘의 가장 큰 차이점은 apt는 low-level, aptitude는 high-level 패키지 매니저라는 것이다.

이를테면, aptitude는 사용하지 않는 패키지를 자동으로 제거해주는 반면 apt는 추가적인 옵션이 필요하다 (ex: -auto-remove)

또한, apt는 설치, 제거, 업데이트 과정에서 충돌이 생기면 불가능하다는 메시지를 띄우는데, aptitude는 다른 대안을 제시한다.

apt는 low-level 패키지 매니저이므로 다른 하이 레벨 패키지 매니저에 의해 사용될 수도 있다고 한다.
```

> GUI : Graphical User Interface, 사용자가 편리하게 사용할 수 있도록 입출력 등의 기능을 알기 쉬운 아이콘 따위의 그래픽으로 나타낸 것.

---

## AppArmor ?

```
Application Armor의 줄임말로, Security Framework 이다.

Debian 계열이고, MAC(강제 접근 제어)가 적용된다.

강제 접근 제어는 정의된 정책을 활용해 사용자와 프로세스의 행동을 제어하는 보안 모델이다.

AppArmor는 데비안 OS를 사용하면 자동으로 설치되고, enforce, complain 모드로 파일 접근을 제어할 수 있다.

Enforce모드에서는 허가되지 않은 파일에 접근을 거부하고, Complain 모드에서는 실질적으로 보안을 제공하지는 않지만, 애플리케이션이 예측되는 행동이 아닌 다른 행동을 할 경우 로그를 남겨준다.
```

> 모드 확인 Command: "sudo aa-status"(enforced, complain, unconfined)

> "ps auxZ | grep -v ^unconfined" 명령어로 앱아머에 의해 제한된 실행 파일 확인 가능

---

## SSH와 Port Forwarding

```
Secure Shell의 줄임말이며, 이름에서 알 수 있듯이 보안을 염두에 두고 만들어진 프로토콜이다.

컴퓨터와 컴퓨터가 Public Network를 통해 서로 통신할 때, 보안적으로 안전하게 통신을 하기 위해 사용하는 프로토콜을 의미한다.

SSH 클라이언트와 SSH 서버의 관계로 상호작용하면서 SSH 서버가 설치된 운영체제를 제어한다.

우리는 SSH 프로토콜을 이용해서 인증, 암호화, 무결성, 압축 등으로 인증 과정을 수행할 수 있다.

SSH 클라이언트를 통해 SSH 서버에 접속을 하면 둘 사이에 연결이 이루어지는데, 이 통로를 터널이라고 한다.

이 터널을 다른 애플리케이션이 이용할 수가 있는데, 이를 가능하게 하는 것이 바로 포트 포워딩이다.
```

```
포트 포워딩은

네트워크 상에서 패킷이 네트워크 게이트웨이를 지나는 동안,

하나의 IP 주소와 포트 번호 결합의 통신 요청을 다른 곳으로 넘겨주는 NAT(네트워크 주소 변환)의 응용 기술이다.
```

---

## 방화벽 (ufw)

방화벽이란 미리 정의된 보안 규칙에 의거하여 in-out network traffic을 모니터링하고 제어하는 네트워크 보안 시스템이다.

> ufw enable

ufw는 기본 비활성화 상태이기에 이를 활성화해주는 명령어.

> ufw default deny

기본 정책을 차단해주는 명령어.

> ufw allow 4242

4242번 포트 허용

> ufw status verbose

verbose 옵션은 몇 가지 추가 정보를 보여줍니다 . 들어오는 연결을 만나거나 호스트의 응용 프로그램이 외부 세계와 연결을 설정하려고 할 때 방화벽의 기본 동작과 같습니다.

verbose 옵션은 몇 가지 추가 정보를 보여준다. Incoming connection을 만났을 때, 혹은 호스트의 애플리케이션이 외부와 연결을 시도할 때 방화벽의 기본 동작같은 정보를 포함한다.

---

> usermod -aG sudo {username}

루트 계정 실행하면 해당 유저를 sudo에 넣고 해당 유저로 로그인한다.

이미 존재하는 유저일 경우에 쉽게 그룹에 넣고 로그인 할 수 있다.

-aG 옵션은 기존의 2차 그룹 이외에 추가로 2차 그룹을 지정할 때 사용한다. -G 옵션 자체가 추가로 다른 그룹에 속하게 할 때 사용하는데, -a 옵션은 -G 옵션과 함께 쓰이면서 append의 속성을 가진다.

---

> apt install openssh-server

SSH 설치. 보통 이미 깔려있다.

> vim /etc/ssh/sshd_config

sshd_config 파일은 리눅스 SSH 설정 파일이다.

기본적으로 서비스 포트가 22로 규약이 되어 있어서 서브젝트에 맞게 변경해준다.

또한 서브젝트 조건에서 임의의 주소에서 root 계정으로 접속이 불가능하게 처리를 하라고 명시되어 있기 때문에,

PermitRootLogin no 로 root 계정 직접 접근을 막았다.

> systemctl restart ssh
> systemctl status ssh

설정을 변경한 후 재시작을 해준다.

---

> /etc/login.defs

사용자 계정의 설정과 관련된 기본 값을 정의한 파일이다.

해당 파일에서 PASS_MAX_DAYS, PASS_MIN_DAYS, PASS_WARN_AGE 순서대로, 최대 30일 까지 사용이 가능하며, 한 번 변경하면 최소 2일 후에 변경이 허용되며, 만료 7일 이전에 경고를 띄워주는 설정을 할 수 있다.

> apt-get -y install libpam-pwquality

암호 강도를 확인하는 리눅스 pam 모듈이다.

PAM은 리눅스 시스템에서 사용하는 인증 모듈로써 응용 프로그램에 대한 사용자의 사용 권한을 제어하는 모듈이다.

> passwd -e {username}

username의 현재 비밀번호를 만료시키고 다음에 로그인 할 때 재설정하게 한다.

> crontab -e

정기적으로 shell script나 프로그램을 실행시키게 해준다.

분 시 일 월 요일 경로 순으로 들어간다.

\*/10 \* \* \* \* \* /root/monitoring.sh | wall

를 입력했는데, 10분마다 실행을 하게 해주는 설정이다.

wall 명령어로 터미널에 메시지를 보낸다.

---

> aa-stauts

AppArmor 정책에 관한 여러 정보를 보여주는 리눅스 명령어

> aa-enabled

활성화 여부 확인
