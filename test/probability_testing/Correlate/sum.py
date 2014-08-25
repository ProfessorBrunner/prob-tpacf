"""

   Abysmal script written on the fly to check if the test suggested by Matias works (it does but the bin counts are off by a couple thousand). To be changed later to make it less abysmal. 

"""
import os

def sum_numbers_in_file(filename):

    with open(filename) as f:
        m = f.readlines()[2:]
        n = sum([sum([float(x) for x in line.split()]) for line in m]) 
        o = n - 0.316227766017
        f.close()
        return n

os.chdir("/Users/harshilkamdar/Desktop/prob-tpacf/test/probability testing/Bins")

a = sum_numbers_in_file('Original.dat_Original.dat_drbins')
b = sum_numbers_in_file('Bin_1.dat_Bin_1.dat_drbins')
c = sum_numbers_in_file('Bin_2.dat_Bin_2.dat_drbins')
d = sum_numbers_in_file('Bin_3.dat_Bin_3.dat_drbins')
f = sum_numbers_in_file('Bin_1.dat_Bin_2.dat_drbins')
g = sum_numbers_in_file('Bin_1.dat_Bin_3.dat_drbins')
h = sum_numbers_in_file('Bin_2.dat_Bin_1.dat_drbins')
i = sum_numbers_in_file('Bin_2.dat_Bin_3.dat_drbins')
j = sum_numbers_in_file('Bin_3.dat_Bin_1.dat_drbins')
l = sum_numbers_in_file('Bin_3.dat_Bin_2.dat_drbins')

k = b+c+d+f+g+h+i+j+l

print a
print k

print "Done!"