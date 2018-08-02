// Copyright (c) Knowledge Express Technology, Inc.
//
#ifndef __KXHEAP_H__
#define __KXHEAP_H__


namespace kxlib
{
	
template<typename T>
class kxMaxHeap
{
private:
	T *Slots;
	size_t Top;
	size_t nMaxSlots;
	bool InOrder;
	inline bool IsEmpty();
 	inline bool IsFull();
	inline void PDown(size_t);
public:
	kxMaxHeap(size_t nMax);
	~kxMaxHeap();
	inline void MakeHeap();
	inline bool Push(const T);
	inline void Push(T*, size_t);
	inline T Pop();
	inline void Sort();
	inline T& operator[](size_t Index);
};

template<typename T>
kxMaxHeap<T>::kxMaxHeap(size_t nMax)
{
	Top = 0;
	nMaxSlots = nMax;
	Slots = new T[nMax + 1];
	InOrder = true;
}

template<typename T>
kxMaxHeap<T>::~kxMaxHeap()
{
	delete [] Slots;
}

template<typename T>
bool kxMaxHeap<T>::Push(const T V)
{
	if (Top == nMaxSlots) return false;
	size_t X = ++Top;
	for ( ; X > 1 && V > Slots[X >> 1]; X >>= 1)
		Slots[X] = Slots[X >> 1];
	Slots[X] = V;
	return true;
}

template<typename T>
void kxMaxHeap<T>::Push(T* PV, size_t N)
{
	N = nMaxSlots - Top;
	for (size_t I = 0; I < N; ++I)
		Push(PV[I]);
}

template<typename T>
T kxMaxHeap<T>::Pop()
{
	if (IsEmpty()) return T();
	T Tmp = Slots[1];
	Slots[1] = Slots[Top];
	--Top;
	if (Top > 1) PDown(1);
	return Tmp;
}
	
template<typename T>
T& kxMaxHeap<T>::operator[](size_t X)
{
	return Slots[X];
}

template<typename T>
bool kxMaxHeap<T>::IsEmpty()
{
	return Top == 0;
}

template<typename T>
bool kxMaxHeap<T>::IsFull()
{
	return Top == nMaxSlots;
}

template<typename T>
void kxMaxHeap<T>::MakeHeap()
{
	for (size_t i = Top << 1; i > 0; --i)
		PDown(i);
	InOrder = true;
}

template<typename T>
void kxMaxHeap<T>::PDown(size_t X)
{
	size_t C = X << 1;
	T Tmp = Slots[X];
	while (C <= Top)
	{
		if (C < Top && (Slots[C + 1] > Slots[C])) ++C;
		if (Slots[C] > Tmp)
			Slots[X] = Slots[C];
		else
			break;
		X = C;
		C = X << 1;
	}
	Slots[X] = Tmp;
}

template<typename T>
void kxMaxHeap<T>::Sort()
{
	size_t _Top = Top;
	while (Top > 1) Slots[Top + 1] = Pop();
	Top = _Top;
	InOrder = false;
}

}
#endif