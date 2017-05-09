#include<iostream>
#include <fstream>  
#include<string>
#include<map>
#include<vector>
#include<memory>
using namespace std;

using std::tr1::shared_ptr;

template<class T>
class Node
{
public:
	T value;
	shared_ptr <Node<T>> next;
	Node() : next(NULL) {}
};
template<class T>
class Stack
{
private:
	shared_ptr <Node<T>> head;
	shared_ptr <Node<T>> temp;
public:
	Stack();//StackĬ�Ϲ��캯��
	Stack(const Stack&) = delete;
	Stack& operator=(const Stack&) = delete;
	void push(T elem);//��ջ
	bool pop(T& cell);//��ջ
	void printAll();
};
template<class T>
Stack<T>::Stack()
{
	head = NULL;
	temp = NULL;
}
template<class T>
void Stack<T>::push(T elem)
{
	shared_ptr <Node<T>> p;
	p = make_shared<Node<T>>();
	p->value = elem;//����һ���µ�ָ��ָ��Ҫ����ջ��ֵ�����ʻ���list��ÿ�μ��붼��ѭ����ָ��ָ��listĩβ���ٰ����ָ��ָ���µ�ָ��p
	temp = head;
	if (head == NULL) {
		head = p;
	}
	else {
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = p;
	}

}
template<class T>
bool Stack<T>::pop(T& cell)
{
	if (head == NULL) { return false; }
	if (head->next == NULL) {   //��ջֻ��һ��Ԫ��ʱ������һ����Ԫ�ظ���cell��ɾ��headָ��
		cell = temp->value;
		head = NULL;
	}
	else {    //ջ�в�ֹһ��Ԫ��ʱ����ѭ����ָ��ָ��list�����һ��Ԫ�أ���ȡ��ֵ�����ϸ�Ԫ�ص�next��Ϊ��ָ��
		int n = 0;
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
			n++;
		}
		cell = temp->value;
		temp = head;
		for (int i = 0; i < n - 1; i++) {
			temp = temp->next;
		}
		temp->next = NULL;
		return true;
	}
}
template<class T>
void Stack<T>::printAll() //�����б����ÿ��ֵ
{
	temp = head;
	while (temp != NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
bool issuffix(string s1, string s2) {
	int a = s1.length();
	int b = s2.length();
	if (a > b) { return 0; }
	else {
		int count = 0;
		for (int i = 0; i < a; i++) {
			if (s1[i] == s2[b - a + i]) { count++; }
		}
		if (count == a) { return 1; }
		else { return 0; }
	}
}

void suffix1() {
	cout << "please input the number of suffix:";
	int a;
	cin >> a;
	ifstream infile("EnglishWords.txt");
	string  str;
	map<string, int>wordMap;
	while (getline(infile, str)) {
		if (str.length() > a) {
			string s = str.substr(str.length() - a, a);
			wordMap[s] = 0;
		}

	}
	infile.close();
	infile.clear();
	ifstream ifile("EnglishWords.txt");
	string  stri;
	while (getline(ifile, stri)) {
		if (stri.length() > a) {
			string s = stri.substr(stri.length() - a, a);
			wordMap[s]++;
		}

	}
	map<string, int>::iterator iter = wordMap.begin();
	for (int i = 0; i < 10; i++) {
		string word = iter->first;
		int num = iter->second;
		for (map<string, int>::iterator iter = wordMap.begin(); iter != wordMap.end(); iter++) {
			if (iter->second > num) { num = iter->second; word = iter->first; }
		}
		cout << word << " " << num << endl;
		wordMap[word] = 0;
	}
	

}
void suffix2() {
	int count = 0;
	Stack<string> a1;
	string a2;
	string suff;
	cout << "please input the suffix:" ;
	cin >> suff;
	ifstream infile("EnglishWords.txt");
	string  str;
	while (getline(infile, str)) {
		if (issuffix(suff, str) == 1) {
			count++;
			a1.push(str);

		}
	}
	cout << "The amount of the words with this suffix is:" << count << endl;
	
	while(a1.pop(a2) != false) {
		cout << a2 << endl;
		a1.pop(a2);
		cout << a2 << endl;
	}
}
int main() {
	cout << "please choose the function:1 for inputting a number,2 for inputting a whole suffix.";
	int func;
	cin >> func;
	if (func == 1) {
		suffix1();
	}
	else if (func == 2) {
		suffix2();
	}
	cin.get();
	cin.get();
	return 0;

}