#pragma once

//--------------------------------------------------
template <class T>
class IteratorInterface
{

public:

	virtual ~IteratorInterface() {};

	virtual const T& Next() = 0;

	virtual const bool HasNext() const = 0;
};

//--------------------------------------------------
template <class T>
class AggregateInterface
{

public:

	virtual ~AggregateInterface() {};

	virtual IteratorInterface<T>* Iterator() = 0;
};
