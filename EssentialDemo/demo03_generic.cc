/**STL
主要由两部分组成：容器container包括：vector、list、map、set等；泛型算法：find，sort，replace，merge等
顺序性容器：vector,list,主要对其进行迭代操作；关联容器；map,set，可以快速查找容器中的元素值。
所有容器都提供size(),empty(),clear(),begin(),end(),[insert(),erase(),这俩在对顺序型容器和关联容器是有区别的];
--顺序性容器：
vector,list,deque
顺序性容器都有push_back和pop_back方法，而list和deque还有push_front,pop_front两个方法，注意CPP中的pop函数是void的。查看首尾元素可以用front(),back()
push_front,push_back属于特殊化的insert。每个容器还有四种变形：
1、iterator insert(iterator position, elemType value);将value插入到指定的position，并返回该position的iterator。
【示例1-inert_iterator】
2、void insert( iteartor position, int count, elemType value )  在position之前插入count个数据，值为value。
3、void insert( iterator1 position, iterator 2 first, iterator2 last ) 在position之前插入[first, last)所指向的各个元素。
4、iterator insert( iterator position ) 在position前插入元素，元素值为其所属类型的默认值。
pop_fornt,pop_back属于特殊化的erase。每个容器还有两种变形：
1、iterator erase( iterator position )可以删除position指定的元素。可以形如it = find(begin, end, value);erase(it);
2、iterator erase( iterator first, iterator last );可以删除first到last中的元素。
如：
list<string>::iterator it1 = find( first, last, str1 );
list<string>::iterator it2 = find( first, last, str2 );
slist.erase( it1, it2);


--使用泛型算法
 对于vector，要在其中搜索一个值可以有四种方法：
 find()线性搜索，无序，较慢
 binary_search()二叉搜索，有序，速度快。需要确定数列中存在足够数量的元素，也就是elem必须在此数列之中。可以通过elem和max对比，max可以用max_element(vec.begin(), vec.end())
	要求排序，而不确定是否排序则需要对其进行排序操作：
	vector<int> temp( vec.size() );
	copy( vec.begin(), vec.end(), temp.begin() ); copy需要确保目标容器有足够的空间来存放复制的元素。如果不确定可以用insertion来取代assignment。
	sort( temp.begin(), temp.end() );
	return binray_search( temp.begin(), temp.end(), elem );
 count()返回数值相符的数目。
 search()比对某个容器中是否存在某个子序列。


 --如何设计一个泛型算法
 示例2：给定一个vector<int>，需要返回一个vector<int>，其中需要有原vector中所有小于10的数字。

 -Function object：class的实例对象，对call运算符做了重载操作。
 标准库事先定义了一些function object，分为算术运算arithmetic、关系运算relational、逻辑运算logical
 plus<type>, minus<type>,negate<type>,multiplies<type>,divides<type>,modules<type>
 less<type>,less_equal<type>,greater<type>,greater_equal<type>,equal_to<type>,not_equal_to<type>.
 logical_and<type>,logical_or<type>,logical_not<type>
 使用：transform(fib.begin(), fib.end(), pell.begin(), fib_plus_pell.begin(), plus<int>() );
 -Function Object Adapter:P87
 function_object_adapter会对function_object进行修改奥做。binder_adapter会将 参数绑定到某个特定值，使binary_function_object转化为unary_function_object。
 STL提供了两个binder adapter，bind1st,bind2nd
 示例2


array[2]包括了指针计算和提领两个操作。
vector可以为空，array则不可以。
可以用begin(vec)到end(vec)来表示vector的首尾指针。
用这两个参数作为find函数入参，可以整合vector和array两个格式，但是对于list来说，是不适用的。
因为list是链表，元素以一组指针相互链接。forward指向next元素，backward指向preceding元素。不适合通过指针算数运算进行前后移动。
事实上可以通过修改参数列表，并不需要修改find函数的内容。


Iterator===============================
定义并使用标准容器的Iterator。首先考虑（1）迭代对象的类型，（2）iterator所指的元素类型，这会决定Iterator提领操作的返回值。


map=================================
map被定义为一对数值，其中的key通常是一个字符串，扮演索引的角色。
map有成员：first对应着key，second对应着value。
查询map中是否含有key有三种方法：
1、count = words["vermeer"];这种方式，如果words中没有vermeer，会自动添加一个key为vermeer，且值为0。
2、用map的find，不同于泛型函数find，这里的find的使用方法：words.find("vermeer");如果有，find会返回一个iterator指向这对keyvalue的pair，没有则返回end()。
3、利用map的count，count会返回某特定项在map内的个数。map中找到该元素返回1，否则返回0；
任何一个key在map中只会存在一次，如果需要储存多份相同的key，需要用到multimap。


set====================================
set是存放key的
set会根据所属类型的less-than运算符进行排序。
用count判断是否存在于set中：set.count("vermeer")

iterator inserter:
赋值操作需要保证容器的容量足够，而insert操作则不需要。
STL提供了三个insertion adapter:  【#include<iterator>】
1.back_inserter，以容器的push_back取代assignment操作。比较适合v
 ector，使用方式：unique_copy(ivec.begin(), ivec.end(), back_inserter(result_vec));
2.inserter()会以容器的insert()函数取代assignment操作。接受两个参数，一个是容器，一个是iterator，指向容器内的插入操作七点。unique_copy( ivec.begin(), ivec.end(), inserter(ivec_res, ivec_res.end() ));
3.front_inserter()会以容器的push_front()函数取代assignment运算符。只适用于list和deque。copy( ilist.begin(), ilist.end(), front_inserter(ilist_clone) );


iostream Iterator
istream_iterator从标准输入设备读取字符串，需要一对iterator。
first: istream_iterator<string> is(cin);
end:   istream_iterator<string> eof;
使用：copy( is, eof, back_inserter(text) );

ostream_iterator标识字符串元素的输出位置。一旦不再有任何元素需要输出，就停止输出操作。
定义一个绑定至标准输出设备的ostream_iterator。此标准输出设备供我们输出类型为string的元素。
ostream_iterator<string> os( cout, " " ); 第二个参数可以是C-style字符串，也可以是字符串常量。表示各个元素被输出时的分隔符。
使用：copy(text.begin(), text.end(), os); copy会将存储在text中的所有元素一一写道os所表示的ostream上。每个元素都用空格隔开了

很多时候我们不是从标准输入设备读数据，也不是要写道标准输出设备去，而是希望从文件中读取，写入到文件中去。这只需要将istream_iterator绑定到ifstream。见示例3
*/ 

