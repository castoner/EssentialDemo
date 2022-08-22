#include "demo02_oop.h"


/*����
* ���������������֣�һ��ָ��������int sort(int num1, int num2);��һ�ֲ�ָ��ֱ��ʹ�ò������͡�int sort(int, int);
* �����ķ������Ͳ���voidʱ��������ÿ�����ܵķ��ص㶼��ֵ���ء� 
* 
* ÿ�����ǵ���һ������ʱ���������ڴ��н���һ������������ջ��������������������ṩ��ÿ�����������Ĵ洢�ռ䡣��Ҳ�ṩ�˺��������ÿ��������ڴ�ռ䣬����Щ�����Ϊ�ֲ�����
һ��������ɣ�����ڴ�ͻᱻ�ͷŵ����ӳ����ջ�е�������
* ���뺯���Ĳ������Ϊֵ���ݷ�ʽ���������ƣ��õ���ʵ������һ���ֲ������������Ҫ�����ô��ݻ�ָ�봫�ݲ��ܶԱ������������е�ֵ�޸ġ�
* 
* ������������ʱ����Ҫʹ�ô�ַ��ʽ����ַ��ʽ��Ҫ���ڴ���class object��
* 
* file scope�ڶ���Ķ���߱�static extend����ʾ�ö�����ڴ���main��ʼִ��֮ǰ���Ѿ����������һֱ���ڵ����������������������ͣ���ر���ʼ��Ϊ0��
* 
* 
* ��̬�ڴ棺
* dynamic extent�����ڴ�ϵ�ɳ���Ŀ��пռ䣨free store�����������Ҳ����heap memory�������ڴ��ɳ���Ա�Լ���������ϵͨ��new���ʽ��ɣ��ͷ�ͨ��delete���ʽ��ɡ�
* delete pi; delete [] pia;
* ��Ϊ��̬�ڴ���Ҫ����Ա��������delete���ٶ���������ˣ��ͻ���ɣ�memory leak���ڴ�й©��
* 
* 
* Ĭ�ϲ���ֵ��
* �Բ���������Ϊ������Ĺ�ͨ��ʽ����"ֱ�ӽ���������file scope"Ҫ��Ϊ���ʡ�
* ������Ҫ����Ϣ�������Ļ��void bubble_sort( vector<int> &vec, ofstream &ofil );����ʹ��ofstream &���ͣ���������������Ĭ�ϲ���ֵ����Ϊ���ñ���ָ��������һ������ֵ.
* ������void bubble_sort( vector<int> &vec, ofstream *ofil ); ���Ը�ָ��ofil����ֵΪ0.�������Ƿ������Ϣ��
* Ҳ������void bubble_sort( vector<int> &vec, ostream &os = cout);������Ĭ�ϴ�����Ļ�������Զ���������ļ��С�
* ���ڲ���Ĭ��ֵ����������
*	1��Ĭ��ֵ�Ľ��������Ǵ����Ҳ࿪ʼ�ģ����Ϊĳ�������ƶ���Ĭ��ֵ����ô��һ�����Ҳ�����в�����������Ĭ�ϲ���ֵ���С�
*	2��Ĭ��ֵֻ�ܹ�ָ��һ�Σ��ں����������Ǻ������崦��һ����˵������ں�������������Ϊ�����ɶ��Խϸߡ�
* 
* 
* �ֲ���̬����
* ������һ������������ʱ������һϵ�����ݣ���Щ�������Ժ��ǿ����õ��ģ�get_fibon������ʱ������þֲ�������ܿ�����Ϊÿ�ε��ö���Ҫ�������ɡ�
*		��ʹ��file scope�ǲ����ʵģ���Ϊfilescope�������Ҳ�ͬ����֮��Ķ����ԣ�ʹ����������⡣
* 
* 
* inline����
*	����һЩ�����С���������á����µļ��㲻���ӡ��ĺ�������������Ϊinline�������ڱ��뱻���õĵط����������Ὣ��Ƕ�뵽�������ĺ����У��Լ��ٵ��ö��������ɵ�������ʧ��
*	ʲôʱ���ִ���أ�TODO
*	inline����������������ͷ�ļ��С�
* 
* 
* �ṩ���غ���
* ������һ����������ӷ����ţ��������ַ���ʱ����ʵ��ƴ�ӹ��ܣ��������֣�ʵ����ӵĹ��ܣ�����bool��ʵ�֣�false+false=true�Ĺ��ܡ�����ʹ�����ء�
*	�������ػ��ƣ������б���ͬ���������Ͳ�ͬ���߲���������ͬ�������������������������ڵ�����Щͬ��������ʱ���ͨ���ȶԲ������ҳ�����ʵġ�
* 
* 
* ʹ��ģ�壨����3��
* ����һ����������ͬ����������ֻ�ǲ������Ͳ�ͬ��ʱ�򣬶�������������ʵ�ֻ�������⣬�����10��20������ʵ����̫���ӵĹ����ˡ��Դ˿�����ģ�塣
* function template�������б���ָ����ȫ�������֣�������������Ϣ�����˳����������ڶ��µ����ͽ��в�����ʱ�򣬾Ͳ���Ҫ�����κεĸ����ˡ����������������Ϣ��Ҫ���û���ʹ��template function��ʵ��ʱָ����
* function template�Թؼ���template���������������ԳɶԼ����Ű�Χ������һ��������ʶ������Щ��ʶ��������ռλ���Ľ�ɫ���ڵ��õ�ʱ���û���Ҫָ���������ݡ�
* ģ�庯������Ҳ���������غ���
* 
* 
* **����ָ��**
* const vector<int>* (*seq_ptr)(int);  // ���÷�ʽΪ const vector<int> *seqp = seq_ptr(num);
* 
* �趨ͷ�ļ�
* ��������
*	1�������Ķ���ֻ������һ�ݣ������������������кܶ�ݣ���˲���Ѻ����Ķ������ͷ�ļ��У���Ϊͬһ������Ķ�������ļ����ܶ���������ͷ�ļ���
*	2��Ϊ���ܹ���չinline���������ݣ���ÿ�����õ��ϣ�����������ȡ���䶨�塣���뽫�����������ͷ�ļ��ϡ�
*	3����file scope�ж���Ķ���������ܱ�����ļ����ʣ�Ӧ�ñ�������ͷ�ļ��С�����seq_array��ָ�����顿��
*		const int seq_cnt = 6;
*		const vector<int>* (*seq_array[seq_cnt])(int); // �����ַ�ʽ��ʵ�Ǻ���ָ��Ķ���
*		����Ҫ��Ϊ extern const vector<int>* (*seq_array[seq_cnt])(int);����ΪʲôҪ����extern�أ�
*		const object ��inline����һ������һ�ζ�������µ����⡣const object ֻҪ�����ļ����ǲ��ɼ��ģ���ζ�����ǿ����ڶ�������ļ��м��Զ��塣���ᵼ���κδ���
*		���������seq_array����const object������һ��ָ��const object��ָ�롣
*	4������<>����""
*		������ļ�����Ϊ�Ǳ�׼�Ļ�����Ŀר����ͷ�ļ���������<>�����������������ļ�ʱ��������ĳЩĬ�ϵĴ���Ŀ¼��Ѱ�ҡ�
*		���	���ļ���һ�����û��ṩ��ͷ�ļ�������"",���������������ļ�ʱ������Ҫ�������ļ����ļ����ڴ���Ŀ¼��ʼ����
*
*/




