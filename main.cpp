#include "GetPi.h"

int main(int argc, char **argv)
{
	int num = 10000000000;/*区间个数*/
	int num_thread = 4;
	GetPi get_pi(num, num_thread);
	get_pi.GetTime(Parallel);//并行
	get_pi.GetTime(Serial);//串行
	
	return 0;
}