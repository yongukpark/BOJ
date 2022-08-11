## Binary Search (이진 탐색)

## \<algorithm\> 
### upper_bound(int start, int end, int findIdx) 
  * 찾고자 하는 값보다 큰 가장 작은 값을 구함
  * 주의할점은 찾고자하는 값은 못찾음
### lower_bound(int start, int end, int findIdx)
  * 찾고자 하는 값중 가장 작은 인덱스 혹은 찾고자 하는 값이 없을 때에는 upper_bound와 같은 값을 찾음
### 주의할 점 
  * upper_bound, lower_bound는 리턴값이 **주소**이기에 변수를 잘 선언해야함
  * 또한 **int idx = upper_bound(v.begin(),v.end(),a) - v.begin()** 을 하면 찾고자 하는 값을 **정수형** 인덱스로 반환해줌
### 응용
  ``` cpp
  int a = lower_bound(v1.begin(), v1.end(), goal) - v1.begin();
  int b = upper_bound(v1.begin(), v1.end(), goal) - v1.begin();
  int res = b - a;
  ```
  * 만약 찾고자 하는 goal 값이 있다면 그 goal 값의 개수를 알 수 있음
  * 만약 그 값이 없다면 res는 0이 들어감
  * ex) goal = 5 / arr = 1 2 3 4 **6**(lower,upper) 7 8 / res = 0
  * ex) goal = 5 / arr = 1 2 3 4 **5**(lower) **6**(upper) 7 8 / res = 1
  * ex) goal = 5 / arr = 1 2 **5**(lower) 5 5 **6**(upper) 7 8 / res = 3
