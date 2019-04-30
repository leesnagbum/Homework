#include "pch.h"
#include "HandPhone.h"
#include <iostream>
#include <string>


void HandPhone::Input()
{

	std::cout << "모델명:";
	std::cin >> model;
	std::cout << "회사명:";
	std::cin >> company;
	std::cout << "색 상:";
	std::cin >> color;
	std::cout << "전원 상태:";
	std::cin >> isPowered;
	std::cout << "카메라 여부:";
	std::cin >> hasCamera;
	std::cout << std::endl;
}

void HandPhone::Print()
{
	std::cout << "상품의 모델명은 " << model << std::endl;
	std::cout << "상품의 회사명은 " << company << std::endl;
	std::cout << "상품의 색상은 " << color << std::endl;

	if (isPowered=='o')
	{
		PowerOn();
		std::cout << "전원이" << isPowered <<"켜져있습니다"<< std::endl;
	}
	else
	{
		PowerOff();
		std::cout << "전원이 꺼져있습니다." << (isPowered == false)<<std::endl;
	}

	if (hasCamera)
	{
		CameraYes();
		std::cout << "카메라가 장착되어있습니다." << (hasCamera == true)<< std::endl;
	}
	else
	{	
		CameraNo();
		std::cout << "카메라가 장착되어있지 않습니다." << (hasCamera == true)<<std::endl;
	}
}

// 전원을 끄고 키게 한다.
void HandPhone::TogglePower() { isPowered = !isPowered; } // 토글. 꺼져있을때에는 키고 켜져있을때에는 끈다.
void HandPhone::PowerOn() { isPowered = true; }
void HandPhone::PowerOff() { isPowered = false; }

// 카메라 여부 조작.
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
