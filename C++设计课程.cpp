#include<iostream>
using namespace std;
class Fruit
{
public:
	Fruit() {};
	virtual ~Fruit() {};
	virtual double getPrice() const =  0;
};
//抽象类与纯虚函数

//纯虚析构函数必须要有定义
class Factory
{
public:
	static Fruit *CreateFruit(int Flag);
	static Factory *Instance();
protected:
	Factory() {};
private:
	static Factory *_instance;
};
//工厂类

Factory *Factory ::_instance = 0;

//在工厂里生产水果
Factory *Factory::Instance()
{
	if (_instance == 0)
	{
		_instance = new Factory();
	}
	return _instance;
}
//建立唯一的工厂
class Apple :public Fruit
{
public:
	Apple();
	~Apple() {};
	double getPrice() const
	{
		return price;
	};
private:
	const double price;
};
//苹果
class Pear :public Fruit
{
public:
	Pear();
	~Pear() {};
	double getPrice() const
	{
		return price;
	};
private:
	const double price;
};
//梨子
class Banana:public Fruit
{
public:
	Banana();
	~Banana() {};
	double getPrice() const
	{
		return price;
	};
private:
	const double price;
};
//香蕉
class Peach :public Fruit
{
public:
	Peach();
	~Peach() {};
	double getPrice() const
	{
		return price;
	};
private:
	const double price;
};
//桃子
//四个水果的子类
Apple ::Apple():price(5.0){}
Pear::Pear() : price(3.3) {}
Banana::Banana() : price(2.5) {}
Peach::Peach() : price(6.5) {}
//给水果的价格常量初始化
Fruit *Factory::CreateFruit(int Flag)
{
	Fruit *fruit=0;
	switch (Flag)
	{
	case(1):
		fruit = new Apple();
		break;
	case(2):
		fruit = new Pear();
		break;
	case(3):
		fruit = new Banana();
		break;
	case(4):
		fruit = new Peach();
		break;
	}
	return fruit;
}
int Display()
{
	int flag;
	cout << "Hello!Please tell me which fruit you wanna buy.Input the number in front of fruit to continue." << endl;
	cout << "1.Apple!" << endl;
	cout << "2.Pear" << endl;
	cout << "3.Banana" << endl;
	cout << "4.Peach" << endl;
	cout << "5.I won't buy anything.Bey." << endl;
	cin >> flag;
	if (flag < 1 || flag >5)
		throw flag;
	return flag;
}
int main()
{
	Factory *factory;
	Fruit *f;
	int flag;
	float kilegram;
	try
	{
		flag=Display();
	}
	catch (int )
	{
		cout << "I don't understand what you say." << endl;
		flag = Display();
	}
	factory = Factory:: Instance();
	f=Factory::CreateFruit(flag);
	if (5 == flag)
	{
		cout << "Bey." << endl;
		getchar();
	}
	else
	{
		cout << "how much do you wanna buy?" << endl;
		cin >> kilegram;
		cout << "Total price is:" << kilegram * f->getPrice() << endl;
	}
	delete f;
	getch();
    return 1;
}


