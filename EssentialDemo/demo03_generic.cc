/**STL
��Ҫ����������ɣ�����container������vector��list��map��set�ȣ������㷨��find��sort��replace��merge��
˳����������vector,list,��Ҫ������е�������������������map,set�����Կ��ٲ��������е�Ԫ��ֵ��
�����������ṩsize(),empty(),clear(),begin(),end(),[insert(),erase(),�����ڶ�˳���������͹����������������];
--˳����������
vector,list,deque
˳������������push_back��pop_back��������list��deque����push_front,pop_front����������ע��CPP�е�pop������void�ġ��鿴��βԪ�ؿ�����front(),back()
push_front,push_back�������⻯��insert��ÿ�������������ֱ��Σ�
1��iterator insert(iterator position, elemType value);��value���뵽ָ����position�������ظ�position��iterator��
��ʾ��1-inert_iterator��
2��void insert( iteartor position, int count, elemType value )  ��position֮ǰ����count�����ݣ�ֵΪvalue��
3��void insert( iterator1 position, iterator 2 first, iterator2 last ) ��position֮ǰ����[first, last)��ָ��ĸ���Ԫ�ء�
4��iterator insert( iterator position ) ��positionǰ����Ԫ�أ�Ԫ��ֵΪ���������͵�Ĭ��ֵ��
pop_fornt,pop_back�������⻯��erase��ÿ�������������ֱ��Σ�
1��iterator erase( iterator position )����ɾ��positionָ����Ԫ�ء���������it = find(begin, end, value);erase(it);
2��iterator erase( iterator first, iterator last );����ɾ��first��last�е�Ԫ�ء�
�磺
list<string>::iterator it1 = find( first, last, str1 );
list<string>::iterator it2 = find( first, last, str2 );
slist.erase( it1, it2);


--ʹ�÷����㷨
 ����vector��Ҫ����������һ��ֵ���������ַ�����
 find()�������������򣬽���
 binary_search()���������������ٶȿ졣��Ҫȷ�������д����㹻������Ԫ�أ�Ҳ����elem�����ڴ�����֮�С�����ͨ��elem��max�Աȣ�max������max_element(vec.begin(), vec.end())
	Ҫ�����򣬶���ȷ���Ƿ���������Ҫ����������������
	vector<int> temp( vec.size() );
	copy( vec.begin(), vec.end(), temp.begin() ); copy��Ҫȷ��Ŀ���������㹻�Ŀռ�����Ÿ��Ƶ�Ԫ�ء������ȷ��������insertion��ȡ��assignment��
	sort( temp.begin(), temp.end() );
	return binray_search( temp.begin(), temp.end(), elem );
 count()������ֵ�������Ŀ��
 search()�ȶ�ĳ���������Ƿ����ĳ�������С�


 --������һ�������㷨
 ʾ��2������һ��vector<int>����Ҫ����һ��vector<int>��������Ҫ��ԭvector������С��10�����֡�

 -Function object��class��ʵ�����󣬶�call������������ز�����
 ��׼�����ȶ�����һЩfunction object����Ϊ��������arithmetic����ϵ����relational���߼�����logical
 plus<type>, minus<type>,negate<type>,multiplies<type>,divides<type>,modules<type>
 less<type>,less_equal<type>,greater<type>,greater_equal<type>,equal_to<type>,not_equal_to<type>.
 logical_and<type>,logical_or<type>,logical_not<type>
 ʹ�ã�transform(fib.begin(), fib.end(), pell.begin(), fib_plus_pell.begin(), plus<int>() );
 -Function Object Adapter:P87
 function_object_adapter���function_object�����޸İ�����binder_adapter�Ὣ �����󶨵�ĳ���ض�ֵ��ʹbinary_function_objectת��Ϊunary_function_object��
 STL�ṩ������binder adapter��bind1st,bind2nd
 ʾ��2


array[2]������ָ��������������������
vector����Ϊ�գ�array�򲻿��ԡ�
������begin(vec)��end(vec)����ʾvector����βָ�롣
��������������Ϊfind������Σ���������vector��array������ʽ�����Ƕ���list��˵���ǲ����õġ�
��Ϊlist������Ԫ����һ��ָ���໥���ӡ�forwardָ��nextԪ�أ�backwardָ��precedingԪ�ء����ʺ�ͨ��ָ�������������ǰ���ƶ���
��ʵ�Ͽ���ͨ���޸Ĳ����б�������Ҫ�޸�find���������ݡ�


Iterator===============================
���岢ʹ�ñ�׼������Iterator�����ȿ��ǣ�1��������������ͣ���2��iterator��ָ��Ԫ�����ͣ�������Iterator��������ķ���ֵ��


map=================================
map������Ϊһ����ֵ�����е�keyͨ����һ���ַ��������������Ľ�ɫ��
map�г�Ա��first��Ӧ��key��second��Ӧ��value��
��ѯmap���Ƿ���key�����ַ�����
1��count = words["vermeer"];���ַ�ʽ�����words��û��vermeer�����Զ����һ��keyΪvermeer����ֵΪ0��
2����map��find����ͬ�ڷ��ͺ���find�������find��ʹ�÷�����words.find("vermeer");����У�find�᷵��һ��iteratorָ�����keyvalue��pair��û���򷵻�end()��
3������map��count��count�᷵��ĳ�ض�����map�ڵĸ�����map���ҵ���Ԫ�ط���1�����򷵻�0��
�κ�һ��key��map��ֻ�����һ�Σ������Ҫ��������ͬ��key����Ҫ�õ�multimap��


set====================================
set�Ǵ��key��
set������������͵�less-than�������������
��count�ж��Ƿ������set�У�set.count("vermeer")

iterator inserter:
��ֵ������Ҫ��֤�����������㹻����insert��������Ҫ��
STL�ṩ������insertion adapter:  ��#include<iterator>��
1.back_inserter����������push_backȡ��assignment�������Ƚ��ʺ�v
 ector��ʹ�÷�ʽ��unique_copy(ivec.begin(), ivec.end(), back_inserter(result_vec));
2.inserter()����������insert()����ȡ��assignment��������������������һ����������һ����iterator��ָ�������ڵĲ�������ߵ㡣unique_copy( ivec.begin(), ivec.end(), inserter(ivec_res, ivec_res.end() ));
3.front_inserter()����������push_front()����ȡ��assignment�������ֻ������list��deque��copy( ilist.begin(), ilist.end(), front_inserter(ilist_clone) );


iostream Iterator
istream_iterator�ӱ�׼�����豸��ȡ�ַ�������Ҫһ��iterator��
first: istream_iterator<string> is(cin);
end:   istream_iterator<string> eof;
ʹ�ã�copy( is, eof, back_inserter(text) );

ostream_iterator��ʶ�ַ���Ԫ�ص����λ�á�һ���������κ�Ԫ����Ҫ�������ֹͣ���������
����һ��������׼����豸��ostream_iterator���˱�׼����豸�������������Ϊstring��Ԫ�ء�
ostream_iterator<string> os( cout, " " ); �ڶ�������������C-style�ַ�����Ҳ�������ַ�����������ʾ����Ԫ�ر����ʱ�ķָ�����
ʹ�ã�copy(text.begin(), text.end(), os); copy�Ὣ�洢��text�е�����Ԫ��һһд��os����ʾ��ostream�ϡ�ÿ��Ԫ�ض��ÿո������

�ܶ�ʱ�����ǲ��Ǵӱ�׼�����豸�����ݣ�Ҳ����Ҫд����׼����豸ȥ������ϣ�����ļ��ж�ȡ��д�뵽�ļ���ȥ����ֻ��Ҫ��istream_iterator�󶨵�ifstream����ʾ��3
*/ 

