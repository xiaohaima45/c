//           / d1 reportSingleClassLayoutSon
//    ����������������ӣ��ɿ��麯����ķֲ�
#include<iostream>

using namespace std;

//���庯��ָ�룬���Բ���֪�����������ú���
typedef void(*fun)(void);

//���г�ԱĬ����˽��
class Father {

public:
	Father() { cout << __FUNCTION__ << endl; }
	virtual ~Father() { cout << __FUNCTION__ << endl; }

	virtual void func1() { cout << __FUNCTION__ << endl; }
	virtual void func2() { cout << __FUNCTION__ << endl; }
	virtual void func3() { cout << __FUNCTION__ << endl; }
	 virtual void func4() { cout << __FUNCTION__ << endl; }
	 virtual void func5() { cout << __FUNCTION__ << endl; }
	void func6() { cout << __FUNCTION__ << endl; }//��ͨ��Ա���������麯������

public:
	int a = 0;
	int  c = 'a';
	static int b;
};
//���ھ�̬��Ա��������������������
int b = 1;

/********************************************
*
*		Father�����ĵ�ַ�У��洢�麯����ĵ�һ��ָ���λ��
*		��Father�����ַ�д���麯����ĵ�һ��ָ��
*********************************************/
void textFather()
{
	Father father;
	//�麯����ָ��
	int* vptr = (int*)*(int*)(&father);

	//�麯����ָ�����ĵ�һ���Ǻ�����ָ��
	cout << "���õ�һ���麯��" << endl;
	((fun) * (vptr + 0))();

	cout << "���õ�2���麯��" << endl;
	((fun) * (vptr + 1))();

	cout << "���õ�3���麯��" << endl;
	((fun) * (vptr + 2))();

	cout << "��1�����ݳ�Ա�ĵ�ַ: " << endl;
	cout << &father.a << endl;
	cout << std::hex << (int)&father + 4 << endl;
	cout << "��1�����ݳ�Ա��ֵ��" << endl;
	cout << std::dec << father.a << endl;
	cout << *(int*)((int)&father + 4) << endl;

	cout << "��2�����ݳ�Ա�ĵ�ַ: " << endl;
	cout << &father.c << endl;
	cout << std::hex << (int)&father + 8 << endl;
	cout << "��2�����ݳ�Ա��ֵ��" << endl;
	cout << std::dec << father.c << endl;
	cout << *(int*)((int)&father + 8) << endl;

	cout << "sizeof(father)==" << sizeof(father) << endl;

	Father father2;
	cout << "father���麯����";
	cout << *(int*)(*(int*)&father) << endl;
	cout << "father2���麯����";
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
	//��˭��ʼ��ָ�룬���õ��麯������˭��
	/*Father father1;
	Son son;
	Father* father=&father1;
	father->func1();
	father = &son;
	son.func1();*/

	//�Ӹ���̳����麯�������������д�������������麯��ʱ���õ��Լ���д��
	/*Son son1;
	son1.func1();*/


	//����ָ���ʱ��ע��Ҫ�������������������
	
	//Father* father = new Father;//����
	//delete father;
	
	//���������������ʧ�ˣ���ִ��,��Ҫ�ڸ�����������ǰ����virtual
	Father* son = new Son;
	delete son;

	//����
	/*Son* son = new Son;
	delete son;*/
}

int main(void)
{
	textFather();
	//TextSon();
	return 0;
}