## BitMask
* 메모리의 최소 크기 단위는 1바이트 즉 8비트임
* 이는 1바이트를 사용해서 1비트만 저장할경우 나머지 7비트가 낭비되어버릴수도 있다는 뜻임
* 이를 해결하기위해 비트를 통해 값을 저장하는 비트마스킹 기법을 사용함  

## 비트연산자
* AND(&) 
* OR(|)
* XOR(^)
* NOT(~)
* SHIFT
  * a << b : a를 왼쪽으로 b비트 이동
  * << b : b비트씩 왼쪽으로 이동 (밀려난 왼쪽 비트는 사라지고 새로운 오른쪽 비트는 0으로 채워짐) / 결과적으로 2^n을 곱한것과 같은 결과를 가짐
  * \>\> b : b비트씩 오른쪽으로 이동 (밀려난 오른쪽 비트는 사라지고 새로운 왼쪽 비트는 0으로 채워짐) / 결과적으로 2^n을 나눈것과 같은 결과를 가짐

## BitMasking
* 비트마스킹은 일반적으로 각각의 bit가 집합 원소의 유무를 나타내는 용도로 많이 쓰임
* 공집합 생성
  * **int s = 0** : 0000 0000 0000 0000 0000 0000 0000 0000 인 공집합 생성
* 집합에 원소 추가
  * **s |= (1<<3)** : (1<<3)은 1000이고 이를 s와 or연산 시키면 ... 0000 1000 이 됨
* 집합에 원소 삭제
  * **s &= ~(1<<3)** : 1000을 0111로 만들고 이를 s와 and연산 시키면 ... 0000 0000 으로 3번째 원소가 삭제됨
* 집합에 원소 유무확인
  * **if(s &= (1<<3))** : 1000와 집합 s를 and연산시켰을때 3번째 원소가 1이면 어느 특정값이 나올테고 0이면 0이나옴
* 집합에 최소 원소(가장 맨뒤의 1인 원소) 지우기 
  * **s &= (s-1)** : ex) s = 1010 / s-1 = 1001 / s & (s-1) = 1010 & 1001 = 1000
* s에 모든 원소 채우기
  * **s|= (1<<8) - 1** : 1 0000 0000 -1 = 1111 1111
* **(~s)+1** : 논리회로에서 배우는 2의 보수를 나타냄
* **s&(s의 2의배수)** : 최하위의 1인 비트 ex) s = 10110 이라면 계산한 값은 00010
  

## 비트 연산에서 주의할점
* 비트연산자의 우선순위는 산술연산자 보다 낮기에 괄호를 항상 잊지 말아야함 
