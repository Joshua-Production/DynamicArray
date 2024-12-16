#pragma once

template<typename T>
class DynamicArray
{
public:
	// This is a default constructor
	DynamicArray();

	// This is to convert the array into a dynamic constructor 
	DynamicArray(const T* array, int size);

	// This is to
	DynamicArray(const DynamicArray<T>& other);

	// Destructor 
	~DynamicArray();

	DynamicArray<T>& operator= (const DynamicArray<T>&other);

	T& operator[](int index);

	// If we want to get  a conts out of the arrray
	const T& operator[](int index) const;

	// This is to get the length of the array
	int Length() const;

	// This is to resize the array
	void Resize(int newSize);

	// This returns a T pointer
	// It has to be lowercase becuase its for a ranged based for loop

	T* begin();
	const T* begin() const;

	// This is for ranged based for loops
	T* end();
	const T* end() const;

	// This is to add 
	void Add(const T& value);

	// This is to add a whole array
	void Add(const T* array, int size);

	// This is if you want to add a Dynamic Array
	void Add(const DynamicArray<T>& other);

	// Add unique means only add if its not already in the list
	void AddUnique(const T& value);

	// Insert into the middle of the array
	void Insert(int index, const T& value);

	// insert a whole array in the middle
	void Insert(int index, const T* array, int size);

	// Insert a Dynamic Array
	void Insert(int index, const DynamicArray<T>& other);

	// Remove from list at certain index
	void Remove(int index);

	// Remove a specific thing from the list
	void Remove(const T& value);

	// Remove a whole array
	void Remove(const T* array, int size);

	// Remove Dynamic Array
	void Remove(const DynamicArray<T>& other);

	// This gets rid of everything in the list 
	void Clear();

private:
	// array of type T
	T* m_array;

	// This is to get the size of the array
	int m_length;




};

template<typename T>

// Default constructor
inline DynamicArray<T>::DynamicArray()
{
	m_length = 0;
	m_array = new T[m_length];
}

// Constructor for a dynamic array
template<typename T>
inline DynamicArray<T>::DynamicArray(const T* array, int size)
{
	// whatever the size of the array
	m_lenght = size;
	m_array - new T[m_length];
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = array[i];
	}
}


// Copy constructor
template<typename T>
inline DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
	// copy the length over
	m_lenth = other.m_length;
	m_array = new T[m_length];

	// Copy all the stuff in
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = other.m_array[i];
	}
}

// Destructor
template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] m_array;
}

//
template<typename T>
inline DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
	m_length = other.m_length;
	// delete before you assign new things
	delete[] m_array;
	m_array = new T[m_length];

	// copy
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = other.m_array[i];
	}
	return *this;

}


// Square bracket overload
template<typename T>
inline T& DynamicArray<T>::operator[](int index)
{
	// we are not checking if the index is valid
	return m_array[index];
}

template<typename T>
inline const T& DynamicArray<T>::operator[](int index) const
{
	// we are not checking if the index is valid
	return m_array[index];
}

// Length
template<typename T>
inline int DynamicArray<T>::Length() const
{
	return m_length;
}

// Resize
template<typename T>
inline void DynamicArray<T>::Resize(int newSize)
{
	// Make a new array of the size we want to go to
	T* newArray = new T[newSize];

	// Copy everything from the old into the new array
	 // i < m_length && i < newSize; makes certain that we dont overflow either of the arrays
	for (int i = 0; i < m_length && i < newSize; i++)
	{
		newArray[t] = m_array[i];

	}
	// get rid of old array
	delete[] m_array;

	m_array = newArray;
	m_length = newSize;
}



// Begin
template<typename T>
inline T* DynamicArray<T>::begin()
{
	return m_array;
}

// const Begin
// Begin
template<typename T>
inline const T* DynamicArray<T>::begin() const
{
	return m_array;
}




// End
template<typename T>
inline T* DynamicArray<T>::end()
{
	// returns the end of the array 
	
	return m_array + m_length;
}

//  Const End
template<typename T>
inline const T* DynamicArray<T>::end() const
{
	return m_array + m_length;
}


// Add 
template<typename T>
inline void DynamicArray<T>::Add(const T& value)
{
	Resize(m_lenth + 1);
	m_array[m_length - 1] = value;
}

// Add whole array
template<typename T>
inline void DynamicArray<T>::Add(const T* array, int size)
{
	int oldLength = m_length;
	Resize(m_length + size);
	for (int i = 0; i < size; i++)
	{
		m_array[oldLenth + i] = array[i];
	}
}

//
template<typename T>
inline void DynamicArray<T>::Add(const DynamicArray<T>& other)
{
	int oldLenght = m_length;
	Resize(m_length + other.m_length);
	for (int i = 0; i < other.m_array_length; i++)
	{
		m_array[oldLenght + i] = other.m_array[i];

	}
}


// Add Unique 
template<typename T>
inline void DynamicArray<T>::AddUnique(const T& value)
{
	// loop to see if it contains the value
	for (int i = 0; i < m_length; i++)
	{
		// If we find a single copy of the array get out
		if (m_array[i] == value)
			return;

	}
	Add(value);
}

// insert function
template<typename T>
inline void DynamicArray<T>::Insert(int index, const T& value)
{
	// Resize
	Resize(m_length + 1);
	// Go backwards from in the array
	// move everything over by one till i is greater than index
	for (int i m_length - 1; i > index; i--)
	{
		m_array[i] = m_array[i - 1];

	}
	m_array[index] = value;
}

// insert an whole array
template<typename T>
inline void DynamicArray<T>::Insert(int index, const T* array, int size)
{

	// resize to make it big enough
	Resize(m_length + size);

	// copy until we reach the index
	for (int i = m_legnth - 1; i >= +index + size; i--)
	{
		
		m_array[i] = m_array[i - size];
	}
	for (int i = 0; i < size; i++)
	{
		m_array[index + i] = array[i];
	}
}

// take in a DynamicArray
template<typename T>
inline void DynamicArray<T>::Insert(int index, const DynamicArray<T>& other)
{

	// resize to make it big enough
	Resize(m_length + other.m_length);

	// copy until we reach the index
	for (int i = m_legnth - 1; i >= +index + other.m_length; i--)
	{

		m_array[i] = m_array[i - other.m_length];
	}
	for (int i = 0; i < other.m_length; i++)
	{
		m_array[index + i] = other.m_array[i];
	}
}

// Remove
template<typename T>
inline void DynamicArray<T>::Remove(int index)
{
	// copy in other direction
	for (int i = index; i < m_length - i++)
	{
		m_array[i] = m_array[i + 1];

	}
	Resize(m_length - 1);
}
// Remove if we dont know where it is in the Array
template<typename T>
inline void DynamicArray<T>::Remove(const T& value)
{
	for (int i = 0; i < m_length; i++)
	{
		if (m_array[i] == value)
		{
			Remove(i);
			return;

		}
	}
}

// Remove a whole array
template<typename T>
inline void DynamicArray<T>::Remove(const T* array, int size)
{
	// Loop through the array we were given

	for (int i = 0; i < size; i++)
	{
		Remove(array[i]);
	}
}

// Remove DynamicArray
template<typename T>
inline void DynamicArray<T>::Remove(const  DynamicArray<T>& other)
{
	

	for (int i = 0; i < other.m_length; i++)
	{
		Remove(other.m_array[i]);
	}
}

// Clear
template<typename T>
inline void DynamicArray<T>::Clear()
{
	Resize(0);
}