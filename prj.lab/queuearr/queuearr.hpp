#include <iostream>



class QueueArr {
public:
	QueueArr() = default;
	~QueueArr() = default;
	QueueArr(const QueueArr& data);
	QueueArr(const int& data);

	bool Is_empty();
	void Push(const int& data);
	void Pop();
	int Top();





private:
	int* head_ = nullptr;//������
	int* tail_ = nullptr;//��������� ����
	int size_ = 0;//����� ����� �������
	int capacity_ = 0;//��� �� ���������� ������
	



};