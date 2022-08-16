/**
# 第一章：C++编程基础
涉及到的内容：
1、基础数据类型：布尔值Boolean、字符character、整数integer、浮点数floating point。
2、算术运算符、关系运算符、逻辑运算符。
3、条件分支和循环控制语句，用来改变程序的控制流程。
4、复合类型：指针【间接使用一个已经存在的对象】、数组【定义一组具有相同数据类型的元素】。
5、一套标准的通用的抽象化库，包括字符串、向量vector。
*/

/*
## 函数
函数是一块独立的程序代码序列，由四个部分组成：返回值类型、函数名称、参数列表、函数体。
- 函数名称需要提供函数的功能：如min和sort让人一目了然，而f,g显然不是好名字了，看着一头雾水。
- mian函数，编译器会默认程序中定义了main函数，并从main函数开始执行具体内容，如果没有定义main，在VisualStuio下会报错无法调用main函数：
错误	LNK2019	无法解析的外部符号 main，函数 "int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ) 中引用了该符号	E:\Code\Cpp\EssentialCpp\EssentialDemo\out\build\x64-debug\EssentialDemo	E:\Code\Cpp\EssentialCpp\EssentialDemo\out\build\x64-debug\EssentialDemo\MSVCRTD.lib(exe_main.obj)	1	

## 类
面向对象思想的核心，class的定义通常分为两个部分，一个是头文件，用来声明该class提供的各种操作行为。另一个文件，程序代码文件，则包含了这些操作行为的实现内容。
每一个class应该有自己的output运算符，这样可以让calss的用户能够像面对内置类型一样的一同样的方式输出对象内容。

提领指针之前，首先判断是否为空指针。 if(pv && pv->get_state()) cout << ok << endl;
*/

#include <iostream>  
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main01() {
	// 测试接收用户输入数据
	string first_name, last_name;
	cout << "Please enter your first name";
	cin >> first_name;
	cout << "Please enter your last name";
	cin >> last_name; 
	cout << "\n" << "Hello, " << first_name << last_name << " ... and GoodBye!\n";
	return 0;
}


// 习题1.5 用c_style 和 string分别输入用户信息
void get_userinfo() {
	string user_name;
	cout << "Hello, what's your name in string ?\n";
	cin >> user_name;
	
	if (user_name.size() > 2)
		cout << "Welcome, Dear Mrs/Miss " << user_name << endl;

	char user_name_c[10];
	cout << "Hello, please enter your name in c~ \n";
	cin >> user_name_c;

	if (strlen(user_name_c) > 2)
		cout << "Welcome, Dear Mrs/Miss2 " << user_name_c << endl;

}


// 习题1.6 向array和vector输入数字，计算平均数
void get_nums() {
	int ival, arr_cnt = 0;
	int arr[20];
	vector<int> v_nums(20, 0.0);

	cout << "Please enter ten nums:\n";
	while (cin >> ival) {
		v_nums[arr_cnt] = ival;
		arr[arr_cnt] = ival;
		arr_cnt += 1;
	}

	int sum = 0;
	for (int idx = 0; idx < arr_cnt; idx++) {
		sum += v_nums[idx];
	}

	int sum_arr = 0;
	for (int idx = 0; idx < arr_cnt; idx++) {
		sum_arr += arr[idx];
	}
	cout << sum_arr << "	" << sum << "\n";
	cout << "arr.avg=" << sum_arr / arr_cnt << "vec.avg=" << sum/arr_cnt << endl;
}


// 1.7 输入两行文字存盘，在另一函数中读取该文本数据存放在vector。输出内容，在用sort，排序输出到新文件。
void sort_new_file() {
	ofstream outfile("./ori_data.txt");	// 这里出了糗，ofstream一直写的fstream，还不知道哪里出错了oo
	string sentence;
	vector<string> v_str(3);
	if (!outfile) {
		cerr << "error occur when open file." << endl;
	}
	else {
		cout << "Please input some string";
		int idx = 0;
		while (cin >> sentence) {
			v_str[idx++] = sentence;
		}
		for (int i = 0; i < idx; i++) {
			outfile << v_str[i] << "\n";
		}
		//outfile << endl;	
		outfile.close(); // 记得关闭文件
	}
	ifstream infile("./ori_data.txt");
	if (!infile)
		cerr << "Error occurs";
	else {
		int i = 0;
		string tmp_str;
		while (infile >> tmp_str) {
			v_str[i++] = tmp_str;
			cout << tmp_str << endl;
		}
		infile.close();
	}

	sort(v_str.begin(), v_str.end());
	ofstream sortfile("./sort_data.txt");
	if (!sortfile)
		cerr << "Error occurs" << endl;
	else {
		for (int i = 0; i < v_str.size(); i++) {
			sortfile << v_str[i] << "\n";
		}
		sortfile.close();
	}


}

int main() {
	//get_userinfo();
	//get_nums();
	sort_new_file();
	return 0;
}