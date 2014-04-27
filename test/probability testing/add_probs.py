infile = open("atest.dat", 'r')
out = open("atest_3.dat", "w")

line = infile.readline()
while line:
	out.write(line.strip("\n")+" 0.50\n")
	line = infile.readline()

infile.close()
out.close()
