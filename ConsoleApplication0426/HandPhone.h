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

	bool isPowered; // ������ �����ִ°�?
	bool hasCamera; // ī�޶� �ִ°�?


	// �� ������ ~~�� �մϴ�. ~~~�� ��Ÿ���ϴ�.
	

};

