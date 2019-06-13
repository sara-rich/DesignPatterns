#pragma once

#include <iostream>

// �ύX�s�\�ȃN���X
//--------------------------------------------------
class Target
{
public:

	void HelloWorld()
	{
		std::cout << "hello world" << std::endl;
	}
};

// �t�^�������@�\�����N���X
//--------------------------------------------------
class Adaptee
{
public:
	
	virtual void GoodbyeWorld() = 0;
};

// �t�^���ꂽ�N���X�i�p���Ŏ�������P�[�X�j
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

// �t�^���ꂽ�N���X�i�Ϗ��Ŏ�������P�[�X�j
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
