#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
using namespace std;
int main()
{
	printf("Start priting......\n");
	while (true) {
		Sleep(3000);
		keybd_event('E', 0, 0, 0);
		keybd_event('E', 0, KEYEVENTF_KEYUP, 0);
		printf("Pressed button E\n");
	}

}