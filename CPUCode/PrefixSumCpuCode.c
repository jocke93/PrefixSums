#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"
#include "timer.h"

int main(void) {
	int8_t *data_in, *data_out, *data_outSeq;
	int N, i;
	double elapsed_time;

	//1 Kilo data

	printf("1K data:\n");
	N=1024;
	data_in = malloc(N * sizeof(int8_t));
	data_out = malloc(N * sizeof(int8_t));
	data_outSeq = malloc(N * sizeof(int8_t));

	for (i = 0; i < N; ++i) {
		data_in[i] = (random() % 100) / 100.0 * 100;
	}

	printf("Running on DFE.\n");

	startTime();
	PrefixSum(N, data_in, data_out);
	stopTime(elapsed_time);
	printf("Maxeler time: %.2f\n", elapsed_time * 1e-3);

	startTime();
	data_outSeq[0]=data_in[0];
	for(i=1; i<N; i++) {
		data_outSeq[i]=data_outSeq[i-1] + data_in[i];
	}
	stopTime(elapsed_time);
	printf("Seq time: %.2f\n", elapsed_time * 1e-3);

	for(i=0; i<N; i++) {
		if(data_out[i]!=data_outSeq[i]) {
			printf("Test FAILED\n\n");
			break;
		}
	}

	if(i==N) printf("Test PASSED\n\n");

	printf("Done.\n");
	free(data_in);
	free(data_out);
	free(data_outSeq);

	//1 Mega data
	printf("1M data:\n");
	N=1024*1024;
	data_in = malloc(N * sizeof(int8_t));
	data_out = malloc(N * sizeof(int8_t));
	data_outSeq = malloc(N * sizeof(int8_t));

	for (i = 0; i < N; ++i) {
		data_in[i] = (random() % 100) / 100.0 * 100;
	}

	printf("Running on DFE.\n");

	startTime();
	PrefixSum(N, data_in, data_out);
	stopTime(elapsed_time);
	printf("Maxeler time: %.2f\n", elapsed_time * 1e-3);

	startTime();
	data_outSeq[0]=data_in[0];
	for(i=1; i<N; i++) {
		data_outSeq[i]=data_outSeq[i-1] + data_in[i];
	}
	stopTime(elapsed_time);
	printf("Seq time: %.2f\n", elapsed_time * 1e-3);

	for(i=0; i<N; i++) {
		if(data_out[i]!=data_outSeq[i]) {
			printf("Test FAILED\n\n");
			break;
		}
	}

	if(i==N) printf("Test PASSED\n\n");

	printf("Done.\n");
	free(data_in);
	free(data_out);
	free(data_outSeq);

	//1 Giga data
	printf("10M data:\n");
	N=1024*1024*10;
	data_in = malloc(N * sizeof(int8_t));
	data_out = malloc(N * sizeof(int8_t));
	data_outSeq = malloc(N * sizeof(int8_t));

	for (i = 0; i < N; ++i) {
		data_in[i] = (random() % 100) / 100.0 * 100;
	}

	printf("Running on DFE.\n");

	startTime();
	PrefixSum(N, data_in, data_out);
	stopTime(elapsed_time);
	printf("Maxeler time: %.2f\n", elapsed_time * 1e-3);

	startTime();
	data_outSeq[0]=data_in[0];
	for(i=1; i<N; i++) {
		data_outSeq[i]=data_outSeq[i-1] + data_in[i];
	}
	stopTime(elapsed_time);
	printf("Seq time: %.2f\n", elapsed_time * 1e-3);

	for(i=0; i<N; i++) {
		if(data_out[i]!=data_outSeq[i]) {
			printf("Test FAILED\n\n");
			break;
		}
	}

	if(i==N) printf("Test PASSED\n\n");

	printf("Done.\n");
	free(data_in);
	free(data_out);
	free(data_outSeq);

	return 0;
}

