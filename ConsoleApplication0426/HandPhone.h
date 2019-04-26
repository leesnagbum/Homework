#pragma once

#include "pch.h"
#include <map>


// BSGJ : 핸드폰 클래스의 수정본입니다.

// 수정할 내용은 다음과 같습니다: 소프트웨어 설치, 메모리 관련 간단한 처리, 용량, 볼륨 관련;


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

		// 이름
		std::string name;

		// 메인메모리 사용량과 용량
		unsigned int ramUsage;
		unsigned int softwareSize;

		// 현재 실행중인가
		bool isExecutingNow;
	};

public:
	// 휴대전화는 제조되고나서 바뀔수 없는 불변의 상태를 몇개 가지고 있습니다.
	// 따라서 그 상태들은 읽기전용이 되어야하기 때문에 기본 생성자는 사용할 수 없습니다.
	HandPhone() = delete;

	HandPhone(std::string model, std::string company, std::string color, 
		bool hasCamera, unsigned int maxUserUseableMemory, unsigned int maxUserUseableStorageSize);
	~HandPhone() = default;

	void PrintStatus();

	// 전원 관련 조작
	void TogglePower();
	void PowerOn();
	void PowerOff();

	// 볼륨 조작 관련
	void VolumeUp();
	void VolumeDown();
	void SettingVolume(int newValue);

	// 소프트웨어 관련
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

	bool isPowered; // 전원이 켜져있는가?
	const bool hasCamera; // 카메라가 있는가?

	const unsigned int maxUserUseableMemory;
	const unsigned int maxUserUseableStorageSize;

	unsigned int currentUserUsedMemory;
	unsigned int userUseableStorageSize;
	
	// 소프트웨어는 중복으로 설치될 수 없다는 가정하에 저장합니다.
	// 또한 중복으로 실행될 수 없다는 가정을 두고있습니다.
	std::map<std::string, SimpleSoftware> softwares;
};

