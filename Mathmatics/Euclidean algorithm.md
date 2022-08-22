## 유클리드 호제법  
* 2개의 자연수의 최대공약수를 구하는 알고리즘 중 하나
* 호제법이라는 뜻은 두 수를 서로 나누며 원하는 값을 얻어내는 방법임
* 유클리드 호제법은 명시적으로 알려진 가장 오래된 알고리즘임 (BC 300년경)

## 소스코드

### 반복문  
```cpp
int GCD(int a, int b) // a > b
{
    int tmp;
    while(b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
```

  
### 재귀
```cpp
int GCD(int a, int b) // a > b
{
    if(b==0) return a;
    else return GCD(b,a%b);
}
```
