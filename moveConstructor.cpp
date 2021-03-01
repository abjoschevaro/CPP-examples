#include <iostream>
#include <string.h>
using namespace std;

class MyString{
	private:
		char* buffer;
	public:
		MyString(const char* initString){
			cout << "Default constructor: creating new MyString" << endl;
			buffer = nullptr;
			if(initString != nullptr){
				buffer = new char[strlen(initString) + 1];
				strcpy(buffer, initString);
				cout << "buffer position: " << (unsigned int*)buffer << endl;
			}
		}

		//copy constructor
		MyString(const MyString& copySource){
			cout << "Copy constructor: copying from MyString" << endl;
			buffer = nullptr;
			if(copySource.buffer != nullptr){
				buffer = new char[strlen(copySource.buffer) + 1];
				strcpy(buffer, copySource.buffer);
				cout << "buffer position: " << (unsigned int*)buffer << endl;
			}
		}

		//move constructor
		MyString(MyString&& moveSource){
			if(moveSource.buffer != nullptr){
				cout << "Move constructor" << endl;
				buffer = moveSource.buffer;
				moveSource.buffer = nullptr;
			}
		}
		~MyString(){
			cout << "Invoking destructor. Clearing up" << endl;
			delete[] buffer;
		}
		
		int GetLen(){
			return strlen(buffer);
		}

		const char* GetString(){
			return buffer;
		}
		void EditString(){
			buffer[0] = 'h';
		}

};

MyString Copy(MyString& source){
	MyString copyForReturn(source.GetString());
	copyForReturn.EditString();
	return copyForReturn;
}

int main(){	
	MyString saludo("Hola a todos, amigos");
	cout << saludo.GetString() << endl;
	cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,," << endl;
	MyString saludo1(Copy(saludo));
	cout << saludo1.GetString() << endl;
	cout << "+++++++++++++++++++++++++++++" << endl;
	MyString saludo2 = Copy(saludo);
	cout << saludo2.GetString() << endl;
	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
	MyString saludo3 = saludo;
	cout << saludo3.GetString() << endl;
	cout << "-----------------------------" << endl;
	cout << "after call 'EditString' member function saludo buffer: ";
	cout << saludo.GetString() << endl;
	cout << "-----------------------------" << endl;
	return 0;
}
