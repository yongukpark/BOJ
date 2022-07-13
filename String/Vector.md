### 정의
* size와 capacity의 차이
  * capacity는 vector의 요소들을 담을 수 있는 메모리의 할당량이고 size는 실제로 지금 들어있는 원소들의 개수를 센 것임
  * capacity > size이면 그냥 size++
  * capacity == size이면 capacity가 증가한 새로운 공간을 할당하고 capacity > size인 상황을 만들어 할당함 

### 메소드
