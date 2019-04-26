#pragma once

#include "pch.h"
#include <map>


// BSGJ : �ڵ��� Ŭ������ �������Դϴ�.

// ������ ������ ������ �����ϴ�: ����Ʈ���� ��ġ, �޸� ���� ������ ó��, �뷮, ���� ����;


class HandPhone
{
private:
	enum Setting {
		MaxVolume = 100,
		VolumeChangeAmount = 10,
	};

public:
	struct SimpleSoftware {
		SimpleSoftware() :isExecutingNow(false) {}

		// �̸�
		std::string name;

		// ���θ޸� ��뷮�� �뷮
		unsigned int ramUsage;
		unsigned int softwareSize;

		// ���� �������ΰ�
		bool isExecutingNow;
	};

public:
	// �޴���ȭ�� �����ǰ��� �ٲ�� ���� �Һ��� ���¸� � ������ �ֽ��ϴ�.
	// ���� �� ���µ��� �б������� �Ǿ���ϱ� ������ �⺻ �����ڴ� ����� �� �����ϴ�.
	HandPhone() = delete;

	HandPhone(std::string model, std::string company, std::string color, 
		bool hasCamera, unsigned int maxUserUseableMemory, unsigned int maxUserUseableStorageSize);
	~HandPhone() = default;

	void PrintStatus();

	// ���� ���� ����
	void TogglePower();
	void PowerOn();
	void PowerOff();

	// ���� ���� ����
	void VolumeUp();
	void VolumeDown();
	void SettingVolume(int newValue);

	// ����Ʈ���� ����
	bool InstallSoftware(SimpleSoftware soft);
	bool DeleteSoftware(std::string name);
	bool SoftwareExecution(std::string name);

	bool SoftwareTerminate();
	bool SoftwareTerminate(std::string name);


private:
	const std::string model;
	const std::string company;
	const std::string color;

	int volume;

	bool isPowered; // ������ �����ִ°�?
	const bool hasCamera; // ī�޶� �ִ°�?

	const unsigned int maxUserUseableMemory;
	const unsigned int maxUserUseableStorageSize;

	unsigned int currentUserUsedMemory;
	unsigned int userUseableStorageSize;
	
	// ����Ʈ����� �ߺ����� ��ġ�� �� ���ٴ� �����Ͽ� �����մϴ�.
	// ���� �ߺ����� ����� �� ���ٴ� ������ �ΰ��ֽ��ϴ�.
	std::map<std::string, SimpleSoftware> softwares;
};

