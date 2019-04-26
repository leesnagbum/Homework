#include "pch.h"
#include "NameCard.h"

#include <iostream>

NameCard::NameCard(std::string name, std::string position, std::string companyName, 
	std::string companyAddress, std::string tel, std::string fax, std::string email)
	:name(name), position(position), companyName(companyName), companyAddress(companyAddress), tel(tel), fax(fax), email(email)
{}

// Getter��. ���� ��� �̰��� �����ϱ� ������ �б��������� ���� �� �ֽ��ϴ�.
std::string NameCard::GetName() const { return name; }
std::string NameCard::GetPosition() const { return position; }
std::string NameCard::GetCompanyName() const { return companyName; }
std::string NameCard::GetCompanyAddress() const { return companyAddress; }
std::string NameCard::GetTelNumber() const { return tel; }
std::string NameCard::GetFaxNumber() const { return fax; }
std::string NameCard::GetEmail() const { return email; }


void NameCard::Print() const
{
	// ������ ȸ���, �̸�, ����, ��ȭ��ȣ, �ѽ���ȣ, �̸���, ȸ���ּ�
	std::cout << "====== [" << name << "�� ����] ======\n";
	std::cout << "ȸ��� : " << companyName << "\n";
	std::cout << "��  �� : " << name << "\n";
	std::cout << "��  �� : " << position << "\n";
	std::cout << " TEL   : " << tel << "\n";
	std::cout << " FAX   : " << fax << "\n";
	std::cout << "Email  : " << email << "\n";
	std::cout << "ȸ���ּ� : " << companyAddress << "\n\n\n";

	std::cout.flush();
}