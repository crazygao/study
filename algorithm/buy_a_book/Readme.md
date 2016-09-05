A book value 8 Euro.
Here is a list of discount.
| Book Num | Discount |
|----------|----------|
|2|5%|
|3|10%|
|4|20%|
|5|25%|
calculate how to buy and the minimum price

Only different books in a series can have this account,
eg, Type 1 + Type 1 won't have discount
eg2, Type 1 + Type 2 could have the 5% discount

Analysis

Total Discount

|Book Num|Strategy|Total Value|
|--------|--------|-----------|
|2|2|2\*5%\*8 = 0.8|
|3|3|3\*10%\*8 = 2.4|
|4|4|6.4|
|5|5|10|
|6|1 + 5|10|
|6|2 + 4|7.2|
etc

There is a list of Input
Book you want to buy can be a list of 5
[Y1, Y2, Y3, Y4, Y5]
Output the Strategy, for using the different combine of discounts
[Z1, Z2, Z3, Z4, Z5]
Of course Z1 * 1 + Z2 * 2 + Z3 * 3 + Z4 * 4 + Z5 * 5 = Y1 + ... + Y5
and a discount value Z = Z1 * 1 + Z2 * 2 * X2 + ...
Z should be maximized.
