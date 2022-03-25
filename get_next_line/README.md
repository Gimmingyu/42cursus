##### Get Next Line

### 목표

# 1. GNL 함수를 loop안에서 호출하면 fd의 텍스트를 EOF까지 한 번에 한 줄씩 읽을 수 있다.
# 2. file로부터, redirection으로부터, stdin으로부터 읽었을 때 함수가 제대로 동작해야 한다.
# 3. 이 프로그램은 -D BUFFER_SIZE=xx 플래그를 붙여서 컴파일 해야 한다. 즉, read 함수는 표준입력으로 또는 파일로부터 읽어들이기 위해서 컴파일할 때 정의된 BUFFER_SIZE를 사용해야 한다.
# 4. BUFFER_SIZE가 1일 때도, 9999일 때도, 10000000 (1000만)일 때도 함수가 제대로 동작해야 한다.
# 5. Single Static Variable로 get_next_line 성공하기.
# 6. 다중 file descriptor를 관리 할 수 있는 함수로 만들기.
