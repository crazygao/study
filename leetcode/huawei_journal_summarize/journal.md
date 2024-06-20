Journal line type, DAU, MAU.
`yyyy-mm-dd|client_ip|url|result`
DAU: how many unique client_ip with url /login.do and result=success in a DAY
MAU: how many unique client_ip with url /login.do and result=success in a MONTH

Inputs:
input number n: 1 <= n <= 50000
next n lines of logs
Outputs:
32 integers, first number is MAU, next 31 numbers are DAU of each day in the month

2022-06-18|123.1.1.1|/login.do|success
2022-06-18|122.1.1.1|/login.do|success