// ��ϰ2.1 ѭ����λȡ쳲����������е�����
int get_fibon(int pos) {
	int element = 1;
	int n_2 = 1, n_1 = 1;
	for (int ix = 3; ix <= pos; ix++) {
		element = n_1 + n_2;
		n_1 = n_2;
		n_2 = element;
	}

	return element;
}


// ����1����ð������ʵ�ֶ�vector�ڵ��������� ����һ������Ѳ����е����÷�ȥ������ʲôЧ����
void display(vector<int>& vec) {
	for (int ix = 0; ix < vec.size(); ix++)
		cout << vec[ix] << "\t";
	cout << endl;
}

void swap(int& num_1, int& num_2) {
	int tmp;
	tmp = num_1;
	num_1 = num_2;
	num_2 = tmp;
}

void bubble_sort(vector<int>& vec) {
	for (int ix = 0; ix < vec.size(); ix++) {
		for (int jx = ix + 1; jx < vec.size(); jx ++){
			if (vec[ix] > vec[jx])
				swap(vec[ix], vec[jx]);
		}
	}
}


// ����2���þ�̬�ֲ���������ȡ쳲���������ָ��Ԫ��ֵ������ֵconst vector<int>*
int fibon_seq(int pos) {
	static vector<int> elems;
	for (int ix = elems.size(); ix <= pos; ix++) {
		if (ix < 2)
			elems.push_back(1);
		else
			elems.push_back(elems[ix - 1] + elems[ix - 2]);
	}

	display(elems);

	cout << endl;
	return elems[pos];
}


// ����3����templateʵ�������Ϣ����
template<typename T>	// typename��ʾ�����T�ں�������һ����ʱ������͵�ռλ��
void display_message(const string& msg, const vector<T>& vec) {
	cout << msg;
	for (int x = 0; x < vec.size(); x++) {
		T val = vec[x];
		cout << val << '\t';
	}
}


// ��ϰ2.2��Pentagonal������P(n)=n(3n-1)/2���ɡ����庯�����ù�ʽ��������Ԫ�طŵ��û������vector�С�������һ������������vector�е�����Ԫ�ش�ӡ�������˺����ĵڶ���������һ���ַ�������ʾvector�ڵ����е����͡�
bool create_pentagonal(int size, vector<int>& vec) {
	/*if (size < 0 || size > 64) {
		cerr << "Sorry, Invalid position: " << size << endl;
		return false;
	}*/
	if (!judge_size(size))
		return false;
	
	int elem = 0;
	for (int i = 0; i < size; i++) {
		elem = i * (3 * i - 1);
		vec.push_back(elem);
	}
	return true;
}

