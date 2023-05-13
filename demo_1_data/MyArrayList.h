#pragma once

template<typename T>
class MyArrayList {
public:
	//build the list and check the list is not empty
	MyArrayList() : m_length(0), m_data(nullptr) {}

	~MyArrayList()
	{
		clear();
	}

	int GetLength()
	{
		return m_length;
	}
	
	bool insert(T element);
	
	//Clear the linear table
	void clear()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	//Gets the index location
	T GetElement(int index);

	//Gets the element from the index
	int LocateElement(T element);

	//Delete the element and return it
	T DeleteElement(int index);

	

private:
	int m_length;//the length of List
	T* m_data;

};

template<typename T>
bool MyArrayList<T>::insert(T element)
{
	T* newdata = new T[m_length + 1];
	if (newdata == nullptr)
	{
		throw("Error: Insufficient memory.");
		return false;
	}
	else
	{
		//Store old data
		for (int i=0; i < m_length; i++)
		{
			newdata[i] = m_data[i];
		}

		newdata[m_length] = element;
		m_length++;

		delete[] m_data;
		m_data = newdata;
		return true;
	}
}

template<typename T>
T MyArrayList<T>::GetElement(int index)
{
	if (index < 0 || index > m_length) {
		throw("out of the range");
		return T();
	}
	else
		return m_data[index];
}

template<typename T>
int MyArrayList<T>::LocateElement(T element)
{
	for (int i = 0; i < m_length; i++)
	{
		if (m_data[i] == element)
			return i;
	}
	 
	return -1;
}

template<typename T>
T MyArrayList<T>::DeleteElement(int index)
{
	if (index < 0 || index > m_length) 
	{
		throw("out of the range");
		return T();
	}

	else 
	{
		T elem = m_data[index];
		T* newdata = new T[m_length - 1];
		if (newdata == nullptr) {
			throw("out of the range");
			return T();
		}

		for (int i = 0, j = 0; i < m_length; i++)
		{
			if (i != index)
				newdata[j++] = m_data[i];
		}

		m_length--;
		delete[] m_data;
		m_data = newdata;
		return elem;
	}
}







