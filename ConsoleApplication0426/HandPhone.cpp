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

// ���� ������ �����մϴ�.
void HandPhone::PrintStatus()
{
	std::cout << "�� ���� ���� ������ " << (isPowered?"����":"����") << " �ֽ��ϴ�.\n\n";

	std::cout << "�𵨸� : " << model << "\n";
	std::cout << "������ : " << company << "\n";
	std::cout << " ����  :" << color << "\n";
	std::cout << "���纼��ũ�� : " << volume << "\n";
	std::cout << "�� �޴���ȭ�� ī�޶� " << (hasCamera ? "�ֽ��ϴ�." : "�����ϴ�.") << "\n";
	
	std::cout << "\n\nRAM ũ�� : " << maxUserUseableMemory << "\n";
	std::cout << "��� ������ RAM ũ�� : " << maxUserUseableMemory-currentUserUsedMemory << "\n";
	
	std::cout << "\n\n�ִ� �뷮 : " << maxUserUseableStorageSize << "\n";
	std::cout << "��� ������ �뷮 : " << userUseableStorageSize << "\n";


	std::cout << "-- ��ġ�Ǿ��ִ� ���α׷� ���� -- \n";
	for (auto i : softwares)
	{
		std::cout << (i.second.isExecutingNow?"EXE ":"    ") 
			<< i.second.name << ", " 
			<< i.second.softwareSize << "MB ���, " 
			<< i.second.ramUsage << "��ŭ RAM ����\n\n";
	}

	std::cout.flush();
}

// ������ ���� Ű�� �Ѵ�.

// ���. �������������� Ű�� �������������� ����.
void HandPhone::TogglePower() { 
	if(isPowered) SoftwareTerminate(); // ������ �����ִ� ���¿��� ����ϸ� ���°��̹Ƿ� ���α׷��� �����ؾ��Ѵ�.
	
	isPowered = !isPowered; 
} 
void HandPhone::PowerOn() { isPowered = true; }
void HandPhone::PowerOff() {
	if (isPowered)
	{
		SoftwareTerminate(); // ����ÿ��� ���α׷��� �����Ѵ�.
		isPowered = false;
	}
}



// ���� ���� ����
void HandPhone::SettingVolume(int newValue)
{
	if (!isPowered) return; // ���� ���������� ���� �Ҵ�

	if (newValue > Setting::MaxVolume) volume = Setting::MaxVolume;
	else if (newValue < 0) volume = 0;
	else volume = newValue;
}
void HandPhone::VolumeUp()
{
	if (!isPowered) return; // ���� ���������� ���� �Ҵ�

	volume += Setting::VolumeChangeAmount;
	if (volume > Setting::MaxVolume) volume = Setting::MaxVolume;
}
void HandPhone::VolumeDown()
{
	if (!isPowered) return; // ���� ���������� ���� �Ҵ�

	volume -= Setting::VolumeChangeAmount;
	if (volume < 0) volume = 0;
}




// ����Ʈ���� ��ġ �� ����
bool HandPhone::InstallSoftware(SimpleSoftware soft)
{
	if (!isPowered) return false; // ���� ���������� ���� �Ҵ�

	if(softwares.find(soft.name) != softwares.end()    // �̹� �����ϰų�
		|| soft.softwareSize > userUseableStorageSize) // ��� ������ �뷮���� Ŭ ��� �ź�.
		return false;

	
	userUseableStorageSize -= soft.softwareSize; // �뷮 ���̰�
	softwares[soft.name] = soft;				 // ���
	return true;
}
bool HandPhone::DeleteSoftware(std::string name)
{
	if (!isPowered) return false; // ���� ���������� ���� �Ҵ�

	if (softwares.find(name) == softwares.end() ||	// ����� ���ų�
		softwares[name].isExecutingNow)				// ����� �������̶�� 
		return false;								// �ź�


	userUseableStorageSize += softwares[name].softwareSize; // �뷮 �ٽ� Ȯ���ϰ�
	softwares.erase(name);									// ����
	return true;
}



// ��� ����
bool HandPhone::SoftwareExecution(std::string name)
{
	if (!isPowered) return false; // ���� ���������� ���� �Ҵ�

	if ( (softwares.find(name) == softwares.end())										// ����� ���ų�
		|| (softwares[name].ramUsage+currentUserUsedMemory > maxUserUseableMemory) 		// ���� �޸𸮰� �����ϰų�
		|| (softwares[name].isExecutingNow))											// �̹� �������̶��
		return false;																	// �ź�
	
	// �����̶� �����ϰ� �޸𸮸� ���ҽ�Ų��.
	softwares[name].isExecutingNow = true;
	currentUserUsedMemory += softwares[name].ramUsage;

	return true;
}

// ��ü ����
bool HandPhone::SoftwareTerminate()
{
	if (!isPowered) return false; // ���� ���������� ���� �Ҵ�

	// ��� �����Ͽ� ���� ���°� �ƴ��� ��Ȯ�� �� ��
	for (auto i : softwares) i.second.isExecutingNow = false;
	currentUserUsedMemory = 0; // ��� ���α׷��� ����Ǿ����Ƿ� �޸� �ʱ�ȭ
	return true;
}

// ��� ����
bool HandPhone::SoftwareTerminate(std::string name)
{
	if (!isPowered) return false; // ���� ���������� ���� �Ҵ�

	if ( (softwares.find(name) == softwares.end())	// ����� �������� �ʰų�
		|| (!softwares[name].isExecutingNow) )		// ����� ���������� �ʴٸ�
		return false; // �ź�

	// �ߴ����� �����ϰ� �޸𸮸� Ȯ���Ѵ�.
	softwares[name].isExecutingNow = false;
	currentUserUsedMemory -= softwares[name].ramUsage;

	return true;
}
