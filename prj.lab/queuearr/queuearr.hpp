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
	int* head_ = nullptr;//Голова
	int* tail_ = nullptr;//Последний элем
	int size_ = 0;//колво ячеек занятых
	int capacity_ = 0;//Кол во выделенной памяти
	



};