### 설명
* map : 노드 기반의 균형 이진 트리 구조임
* key의 값은 고유값이므로 중복해서 사용불가능함
* 자동으로 오름차순 정렬됨
* map의 기본적인 사용 map <자료형,자료형> 변수명  
* 내림차순으로 사용하고싶은 경우 map<자료형,자료형,greater<자료형>>변수명으로 선언하면되고 key값을 기준으로 정렬됨

### 메소드
* size() map의 크기 구함
* rbegin(), rend() 역방향으로 참조가능 (iter로 반환)
* lower_bound(int) a보다 크거나 같은 원소 중 가장 작은 값을 return (없을경우 end()리턴) (iter로 반환)
* erase(iterator) iterator위치에 있는 원소를 삭제함
