#pragma once

#include <iostream>

// 変更不可能なクラス
//--------------------------------------------------
class Target
{
public:

	void HelloWorld()
	{
		std::cout << "hello world" << std::endl;
	}
};

// 付与したい機能を持つクラス
//--------------------------------------------------
class Adaptee
{
public:
	
	virtual void GoodbyeWorld() = 0;
};

// 付与されたクラス（継承で実装するケース）
//--------------------------------------------------
class AdapterCase1 : public Adaptee, private Target
{
public:
	
	void GoodbyeWorld()
	{
		HelloWorld();
		std::cout << "goodbye world." << std::endl;
	}
};

// 付与されたクラス（委譲で実装するケース）
//--------------------------------------------------
class AdapterCase2 : public Adaptee
{
public:

	void GoodbyeWorld()
	{
		m_Target.HelloWorld();
		std::cout << "goodbye world." << std::endl;
	}

private:

	Target m_Target;
};
