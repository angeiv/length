#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

char name[6]; //各个单位的名称
double zhl[6]; //各个单位的转换率存储在此数组中
void read(); //从文件读入
void write(); //写入到文件

int main()
{
	read();
	write();
	return 0;
}

void read()
{
	int num; //读取不需要的数字
	char str[10]; //读取不需要的字符串
 	ifstream infile("input.txt",ios::in);
  
 	if(!infile)
 	{
		cerr << "open error!" << endl;
		exit(1);
	}
  
	//将文件前6行读入到数组中
	for(int i = 0;i < 6;i++)
	{
		//此处存在错误

		infile >> num; //读取第一个数字
		infile >> name[i]; //读取单位名字
		infile >> str; //读取不需要的字符，“=”
		infile >> zhl[i]; //单位转换率
		infile >> str; //读取不需要的字符，“m”
	}
	
	//读取需要计算的部分（暂缺）
	
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
	
	//输出结果
	outfile << "447407567@qq.com" << endl; //第1行是您在渣打编程马拉松官网上报名时的注册邮箱
	outfile << endl; //第2行是空行

	//输出计算结果（暂缺）
	//outfile << zhl[0] << endl;
	
	outfile.close();
}