void display_pen(vector<int>& vec, string elem_type) {
	if (elem_type == "int") {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << "\t";
			if ((i+1) % 10 == 0)
				cout << endl;
		}
	}
	else {
		cerr << "Please enter correctly elem_type !\n"; 
	}
	cout << endl;
}

// ��ϰ2.4���Ծֲ���̬vector�洢Pentagonal����Ԫ�ء���һ����������λ�ã������б��λ���ϵ�Ԫ��
const vector<int>* gen_pentagonal(int size) {
	static vector<int> vec_pentagonal;
	for (int ix = vec_pentagonal.size(); ix < size; ix++) {
		int elem = ix * (ix * 3 - 1) / 2;
		vec_pentagonal.push_back(elem);
	}
	return &vec_pentagonal;
}

int get_elem(int pos) {
	const vector<int> *pent_vec = gen_pentagonal(pos);
	int elem = (*pent_vec)[pos-1];
	cout << elem << endl;
	return elem;
}


// ��ϰ2.5������max
int max(int num1, int num2) {
	if (num1 > num2)
		return num1;
	else
		return num2;
}

float max(float num1, float num2) {
	if (num1 > num2)
		return num1;
	else
		return num2;
}

string max(string str1, string str2) {
	if (str1 > str2)
		return str1;
	else
		return str2;
}

int max(vector<int> vec) {
	bubble_sort(vec);
	return vec[vec.size() - 1];
}

double max(vector<double> vec) {
	for (int ix = 0; ix < vec.size(); ix++) {
		for (int ij = ix + 1; ij < vec.size(); ij++) {
			if (vec[ix] > vec[ij]) {
				double tmp;
				tmp = vec[ij];
				vec[ij] = vec[ix];
				vec[ix] = tmp;
			}
		}
	}
	return vec[vec.size() - 1];
}

int max(int* arr, int size) {
	for (int ix = 0; ix < size; ix++) {
		for (int ij = 0; ij < size; ij++) {
			if (arr[ix] > arr[ij]) {
				int tmp;
				tmp = arr[ix];
				arr[ix] = arr[ij];
				arr[ij] = tmp;
			}
		}
	}
	return arr[size - 1];
}

// ��ϰ2.6
template<typename T>
T tmax(T arg1, T arg2) {
	return arg1 < arg2 ? arg1 : arg2;
}

template<typename T>
T tmax(vector<T> vec) {
	for (int ix = 0; ix < vec.size(); ix++) {
		for (int ij = ix + 1; ij < vec.size(); ij++) {
			if (vec[ix] < vec[ij]) {
				T tmp;
				tmp = vec[ij];
				vec[ij] = vec[ix];
				vec[ix] = tmp;
			}
		}
	}
	return vec[vec.size() - 1];
}

template<typename T>
T tmax(T* arr, T size) {
	for (int ix = 0; ix < size; ix++) {
		for (int ij = 0; ij < size; ij++) {
			if (arr[ix] < arr[ij]) {
				T tmp;
				tmp = arr[ix];
				arr[ix] = arr[ij];
				arr[ij] = tmp;
			}
		}
	}
	return arr[size - 1];
} 

int main() {
	// ��ϰ2.1|����2
	/*int num_input;
	int num_fibon;
	while (1) {
		cout << "Please enter the pos, if you want to quit please enter 0:\t";
		cin >> num_input;
		if (num_input < 0) {
			cout << "sb!" << endl;
			continue;
		}
		else if (num_input == 0) {
			cout << "GoodBye~";
			break;
		}
		else if (num_input <2 ) {
			num_fibon = 1;
		}
		else {
			//num_fibon = get_fibon(num_input);
			num_fibon = fibon_seq(num_input);
		}
		cout << "The num in fibon with index " << num_input << " is " << num_fibon << endl;
	}*/

	// ����1
	/*vector<int> vec = { 1, 33, 21, 24, 29, 81, 12, 2, 8, 5, 101 };
	cout << "before bubble_sort: ";
	display(vec);

	cout << "\n after bubble_sort: ";
	bubble_sort(vec);
	display(vec);*/

	// ����3
	/*vector<int> ivec = {1, 3, 4, 2, 5, 7, 9};
	vector<char> cvec = { 'i', ' ', 'l', 'o', 'v', 'e', ' ', 'c', 'o', 'c', 'o' };
	string msg = "hello template\n";
	display_message(msg, ivec);
	cout << endl;
	display_message(msg, cvec);*/

	// ��ϰ2.2 | ��ϰ2.3
	/*vector<int> vec;
	create_pentagonal(15, vec);
	display_pen(vec, "int");
	vec = {};
	create_pentagonal(10, vec);
	display_pen(vec, "int");
	vec = {};
	create_pentagonal(65, vec);
	display_pen(vec, "int");*/
	
	// ��ϰ2.4
	//get_elem(4);

	// ��ϰ2.5

	// ��ϰ2.6
	vector<string> vec = { "hello", "caston", "coco", "love" };
	int arr[10] = { 2, 3, 5, 2, 7, 11, 5, 6,2222, 10 };
	cout << tmax(arr, 10) << endl;
	
	return 0;
}