#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <expat.h>

using std::string;

// ��������� ��� �������� ���������������� ������
struct MyData
{
	// ��������� ��������
	std::vector<string> news;

	// ������� �������� ���
	string openTag;

	// ����� ������ ���� title
	string title;
};

// ���������� ��� ������������ ����
// el - ��� ����
// attr - ��������� ����
void start(void * data, const char * el, const char ** attr)
{
	MyData & d = *static_cast<MyData *>(data);

	// ��������� ��������� �������� ���
	d.openTag = el;
}

// ���������� ��� ������������ ����
// el - ��� ����
void end(void * data, const char * el)
{
	MyData & d = *static_cast<MyData *>(data);
	if (d.openTag == "title")
	{
		// ��������� ��������� � �������
		d.news.push_back(d.title);

		// ������� title
		d.title = "";
	}
}

// ���������� ��� ������ ������ �����
void text(void * data, const char *s, int len)
{
	MyData & d = *static_cast<MyData *>(data);

	if (d.openTag == "title")
	{
		// ���������� ����� ���������
		d.title += string(s, len);
	}
}

int main()
{
	// ������ XML ������
	XML_Parser p = XML_ParserCreate(0);

	// ��������� ���� � XML � �������� ������
	std::ifstream f("rss.xml", std::ifstream::binary);

	// ��������� ������ �������� �����
	if (!f.is_open())
	{
		std::cerr << "Can not open 'rss.xml' for reading\n";
		return 1;
	}

	// ������������� ��������� �� �������, �������
	// ����� �������� ��� ������� ������������ ���� 
	// (start) � ������������ ���� (end)
	XML_SetElementHandler(p, start, end);

	// ������������� ��������� �� ������� ��� ��������� 
	// ������ ������ XML �����
	XML_SetCharacterDataHandler(p, text);

	// ���������������� ������, ������� �� ����� ������������
	// ��� �������� XML
	MyData data;

	// ������������� ��������� �� ���������������� ������ 
	XML_SetUserData(p, &data);

	// ����� ��������� �� 1�� �� ���
	char buff[1024];

	// ������ ������ �� �����
	while (f.read(buff, sizeof(buff)))
	{
		// ����������� ��������� ������
		size_t len = f.gcount();

		// ������ ����������� �������
		if (!XML_Parse(p, buff, len, f.eof()))
		{
			// ��������� ������ ��� ��������
			std::cerr << "Parser error at line "
				<< XML_GetCurrentLineNumber(p) << ": "
				<< XML_ErrorString(XML_GetErrorCode(p))
				<< std::endl;
			return 1;
		}
	}

	// ������� ��� ��������� �� ����������� �����
	for (size_t i = 0; i != data.news.size(); ++i)
		std::cout << data.news[i] << std::endl;

	return 0;
}