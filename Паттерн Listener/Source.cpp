// ��������, � �������� ��� ��� ����� �� ��������� ���.
struct Button;

// ���������, ������� ��������� ��� ������,
// ������� ������� ����� ����������� �� �������
// "������ ������"
struct ButtonListener
{
	// �����, ������� ����� ����������, �����
	 // ���������� ������� "������ ������"
	virtual void onButtonClick(Button * b, bool down) = 0;
	virtual ~ButtonListener() {}
};

// ����� ����� ��� ������
struct Button
{
	// ����� ��������� ��������� ������ �����,
	// ������������ ��������� ButtonListener
   // �� ������� "������ ������"
	void subscribe(ButtonListener * bl);
};

// ���� �� ������ �������������� ����� ����������� ��� ������������, ����������� ������� � ����������� ��� ������ ���������� �� �������.
// ������� � ������� ���������� �� ������� :
struct Button;

// ��� ��������� �� �������, ������� ����� ����������,
// ����� ������� "������ ������"
typedef void(*ButtonProc)(Button *, bool, void *);

// ����� ����� ��� ������
struct Button
{
	// ����� ��������� ��������� ������ �������
	// ���� ButtonProc �� ������� "������ ������"
	void subscribe(ButtonProc bp, void * arg);
};