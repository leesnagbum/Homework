#include "pch.h"
#include "HandPhone.h"
#include <iostream>
#include <string>


void HandPhone::Input()
{
	std::cout << "�𵨸�:" << model << std::endl;
	std::cout << "ȸ���:" << company << std::endl;
	std::cout << "�� ��:" << color << std::endl;
	std::cout << "���� ����:" << power << std::endl;
	std::cout << "ī�޶� ����:" << camera << std::endl;
}

void HandPhone::Print()
{
	std::cout << "��ǰ�� �𵨸��� " << model << std::endl;
	std::cout << "��ǰ�� ȸ����� " << company << std::endl;
	std::cout << "��ǰ�� ������ " << color << std::endl;

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


