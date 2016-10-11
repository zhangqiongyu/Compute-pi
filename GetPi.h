#ifndef GETPI_H
#define GETPI_H

#include <iostream>
#include <omp.h>
#include <iomanip>

enum Mode { Parallel, Serial };
class GetPi
{
private: 
	double width;
	int num;
	double pi;
	double time;
	int num_threads;//并行计算线程数，默认为1
	Mode currentmode;
public:
	GetPi(int n, int num_threads = 1) :num(n), num_threads(num_threads), time(0), pi(0)
	{ 
		width = 1.0 / double(num);
	}
	void ComputePiSerial();
	void ComputePiParallel();
	void GetTime(Mode mode);
};
#endif // !GETPI_H