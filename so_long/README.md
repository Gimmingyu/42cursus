# So_long

참조

- [링크1](https://velog.io/@jeunghoon/MiniLibX%EB%A5%BC-%EA%B3%B5%EB%B6%80%ED%95%B4%EB%B3%B4%EC%9E%90#initC)
- [링크2](https://github.com/taesukang-dev/42_cursus/tree/master/so_long)

---

## MiniLibX

so_long 과제의 핵심. 학생을 위한 간단한 window 인터페이스 라이브러리.

---

## MLX 함수

---

### mlx_init

```c
#include <mlx.h>

void	*mlx_init();
```

- mlx 모든 함수 이전에 사용해야 하는 함수.
- 소프트위어와 디스플레이를 연결한다.
- 연결이 되면 MiniLibX를 사용해 디스플레이와 메시지를 주고 받을 수 있다.

#### @Return

```c
- NOT_NULL_PTR	: 연결 식별자 포인터
- NULL			: 연결 실패
```

---

### mlx_new_window

```c
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
```

새 창을 생성하는 함수.

#### @Params

```c
- mlx_ptr			: 연결 식별자.
- size_x, size_y	: 새 창의 사이즈.
- title				: 창의 타이틀 바에 보일 문자열.
```

#### @Return

```c
- void *win_ptr	: 창 사용 식별자
- NULL			: 실패
```

---

### mlx_clear_window

창을 검은색으로 초기화하는 함수

```c
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
```

#### @Params

```c
mlx_ptr	: 연결 식별자
win_ptr	: 창 사용 식별자
```

---

### mlx_destroy_window

창을 삭제하는 함수

```c
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
```

#### @Params

```c
mlx_ptr	: 연결 식별자
win_ptr	: 창 사용 식별자
```

---

## 드로잉 함수

표시 가능한 모든 색상은 빨강, 녹색, 파랑의 3 가지 기본 색상으로 나눌 수 있다.

0~255 범위의 세 가지 관련 값은 색상이 혼합되어 원래 색상을 만드는 정도를 나타낸다.

0xTTRRGGBB = T: Transparency, R: Red, G: Green, B: Blue

---

### mlx_pixel_put

지정된 픽셀을 그리는 함수

```c
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
```

(0, 0): 창의 좌측 상단.

x는 오른쪽으로, y는 아래를 향해 포인팅한다. (y 아래가 양수)

#### @Params

```c
x, y	: 화면의 x, y 좌표값
color	: 바이트 단위로 000-255 사이의 투명도 값 저장
|투명도|R|G|B| ==> 0x00RRGGBB
```

---

### mlx_string_put

지정된 문자열을 그리는 함수

```c
int mlx_string_put (void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
```

#### @Params

```c
string	: 나타낼 문자열
```

---

## 이미지 함수

---

### mlx_new_image

메모리에 새로운 이미지를 생성한다.

```c
void	*mlx_new_image(void *mlx_ptr, int width, int height);
```

---

### mlx_put_image_to_window

이미지를 스크린에 출력한다.

```c
int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
```

---

### mlx_get_data_addr

생성된 이미지의 정보를 반환하는 함수이다.
이미지 수정도 가능하다.

```c
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
```

#### @Params

```c
bits_per_pixel	: 비트로 표현된 픽셀 색깔(이미지의 깊이)
size_line		: 이미지의 한줄을 메모리에 저장하는 데 사용되는 바이트 수. 이 정보는 이미지에서 한 줄에서 다른 줄로 이동할 때 필요.
endian			: 픽셀 색깔을 저장하는 변수가 리틀엔디안(endian == 0)인지 혹은 빅엔디안(endian == 1) 방식인지 나타낸다.

**MacOS에서는 클라이언트와 그래픽 프레임워크가 동일한 엔디안이라 필요 X**

```

#### @Return

```c
char *ptr

이미지가 저장된 메모리 영역의 시작을 나타내는 주소를 반환한다.

이 주소로부터 첫 번째 bits_per_pixel 비트가 이미지의 제일 첫 줄의 첫 번째 픽셀의 색상을 나타낸다.

두 번째 그룹의 bits_per_pixel 비트가 첫 줄의 두 번째 픽셀을 나타내고...and so on

주소의 size_line을 추가해서 두 번째 줄 시작점을 얻는 방식으로 이미지의 모든 픽셀에 도달할 수 있다.
```

> 리틀 엔디안: 앞 주소에 작은 바이트부터 기록
> 빅 엔디안: 앞 주소에 큰 바이트부터 기록

---

### mlx_get_color_value

이미지 내부에 색상을 저장한다.

```c
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
```

디스플레이에 따라 픽셀 색상을 저장하는 데 사용되는 비트 수가 변경될 수 있다.

사용자는 일반적으로 각 구성 요소에 1바이트를 사용하여 RGB 모드에서 색상을 나타낸다.

이것은 이미지의 bits_per_pixel 요구사항에 맞게 변환되어야 하며, 디스플레이에서 색상을 이해할 수 있도록 해야하는데, 이것이 이 함수의 역할이다.

표준 RGB 색상 매개변수를 사용하고, unsigned int 값을 리턴한다.

이 값의 bits_per_pixel 최하위 비트는 이미지에 저장될 수 있다.

최하위 비트 위치는 로컬 컴퓨터의 엔디안에 따라 다른데, 이미지의 엔디안이 로컬 엔디안과 다른 경우, 값을 사용하기 전에 변환해야 한다.

---

### mlx_xpm_to_image

### mlx_xpm_file_to_image

### mlx_png_file_to_image

포맷에 맞는 새 이미지를 생성한다.

```c
void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);

void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

void *mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
```

---

### mlx_destroy_image

주어진 이미지를 삭제한다.

```c
int *mlx_destroy_image(void *mlx_ptr, void *img_ptr);
```

---

## 이벤트 관리 함수

### mlx_loop

```c
int	mlx_loop(void *mlx_ptr);

반환값이 없고, 이벤트를 기다린 다음 이 이벤트와 연결된 사용자 정의 함수를 호출하는 무한루프.

키 입력, 마우스 입력, 창의 일부분을 다시 그리는 expose 의 세 가지 이벤트에 다른 함수를 할당할 수 있다.
```

---

### mlx_key_hook

### mlx_mouse_hook

### mlx_expose_hook

```c
int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);

이벤트 발생 시 내가 호출하고 싶은 함수를 가리키는 함수 포인터를 받는다.

이 할당은 win_ptr에 의해 특정된 윈도우에만 적용된다.

param은 호출될 때마다 함수에 전달되며, 필요한 매개 변수를 저장하는데 사용된다.
```

---

### mlx_loop_hook

```c
int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);

아무 이벤트도 일어나지 않을 경우 매개 변수로 받았던 함수가 호출된다.

이벤트를 포착했을 경우, MiniLibX는 특정 함수를 고정 파라미터를 이용해 호출한다.
```
