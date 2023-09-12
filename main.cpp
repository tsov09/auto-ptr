#include <iostream>


template <typename T>
class auto_ptr {
	T* m_ptr;
public:
	auto_ptr() {

	}
	auto_ptr(T* ptr) {
		m_ptr = ptr;
		std::cout << "Constructor" << std::endl;

	}
	auto_ptr(const auto_ptr& obj) {
		std::cout << "Copy constructor" << std::endl;
		m_ptr = obj.m_ptr;
	}
	auto_ptr& operator = (auto_ptr& obj) {
		delete m_ptr;
		m_ptr = obj.m_ptr;
	}
	auto_ptr& operator * () {
		return *m_ptr;
	}
	auto_ptr* operator -> () {
		return m_ptr;
	}
	~auto_ptr() {
		delete m_ptr;
		m_ptr = nullptr;
		std::cout << "Destructor" << std::endl;
	}
};

int main() {

	auto_ptr<int> a1(new int(5));
	auto_ptr<int> a2 = a1;


	return 0;
}