#include "demo02_oop.h"


/*函数
* 函数声明：有两种，一种指定参数名int sort(int num1, int num2);，一种不指定直接使用参数类型。int sort(int, int);
* 函数的返回类型不是void时，必须在每个可能的返回点都把值返回。 
* 
* 每当我们调用一个函数时，都会再内存中建立一块叫做“程序堆栈”的特殊区域。这块区域提供了每个函数参数的存储空间。它也提供了函数定义的每个对象的内存空间，将这些对象成为局部对象。
一旦函数完成，这块内存就会被释放掉（从程序堆栈中弹出）。
* 传入函数的参数如果为值传递方式则会产生复制，得到的实际上是一个局部变量，因此需要用引用传递或指针传递才能对变量本身所具有的值修改。
* 
* 传递内置类型时，不要使用传址方式。传址方式主要用于传递class object。
* 
* file scope内定义的对象具备static extend，表示该对象的内存在main开始执行之前就已经被分配好了一直存在到程序结束；如果是内置类型，则必被初始化为0，
* 
* 
* 动态内存：
* dynamic extent，其内存系由程序的空闲空间（free store）分配而来，也叫做heap memory，这种内存由程序员自己管理，分配系通过new表达式完成，释放通过delete表达式完成。
* delete pi; delete [] pia;
* 因为动态内存需要程序员管理，调用delete销毁对象。如果忘了，就会造成（memory leak）内存泄漏。
* 
* 
* 默认参数值：
* 以参数传递作为函数间的沟通方式，比"直接将对象定义于file scope"要更为合适。
* 假设需要将信息输出到屏幕：void bubble_sort( vector<int> &vec, ofstream &ofil );这里使用ofstream &类型，这样不可以设置默认参数值，因为引用必须指向对象而非一个具体值.
* 可以用void bubble_sort( vector<int> &vec, ofstream *ofil ); 可以给指针ofil赋初值为0.来决定是否输出信息。
* 也可以用void bubble_sort( vector<int> &vec, ostream &os = cout);来设置默认传到屏幕，可以自定义输出到文件中。
* 关于参数默认值的两个规则；
*	1、默认值的解析操作是从最右侧开始的，如果为某个参数制定了默认值，那么这一参数右侧的所有参数都必须有默认参数值才行。
*	2、默认值只能够指定一次，在函数声明或是函数定义处。一般来说都会放在函数声明出，因为这样可读性较高。
* 
* 
* 局部静态对象：
* 场景：一个函数在运行时会生成一系列数据，这些数据在以后都是可以用到的（get_fibon），这时候如果用局部变量会很亏，因为每次调用都需要重新生成。
*		而使用file scope是不合适的，因为filescope对象会打乱不同函数之间的独立性，使他们难以理解。
* 
* 
* inline函数
*	对于一些【体积小、常被调用、从事的计算不复杂】的函数，可以声明为inline函数，在必须被调用的地方，编译器会将他嵌入到调用它的函数中，以减少调用多个函数造成的性能损失。
*	什么时候会执行呢？TODO
*	inline函数常常被定义在头文件中。
* 
* 
* 提供重载函数
* 场景：一个函数，如加法符号，在两个字符串时，想实现拼接功能；两个数字，实现相加的功能；两个bool想实现，false+false=true的功能。可以使用重载。
*	函数重载机制：参数列表不相同（参数类型不同或者参数个数不同）的两个或多个函数。编译器在调用这些同名函数的时候会通过比对参数，找出最合适的。
* 
* 
* 使用模板（案例3）
* 对于一个函数有相同参数个数，只是参数类型不同的时候，定义两三个函数实现还可以理解，如果是10个20个，那实在是太繁杂的工作了。对此可以用模板。
* function template将参数列表中指定的全部（部分）参数的类型信息抽离了出来，这样在对新的类型进行操作的时候，就不需要再有任何的更改了。不过这里的类型信息需要由用户在使用template function的实例时指定。
* function template以关键字template开场，其后紧接着以成对尖括号包围起来的一个或多个标识符。这些标识符扮演者占位符的角色，在调用的时候，用户需要指定具体内容。
* 模板函数本身也可以是重载函数
* 
* 
* **函数指针**
* const vector<int>* (*seq_ptr)(int);  // 调用方式为 const vector<int> *seqp = seq_ptr(num);
* 
* 设定头文件
* 几个规则；
*	1、函数的定义只可以由一份！！！但是声明可以有很多份，因此不会把函数的定义放在头文件中，因为同一个程序的多个代码文件可能都会包含这个头文件。
*	2、为了能够拓展inline函数的内容，在每个调用点上，编译器都得取到其定义。必须将函数定义放在头文件上。
*	3、在file scope中定义的对象，如果可能被多个文件访问，应该被声明在头文件中。例如seq_array【指针数组】，
*		const int seq_cnt = 6;
*		const vector<int>* (*seq_array[seq_cnt])(int); // 用这种方式其实是函数指针的定义
*		所以要改为 extern const vector<int>* (*seq_array[seq_cnt])(int);但是为什么要加上extern呢？
*		const object 和inline函数一样，是一次定义规则下的例外。const object 只要出了文件就是不可见的，意味着我们可以在多个代码文件中加以定义。不会导致任何错误。
*		但是这里的seq_array不是const object，而是一个指向const object的指针。
*	4、对于<>还是""
*		如果此文件被认为是标准的或者项目专属的头文件，可以用<>，编译器在搜索此文件时，会现在某些默认的磁盘目录中寻找。
*		如果	此文件是一个由用户提供的头文件，则用"",编译器在搜索此文件时，会由要包含此文件的文件所在磁盘目录开始找起。
*
*/




