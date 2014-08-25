/*test for pc source binary file; takes binary file and reverses it to RA/DEC/PROBABILITY. works. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "test.h"

int main()
{
	FILE *in, *out; 
	int i, NumSamples, NumData;
	int *Samples;
	double rad2deg, raRad, decRad, ra, dec, cdecRad;
	pcsource *data;
	Samples = NULL;

	in = fopen("atest_1.dat0.bin", "r");
	out = fopen("test.dat", "wb");
	fread(&NumSamples, sizeof(int), 1, in);
	printf("%d\n", NumSamples);

	Samples = malloc((NumSamples+1)*sizeof(int));

	if(fread(Samples,sizeof(int),(NumSamples+1),in) != (NumSamples+1))
		printf("%s\n", "error");

	printf("%d\n", *Samples);
	data = malloc(*Samples*sizeof(pcsource));

	fread(data,sizeof(pcsource),*Samples,in);

	rad2deg = 180/M_PI;
	NumData = *Samples;
	//printf("%f\n", data[0].y);
	for(i=0; i<NumData; i++)
	{
		decRad = asin(data[i].z);
		cdecRad = cos(decRad);
		raRad = acos(data[i].x/cdecRad);
		ra = raRad*rad2deg; 
		dec = decRad*rad2deg;
		fprintf(out, "%f", ra);
		fprintf(out, "%s %f", "", dec);
		fprintf(out, "%s %f\n", "", data[i].probability);
	}
}
