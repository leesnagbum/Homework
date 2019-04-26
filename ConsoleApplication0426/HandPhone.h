#pragma once

#include "pch.h"
#include <string>
#include <cstring>
#include <iostream>


class HandPhone
{
public:

	HandPhone();
	~HandPhone();

	void Input();
	void Print();
	void PowerOn();
	void PowerOff();
	void CameraYes();
	void CameraNo();

private:
	std::string model;
	std::string company;
	std::string color;

	bool on;
	bool install;
	char power;
	char camera;

};

