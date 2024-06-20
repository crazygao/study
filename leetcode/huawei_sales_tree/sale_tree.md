Sales point distribution
Chief Sales <-- Multiple Country Sales <-- etc

Build Tree Input:
Number
01...99

First line integer n. How many sales.
Second line integer m. How many sales has a successor.
M lines: ID k ID[1] ... ID[k]
Final line: the one that need to calculate which level is the most popular level

Output:
Array with two numbers
1st: the most popular level
2nd: the most popular number

Example
23
13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18

01
4 9
09
1 1
06
2 2
20
1 1

4
2
01 1 02
02 2 03 04
