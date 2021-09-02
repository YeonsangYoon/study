# Type Casting이란?

어떤 변수의 자료형(type)을 다른 자료형으로 변환하는 것을 말한다.

### 왜 필요한가?

각 자료형마다 표현할 수 있는 수의 범위와 유형이 다르기 때문에 때에 따라 자료형을 바꿔줄 필요가 있음

| 구분  | 자료형                  | 메모리 크기(byte) | 범위                                                          |
|-----|----------------------|:--------------:|:-------------------------------------------------------------:|
| 기본형 | `void`                 | –            | –                                                           |
| 문자형 | `char`       | 1 byte       | -128 ~ 127                                                  |
|     | `unsigned char`        | 1 byte       | 0 ~ 255                                                     |
|     | `wchar_t`              | 2 byte       | 0 ~ 65,535                                                  |
| 정수형 | `bool`                 | 1 byte       | 0 ~ 1                                                       |
|     | `short` | 2 byte       | -32,768 ~ 32,767                                            |
|     | `unsigned short` | 4 byte       | 0 ~ 65,535                                                  |
|     | `int`         | 4 byte       | -2,147,483,648 ~ 2,147,483,647                              |
|     | `unsigned int`         | 4 byte       | 0 ~ 4,294,967,295                                           |
|     | `long`  | 4 byte       | -2,147,483,648 ~ 2,147,483,647                              |
|     | `unsigned long`  | 8 byte       | 0 ~ 4,294,967,295                                           |
|     | `long long`  | 4 byte       | –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807,295                                           |
|     | `__int8`               | 1 byte       | -128 ~ 127                                                  |
|     | `__int16`              | 2 byte       | -32,768 ~ 32,767                                            |
|     | `__int32`              | 4 byte       | -2,147,483,648 ~ 2,147,483,647                              |
|     | `__int64`              | 8 byte       | -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807      |
| 실수형 | `float`                | 4 byte       | 3.4E-38 ~ 3.4E+38(7digits)          |
|     | `double`       | 8 byte       | 1.79E-308 ~ 1.79E+308 (15digits) |

### Type Casting의 종류

### 1. 묵시적 형 변환
컴파일 시 묵시적으로 왼쪽 변수의 type으로 형이 변환된다. (개발자 관여 x)

- 키워드나 특수 명령문이 필요하지 않음.
- 더 작은 data type에서 큰 data type으로 변환하는 것을 형승격(type promotion)이라고 한다.
- 묵시적 형 변환은 항상 호환되는 데이터 유형에서 발생하고 그 외의 변환은 데이터가 유실될 수 있다.

    - float을 int로 변환하면 분수부분이 잘림.
    - double을 float으로 변환하면 숫자가 반올림된다.
    - long long을 int로 변환하면 상위 bit가 삭제된다.

<img src="/img/그림1.png" width="50%" height="50%"></img>

예제 1) 
```cpp
int main(void) {
	float a = 3.33;
	int b = a;          // float => int
	long long c = b;    // int => long long

	cout << "a : " << a << ", bytes : " << sizeof(a) << endl;
	cout << "b : " << b << ", bytes : " << sizeof(b) << endl;
	cout << "c : " << c << ", bytes : " << sizeof(c) << endl;

	return 0;
}
```
출력
```
a : 3.33, bytes : 4
b : 3, bytes : 4
c : 3, bytes : 8
```

### 2. 명시적 형 변환
개발자가 직접 해당 변수의 type을 명시해서 자료형을 변환하는 방법. (개발자 관여 o)

- 함수의 인자와 매개변수의 type이 다른 경우 
- void로 인자를 넘긴 후 함수 내부에서 casting하는 경우

예제 1)
```cpp
int main(void) {
	int a = 3;
	int b = 2;

	double c, d;
	c = a / b;          // a / b를 계산한 후 double형으로 묵시적 typecasting
	d = (double)a / b;  // a, b를 double형으로 변환 후 나눗셈 계산

	cout << "c : " << c << ", bytes : " << sizeof(c) << endl;
	cout << "d : " << d << ", bytes : " << sizeof(d) << endl;

	return 0;
}
```
출력
```
c : 1, bytes : 8
d : 1.5, bytes : 8
```

예제 2)
```cpp
void casting_inside(void* ptr) {
	int* param = (int *)ptr;
	cout << *param << endl;
}
void casting_outside(int param) {
	cout << param << endl;
}

int main(void) {
	int a = 4;
	float b = 4.44;

	casting_inside(&a);
	casting_outside((int)b);

	return 0;
}
```
출력
```
4
4
```

### 3. Cast operator
위의 두 type casting은 매우 유연하기 때문에 컴파일 시 통과하더라도 런타임에서 오류를 일으킬 수 있다. 이를 casting 연산자를 사용하여 이를 방지할 수 있다.

### 1) static_cast
논리적으로 변경 가능한 경우에만 변경을 허용하는 연산자
```cpp
int main(void) {
    float a = 3.14;
    int b = static_cast<int>(a);    // float => int
    a = static_cast<float>(b);      // int => float

    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

    return 0;
}
```
- 실수 => 정수 or 정수 => 실수
- 부모 class 포인터가 부모 class를 가리키는 것
- 자식 class 포인터가 자식 class를 가리키는 것
- 부모 class 포인터가 자식 class를 가리키는 것
- 자식 class 포인터가 부모 class를 가리키는 것
- 포인터 type => 정수 타임 (불가능)



### 2) const_cast
상수 속성(const), volatile 속성을 처리할 때 사용하는 연산자이고 포인터 및 참조형에서만 사용 가능하다.

```cpp
int main(void) {
    const int* param = new int(4);

    cout << "const 제거 전 값 : " << * param << endl;

    int* ptr;
    ptr = const_cast<int*>(param);
    *ptr = 6;

    cout << "const 제거 후 값 : " << *param << endl;

    return 0;
}
```
```
const 제거 전 값 : 4
const 제거 후 값 : 6
```

### 3) reinterpret_cast
C 스타일의 명시적 type casting이 가능하다. 포인터 변수를 정수형으로 변환하는 것도 가능하다.

```cpp
int main(void) {
    int a = 4;
    int* ptr = &a;

    cout << "a의 주소값: " << ptr << endl;
    
    int ptr_int = reinterpret_cast<int>(ptr);
    
    cout << "주소의 정수값 : " << ptr_int << endl;

    return 0;
}
```
```
a의 주소값: 010FFD28
주소의 정수값 : 17825064
```

### 4) dynamic_cast
static_cast가 해결하지 못한 class 상속관계에서의 형변환을 보다 안전하게 처리한다.
