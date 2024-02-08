#ifndef LIST_H
#define LIST_H

// This implementation is here to replace std::vector that is not included in Arduino C++.

template <typename T>
class List
{
public:
    List();
    ~List();

    void push_back(const T& value);
    void pop_back();
    T& at(int index);
    int size() const;
    bool empty() const;
    void reverse();

private:
    T* m_data;
    int m_size;
    int m_capacity;

    void resize(int newCapacity);
};

template <typename T>
List<T>::List()
    : m_data(nullptr), m_size(0), m_capacity(0)
{
}

template <typename T>
List<T>::~List()
{
    delete[] m_data;
}

template <typename T>
void List<T>::push_back(const T& value)
{
    if (m_size == m_capacity)
    {
        resize(m_capacity == 0 ? 1 : m_capacity * 2);
    }

    m_data[m_size++] = value;
}

template <typename T>
void List<T>::pop_back()
{
    if (m_size > 0)
    {
        --m_size;
    }
}

template <typename T>
T& List<T>::at(int index)
{
    return m_data[index];
}

template <typename T>
int List<T>::size() const
{
    return m_size;
}

template <typename T>
bool List<T>::empty() const
{
    return m_size == 0;
}

template <typename T>
void List<T>::reverse()
{
    for (int i = 0; i < m_size / 2; ++i)
    {
        T temp = m_data[i];
        m_data[i] = m_data[m_size - i - 1];
        m_data[m_size - i - 1] = temp;
    }
}

template <typename T>
void List<T>::resize(int newCapacity)
{
    T* newData = new T[newCapacity];

    for (int i = 0; i < m_size; ++i)
    {
        newData[i] = m_data[i];
    }

    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
}

#endif // LIST_H