#include "demo03.h"
#include <direct.h>

// 示例1-insert_iterator
template<typename T>
typename list<T>::iterator insert_iterator(list<T> ilist, T ival) {
	list<T>::iterator it = ilist.begin();
	while (it != ilist.end()) {
		if (*it >= ival) {
			ilist.insert(it, ival);
			ibreak;
		}
		++it;
	}
	if (it == ilist.end())
		ilist.push_back(ival);

	return it;
}


// 实例2-Function Object Adapter
/*
* less的function call操作符重构
template <class _Ty = void>
struct less {
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _FIRST_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty _SECOND_ARGUMENT_TYPE_NAME;
    _CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool _RESULT_TYPE_NAME;

    _NODISCARD constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left < _Right;
    }
};
*/
vector<int> filter(const vector<int>& vec, int val, less<int>& it) {
	vector<int> nvec;
	vector<int>::const_iterator iter = vec.begin();

	// bind2nd( less<int>, val);
	// 将val绑定与less<int>的第二个参数上
	// 这样less<int>会将每个元素拿来和val比较

	while ((iter = find_if(iter, vec.end(), bind2nd(it, val))) != vec.end()) {
		nvec.push_back(*iter );
		iter++;
	}
	return nvec;
}


// 示例2-消除vector要求的filter
template<typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter_full(InputIterator first, InputIterator last, OutputIterator at, const ElemType& val, Comp pred) {
	while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
		cout << "found value: " << *first << endl;
		*(at++) = *(first++);
	}
	return at;
}