// 练习2.1 循环按位取斐波那契数列中的数据
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


// 案例1：用冒泡排序法实现对vector内的整数排序 【试一试如果把参数中的引用符去掉，是什么效果】
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


// 案例2：用静态局部变量降低取斐波那契数列指定元素值的消费值const vector<int>*
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


// 案例3：用template实现输出信息操作
template<typename T>	// typename表示这里的T在函数中是一个暂时存放类型的占位符
void display_message(const string& msg, const vector<T>& vec) {
	cout << msg;
	for (int x = 0; x < vec.size(); x++) {
		T val = vec[x];
		cout << val << '\t';
	}
}


// 练习2.2：Pentagonal数列由P(n)=n(3n-1)/2生成。定义函数利用公式将产生的元素放到用户传入的vector中。并用另一个函数将给定vector中的所有元素打印出来，此函数的第二参数接受一个字符串，表示vector内的数列的类型。
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

// 练习2.4：以局部静态vector存储Pentagonal数列元素。另一个函数接受位置，返回列表该位置上的元素
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


// 练习2.5：重载max
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

// 练习2.6
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
	// 练习2.1|案例2
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

	// 案例1
	/*vector<int> vec = { 1, 33, 21, 24, 29, 81, 12, 2, 8, 5, 101 };
	cout << "before bubble_sort: ";
	display(vec);

	cout << "\n after bubble_sort: ";
	bubble_sort(vec);
	display(vec);*/

	// 案例3
	/*vector<int> ivec = {1, 3, 4, 2, 5, 7, 9};
	vector<char> cvec = { 'i', ' ', 'l', 'o', 'v', 'e', ' ', 'c', 'o', 'c', 'o' };
	string msg = "hello template\n";
	display_message(msg, ivec);
	cout << endl;
	display_message(msg, cvec);*/

	// 练习2.2 | 练习2.3
	/*vector<int> vec;
	create_pentagonal(15, vec);
	display_pen(vec, "int");
	vec = {};
	create_pentagonal(10, vec);
	display_pen(vec, "int");
	vec = {};
	create_pentagonal(65, vec);
	display_pen(vec, "int");*/
	
	// 练习2.4
	//get_elem(4);

	// 练习2.5

	// 练习2.6
	vector<string> vec = { "hello", "caston", "coco", "love" };
	int arr[10] = { 2, 3, 5, 2, 7, 11, 5, 6,2222, 10 };
	cout << tmax(arr, 10) << endl;
	
	return 0;
}