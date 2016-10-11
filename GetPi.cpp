#include "GetPi.h"
using namespace std;

void GetPi::ComputePiSerial()
{
	double sum = 0.0;
	double x;
	for (int i = 0; i < num; i++)
	{
		x = width*(double(i) - 0.5);
		sum += 4.0 / (1.0 + x*x);
	}
	pi = width*sum;
}

void GetPi::ComputePiParallel()
{
	double sum = 0.0, l_sum = 0.0;
	double x;

	omp_set_num_threads(num_threads);//���ò����߳���
	
	#pragma omp parallel for private(x) reduction(+:sum) 
		for (int i = 0; i < num; i++)
		{
			x = width*(double(i) - 0.5);
			sum += 4.0 / (1.0 + x*x);
		}	
	
	pi = width*sum;
}

void GetPi::GetTime(Mode mode)
{	
	currentmode = mode;
	double t_start = omp_get_wtime();
	double t_end;
	switch (currentmode)
	{
	case Parallel:
		ComputePiParallel();
		t_end = omp_get_wtime();
		time = t_end - t_start;
		cout << "�������pi = " << setprecision(10) << pi << endl;
		cout << "��������ʱ��Ϊ��" << time << "s" << endl;
		break;
	case Serial:
		ComputePiSerial();
		t_end = omp_get_wtime();
		time = t_end - t_start;
		cout << "�������pi = " << setprecision(10) << pi << endl;
		cout << "��������ʱ��Ϊ��" << time << "s" << endl;
		break;
	default:
		break;
	}
}