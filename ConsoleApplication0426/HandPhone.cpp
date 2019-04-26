#include "pch.h"
#include "HandPhone.h"
#include <iostream>
#include <string>


void HandPhone::Input()
{


	std::cout << "모델명:";
	std::cin >> model;

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

	if (isPower)
	{
		std::cout << "전원이 켜져있습니다." << std::endl;
	}
	else
	{
		std::cout << "전원이 꺼져있습니다." << std::endl;
	}
}

// 전원을 끄고 키게 한다.
void HandPhone::TogglePower() { isPowered = !isPowered; } // 토글. 꺼져있을때에는 키고 켜져있을때에는 끈다.
void HandPhone::PowerOn() { isPowered = true; }
void HandPhone::PowerOff() { isPowered = false; }



// 카메라 여부 조작.
void HandPhone::CameraYes(){ hasCamera = true; }
void HandPhone::CameraNo() { hasCamera = false; }


