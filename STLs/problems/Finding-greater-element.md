## Problem Name: Find the greater element
### Problem Difficulty: None
#### Problem Constraints: 
1 <= n <= 10^6
-10^8 <= A<sub>i</sub> <= 10^8 , 0<= i< n

#### Problem Description:
We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element A<sub>i</sub> , start from index i + 1 and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.

#### Input Format: 
First line contains the length of the array n.
Second line contains the n space separated integers.
* Sample Input: 
<pre>
3
1 2 3
</pre>

#### Output Format: 
Print n space separated integers each representing the next greater element.
* Sample Output:
<pre> 
2 3 -1
</pre>