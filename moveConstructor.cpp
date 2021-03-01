#include <iostream>
#include <string.h>
using namespace std;

class MyString{
	//private:
	public:
		char* buffer;
	//public:
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
	//MyString copyForReturn(source.GetString());
	MyString copyForReturn(source);
	copyForReturn.EditString();
	return copyForReturn;
}

void UseMyString(MyString buffer){
	cout << "String buffer in MyString is: " << buffer.GetLen();
	cout << " characters long" << endl;

	cout << "buffer contains: " << buffer.GetString() << endl;
};

int main(){	
	MyString saludo("Hola a todos, amigos");
	cout << saludo.GetString() << endl;
	//cout << "-----------------------------" << endl;
	//Copy(saludo);
	//const MyString& meet = Copy(saludo);
	//cout << "-----------------------------" << endl;
	//MyString saludoAgain(meet);
	//cout << "++++++++++++++++++++++++++++++++++" << endl;
	//Copy(saludo);
	cout << ",,,,,,,,,,,,,,,,,,,,,,,,,,,," << endl;
	MyString saludoAgain(Copy(saludo));
	cout << saludoAgain.GetString() << endl;
	cout << "+++++++++++++++++++++++++++++" << endl;
	MyString saludo1 = Copy(saludo);
	cout << saludo1.GetString() << endl;
	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
	MyString saludoTwice = saludo;
	cout << saludoTwice.GetString() << endl;
	cout << "-----------------------------" << endl;
	cout << "saludo buffer: ";
	cout << saludo.GetString() << endl;
	return 0;
}
