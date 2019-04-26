#include "pch.h"
#include "HandPhone.h"
#include <iostream>
#include <string>


void HandPhone::Input()
{


	std::cout << "�𵨸�:";
	std::cin >> model;

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

	if (isPower)
	{
		std::cout << "������ �����ֽ��ϴ�." << std::endl;
	}
	else
	{
		std::cout << "������ �����ֽ��ϴ�." << std::endl;
	}
}

// ������ ���� Ű�� �Ѵ�.
void HandPhone::TogglePower() { isPowered = !isPowered; } // ���. �������������� Ű�� �������������� ����.
void HandPhone::PowerOn() { isPowered = true; }
void HandPhone::PowerOff() { isPowered = false; }



// ī�޶� ���� ����.
void HandPhone::CameraYes(){ hasCamera = true; }
void HandPhone::CameraNo() { hasCamera = false; }


