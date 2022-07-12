### 정의
* priority queue도 일반적인 queue처럼 FIFO의 원리를 가짐 
* 단 **우선순위가 높은데이터**가 무조건 빠르게 나오게되어 있음
* 구현방식
  * Array : O(N)
  * Linked list : O(N)
  * Heap : O(logN)
  * 위와 같은 이유로 일반적으로 **힙**을 이용하여 구현함
* 선언
  * priority_queue<자료형>변수명 / **내림차순 정렬**
  * priority_queue<자료형,Container,비교함수>변수명 / **비교함수에따라 정렬** 
    * Container에는 보통 vector<자료형>이 들어감
    * 비교함수는 구조체를 이용하여 구현함
      ```cpp
      struct compare
      {
          bool operator()(int a,int b)
          {
              return a > b; // 오름차순정렬
          }
      }
      ```
  * 비교함수에 greater\<int\>를 넣으면 오름

### 메소드
* push()
* pop()
* top()
* empty()
* size()
