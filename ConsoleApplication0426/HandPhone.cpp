#include "pch.h"
#include "HandPhone.h"
#include <iostream>
#include <algorithm>
#include <string>



HandPhone::HandPhone(std::string model, std::string company, std::string color, bool hasCamera, unsigned int maxUserUseableMemory, unsigned int maxUserUseableStorageSize)
	:model(model), company(company), color(color), hasCamera(hasCamera), maxUserUseableMemory(maxUserUseableMemory), maxUserUseableStorageSize(maxUserUseableStorageSize)
{
	volume = Setting::MaxVolume / 2;
	currentUserUsedMemory = 0;
	userUseableStorageSize = maxUserUseableStorageSize;
}

// 종합 정보를 나열합니다.
void HandPhone::PrintStatus()
{
	std::cout << "이 기기는 현재 전원이 " << (isPowered?"켜져":"꺼져") << " 있습니다.\n\n";

	std::cout << "모델명 : " << model << "\n";
	std::cout << "제조사 : " << company << "\n";
	std::cout << " 색깔  :" << color << "\n";
	std::cout << "현재볼륨크기 : " << volume << "\n";
	std::cout << "이 휴대전화는 카메라가 " << (hasCamera ? "있습니다." : "없습니다.") << "\n";
	
	std::cout << "\n\nRAM 크기 : " << maxUserUseableMemory << "\n";
	std::cout << "사용 가능한 RAM 크기 : " << maxUserUseableMemory-currentUserUsedMemory << "\n";
	
	std::cout << "\n\n최대 용량 : " << maxUserUseableStorageSize << "\n";
	std::cout << "사용 가능한 용량 : " << userUseableStorageSize << "\n";


	std::cout << "-- 설치되어있는 프로그램 정보 -- \n";
	for (auto i : softwares)
	{
		std::cout << (i.second.isExecutingNow?"EXE ":"    ") 
			<< i.second.name << ", " 
			<< i.second.softwareSize << "MB 사용, " 
			<< i.second.ramUsage << "만큼 RAM 점유\n\n";
	}

	std::cout.flush();
}

// 전원을 끄고 키게 한다.

// 토글. 꺼져있을때에는 키고 켜져있을때에는 끈다.
void HandPhone::TogglePower() { 
	if(isPowered) SoftwareTerminate(); // 전원이 켜져있는 상태에서 토글하면 끄는것이므로 프로그램을 종료해야한다.
	
	isPowered = !isPowered; 
} 
void HandPhone::PowerOn() { isPowered = true; }
void HandPhone::PowerOff() {
	if (isPowered)
	{
		SoftwareTerminate(); // 종료시에는 프로그램을 종료한다.
		isPowered = false;
	}
}



// 볼륨 관련 조작
void HandPhone::SettingVolume(int newValue)
{
	if (!isPowered) return; // 전원 꺼져있으면 동작 불능

	if (newValue > Setting::MaxVolume) volume = Setting::MaxVolume;
	else if (newValue < 0) volume = 0;
	else volume = newValue;
}
void HandPhone::VolumeUp()
{
	if (!isPowered) return; // 전원 꺼져있으면 동작 불능

	volume += Setting::VolumeChangeAmount;
	if (volume > Setting::MaxVolume) volume = Setting::MaxVolume;
}
void HandPhone::VolumeDown()
{
	if (!isPowered) return; // 전원 꺼져있으면 동작 불능

	volume -= Setting::VolumeChangeAmount;
	if (volume < 0) volume = 0;
}




// 소프트웨어 설치 및 삭제
bool HandPhone::InstallSoftware(SimpleSoftware soft)
{
	if (!isPowered) return false; // 전원 꺼져있으면 동작 불능

	if(softwares.find(soft.name) != softwares.end()    // 이미 존재하거나
		|| soft.softwareSize > userUseableStorageSize) // 사용 가능한 용량보다 클 경우 거부.
		return false;

	
	userUseableStorageSize -= soft.softwareSize; // 용량 줄이고
	softwares[soft.name] = soft;				 // 등록
	return true;
}
bool HandPhone::DeleteSoftware(std::string name)
{
	if (!isPowered) return false; // 전원 꺼져있으면 동작 불능

	if (softwares.find(name) == softwares.end() ||	// 대상이 없거나
		softwares[name].isExecutingNow)				// 대상이 실행중이라면 
		return false;								// 거부


	userUseableStorageSize += softwares[name].softwareSize; // 용량 다시 확보하고
	softwares.erase(name);									// 제거
	return true;
}



// 대상 실행
bool HandPhone::SoftwareExecution(std::string name)
{
	if (!isPowered) return false; // 전원 꺼져있으면 동작 불능

	if ( (softwares.find(name) == softwares.end())										// 대상이 없거나
		|| (softwares[name].ramUsage+currentUserUsedMemory > maxUserUseableMemory) 		// 가용 메모리가 부족하거나
		|| (softwares[name].isExecutingNow))											// 이미 실행중이라면
		return false;																	// 거부
	
	// 실행이라 설정하고 메모리를 감소시킨다.
	softwares[name].isExecutingNow = true;
	currentUserUsedMemory += softwares[name].ramUsage;

	return true;
}

// 전체 종료
bool HandPhone::SoftwareTerminate()
{
	if (!isPowered) return false; // 전원 꺼져있으면 동작 불능

	// 모두 접근하여 실행 상태가 아님을 명확히 한 후
	for (auto i : softwares) i.second.isExecutingNow = false;
	currentUserUsedMemory = 0; // 모든 프로그램이 종료되었으므로 메모리 초기화
	return true;
}

// 대상 종료
bool HandPhone::SoftwareTerminate(std::string name)
{
	if (!isPowered) return false; // 전원 꺼져있으면 동작 불능

	if ( (softwares.find(name) == softwares.end())	// 대상이 존재하지 않거나
		|| (!softwares[name].isExecutingNow) )		// 대상이 실행중이지 않다면
		return false; // 거부

	// 중단으로 설정하고 메모리를 확보한다.
	softwares[name].isExecutingNow = false;
	currentUserUsedMemory -= softwares[name].ramUsage;

	return true;
}
