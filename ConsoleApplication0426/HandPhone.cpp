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
	std::cin >> power;
	std::cout << "ī�޶� ����:";
	std::cin >> camera;
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