// 示例2-排序的方法获取小于val的所有值,find_if找到第一个大于val的值，erase之后的空间，不要对原vector进行修改
vector<int> less_than_val(const vector<int> ivec, int val) {
	vector<int> local_vec( ivec );
	sort( local_vec.begin(), local_vec.end() );
	vector<int>::iterator iter = find_if(local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val));
	local_vec.erase(iter, local_vec.end());
	return local_vec;
}


//示例3-用istream_iterator操作文件
bool stream_file(string in, string out) {
	ifstream in_file;
	//in_file.open("E:\\Code\\Cpp\\EssentialCpp\\EssentialDemo\\EssentialDemo\\files\\in.txt");// 这里用绝对路径是因为vs中debug的路径与执行路径有所不同。
	in_file.open(in);
	ofstream out_file;
	out_file.open(out);
	//out_file.open("E:\\Code\\Cpp\\EssentialCpp\\EssentialDemo\\EssentialDemo\\files\\out.txt");

	if (!in_file || !out_file) {
		cerr << "!! unable open the necessary files. \n";
		return false;
	}

	istream_iterator<string> is(in_file);
	istream_iterator<string> eof;

	vector<string> text;
	copy(is, eof, back_inserter(text));
	sort(text.begin(), text.end());
	
	ostream_iterator<string> os(out_file, " ");
	copy(text.begin(), text.end(), os);
	return true;
}


// 练习3.1 读取文本，将单词存入map为key，value为单词出现的次数。设置排除清单set，去除a,an,or,the,and,but之类的，存入map之前需确认单词不在排除清单中。
bool file_word(string in, string out) {
	ifstream in_file(in);
	ofstream out_file(out);
	if (!in_file.is_open() || !out_file.is_open())
	{
		cout << "Could not open the file " <<  endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}

	set<string> word_exclude = { "a", "an", "or", "and", "but", "the" };
	set<string>::iterator set_begin = word_exclude.begin();
	map<string, int> word_map_count;
	string word;

	while (in_file >> word) {
		if (word_exclude.count(word))
			word_map_count[ word ]++;
	}
	map<string, int>::iterator iter = word_map_count.begin();

	while (iter != word_map_count.end()) {
		out_file << iter->first << " ( " << iter->second << " )" << endl;
		iter++;
	}
	out_file << endl;

	return true;
}

int main() {
	/*int arr[20] = { 1, 3, 5, 7, 9 };
	vector<int> vec = { 1, 3, 5, 7, 9 };
	vector<int>::iterator earr = vec.begin();*/ 

	// 示例2filter_full调用
	/*const int elem_size = 8;
	int ia[elem_size] = { 12, 8, 43, 0, 6, 21, 3, 7 };
	vector<int> ivec(ia, ia + elem_size);
	int ia2[elem_size];
	vector<int> ivec2(elem_size);

	cout << "filtering integer array for values less than 8\n";
	filter_full( ia, ia+elem_size, ia2, elem_size, less<int>() );

	cout << "filtering integer vector fo values greater than 8\n";
	filter_full(ivec.begin(), ivec.end(), ivec2.begin(), elem_size, greater<int>());*/

	//vector<int> result_vec;
	//int ia[9] = { 12, 8, 43, 0, 6, 21, 3, 2, 7 };
	//vector<int> ivec(ia, ia+9);
	//unique_copy(ivec.begin(), ivec.end(), back_inserter(result_vec));// 复制到result_vec中，用push_back的方式实现。
	//cout << result_vec[4] << endl;

	/*string in = "files/in.txt";
	string out = "files/out.txt";
	bool status = stream_file(in, out);
	if (status) cout << "success writer into " << out << endl;*/

	// 习题3.1
	string in = "E:\\Code\\Cpp\\EssentialCpp\\EssentialDemo\\EssentialDemo\\files\\in.txt";
	string out = "E:\\Code\\Cpp\\EssentialCpp\\EssentialDemo\\EssentialDemo\\files\\out.txt";
	 
	return 0;
}