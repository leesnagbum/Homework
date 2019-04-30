#include "pch.h"
#include "HandPhone.h"
#include <iostream>
#include <string>


void HandPhone::Input()
{

	std::cout << "�𵨸�:";
	std::cin >> model;
	std::cout << "ȸ���:";
	std::cin >> company;
	std::cout << "�� ��:";
	std::cin >> color;
	std::cout << "���� ����:";
	std::cin >> isPowered;
	std::cout << "ī�޶� ����:";
	std::cin >> hasCamera;
	std::cout << std::endl;
}

void HandPhone::Print()
{
	std::cout << "��ǰ�� �𵨸��� " << model << std::endl;
	std::cout << "��ǰ�� ȸ����� " << company << std::endl;
	std::cout << "��ǰ�� ������ " << color << std::endl;

	if (isPowered=='o')
	{
		PowerOn();
		std::cout << "������" << isPowered <<"�����ֽ��ϴ�"<< std::endl;
	}
	else
	{
		PowerOff();
		std::cout << "������ �����ֽ��ϴ�." << (isPowered == false)<<std::endl;
	}

	if (hasCamera)
	{
		CameraYes();
		std::cout << "ī�޶� �����Ǿ��ֽ��ϴ�." << (hasCamera == true)<< std::endl;
	}
	else
	{	
		CameraNo();
		std::cout << "ī�޶� �����Ǿ����� �ʽ��ϴ�." << (hasCamera == true)<<std::endl;
	}
}

// ������ ���� Ű�� �Ѵ�.
void HandPhone::TogglePower() { isPowered = !isPowered; } // ���. �������������� Ű�� �������������� ����.
void HandPhone::PowerOn() { isPowered = true; }
void HandPhone::PowerOff() { isPowered = false; }

// ī�޶� ���� ����.
void HandPhone::CameraYes(){ hasCamera = true; }
void HandPhone::CameraNo() { hasCamera = false; }


int main(void)
{
	HandPhone phone;
	phone.Input();
	phone.Print();
	phone.PowerOn();
	phone.PowerOff();
	phone.CameraYes();
	phone.CameraNo();
	
}
