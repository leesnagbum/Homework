#include "pch.h"
#include "NameCard.h"

#include <iostream>

NameCard::NameCard(std::string name, std::string position, std::string companyName, 
	std::string companyAddress, std::string tel, std::string fax, std::string email)
	:name(name), position(position), companyName(companyName), companyAddress(companyAddress), tel(tel), fax(fax), email(email)
{}

// Getter들. 변수 대신 이것을 노출하기 때문에 읽기전용으로 사용될 수 있습니다.
std::string NameCard::GetName() const { return name; }
std::string NameCard::GetPosition() const { return position; }
std::string NameCard::GetCompanyName() const { return companyName; }
std::string NameCard::GetCompanyAddress() const { return companyAddress; }
std::string NameCard::GetTelNumber() const { return tel; }
std::string NameCard::GetFaxNumber() const { return fax; }
std::string NameCard::GetEmail() const { return email; }


void NameCard::Print() const
{
	// 순서는 회사명, 이름, 직급, 전화번호, 팩스번호, 이메일, 회사주소
	std::cout << "====== [" << name << "의 명함] ======\n";
	std::cout << "회사명 : " << companyName << "\n";
	std::cout << "이  름 : " << name << "\n";
	std::cout << "직  급 : " << position << "\n";
	std::cout << " TEL   : " << tel << "\n";
	std::cout << " FAX   : " << fax << "\n";
	std::cout << "Email  : " << email << "\n";
	std::cout << "회사주소 : " << companyAddress << "\n\n\n";

	std::cout.flush();
}