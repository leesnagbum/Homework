// ConsoleApplication0425.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
class NameCard
{
	char *m_Name;
	char *m_Phone;
	char *m_Address;
	char *m_Pos;
public:
	NameCard(char *strName, char *strPhone, char *strAddress, char *strPos)
	{
		m_Name = new char[strlen(strName) + 1];
		strcpy_s(m_Name, strlen(strName) + 1, strName);

		m_Phone = new char[strlen(strPhone) + 1];
		strcpy_s(m_Phone, strlen(strPhone) + 1, strPhone);

		m_Address = new char[strlen(strAddress) + 1];
		strcpy_s(m_Address, strlen(strAddress) + 1, strAddress);

		m_Pos = new char[strlen(strPos) + 1];
		strcpy_s(m_Pos, strlen(strPos) + 1, strPos);
	};
	~NameCard()
	{
		if (m_Address != NULL)
		{
			delete[]m_Address;
			m_Address = NULL;
		}
		if (m_Phone != NULL)
		{
			delete[]m_Phone;
			m_Phone = NULL;
		}
		if (m_Pos != NULL)
		{
			delete[]m_Pos;
			m_Pos = NULL;
		}
		if (m_Name != NULL)
		{
			delete[]m_Name;
			m_Name = NULL;
		}
	};
	void ShowData()
	{
		std::cout << "이    름: " << m_Name << std::endl;
		std::cout << "전화번호: " << m_Phone << std::endl;
		std::cout << "주    소: " << m_Address << std::endl;
		std::cout << "직    급: " << m_Pos << std::endl;
	};
};
int main()
{
   
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
