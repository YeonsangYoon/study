> C++ Split 구현

문자열을 특정 구분 기호로 나눠 벡터에 저장하는 함수

```cpp
vector<string> split(string s, char delim);
```
- string s : 나눠지는 문자열
- char delim : 구분 기호


> 전체 코드
```cpp
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, char delim) {
	vector<string> retval;  // 리턴 값
	stringstream os(s);     // stream에 문자열 저장
	string tmp;

	while (getline(os, tmp, delim)) {   // getline으로 delim 만나기 전까지 tmp에 저장
		retval.push_back(tmp);
	}

	return retval;
}
```

