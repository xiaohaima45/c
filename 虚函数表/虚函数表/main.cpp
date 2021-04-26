//           / d1 reportSingleClassLayoutSon
//    在属性命令行中添加，可看虚函数表的分布
#include<iostream>

using namespace std;

//定义函数指针，可以不用知道函数名调用函数
typedef void(*fun)(void);

//类中成员默认是私有
class Father {

public:
	Father() { cout << __FUNCTION__ << endl; }
	virtual ~Father() { cout << __FUNCTION__ << endl; }

	virtual void func1() { cout << __FUNCTION__ << endl; }
	virtual void func2() { cout << __FUNCTION__ << endl; }
	virtual void func3() { cout << __FUNCTION__ << endl; }
	 virtual void func4() { cout << __FUNCTION__ << endl; }
	 virtual void func5() { cout << __FUNCTION__ << endl; }
	void func6() { cout << __FUNCTION__ << endl; }//普通成员函数不在虚函数表中

public:
	int a = 0;
	int  c = 'a';
	static int b;
};
//类内静态成员函数必须这样声明定义
int b = 1;

/********************************************
*
*		Father类对象的地址中，存储虚函数表的第一个指针的位置
*		既Father对象地址中存的虚函数表的第一个指针
*********************************************/
void textFather()
{
	Father father;
	//虚函数表指针
	int* vptr = (int*)*(int*)(&father);

	//虚函数表指针里存的第一个是函数的指针
	cout << "调用第一个虚函数" << endl;
	((fun) * (vptr + 0))();

	cout << "调用第2个虚函数" << endl;
	((fun) * (vptr + 1))();

	cout << "调用第3个虚函数" << endl;
	((fun) * (vptr + 2))();

	cout << "第1个数据成员的地址: " << endl;
	cout << &father.a << endl;
	cout << std::hex << (int)&father + 4 << endl;
	cout << "第1个数据成员的值：" << endl;
	cout << std::dec << father.a << endl;
	cout << *(int*)((int)&father + 4) << endl;

	cout << "第2个数据成员的地址: " << endl;
	cout << &father.c << endl;
	cout << std::hex << (int)&father + 8 << endl;
	cout << "第2个数据成员的值：" << endl;
	cout << std::dec << father.c << endl;
	cout << *(int*)((int)&father + 8) << endl;

	cout << "sizeof(father)==" << sizeof(father) << endl;

	Father father2;
	cout << "father的虚函数表：";
	cout << *(int*)(*(int*)&father) << endl;
	cout << "father2的虚函数表：";
	cout << *(int*)(*(int*)&father2) << endl;


}


class Son :public Father {
public:
	Son():Father(){ cout << __FUNCTION__ << endl; }
	~Son() { cout << __FUNCTION__ << endl; }
	virtual void func1() { cout << __FUNCTION__ << endl; }
	virtual void func6() { cout << __FUNCTION__ << endl; }

};

void TextSon()
{
	//用谁初始化指针，调用的虚函数就是谁的
	/*Father father1;
	Son son;
	Father* father=&father1;
	father->func1();
	father = &son;
	son.func1();*/

	//从父类继承了虚函数，子类如果重写则子类调用这个虚函数时，用的自己重写的
	/*Son son1;
	son1.func1();*/


	//当用指针的时候，注意要给父类添加虚析构函数
	
	//Father* father = new Father;//正常
	//delete father;
	
	//子类的析构函数丢失了，不执行,需要在父类析构函数前加上virtual
	Father* son = new Son;
	delete son;

	//正常
	/*Son* son = new Son;
	delete son;*/
}

int main(void)
{
	textFather();
	//TextSon();
	return 0;
}