/**
# ��һ�£�C++��̻���
�漰�������ݣ�
1�������������ͣ�����ֵBoolean���ַ�character������integer��������floating point��
2���������������ϵ��������߼��������
3��������֧��ѭ��������䣬�����ı����Ŀ������̡�
4���������ͣ�ָ�롾���ʹ��һ���Ѿ����ڵĶ��󡿡����顾����һ�������ͬ�������͵�Ԫ�ء���
5��һ�ױ�׼��ͨ�õĳ��󻯿⣬�����ַ���������vector��
*/

/*
## ����
������һ������ĳ���������У����ĸ�������ɣ�����ֵ���͡��������ơ������б������塣
- ����������Ҫ�ṩ�����Ĺ��ܣ���min��sort����һĿ��Ȼ����f,g��Ȼ���Ǻ������ˣ�����һͷ��ˮ��
- mian��������������Ĭ�ϳ����ж�����main����������main������ʼִ�о������ݣ����û�ж���main����VisualStuio�»ᱨ���޷�����main������
����	LNK2019	�޷��������ⲿ���� main������ "int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ) �������˸÷���	E:\Code\Cpp\EssentialCpp\EssentialDemo\out\build\x64-debug\EssentialDemo	E:\Code\Cpp\EssentialCpp\EssentialDemo\out\build\x64-debug\EssentialDemo\MSVCRTD.lib(exe_main.obj)	1	

## ��
�������˼��ĺ��ģ�class�Ķ���ͨ����Ϊ�������֣�һ����ͷ�ļ�������������class�ṩ�ĸ��ֲ�����Ϊ����һ���ļ�����������ļ������������Щ������Ϊ��ʵ�����ݡ�
ÿһ��classӦ�����Լ���output�����������������calss���û��ܹ��������������һ����һͬ���ķ�ʽ����������ݡ�

����ָ��֮ǰ�������ж��Ƿ�Ϊ��ָ�롣 if(pv && pv->get_state()) cout << ok << endl;
*/

#include <iostream>  
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main01() {
	// ���Խ����û���������
	string first_name, last_name;
	cout << "Please enter your first name";
	cin >> first_name;
	cout << "Please enter your last name";
	cin >> last_name; 
	cout << "\n" << "Hello, " << first_name << last_name << " ... and GoodBye!\n";
	return 0;
}


// ϰ��1.5 ��c_style �� string�ֱ������û���Ϣ
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


// ϰ��1.6 ��array��vector�������֣�����ƽ����
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


// 1.7 �����������ִ��̣�����һ�����ж�ȡ���ı����ݴ����vector��������ݣ�����sort��������������ļ���
void sort_new_file() {
	ofstream outfile("./ori_data.txt");	// ��������ܣ�ofstreamһֱд��fstream������֪�����������oo
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
		outfile.close(); // �ǵùر��ļ�
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