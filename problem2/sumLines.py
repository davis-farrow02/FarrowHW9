# code name: sumLines.py
# code by: Davis Farrow
# 
# CPE 422 HW 9 problem 2
# this code reads a text file and computes the sum, number
# of integers, and the average of all numbers.
#
# Example invocation and output:
# debian@beaglebone:$ python3 sumLines.py dataInput.txt
# 917 26 35.26923076923077
# 
# Where sum = 917, Number of Elements = 26, and Average = 35.26923076923077

import sys

def checkline(): # number of elements total in file
    global l
    global elementcount
    w = l.split()
    elementcount += len(w)
def checksum(): # sum of all elements in file
    global total
    w = l.split()
    sums = map(int, w)
    total += sum(sums)

elementcount = 0
total = 0
f = open(sys.argv[1])
flines = f.readlines()
for l in flines:
    checkline()
    checksum()
average = total/elementcount # average value of all elements in file
print (total, elementcount, average)
