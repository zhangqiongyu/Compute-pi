#include "GetPi.h"

int main(int argc, char **argv)
{
	int num = 10000000000;/*�������*/
	int num_thread = 4;
	GetPi get_pi(num, num_thread);
	get_pi.GetTime(Parallel);//����
	get_pi.GetTime(Serial);//����
	
	return 0;
}