DB curTable: neId neName neFlag
For integrity, need to get info from backup table bakTable: neId neName
Sync rule
1. for neId not in curTable, create curTable with neId, neName, neFlag=0
2. for neId in curTable, update neName if neName is different

neid, neName:
1. 1 <= neId <= 100000
2. neName is a string with length <= 20
3. neFlag < 10
4. curTableSize, bakTableSize <= 50000

output curTable by neId ascending order

Input:
curTableSize
curTable
bakTableSize
bakTable

Output:
curTable by neId ascending order

4
256 NE256 1
290 NE290 0
268 26900000 1
257 NE257 1
3
273 NE273
268 NE268
257 NE257

Output:

0
1
257 NE257
Output:
