#include<iostream>
#include<string>
#include <sstream>
#include<fstream>
#include<iomanip>

using namespace std;

char name[6][8]; //������λ������
float zhl[6]; //������λ��ת���ʴ洢�ڴ�������
float result[10] ; //10�����
void read(); //���ļ����벢����
void write(); //д�뵽�ļ�
int isOperator(string str); //�ж��Ƿ������������Ϊ7����Ϊ8
int isUnit(string str); //�жϵ�λ
float str2float(string str);//stringתfloat

int main()
{
	read(); //��ȡ����
	write(); //д������

	return 0;
}

void read()
{
	int num; //��ȡ����Ҫ������
	char str[10]; //��ȡ����Ҫ���ַ���
 	ifstream infile("input.txt");
  
 	if(!infile)
 	{
		cerr << "open error!" << endl;
		exit(1);
	}
  
	//���ļ�ǰ6�ж��뵽������
	for(int i = 0;i < 6;i++)
	{
		infile >> num; //��ȡ��һ������
		infile >> name[i]; //��ȡ��λ����
		infile >> str; //��ȡ����Ҫ���ַ�����=��
		infile >> zhl[i]; //��λת����
		infile >> str; //��ȡ����Ҫ���ַ�����m��
	}
	
	//��ȡ��Ҫ����Ĳ��֣������Լ���
	float tmp; //����洢����
	string cal; //Ҫ������ַ��������֣�
	string line; //Ҫ������ַ������У�
	int statius1 = 0,statius2 = 0; //�Ƿ��еı�־�����������λ��
	int l=0; //�ڼ���
	int zf=1; //�жϼӼ�
	
	while(!(infile.eof()))
	{

		infile >> cal;

		if(!isUnit(cal) && !isOperator(cal)) //�ж��Ƿ�Ϊ����
		{
			statius1 = statius2;
			statius2 = 1;

			tmp = str2float(cal);

			if(statius1==2 && statius2==1) //���б�־����λ2������1��
			{
				l++;
				zf=1; //���к����Ҫ����
			}
			continue;
		}
			
		if(isUnit(cal))
		{
			statius1 = statius2;
			statius2 = 2;

			cout<<zf<<endl;
			result[l] += tmp * zhl[isUnit(cal)-1] *zf;
			//�Ż�����
		/*	switch(isUnit(cal))
			{
			case 1:
				result[l] += tmp * zhl[0] * zf;
				break;
			case 2:
				result[l] += tmp * zhl[1] * zf;
				break;
			case 3:
				result[l] += tmp * zhl[2] * zf;
				break;
			case 4:
				result[l] += tmp * zhl[3] * zf;
				break;
			case 5:
				result[l] += tmp * zhl[4] * zf;
				break;
			case 6:
				result[l] += tmp * zhl[5] * zf;
				break;
			} */
			continue;
		}
		if(isOperator(cal))
		{
			statius1 = statius2;
			statius2 = 3;

			if(isOperator(cal)-7)
				zf=-1;
			else
				zf=1;
			continue;
		}
	}
	
	infile.close();
}

void write()
{

	ofstream outfile("output.txt");
	
	if(!outfile)
	{
		cerr << "open output.txt error!" << endl;
		exit(1);
	}
	
	//������
	outfile << "447407567@qq.com" << endl; //��1�������������������ɹ����ϱ���ʱ��ע������
	//��2���ǿ���

	//���������
	for(int i = 0 ; i < 10 ; i++)
		outfile << endl <<setiosflags(ios::fixed)<<setprecision(2)<< result[i] << " m"; //����һ�д�������������������
	
	//���һ�в���Ҫ����

	outfile.close();
}

int isOperator(string str)
{
	if(str=="+")
		return 7;
	if(str=="-")
		return 8;
	return 0;
}

int isUnit(string str)
{
	if((str=="mile") || (str=="miles"))
		return 1;
	if((str=="yard") || (str=="yards"))
		return 2;
	if((str=="inch") || (str=="inches"))
		return 3;
	if((str=="foot") || (str=="feet"))
		return 4;
	if((str=="fath") || (str=="faths"))
		return 5;
	if((str=="furlong") || (str=="furlongs"))
		return 6;
	else return 0;
}

float str2float(string str)
{ 
   stringstream sstr(str); 
   float num; 
   if((sstr >> num).fail()) 
   {       //ERROR   
   } 
   return num;

}