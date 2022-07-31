## Knapsack Problem(배낭 문제)
* 배낭 문제는 각각의 무게와 가치가 주어진 보석을 일정 용량의 가방에 최대의 가치로 넣는 방법을 구하는 것임
* 일반적으로 Brute Force와 Greedy 알고리즘이 있지만 각각 시간복잡도가 너무 높고 항상 최적의 해를 구하지 못하기 때문에 사용하지 못함
* 그래서 사용하게 된것이 바로 Dynamic Programming임  
 
## <a href = "https://www.acmicpc.net/problem/12865">12865</a>를 통한 배낭문제 풀이
* 기본적으로 dp는 이차원 배열로 선언 (하나는 원소의 개수, 나머지는 가방의 무게만큼)
* 지금의 문제는 원소의 개수 100, 가방의 최대무게 100000이므로 다음과 같이 선언
 ```cpp
 int dp[103][100003];
 ```
 * 그리고 각각의 무게 가치를 입력받아 배열로 저장
 ``` cpp
    int w[103];
    int v[103];
    
    int num, weight;
    cin >> num >> weight;
    for(int i = 1 ; i <= num ; i++)
    {
        cin >> w[i] >> v[i];
    }
```
* dp는 각각의 경우에서 최적의 값이 나오도록 구해야함

<table style="border-collapse: collapse; width: 100%; height: 57px;" border="1" data-ke-style="style12">
<tbody>
<tr style="height: 19px;">
<td style="width: 20%; height: 19px; text-align: center;">물건</td>
<td style="width: 20%; height: 19px; text-align: center;">1</td>
<td style="width: 20%; height: 19px; text-align: center;">2</td>
<td style="width: 20%; height: 19px; text-align: center;">3</td>
<td style="width: 20%; height: 19px; text-align: center;">4</td>
</tr>
<tr style="height: 19px;">
<td style="width: 20%; height: 19px; text-align: center;">무게</td>
<td style="width: 20%; height: 19px; text-align: center;">6</td>
<td style="width: 20%; height: 19px; text-align: center;">4</td>
<td style="width: 20%; height: 19px; text-align: center;">3</td>
<td style="width: 20%; height: 19px; text-align: center;">5</td>
</tr>
<tr style="height: 19px;">
<td style="width: 20%; height: 19px; text-align: center;">가치</td>
<td style="width: 20%; height: 19px; text-align: center;">13</td>
<td style="width: 20%; height: 19px; text-align: center;">8</td>
<td style="width: 20%; height: 19px; text-align: center;">6</td>
<td style="width: 20%; height: 19px; text-align: center;">12</td>
</tr>
  
<table style="border-collapse: collapse; width: 100%; height: 114px;" border="1" data-ke-style="style12">
<tbody>
<tr style="height: 19px;">
<td style="width: 11.1111%; text-align: center; height: 19px;">&nbsp;</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">1</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">2</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">3</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">4</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">5</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">6</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">7</td>
</tr>
<tr style="height: 19px;">
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
</tr>
<tr style="height: 19px;">
<td style="width: 11.1111%; text-align: center; height: 19px;">1</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">13</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">13</td>
</tr>
<tr style="height: 19px;">
<td style="width: 11.1111%; text-align: center; height: 19px;">2</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;"><b><span style="color: #ee2323;">8</span></b></td>
<td style="width: 11.1111%; text-align: center; height: 19px;">8</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">13</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">13</td>
</tr>
<tr style="height: 19px;">
<td style="width: 11.1111%; text-align: center; height: 19px;">3</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">0</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">6</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">8</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">8</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">13</td>
<td style="width: 11.1111%; text-align: center; height: 19px;"><b><span style="color: #006dd7;">14</span></b></td>
</tr>
<tr style="height: 19px;">
<td style="width: 11.1111%; text-align: center; height: 19px;">4</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">&nbsp;</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">&nbsp;</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">&nbsp;</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">&nbsp;</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">&nbsp;</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">&nbsp;</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">&nbsp;</td>
<td style="width: 11.1111%; text-align: center; height: 19px;">&nbsp;</td>
</tr>
</tbody>
</table>
  
* 위 표의 (3,7)을 보게되면 다른 값들과는 조금 다른 방법으로 입력이 되었다는 것을 알 수 있음  
* 일단 (3,7)이라는 뜻은 3번째 보석을 용량이 7인 가방에 넣을때 넣을 수 있는 최대의 가치를 말하는 것임  
* 일단 3번째 보석이 용량이 7보다 크면 넣을 수 없으므로 (2,7)을 넣어야함  
* 하지만 위 경우에서는 무게가 3이므로 오히려 4의 용량이 남게 됨
* 이렇게되면 2번째 보석을 넣었을 때의 무게 3(최대용량 7- 현재보석 4)인 (2,3)의 최대 가치에 현재 보석의 가치를 더한 것과 (2,7)을 비교하여 더 큰 값을 dp로 취함
* 위와 같은 방법을 반복하면 마지막 (num, weight)의 dp값이 넣을 수 있는 최댓값이 됨
``` cpp
      for(int i = 1 ; i <= num ; i++)
    {
        for(int j = 1 ; j <= weight ; j++)
        {
            if(w[i] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j-w[i]] + v[i] , dp[i-1][j]);
            }
        }
    }
    cout << dp[num][weight];
  ```
