#pragma once

#include "pch.h"
#include <string>
#include <cstring>
#include <iostream>


class HandPhone
{
public:

	HandPhone();
	~HandPhone() = default;

	void Input();
	void Print();
	void TogglePower();

	void PowerOn();
	void PowerOff();

	void CameraYes();
	void CameraNo();


private:
	std::string model;
	std::string company;
	std::string color;

	bool isPowered; // 전원이 켜져있는가?
	bool hasCamera; // 카메라가 있는가?


	// 이 변수는 ~~를 합니다. ~~~를 나타냅니다.
	

};