#include "demo03.h"
#include <direct.h>

// ʾ��1-insert_iterator
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


// ʵ��2-Function Object Adapter
/*
* less��function call�������ع�
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
	// ��val����less<int>�ĵڶ���������
	// ����less<int>�Ὣÿ��Ԫ��������val�Ƚ�

	while ((iter = find_if(iter, vec.end(), bind2nd(it, val))) != vec.end()) {
		nvec.push_back(*iter );
		iter++;
	}
	return nvec;
}


// ʾ��2-����vectorҪ���filter
template<typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter_full(InputIterator first, InputIterator last, OutputIterator at, const ElemType& val, Comp pred) {
	while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
		cout << "found value: " << *first << endl;
		*(at++) = *(first++);
	}
	return at;
}

// ʾ��2-����ķ�����ȡС��val������ֵ,find_if�ҵ���һ������val��ֵ��erase֮��Ŀռ䣬��Ҫ��ԭvector�����޸�
vector<int> less_than_val(const vector<int> ivec, int val) {
	vector<int> local_vec( ivec );
	sort( local_vec.begin(), local_vec.end() );
	vector<int>::iterator iter = find_if(local_vec.begin(), local_vec.end(), bind2nd(greater<int>(), val));
	local_vec.erase(iter, local_vec.end());
	return local_vec;
}


//ʾ��3-��istream_iterator�����ļ�
bool stream_file(string in, string out) {
	ifstream in_file;
	//in_file.open("E:\\Code\\Cpp\\EssentialCpp\\EssentialDemo\\EssentialDemo\\files\\in.txt");// �����þ���·������Ϊvs��debug��·����ִ��·��������ͬ��
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


// ��ϰ3.1 ��ȡ�ı��������ʴ���mapΪkey��valueΪ���ʳ��ֵĴ����������ų��嵥set��ȥ��a,an,or,the,and,but֮��ģ�����map֮ǰ��ȷ�ϵ��ʲ����ų��嵥�С�
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

	// ʾ��2filter_full����
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
	//unique_copy(ivec.begin(), ivec.end(), back_inserter(result_vec));// ���Ƶ�result_vec�У���push_back�ķ�ʽʵ�֡�
	//cout << result_vec[4] << endl;

	/*string in = "files/in.txt";
	string out = "files/out.txt";
	bool status = stream_file(in, out);
	if (status) cout << "success writer into " << out << endl;*/

	// ϰ��3.1
	string in = "E:\\Code\\Cpp\\EssentialCpp\\EssentialDemo\\EssentialDemo\\files\\in.txt";
	string out = "E:\\Code\\Cpp\\EssentialCpp\\EssentialDemo\\EssentialDemo\\files\\out.txt";
	 
	return 0;
}