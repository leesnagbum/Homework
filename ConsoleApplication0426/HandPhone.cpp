#include "pch.h"
#include "HandPhone.h"
#include <iostream>
#include <string>


void HandPhone::Input()
{
	std::cout << "모델명:" << model << std::endl;
	std::cout << "회사명:" << company << std::endl;
	std::cout << "색 상:" << color << std::endl;
	std::cout << "전원 상태:" << power << std::endl;
	std::cout << "카메라 여부:" << camera << std::endl;
}

void HandPhone::Print()
{
	std::cout << "상품의 모델명은 " << model << std::endl;
	std::cout << "상품의 회사명은 " << company << std::endl;
	std::cout << "상품의 색상은 " << color << std::endl;

	if (power == "on" || power == "ON")
	{
		PowerOn();
	}
	else
	{
		PowerOff();
	}
}

void HandPhone::PowerOn()
{

}
void HandPhone::PowerOff()
{

}
void HandPhone::CameraYes()
{

}
void HandPhone::CameraNo()
{

}


