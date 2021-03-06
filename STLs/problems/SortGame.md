## Problem Name: Sort Game
### Problem Difficulty: 1
#### Problem Constraints: 1 <= N <= 10^5
1 <= | Length of the name | <= 100 
1 <= x, salary <= 100

#### Problem Description:
Sanju needs your help! He gets a list of employees with their salary. The maximum salary  is 100.
<br/>
Sanju is supposed to arrange the list in such a manner that the list is sorted in decreasing order of salary. And if two employees have the same salary, they should be arranged in lexicographical manner such that the list contains only names of those employees having salary greater than or equal to a given number  x.

Help Sanju prepare the same!
<br/>

#### Input Format:
On the first line of the standard input, there is an integer x. The next line contans integer N, denoting the number of employees. N lines follow, which contain a string and an integer, denoting the name of the employee and his salary. 
* Sample Input:
<pre>
79
4
Eve 78
Bob 99
Suzy 86
Alice 86
</pre>
#### Output Format: 
You must print the required list. 
* Sample Output:
<pre>
Bob 99
Alice 86
Suzy 86
</pre>
