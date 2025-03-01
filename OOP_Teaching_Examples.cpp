#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
using namespace std;

namespace others
{

	namespace Lec1
	{
		namespace Ex1
		{
			int main()
			{
				cout << "Size of short: " << sizeof(short) << endl;
				cout << "Size of int: " << sizeof(int) << endl;
				cout << "Size of long: " << sizeof(long) << endl;
				cout << "Size of long long: " << sizeof(long long) << endl;
				cout << "Size of double: " << sizeof(double) << endl;
				cout << "Size of long double: " << sizeof(long double) << endl;
				cout << "Size of float: " << sizeof(float) << endl;
				return 0;
			}
		} // namespace Ex1
		namespace Ex2
		{
			int main()
			{
				int sec = 0;
				cout << "Enter seconds: ";
				cin >> sec;
				cout << "Minuets: " << sec / 60;
				cout << ", Seconds: " << sec % 60;
				return 0;
			}
		} // namespace Ex2

		namespace Ex3
		{
			int main()
			{
				int a = 2;
				cout << a << "\n";
				a++;
				cout << a << "\n";
				return 0;
			}
		} // namespace Ex3

	} // namespace Lec1

	namespace Lec3
	{
		namespace Ex1
		{
			void resetValues(int a, int b)
			{
				a = 0;
				b = 0;
			}

			void updateNumbers(const int& m, int& n)
			{
				resetValues(m, n);
			}

			int main()
			{
				int x = 5, y = 5;
				updateNumbers(x, y);
				cout << x << " " << y;
				return 0;
			}
		} // namespace Ex4

		namespace Ex2
		{
			void displaySequence(int& from, int& to)
			{
				while (from <= to) cout << from++ << endl;
			}

			int main()
			{
				cout << "Enter two numbers: ";
				int num1, num2;
				cin >> num1 >> num2;
				cout << "The sequence:" << endl;
				displaySequence(num1, num2);
				cout << "That was the sequence from "
					<< num1 << " to " << num2 << endl;
				return 0;
			}
		} // namespace Ex5

		namespace Ex3
		{
			int max(int& num1, int& num2)
			{
				int result;
				if (num1 > num2)
					result = num1;
				else
					result = num2;
				return result;
			}

			int main()
			{
				int i = 5;
				int j = 2;
				int k = max(i, j);
				return 0;
			}
		} // namespace Ex6

		namespace Ex4
		{
			void t1();
			void t2();

			int main()
			{
				t1();
				t2();
				return 0;
			}
			int y;
			void t1()
			{
				int x = 0;
				cout << "In t1: x is " << ++x << ", y is " << ++y << endl;
			}
			void t2()
			{
				int x = 0;
				cout << "In t2: x is " << ++x << ", y is " << ++y << endl;
			}
		} // namespace Ex4

		namespace Ex5
		{
			void t1();
			void t2();

			int main()
			{
				t1();
				t1();
				t2();
				return 0;
			}
			void t1()
			{
				int x = 0;
				static int y;
				y = 0;
				cout << "In t1: x is " << ++x << ", y is " << ++y << endl;
			}
			void t2()
			{
				int x = 0;
				static int y;
				cout << "In t2: x is " << ++x << ", y is " << ++y << endl;
			}
		} // namespace Ex4

		namespace Ex6
		{
			void printArray(int arr[], int arraySize); // Prototype

			int main()
			{
				int numbers[2];
				numbers[0] = -5; numbers[1] = 8;
				printArray(numbers, 2);
				return 0;
			}

			void printArray(int arr[], int arraySize)
			{
				cout << arr;
				for (int i = 0; i < arraySize; i++)
					cout << arr[i] << " ";
			}
		} // namespace Ex6

	} // namespace Lec3

	namespace Lec4
	{
		namespace Ex1
		{
			void p(/*const*/ int arr[], int arraySize)
			{
				for (int i = 0; i < arraySize; i++)
					arr[i]++;
			}
			int main()
			{
				int numbers[] = { 1, 4, 3, 6, 8 };
				p(numbers, 5);
				return 0;
			}
		} // namespace Ex1

		namespace Ex2
		{
			void reverse(const int inArr[], int outArr[], int size)
			{
				for (int i = 0, j = size - 1; i < size; i++, j--)
					outArr[j] = inArr[i];
			}
			int main()
			{
				int a[5] = { 1, 2, 3, 4, 5 };
				int b[5];
				reverse(a, b, 5);
				return 0;
			}
		} // namespace Ex2

		namespace Ex3
		{
			void m(int num, int arr[], int size)
			{
				num = 1001;
				arr[0] = 5555;
			}

			int main()
			{
				int x = 1;
				int y[] = { 2,3 };

				m(x, y, 2);

				cout << "x is " << x << endl;
				cout << "y[0] is " << y[0] << endl;
				cout << "y[1] is " << y[1] << endl;

				return 0;
			}
		} // namespace Ex3

	} // namespace Lec4

	namespace Lec5
	{
		//Global/Local/Member Scopes
		namespace Ex0
		{
			int x; // Global variable

			class Test
			{
			public:
				int x = 10, y = 10; // Data fields

				void print()
				{
					int x = 20; // Local variable
					cout << "Local x is " << x << endl;
					cout << "Member x is " << Test::x << endl;
					cout << "Global x is " << Ex0::x << endl;
					cout << "Member y is " << y << endl;
				}
			};

			int main()
			{
				Test test;
				test.print();

				return 0;
			}

		} // namespace Ex0

		namespace comp_proc
		{
#include <iostream>
			using namespace std;

			// Bank account data
			double balance = 0.0;

			void deposit(double amount) {
				balance += amount;
				cout << "New Balance: $" << balance << endl;
			}

			void withdraw(double amount) {
				if (amount > balance)
					cout << "Insufficient funds!" << endl;
				else {
					balance -= amount;
					cout << "New Balance: $" << balance << endl;
				}
			}

			int main() {
				deposit(100);
				withdraw(30);
				withdraw(80);
			}

		}

		namespace comp_oop
		{
#include <iostream>
			using namespace std;

			class BankAccount {
			private:
				double balance;

			public:
				BankAccount(double initVal) { balance = initVal; }

				void deposit(double amount) {
					balance += amount;
					cout << "New Balance: $" << balance << endl;
				}

				void withdraw(double amount) {
					if (amount > balance)
						cout << "Insufficient funds!" << endl;
					else {
						balance -= amount;
						cout << "New Balance: $" << balance << endl;
					}
				}
			};

			int main() {
				BankAccount myAccount(50);
				myAccount.deposit(100);
				myAccount.withdraw(30);
				myAccount.withdraw(80);
			}
		}

		namespace Ex1
		{
			class Circle1
			{
			private:
				double radius = 1;
				double area = 3.14;
			public:
				void setRadius(double r) { radius = r; }
				void calcArea() { area = 3.14 * radius * radius; }
				double getRadius() { return radius; }
				double getArea() { return area; }
			};

			class Circle2
			{
			private:
				double radius = 1;
				double area = 3.14;
			public:
				void setRadius(double r)
				{
					radius = r;
					area = 3.14 * radius * radius;
				}
				double getRadius() { return radius; }
				double getArea() { return area; }
			};

			class Circle3
			{
			private:
				double radius = 1;

			public:
				void setRadius(double r) { radius = r; }
				double getRadius() { return radius; }
				double getArea() { return 3.14 * radius * radius; }
			};

			int main()
			{
				Circle1 c1;
				c1.setRadius(10);
				c1.calcArea();
				cout << "Area: " << c1.getArea() << endl;

				c1.setRadius(5);
				c1.calcArea();
				cout << "Area: " << c1.getArea() << endl;

				return 0;
			}

		} // namespace Ex1

		namespace Ex2 // Abstraction
		{
			int main()
			{
				string s1 = "CIE202", s2 = "CIE 202";
				bool check = s1 == s2; // abstraction example: == is a function
				return 0;
			}
		} // namespace Ex2

		namespace Ex3
		{
			class TV
			{
			private:
				int channel = 1, volumeLevel = 1;
				bool on = false;

			public:
				// Getters (Accessors):
				// returnType getPropertyName()
				int getChannel()
				{
					return channel;
				}
				bool isOn()
				{
					return on;
				}

				// Setters (Mutators):
				// void setPropertyName(dataType value)
				void setChannel(int newChannel)
				{
					if (on && newChannel >= 1 && newChannel <= 120)
						channel = newChannel;
				}
				void TurnOn()
				{
					on = true;
				}
				void TurnOff()
				{
					on = false;
				}
			};

		} // namespace Ex3

		namespace Ex4
		{
			class Grade
			{
			private:
				int static minGrade;
				int grade;

			public:
				void setGrade(int v);
				double getGrade() const;
				static void setMinGrade(int v);
				bool isPassing() const;
				string getPF() const;
			};

			int Grade::minGrade = 60;

			void Grade::setGrade(int v) { grade = v; }
			double Grade::getGrade() const { return grade; }

			void Grade::setMinGrade(int v)
			{
				minGrade = v;
			}

			bool Grade::isPassing() const
			{
				return grade >= minGrade;
			}

			string Grade::getPF() const
			{
				if (isPassing()) return "P";
				else return "F";
			}

			int main()
			{
				Grade s[10];
				for (int i = 0; i < 10; i++)
					s[i].setGrade(10 * i + 1);

				for (int i = 0; i < 10; i++)
					cout << i << ": " << s[i].getPF() << endl;

				cout << string(4, '-') << endl;

				Grade::setMinGrade(20);
				for (int i = 0; i < 10; i++)
					cout << i << ": " << s[i].getPF() << endl;

				return 0;
			}

		}//Ex4
	} // namespace Lec5

	namespace Lec6
	{
		//All Static Class
		namespace Ex0
		{
			class AppConfig
			{
			private:
				AppConfig() = delete;
			public:
				static const int versionMajor;
				static const int versionMinor;
				static const string themeColor;
				static const int MAX_USERS;

				// Static function to display application configuration
				static void displayConfig()
				{
					cout << "Application Version: " << versionMajor
						<< "." << versionMinor << endl;
					cout << "Theme Color: " << themeColor << endl;
					cout << "Maximum Number of Users: "
						<< MAX_USERS << endl;
				}
			};

			// Initialize static members
			const int AppConfig::versionMajor = 1;
			const int AppConfig::versionMinor = 0;
			const string AppConfig::themeColor
				= "DarkBlue";
			const int AppConfig::MAX_USERS = 100;

			int main()
			{
				// Accessing and using static class members
				// without instantiation
				AppConfig::displayConfig();

				return 0;
			}
		} // namespace Ex0

		//Static with Constructor/Destructor
		namespace Ex1
		{
			class Circle
			{
			public:
				Circle(double = 1);
				~Circle();
				double getArea() const { return radius * radius * 3.14; }
				double getRadius() const { return radius; }
				void setRadius(double r) { radius = r; };
				static int getNumOfObjects();

			private:
				double radius;
				static int numOfObjects;
			};

			int Circle::numOfObjects = 0;

			Circle::Circle(double newRadius)
			{
				radius = newRadius;
				numOfObjects++;
			}

			int Circle::getNumOfObjects()
			{
				return numOfObjects;
			}

			Circle::~Circle()
			{
				numOfObjects--;
			}

			int main()
			{
				cout << "Number of circle objects created: "
					<< Circle::getNumOfObjects() << endl;

				Circle circ1;
				cout << "The radius of the circle is "
					<< circ1.getRadius() << endl;
				cout << "Number of circle objects created: "
					<< Circle::getNumOfObjects() << endl;

				Circle circ2(5.0);
				cout << "The radius of the circle is "
					<< circ2.getRadius() << endl;
				cout << "Number of circle objects created: "
					<< circ2.getNumOfObjects() << endl;
				return 0;
			}

		} // Ex1

		//Demo1 for Constructor/Destructor order
		namespace Ex2
		{
			class Demo
			{
			public:
				Demo() // Constructor
				{
					cout << "1. Welcome to the constructor!\n";
				}
				~Demo() // Destructor
				{
					cout << "2. The destructor is running.\n";
				}
			};

			int main()
			{
				Demo demoObject; // Define a demo object;

				cout << "A. This is a demo\n";
				cout << "B. for constructor / destructor.\n";
				return 0;
			}
		} // Ex2

		//Demo2 for Constructor/Destructor order
		namespace Ex3
		{
			class Demo
			{
			public:
				Demo() // Constructor
				{
					cout << "1. Welcome to the constructor!\n";
				}
				~Demo() // Destructor
				{
					cout << "2. The destructor is running.\n";
				}
			};

			void SomeGlobalFunction()
			{
				Demo demoObject;
			}

			int main()
			{
				SomeGlobalFunction();

				cout << "A. This is a demo\n";
				cout << "B. for constructor / destructor.\n";
				return 0;
			}
		} // Ex3

		//Class Example with Constructor/Destructor Static
		namespace Ex4
		{
			class Book
			{
			private:
				string title, author;
				static int bookCount; // Static member

			public:
				// Constructor
				Book(string t, string a);

				// Getters
				string getTitle() const { return title; }
				string getAuthor() const { return author; }

				// Setters
				void setTitle(const string& t) { title = t; }
				void setAuthor(const string& a) { author = a; }

				// Const function to display book details
				void displayDetails() const;

				// Static member function to get the total book count
				static int getTotalBookCount() { return bookCount; }
			};

			// Initialize static member
			int Book::bookCount = 0;

			Book::Book(string t, string a)
			{
				title = t;
				author = a;

				bookCount++;
			}
			inline void Book::displayDetails() const
			{
				cout << title << ", " << author << endl;
			}

			int main()
			{
				Book book1("Age of Science", "Ahmed Zewail");
				Book book2("The Book of Healing", "Ibn Sina");

				book1.displayDetails();
				book2.displayDetails();

				cout << "Total books: " << Book::getTotalBookCount() << endl;

				return 0;
			}
		} // Ex4

		//Intro to Inheritance
		namespace Ex5
		{
			class GeometricObject
			{
			public: string getColor() const { return "red"; };
			};

			class Circle : public GeometricObject
			{
			public: double getRadius() const { return 1; };
			};

			void dispData(const GeometricObject& o)
			{
				cout << o.getColor();
			}

			int main()
			{
				Circle c;
				dispData(c);
				return 0;
			}
		} // namespaceEx5

		//Intro to Class cross communication
		namespace Ex6
		{
			class BankAccount
			{
			private: double balance;

			public:
				BankAccount(double initBal) : balance(initBal) {}

				bool hasSameBalance(const BankAccount& other) const
				{
					return balance == other.balance;
				}
			};

			int main() {
				BankAccount account1(5000.00), account2(3000.00);

				if (account1.hasSameBalance(account2))
					cout << "Same balance." << endl;
				else
					cout << "Different balances." << endl;

				return 0;
			}

		} // namespace Ex6

		//Intro to Class cross communication
		namespace Ex7
		{
			class ClassB;
			class ClassA
			{
			public:	int dataA = 1;
				  //private:	int dataA = 1;
			public:
				bool isEqualToDataB(const ClassB& b);
			};

			class ClassB
			{
			public:
				int dataB = 2;
				bool isEqualToDataA(const ClassA& a)
				{
					return dataB == a.dataA; // Line 2
				}
			};

			bool ClassA::isEqualToDataB(const ClassB& b)
			{
				return dataA == b.dataB; // Line 1
			}
			int main()
			{
				ClassA objA;
				ClassB objB;
				cout << boolalpha << objB.isEqualToDataA(objA) << endl;

				return 0;
			}
		} // namespace Ex7

		//Intro to Association
		namespace Ex8
		{
			class Instructor
			{
			private: string _name = "Default Name";
			public:
				void setName(string newName) { _name = newName; }
				string getName() const { return _name; }
			};

			class Student
			{
			private: Instructor* _instr = nullptr;
			public:
				void setInstr(Instructor& instr) { _instr = &instr; }
				string getInstrName() const
				{
					if (_instr) return _instr->getName();
					return "N/A";
				}
			};
			int main()
			{
				Instructor instr;
				cout << "Instr name: " << instr.getName() << endl;
				cout << string(24, '-') << endl;

				Student st1; st1.setInstr(instr);
				Student st2; st2.setInstr(instr);
				cout << "St 1 instr: " << st1.getInstrName() << endl;
				cout << "St 2 instr: " << st2.getInstrName() << endl;
				cout << string(24, '-') << endl;

				instr.setName("new name");
				cout << "Instr name: " << instr.getName() << endl;
				cout << string(24, '-') << endl;

				cout << "St 1 instr: " << st1.getInstrName() << endl;
				cout << "St 2 instr: " << st2.getInstrName() << endl;
				return 0;
			}
		} // namespace Ex8

		//Passing Objects to Functions
		namespace Ex9
		{
			class Circle
			{
			public:
				Circle(double r = 1) : radius(r) {}

				double getArea() const;
				double getRadius() const;
				void setRadius(double r);

			private:
				double radius;
			};
			void displayCircle(const Circle& c)
			{
				cout << "Radius: "
					<< c.getRadius() << endl;
				cout << "Area: "
					<< c.getArea() << endl;
			}
			void initializeCircle(Circle& c, double r)
			{
				c.setRadius(r);
			}
			int main()
			{
				Circle c(5);
				initializeCircle(c, 10);
				displayCircle(c);
				return 0;
			}
			double Circle::getArea() const { return radius * radius * 3.14159; }
			double Circle::getRadius() const { return radius; }
			void Circle::setRadius(double r) { radius = r; }
		} // namespace Ex9

		//Different constructors
		namespace Ex10
		{
			class Rectangle
			{
			private:
				double width = 1;
				double length = 2;
			public:
				//Rectangle(double w, double h) : length(w), width(h) {}
				Rectangle() : length(width), width(20) {}
				//Rectangle() : length(10), width(length) {}
				//Rectangle() : length(10), width(20) {}
				double getLength() const;
				double getWidth() const;
			};
			double Rectangle::getLength() const { return length; }
			double Rectangle::getWidth() const { return width; }
			void displayRectangle(const Rectangle& r)
			{
				cout << "Length: " << r.getLength() << endl;
				cout << "Width: " << r.getWidth() << endl;
			}
			int main()
			{
				Rectangle r;
				displayRectangle(r);
				return 0;
			}
		} // namespace Ex10

	} // namespace Lec6

	namespace Lec7
	{
		// Aggregation and Composition
		namespace Ex1
		{
			// Aggregation example: Library and Book
			// The Book class represents a book with a title.
			class Book
			{
			private: string title, author;
			public:
				Book(string t = "title", string a = "author")
					: title(t), author(a) {
				}
			};

			class TwoBookPackage
			{
			private: Book& book1, & book2;
			public:
				TwoBookPackage(Book& b1, Book& b2)
					: book1(b1), book2(b2) {
				}
			};

			void testAggregation()
			{
				// Books exist independently of the TwoBookPackage
				Book book1("Age of Science", "Ahmed Zewail");
				Book book2("The Book of Healing", "Ibn Sina");

				TwoBookPackage package(book1, book2);
			}

			// Composition example: Apartment and Room
			class Room
			{
			private: string name;
			public:
				Room(string n = "Room") : name(n) {}
			};

			// The Apartment class represents an apartment, which is composed of Rooms.
			// Rooms cannot logically exist without an apartment, illustrating a strong relationship.
			class TwoRoomApartment
			{
			private:
				Room room1, room2;

			public:
				TwoRoomApartment(string n1, string n2)
				{
					room1 = Room(n1);
					room2 = Room(n2);
				}
			};

			void testComposition()
			{
				TwoRoomApartment apartment(
					"Living Room",
					"Bedroom"
				);
			}

			int main()
			{
				testAggregation();
				testComposition();
				return 0;
			}

		}// namespace Ex1
	} // namespace Lec7

	namespace Lec10
	{
		// printArray
		namespace Ex2
		{
			void printArray(int* list, int size)
			{
				for (int i = 0; i < size; i++)
					cout << list[i] << " ";
			}
			int main()
			{
				int a[] = { 1,2,3 };
				printArray(a, 3);
				return 0;
			}
		} // namespace Ex2

		// reverse
		namespace Ex3
		{
			void reverse(int* list, int size)
			{
				int* left = list;
				int* right = list + size - 1;

				for (; left < right; ++left, --right)
				{
					int temp = *left;
					*left = *right;
					*right = temp;
				}
			}

			int main()
			{
				int myArray[5] =
				{ 1, 2, 3, 4, 5 };

				reverse(myArray, 5);

				// Print the reversed array
				for (int i = 0; i < 5; i++)
					cout << myArray[i] << " ";

				return 0;
			}
		} // namespace Ex3

		// reverse with return
		namespace Ex4
		{
			void reverse_lastLec(int* list, int size)
			{
				int* left = list;
				int* right = list + size - 1;

				for (; left < right; ++left, --right)
				{
					int temp = *left;
					*left = *right;
					*right = temp;
				}
			}

			int* reverse(int* list, int size)
			{
				//int* result = list;
				//int result[size];
				//int result[1000];
				//int* result = new int[size];

				for (int i = 0; i < size; ++i)
					list[i] = list[size - 1 - i];
				return list;
			}

			int main()
			{
				int myArray[5] = { 1, 2, 3, 4, 5 };

				reverse_lastLec(myArray, 5);

				// Print the original array
				cout << "Original array: ";
				for (int i = 0; i < 5; i++)
					cout << myArray[i] << " ";
				cout << endl;

				// Print the reversed array

				return 0;
			}
		} // namespace Ex4

		// repeat dyn array
		namespace Ex5
		{
			int main()
			{
				char continueInput = 'Y';

				while (continueInput == 'Y')
				{
					cout << "Enter the size of the array: ";
					int size;
					cin >> size;
					int* array = new int[size];

					cout << "Enter " << size << " integers:" << endl;
					int sum = 0;
					for (int i = 0; i < size; ++i)
					{
						cin >> array[i];
						sum += array[i];
					}

					cout << "You entered:" << endl;
					for (int i = 0; i < size; ++i)
						cout << array[i] << " ";
					cout << endl;
					cout << "The sum is: " << sum << endl;

					delete[] array;


					// Ask user to repeat or exit
					cout << "Do you want to enter another array? (Y/N): ";
					cin >> continueInput;
				}

				return 0;
			}

		} // namespace Ex5

		// destructor importance
		// copy constructor
		namespace Ex6
		{
			class AudioBuffer
			{
			private:
				float* samples = nullptr; // Array of samples
				int size = 0;
			public:
				const int CAPACITY;
				AudioBuffer(int n = 0) : CAPACITY(n)
				{
					if (n <= 0) return;
					samples = new float[n];
					for (int i = 0; i < n; ++i) samples[i] = 0.0;
				}

				AudioBuffer(const AudioBuffer& other) :
					CAPACITY(other.CAPACITY), size(other.size)
				{
					if (other.CAPACITY <= 0) return;

					this->samples = new float[other.CAPACITY];

					for (int i = 0; i < this->CAPACITY; ++i)
						this->samples[i] = other.samples[i];
				}

				~AudioBuffer()
				{
					delete[] samples;
					samples = nullptr;
				}
				bool addSample(float value)
				{
					if (!samples || size >= CAPACITY) return false;

					samples[size++] = value;
					return true;
				}
			};

			int main()
			{
				int NUM_SAMPLES = 50;
				AudioBuffer buffer(NUM_SAMPLES);

				// Open a file for reading
				ifstream file("samples.txt");

				float sample;

				// Read sample values from the file
				while (file >> sample &&
					buffer.addSample(sample))
				{
				}

				file.close(); // Close the file

				return 0; // Destructor is called
			}

		} // namespace Ex2

		namespace freeExample
		{
			int main()
			{
				return 0;
			}
		} // namespace freeExample

	} // namespace Lec10

	namespace Lec11
	{
		// destructor importance
		// // copy constructor
		namespace Ex1a
		{
			class AudioBuffer
			{
			private:
				float* samples = nullptr; // Array of samples
				int size = 0;
			public:
				const int CAPACITY;
				AudioBuffer(int n = 0) : CAPACITY(n)
				{
					if (n <= 0) return;
					samples = new float[n];
					for (int i = 0; i < n; ++i) samples[i] = 0.0;
				}

				AudioBuffer(const AudioBuffer& other) :
					CAPACITY(other.CAPACITY), size(other.size)
				{
					if (other.CAPACITY <= 0) return;

					this->samples = new float[other.CAPACITY];

					for (int i = 0; i < this->CAPACITY; ++i)
						this->samples[i] = other.samples[i];
				}

				~AudioBuffer()
				{
					delete[] samples;
					samples = nullptr;
				}
				bool addSample(float value)
				{
					if (!samples || size >= CAPACITY) return false;

					samples[size++] = value;
					return true;
				}
			};

			int main()
			{
				int NUM_SAMPLES = 50;
				AudioBuffer buffer(NUM_SAMPLES);

				// Open a file for reading
				ifstream file("samples.txt");

				float sample;

				// Read sample values from the file
				while (file >> sample &&
					buffer.addSample(sample))
				{
				}

				file.close(); // Close the file

				return 0; // Destructor is called
			}
		} // namespace Ex1a

		// const pointer
		namespace Ex1b
		{
			class Circle
			{
			private:
				double radius;
			public:
				Circle(double r) : radius(r) {}
				void setRadius(double r) { radius = r; }
				double getRadius() const { return radius; }
				double getArea() const { return 3.14 * radius * radius; }
			};

			// OK function!
			void displayCircleData(const Circle* const p)
			{
				// p = new Circle(10); // Should not do that
				// p->setRadius(10); // Should not do that

				cout << "Radius: " << p->getRadius() << endl;
				cout << "Area: " << p->getArea() << endl;
			}


			//int main()
			//{
			//	double radius = 5, length = 4;
			//	const double MAX_RADIUS = 100;

			//	double* const ptr1 = &radius;
			//	cout << *ptr1 << endl;
			//	*ptr1 += 5;

			//	ptr1 = &length;
			//	cout << *ptr1 << endl;
			//	*ptr1 += 5;

			//	ptr1 = &MAX_RADIUS;
			//	cout << *ptr1 << endl;

			//	return 0;
			//}
		} // namespace Ex1b

		// Basic inheritance
		namespace Ex1
		{
			class GeometricObject
			{
			public:
				GeometricObject();
				GeometricObject(const string&, bool);
				string getColor() const;
				void setColor(const string&);
				bool isFilled() const;
				void setFilled(bool);
				string toString() const;

			private:
				string color;
				bool filled;
			}; // Must place semicolon here

			GeometricObject::GeometricObject()
				: color("white"), filled(false)
			{
			}

			GeometricObject::GeometricObject(const string& col, bool fil)
			{
				color = col;
				filled = fil;
			}

			string GeometricObject::getColor() const
			{
				return color;
			}

			void GeometricObject::setColor(const string& col)
			{
				color = col;
			}

			bool GeometricObject::isFilled() const
			{
				return filled;
			}

			void GeometricObject::setFilled(bool fil)
			{
				filled = fil;
			}

			string GeometricObject::toString() const
			{
				return "Geometric Object";
			}


			class Circle : public GeometricObject
			{
			public:
				Circle();
				Circle(double);
				Circle(double, const string&, bool);
				double getRadius() const;
				void setRadius(double);
				double getArea() const;
				double getPerimeter() const;
				double getDiameter() const;
				string toString() const;

			private:
				double radius;
			}; // Must place semicolon here

			// Construct a default circle object
			Circle::Circle()
			{
				radius = 1;
			}

			// Construct a circle object with specified radius
			Circle::Circle(double newRadius)
			{
				setRadius(newRadius);
			}

			// Construct a circle object with specified radius,
			//  color and filled values
			Circle::Circle(double newRadius, const string& col, bool fil)
			{



			}

			// Return the radius of this circle
			double Circle::getRadius() const
			{
				return radius;
			}

			// Return the diameter of this circle
			double Circle::getDiameter() const
			{
				return 2 * radius;
			}

			// Set a new radius
			void Circle::setRadius(double newRadius)
			{
				if (newRadius >= 0)
					radius = newRadius;
				else
					radius = 0;
			}
			// Return the area of this circle
			double Circle::getArea() const
			{
				return radius * radius * 3.14159;
			}

			// Return the perimeter of this circle
			double Circle::getPerimeter() const
			{
				return 2 * radius * 3.14159;
			}

			// Redefine the toString function
			string Circle::toString() const
			{
				return "Circle object";
			}
		} // namespace Ex1

		//Chaining 1
		namespace Ex2
		{
			class BaseClass
			{
			public:
				BaseClass() // Constructor
				{
					cout << "BaseClass constructor.\n";
				}
				~BaseClass() // Destructor
				{
					cout << "BaseClass destructor.\n";
				}
			};
			class DerivedClass : public BaseClass
			{
			public:
				DerivedClass() // Constructor
				{
					cout << "DerivedClass constructor.\n";
				}
				~DerivedClass() // Destructor
				{
					cout << "DerivedClass destructor.\n";
				}
			};

			int main()
			{
				cout << "We will now define a DerivedClass object.\n";
				DerivedClass object;
				cout << "The program is now going to end.\n";

				return 0;
			}

		} // namespace

		//Chaining 2
		namespace Ex3
		{
			class BaseClass
			{
			public:
				BaseClass() { cout << "1 "; }
				~BaseClass() { cout << "2 "; }
			};
			class DerivedClass : public BaseClass
			{
			public:
				DerivedClass() { cout << "3 "; }
				~DerivedClass() { cout << "4 "; }
			};
			DerivedClass* someFunc()
			{
				cout << "5 "; DerivedClass* ptr = new DerivedClass;
				cout << "6 "; return ptr;
			}
			int main()
			{
				cout << "7 "; DerivedClass* ptr = someFunc();
				cout << "8 "; delete ptr;
				return 0;
			}
		} // namespace Ex3

		//Accessing base class members 1
		namespace Ex3b
		{
			class BaseClass
			{
			private:
				int privData;
				void privMethod() {}
			protected:
				int protData;
				void protMethod() {}
			public:
				int pubData;
				void pubMethod() {}
			};
			class DerivedClass : public BaseClass
			{
			public:
				void DerivedClassMethod()
				{
					this->protData = 5;
				}
			};
			int	main()
			{
				BaseClass base;
				base.pubData = 10;
				DerivedClass derived;
				derived.pubData = 8;

				return 0;
			}
		} // namespace Ex3b

		// Example of protected members
		namespace Ex4
		{
			class Mover
			{
			protected: int incr, coveredD;
			public:
				Mover() : incr(10), coveredD(0) {}
				void move() { coveredD += incr; }
				int getCoveredDistance() const { return coveredD; }
			};

			class FastRunner : public Mover
			{
			public: FastRunner() { incr = 30; }
			};
			class SlowWalker : public Mover
			{
			public: SlowWalker() { incr = 5; }
			};


			int main()
			{
				FastRunner runner;
				SlowWalker walker;

				runner.move();  // Moves by 30 units
				walker.move();  // Moves by 5 units

				cout << "Runner covered: " << runner.getCoveredDistance() << endl;
				cout << "Walker covered: " << walker.getCoveredDistance() << endl;

				return 0;
			}
		} // namespace Ex4

	} // namespace Lec11

	namespace Lec12
	{
		//Accessing base class members 2
		namespace Ex1
		{
			class Base
			{
			private:
				int bsPvDta;
				void bsPvMthd() {}
			protected:
				int bsPtDta;
				void bsPtMthd() {}
			public:
				int bsPbDta;
				void bsPbMthd() {}
			};
			class Derived : public Base
				//class Derived : protected Base
				//class Derived : private Base
			{
			public:
				void drvPbMthd() { this->bsPtDta = 5; }
			};
			class DerivedDerived : public Derived
			{
			public:
				void drvDrvPbMthd() { this->bsPtDta = 5; }
			};
			int	main()
			{
				Base bs;
				bs.bsPbDta = 10;
				Derived drv;
				drv.drvPbMthd();
				DerivedDerived drvDrv;
				drvDrv.drvPbMthd();

				return 0;
			}
		} // namespace Ex3b

		// Redefinition
		namespace Ex2
		{
			class P
			{
			public: void print() { cout << "P "; }
			};

			class Q :public P {};

			class R :public Q { public: void print() { cout << "R "; } };

			void display(P& p) { p.print(); }

			int main(void)
			{
				P* p = new R;
				p->print();
				return 0;
			}

		} // namespace Ex5

		// Generic Programing
		namespace Ex3
		{
			class GeometricObject
			{
			public:
				string toString()
				{
					return "Geometric Object";
				}
			};
			class Circle : public GeometricObject
			{
			public:
				string toString()
				{
					return "Circle";
				}
			};
			class Rectangle : public GeometricObject
			{
			public:
				string toString()
				{
					return "Rectangle";
				}
			};
			void dispType(GeometricObject* geo)
			{
				cout << geo->toString();
				cout << endl;
			}

			int main()
			{
				GeometricObject geo;
				Circle cir;
				Rectangle rec;

				cout << geo.toString() << endl;
				cout << cir.toString() << endl;
				cout << rec.toString() << endl;

				GeometricObject* base = new GeometricObject;
				dispType(base);

				Circle* derived = new Circle;
				dispType(derived);

				return 0;
			}
		} // namespace Ex6

		// Polymorphism
		namespace Ex4
		{
			class Animal
			{
			public:
				virtual void Speak() { cout << "Noise!\n"; }
				~Animal() {}
			};
			class Dog : public Animal
			{
			public: void Speak() { cout << "Woof!\n"; }
			};
			class Duck : public Animal
			{
			public: void Speak() { cout << "Quack!\n"; }
			};
			class Cat : public Animal
			{
			public: void Speak() { cout << "Meow!\n"; }
			};
			//class Wolf : public Animal
			//{
			//public: void Speak() { cout << "Howl!"; }
			//};

			Animal* createAnimal()
			{
				int choice;
				cout << "Choose an animal: ";
				cin >> choice;
				switch (choice)
				{
				case 1: return new Dog();
				case 2: return new Duck();
				case 3: return new Cat();
					//case 4: return new Wolf();
				default: return nullptr;
				}
			}

			void test1()
			{
				int n;
				cout << "Number of animals: ";
				cin >> n;

				vector<Animal*> animals;

				for (int i = 0; i < n; i++)
					animals.push_back(createAnimal());

				for (Animal* animal : animals)
					if (animal) animal->Speak();

				// Clean up
				for (Animal* animal : animals)
					delete animal;
			}

			void test2()
			{
				Animal* animals[3] =
				{
					new Dog(),
					new Duck(),
					new Cat()
				};

				for (int i = 0; i < 3; i++)
					animals[i]->Speak();
			}
		} // namespace Ex4

		// virtual & override & final
		namespace Ex5
		{
			class Animal
			{
			public: virtual void speak() const { cout << "Noise." << endl; }
			};

			class Dog : public Animal
			{
			public: void speak() const override final { cout << "Woof!" << endl; }
			};

			class Cat : public Animal
			{
				//public: void speak() { cout << "Meow!" << endl; }
			public: void speak() const override { cout << "Meow!" << endl; }
			};

			class Duck : public Animal
			{
				//public: void speaks() const { cout << "Quack!" << endl; }
			public: void speak() const override { cout << "Quack!" << endl; }
			};

			//class BullDog : public  Dog
			//{
			//public: void speak() const override { cout << "WOOF!" << endl; }
			//};

			class Base final
			{
				// Class contents
			};
			//class Derived : public Base { };  // Compile-time error: Base is marked 'final'

			class Base2
			{
			public: virtual void doSomething() final { /*Code*/ }
			};

			class Derived : public Base2
			{
				//void doSomething() { }  // Error: doSomething() is 'final' in Base
			};


			int main()
			{
				Animal* animals[3] =
				{
					new Dog(),
					new Duck(),
					new Cat()
				};

				for (int i = 0; i < 3; i++)
					animals[i]->speak();

				return 0;
			}
		} // namespace

		// virtual & override quiz
		namespace Ex6
		{
			class Base
			{
			public:
				void func() { cout << "Base fn" << endl; }
				virtual void vfunc() { cout << "Base virFn" << endl; }
			};

			class Derived : public Base
			{
			public:
				void func() { cout << "Derived fn" << endl; }
				void vfunc() override { cout << "Derived  virFn" << endl; }
			};

			int main()
			{
				Base* b = new Derived();
				b->func();
				b->vfunc();
				delete b;
				return 0;
			}
		} // namespace Ex6

		// Bad pointer arithmatics
		namespace Ex7
		{
			class Base
			{
			public:
				int baseData;
				Base(int i = 5) : baseData(i) {}
			};

			class Derived : public Base
			{
			public:
				long double extraData;
				Derived(int i = 6, long double d = 7)
					: Base(i), extraData(d) {
				}
			};

			void display(Base arr[], int size)
			{
				for (int i = 0; i < size; i++)
					cout << arr[i].baseData << endl;
			}

			void display(Base* arr[], int size)
			{
				for (int i = 0; i < size; i++)
					cout << arr[i]->baseData << endl;
			}

			//void test1()
			//{
			//	// Array of Derived objects, but pointer is of type Base
			//	Base* arr = new Derived[]
			//	{
			//		Derived(1, 1.5),
			//		Derived(2, 2.5),
			//		Derived(3, 3.5)
			//	};
			//	display(arr, 3);
			//}

			//void test2()
			//{
			//	// Array of Derived objects, but pointer is of type Base
			//	Base** arr = new Base * []
			//		{
			//			new Derived(1, 1.5),
			//				new Derived(2, 2.5),
			//				new Derived(3, 3.5)
			//		};
			//	display(arr, 3);
			//}
		} // namespace Ex7

		// Bad pointer arithmatics
		namespace Ex8
		{
			class Base
			{
			public:
				int baseData;
				Base(int b = 0) : baseData(b) {}
				virtual void show() { std::cout << "Base: " << baseData << std::endl; }
				virtual ~Base() {}
			};

			class Derived1 : public Base
			{
			public:
				double derivedData1;
				Derived1(int b = 0, double d1 = 0.0) : Base(b), derivedData1(d1) {}
				void show() override { std::cout << "Derived1: " << baseData << ", " << derivedData1 << std::endl; }
			};

			class Derived2 : public Base
			{
			public:
				double derivedData1, derivedData2;
				Derived2(int b = 0, double d1 = 0.0, double d2 = 0.0) : Base(b), derivedData1(d1), derivedData2(d2) {}
				void show() override { std::cout << "Derived2: " << baseData << ", " << derivedData1 << ", " << derivedData2 << std::endl; }
			};

			void test()
			{
				Base* objects[3]; // Array of pointers to Base objects
				objects[0] = new Derived1(1, 1.1);
				objects[1] = new Derived2(2, 2.2, 2.3);
				objects[2] = new Derived1(3, 3.3);

				for (int i = 0; i < 3; ++i) {
					objects[i]->show();
				}

				//// Attempting to use pointer arithmetic (incorrect and dangerous)
				//Base* ptr = objects[0];
				//for (int i = 0; i < 3; ++i) {
				//	(ptr + i)->show(); // This is incorrect: ptr + i does not account for the actual sizes of the objects
				//}

				// Cleanup
				for (int i = 0; i < 3; ++i) {
					delete objects[i];
				}
			}
		} // namespace Ex8

		namespace Ex9
		{
			class GeometricObject
			{
			public:
				virtual double getArea() const = 0;
				virtual ~GeometricObject() {}
			};

			class Circle : public GeometricObject
			{
			private: double radius;
			public:
				virtual double getArea() const override
				{
					return radius * radius * 3.14;
				}
				Circle(double r = 1) : radius(r) {}
			};

			class Rectangle : public GeometricObject
			{
			private: double length, width;
			public:
				virtual double getArea() const override
				{
					return width * length;
				}
				Rectangle(double l = 1, double w = 1)
					: width(w), length(l) {
				}
			};

			void displayArea(GeometricObject* g[], int size)
			{
				for (int i = 0; i < size; i++)
					cout << "Area: " << g[i]->getArea() << endl;
			}

			void test()
			{
				GeometricObject* arr[] =
				{
					new Rectangle(3,4),
					new Rectangle(5,6),
					new Circle(5),
					new Circle(9)
				};

				displayArea(arr, 4);
			}
		} // namespace Ex9
	} // namespace L12

	namespace Lec13
	{
		// Fraction Op overloading
		namespace Ex1
		{
			class Fraction
			{
			public:
				Fraction(int num, int denom);
				Fraction(int num);
				Fraction(const Fraction& other);
				Fraction& operator=(const Fraction& other);
				Fraction& operator=(const int& other);
				Fraction operator+(const Fraction& other) const;
				Fraction operator+(const int& other) const;
				friend Fraction operator+(const int& lhs, const Fraction& rhs);
				friend ostream& operator<<(ostream& cout, const Fraction& rhs);

				double convertToDecimal() const
				{
					return double(numerator) / denominator;
				}

				operator double() const { return (double)numerator / denominator; }

			private:
				int numerator = 0;
				int denominator = 1;
			};

			Fraction::Fraction(int num, int denom)
				: numerator(num), denominator(denom) {
			}

			Fraction::Fraction(int num) : Fraction(num, 1) {}

			Fraction::Fraction(const Fraction& other)
			{
				this->numerator = other.numerator;
				this->denominator = other.denominator;
			}

			Fraction& Fraction::operator=(const Fraction& other)
			{
				if (this != &other)
				{
					this->numerator = other.numerator;
					this->denominator = other.denominator;
				}
				return *this;
			}

			Fraction& Fraction::operator=(const int& other)
			{
				numerator = other;
				denominator = 1;
				return *this;
			}

			Fraction Fraction::operator+(const Fraction& other) const
			{
				int newNumerator = numerator * other.denominator
					+ other.numerator * denominator;
				int newDenominator = denominator * other.denominator;

				return Fraction(newNumerator, newDenominator);
			}

			Fraction Fraction::operator+(const int& other) const
			{
				int newNumerator = numerator
					+ other * denominator;
				int newDenominator = denominator;

				return Fraction(newNumerator, newDenominator);
			}

			Fraction operator+(const int& lhs, const Fraction& rhs)
			{
				int newNumerator = lhs * rhs.denominator
					+ rhs.numerator;
				int newDenominator = rhs.denominator;

				return Fraction(newNumerator, newDenominator);
			}

			ostream& operator<<(ostream& cout, const Fraction& rhs)
			{
				cout << rhs.numerator << " / " << rhs.denominator;
				return cout;
			}

			void displayFraction(const Fraction& f)
			{
				cout << f << endl;
			}

			int test()
			{
				Fraction f1(1, 2);
				cout << f1 << endl;

				Fraction f2(2, 3);
				cout << f2 << endl;

				Fraction f3(3, 4);
				cout << f3 << endl;

				f1 = f2 = f3;
				cout << f1 << endl;

				f1 = f2;
				cout << f1 << endl;

				f1 = 1;
				cout << f1 << endl;

				Fraction f4 = f2 + f3;
				cout << f4 << endl;

				Fraction f5 = f2 + 5;
				cout << f5 << endl;

				Fraction f6 = 10 + f2;
				cout << (double)f6 << endl;
				cout << f6 << endl;

				double d = f6;
				cout << d << endl;

				displayFraction(f6);
				displayFraction(2);

				return 0;
			}
		} // namespace Ex1

		// AudioBuffer with Op= overloading
		namespace Ex2
		{
			class AudioBuffer
			{
			private:
				float* samples = nullptr; // Array of samples
				int size = 0;
			public:
				int CAPACITY;
				AudioBuffer(int n = 0) : CAPACITY(n)
				{
					if (n <= 0) return;
					samples = new float[n];
					for (int i = 0; i < n; ++i) samples[i] = 0.0;
				}

				AudioBuffer(const AudioBuffer& other) :
					CAPACITY(other.CAPACITY), size(other.size)
				{
					if (other.CAPACITY <= 0) return;
					samples = new float[other.CAPACITY];
					for (int i = 0; i < CAPACITY; ++i) samples[i] = other.samples[i];
				}

				AudioBuffer& operator=(const AudioBuffer& other) // = Operator
				{
					if (other.CAPACITY <= 0 || this == &other) return *this; // Check for self-assignment
					CAPACITY = other.CAPACITY;
					size = other.size;

					if (samples) delete[] samples; // Free old resources if needed
					samples = new float[other.CAPACITY];
					for (int i = 0; i < CAPACITY; ++i) samples[i] = other.samples[i];

					return *this; // Return a reference to the current object
				}

				~AudioBuffer()
				{
					delete[] samples;
					samples = nullptr;
				}
				bool addSample(float value)
				{
					if (!samples || size >= CAPACITY) return false;

					samples[size++] = value;
					return true;
				}
			};

			int main()
			{
				int NUM_SAMPLES = 50;
				AudioBuffer buffer1(NUM_SAMPLES);
				AudioBuffer buffer2 = buffer1;
				buffer2 = buffer1;

				// Open a file for reading
				ifstream file("samples.txt");

				float sample;

				// Read sample values from the file
				while (file >> sample &&
					buffer1.addSample(sample))
				{
				}

				file.close(); // Close the file

				return 0; // Destructor is called
			}
		} // namespace Ex2

		namespace Q1
		{
			class Test
			{
			public:
				int* data = nullptr;
				int size;
				void test(const Test& rhs)
				{
					{
						if (this == &rhs) return;
						delete[] data;
						size = rhs.size;
						data = new int[size];
						for (int i = 0; i < size; i++)
							data[i] = rhs.data[i];
					}

					{
						int* temp = new int[size];
						for (int i = 0; i < size; i++)
							temp[i] = rhs.data[i];
						delete[] data;
						data = temp;
					}

					{
						if (this == &rhs) return;
						int* temp = new int[size];
						if (!temp) return;
						for (int i = 0; i < size; i++)
							temp[i] = rhs.data[i];
						delete[] data;
						data = temp;
					}
				}
			};
		} // namespace Q1

		// Exception Handling
		namespace Ex4
		{
			class Dummy
			{
			public:
				Dummy() { cout << "Dummy created" << endl; }
				~Dummy() { cout << "Dummy destroyed" << endl; }
			};

			int* readDataFile(const string& flName, int size)
			{
				ifstream file(flName);
				int* data = new int[size];

				if (!file)
				{
					throw string("File not found: " + flName);
				}

				for (int i = 0; i < size; i++)
					file >> data[i];

				return data;
			}

			double calcAvg(const string& flName, int N)
			{
				int* data = readDataFile("counts.txt", N);
				double sum = 0.0;
				for (int i = 0; i < N; i++)
					sum += data[i];
				return sum / N;
			}

			int test()
			{
				try
				{
					int size = 10;
					double average = calcAvg("counts.txt", size);
					cout << "Average: " << average << endl;
				}
				catch (const string& errorMessage)
				{
					cout << "Error: " << errorMessage << endl;
				}

				return 0;
			}

			double calcAvg(const int* data, const int size)
			{
				double sum = 0.0;
				for (int i = 0; i < size; i++)
					sum += data[i];
				return sum / size;
			}

			int test1()
			{
				try
				{
					int size = 10;
					int* data = readDataFile("counts.txt", size);
					double average = calcAvg(data, size);
					cout << "Average: " << average << endl;
				}
				catch (const string& errorMessage)
				{
					cout << "Error: " << errorMessage << endl;
				}

				return 0;
			}

		} // namespace Ex3

		// Exception Handling
		namespace Ex5
		{
			int F1(), F2(), F3();

			void test()
			{
				try
				{
					cout << F1() << endl;
				}
				catch (int e)
				{
					cout << "Exception: " << e << endl;
				}
				catch (string e)
				{
					cout << "Exception: " << e << endl;
				}
			}

			int F1()
			{
				F2();
				return 1;
			}

			int F2()
			{
				F3();
				return 2;
			}

			int F3()
			{
				throw string("Error in F3()");
				return 3;
			}
		} // namespace Ex5

		// Exception Handling
		namespace Ex6
		{
			int F1(), F2(), F3();
			void test()
			{
				try
				{
					cout << F1() << endl;
				}
				catch (int e)
				{
					cout << "Exception: " << e << endl;
				}
				catch (string e)
				{
					cout << "Exception: " << e << endl;
				}
			}
			int F1()
			{
				try
				{
					F2();
				}
				catch (string e)
				{
					cout << "Exception: " << e << endl;
					throw string("Error in F1()");
				}
				return 1;
			}
			int F2()
			{
				try
				{
					F3();
				}
				catch (string e)
				{
					cout << "Exception: " << e << endl;
					throw;
				}
				return 2;
			}

			int F3()
			{
				throw string("Error in F3()");
				return 3;
			}
		} // namespace Ex6

		// Parent Copy Constructor
		namespace Ex7
		{
			class B
			{
			public:
				B() { cout << "1. Base constructor" << endl; }
				B(const B&) { cout << "2. Base copy constructor" << endl; }
			};

			class D : public B
			{
			public:
				D() { cout << "3. Derived constructor" << endl; }
				//D(const D& d) { cout << "4. Derived copy constructor" << endl; }
				//D(const D& d): B(d) { cout << "4. Derived copy constructor" << endl; }
			};

			int main()
			{
				D d;
				cout << endl;
				cout << endl;
				cout << endl;
				D d2(d);
				return 0;
			}
		} // namespace Ex7

	} // namespace Lec13

	namespace Lec13_
	{
		// Deleting this
		namespace Ex2
		{
			void doSomeOtherWorkThatNeedsBigAmuontOfMemory()
			{
				int dummyArray[5000]; // This could potentially overwrite the previous array's memory
			}

			class MyClass
			{
			public:
				int data = 10;
				void dangerousMethod()
				{
					doSomeOtherWorkThatNeedsBigAmuontOfMemory();
					delete this;
					doSomeOtherWorkThatNeedsBigAmuontOfMemory();
				}

				int anotherMethod()
				{
					doSomeOtherWorkThatNeedsBigAmuontOfMemory();
					cout << "This is unsafe if called after dangerousMethod!" << endl;
					doSomeOtherWorkThatNeedsBigAmuontOfMemory();
					return data;
				}
			};

			int main()
			{
				MyClass* myObject = new MyClass;
				myObject->dangerousMethod();
				cout << myObject->anotherMethod() << endl;

				delete myObject;

				MyClass myObject2;
				myObject2.dangerousMethod();
				cout << myObject2.anotherMethod() << endl;

				return 0;
			}
		} // namespace Ex2

		namespace freeExPrep
		{
			class Fraction
			{
			public:
				Fraction(int num, int denom)
					: numerator(num), denominator(denom)
				{
				}

				Fraction& operator=(const Fraction& rhs)
				{
					numerator = rhs.numerator;
					denominator = rhs.denominator;
					return *this;
				}

				void displayFraction(Fraction f)
				{
					cout << f.numerator << " / " << f.denominator << endl;
				}

			private:
				int numerator = 0;
				int denominator = 1;
			};

			int main()
			{
				Fraction f1(1, 3);
				Fraction f2(2, 5);

				return 0;
			}
		}

		// Fraction
		namespace freeEx
		{
			class Fraction
			{
			public:
				Fraction(int num, int denom)
					: numerator(num), denominator(denom)
				{
				}

				Fraction(int num) : Fraction(num, 1)
				{
				}

				Fraction& operator=(const Fraction& rhs)
				{
					numerator = rhs.numerator;
					denominator = rhs.denominator;
					return *this;
				}

				Fraction operator+(const Fraction& rhs)
				{
					int newNumerator = this->numerator * rhs.denominator
						+ this->denominator * rhs.numerator;
					int newDinomenator = this->denominator * rhs.denominator;

					return Fraction(newNumerator, newDinomenator);
				}

				Fraction operator+(const int& rhs)
				{
					int newNumerator = this->numerator
						+ this->denominator * rhs;
					int newDinomenator = this->denominator;

					return Fraction(newNumerator, newDinomenator);
				}
				Fraction operator*(const int& rhs)
				{
					int newNumerator = this->numerator
						+ this->denominator * rhs;
					int newDinomenator = this->denominator;

					return Fraction(newNumerator, newDinomenator);
				}

				operator double() const
				{
					return (double)numerator / denominator;
				}

				friend Fraction operator+(const int& lhs, const Fraction& rhs);
				friend ostream& operator<<(ostream& cout, const Fraction& rhs);

			private:
				int numerator = 0;
				int denominator = 1;
			};

			void displayFraction(const Fraction& f)
			{
				cout << f << endl;
			}

			Fraction operator+(const int& lhs, const Fraction& rhs)
			{
				int newNumerator = lhs * rhs.denominator
					+ rhs.numerator;
				int newDinomenator = rhs.denominator;

				return Fraction(newNumerator, newDinomenator);
			}

			ostream& operator<<(ostream& cout, const Fraction& rhs)
			{
				cout << rhs.numerator << " / " << rhs.denominator;
				return cout;
			}

			int main()
			{
				Fraction f1(1, 3);
				Fraction f2(2, 5);

				Fraction f3 = f1;
				f3 = f1 + f2;
				f1 = f1 + 7;
				f1 = 5 + f2;

				displayFraction(f1);
				displayFraction((Fraction)5);

				cout << 3 * f1;


				return 0;
			}
		}
	} // namespace Le13

	namespace Lec14
	{
		// Ex1 - Multiple Inheritance
		namespace Ex1
		{
			class Person
			{
			protected:
				string name;
			public:
				Person(const string& name) : name(name) {}
				virtual ~Person() = default;

				void setName(const string& newName) { name = newName; }
				string getName() const { return name; }
			};

			class Employee
			{
			protected:
				int id;
			public:
				Employee(int id) : id(id) {}
				virtual ~Employee() = default;

				void setId(int newId) { id = newId; }
				int getId() const { return id; }
			};

			class Manager : public Person, public Employee
			{
			private:
				string department;
			public:
				Manager(const string& name, int id, const string& dept)
					: Person(name), Employee(id), department(dept) {
				}

				void setDepartment(const string& newDept) { department = newDept; }
				string getDepartment() const { return department; }
			};

			int main()
			{
				return 0;
			}
		} // namespace Ex1

		// Casting
		namespace Ex2
		{
			class GeometricObject
			{
			public:
				virtual double getArea() const = 0;
				virtual double getPerimeter() const = 0;
			};

			class Circle : public GeometricObject
			{
			private:
				double radius = 1;
			public:
				virtual double getArea() const override
				{
					return radius * radius * 3.14;
				}
				virtual double getPerimeter() const override
				{
					return 2 * 3.14 * radius;
				}
				Circle(double radius) : radius(radius) {}
				double getRadius() const { return radius; }
				double getDiameter() const { return 2 * radius; }
			};

			class Rectangle : public GeometricObject
			{
			private:
				double length = 1;
				double width = 1;
			public:
				virtual double getArea() const override
				{
					return width * length;
				}
				virtual double getPerimeter() const override
				{
					return 2 * (width + length);
				}
				Rectangle(double length, double width)
					: width(width), length(length)
				{
				}
				double getLength() const { return length; }
				double getWidth() const { return width; }
			};

			void displayGeometricObject(const GeometricObject* g)
			{
				const Circle* ptrC = dynamic_cast<const Circle*>(g);
				const Rectangle* ptrR = dynamic_cast<const Rectangle*>(g);

				if (ptrC)
				{
					cout << "The radius is " << ptrC->getRadius() << endl;
					cout << "The diameter is " << ptrC->getDiameter() << endl;
				}
				if (ptrR != nullptr)
				{
					cout << "The width is " << ptrR->getLength() << endl;
					cout << "The height is " << ptrR->getWidth() << endl;
				}
				if (g != NULL)
				{
					cout << "The area is " << g->getArea() << endl;
					cout << "The perimeter is " << g->getPerimeter() << endl;
				}

			}

			void test()
			{
				vector<GeometricObject*> geometricObjectVector =
				{
					new Rectangle(3,4),
					new Rectangle(6,8),
					new Circle(5),
					new Circle(9)
				};

				for (GeometricObject* geometricObject : geometricObjectVector)
				{
					displayGeometricObject(geometricObject);
					cout << string(20, '-') << endl;
				}
			}

			int main()
			{
				GeometricObject* geometricObjectList[] =
				{
					new Rectangle(3,4),
					new Rectangle(6,8),
					new Circle(5),
					new Circle(9)
				};

				for (int i = 0; i < 4; i++)
				{
					displayGeometricObject(geometricObjectList[i]);
					cout << string(20, '-') << endl;
				}

				return 0;
			}
		} // namespace Ex2

		//Templates
		namespace Ex3
		{
			// Find the maximum element in an integer array
			int maxElement(int arr[], int size)
			{
				int max = arr[0];
				for (int i = 1; i < size; ++i)
					if (arr[i] > max)
						max = arr[i];
				return max;
			}

			// Find the maximum element in a double array
			double maxElement(double arr[], int size)
			{
				double max = arr[0];
				for (int i = 1; i < size; ++i)
					if (arr[i] > max)
						max = arr[i];
				return max;
			}

			// Find the maximum element in a char array
			char maxElement(char arr[], int size)
			{
				char max = arr[0];
				for (int i = 1; i < size; ++i)
					if (arr[i] > max)
						max = arr[i];
				return max;
			}

			template<typename AnyType>
			AnyType maxElement(AnyType arr[], int size)
			{
				AnyType max = arr[0];
				for (int i = 1; i < size; ++i)
					if (arr[i] > max)
						max = arr[i];
				return max;
			}

			template<typename T>
			T max(const T num1, const T num2)
			{
				if (num1 > num2) return num1; else return num2;
			}

			void test1()
			{
				cout << max(1, 3) << endl; // create max int int
				cout << max(1.5, 0.3) << endl; // create max double double
				cout << max(5, 2) << endl; // use max int int
				cout << max('A', 'N') << endl; // create max char char
				cout << Ex3::max(string("NBC"), string("ABC")) << endl; // create
			}

			void test()
			{
				int intArr[] = { 1, 2, 3, 4, 5 };
				double doubleArr[] = { 1.1, 2.2, 3.3, 4.4 };
				string stringArr[] = { "CIE 101", "ENV 101" };

				cout << maxElement(intArr, 5) << endl;
				cout << maxElement(doubleArr, 4) << endl;
				cout << maxElement(stringArr, 2) << endl;
			}
		} // namespace Ex3

		// Template creation example
		namespace Ex4
		{
			void selectionSort(int arr[], int size)
			{
				for (int i = 0; i < size - 1; ++i)
				{
					// Find the minimum element in the unsorted part
					int minIndex = i;
					for (int j = i + 1; j < size; ++j)
						if (arr[j] < arr[minIndex])
							minIndex = j;

					// Swap the found minimum element with the first element
					int temp = arr[minIndex];
					arr[minIndex] = arr[i];
					arr[i] = temp;
				}
			}

			int test1()
			{
				int arr[] = { 64, 25, 12, 22, 11 };
				int size = sizeof(arr) / sizeof(arr[0]);

				cout << "Before sorting: ";
				for (int i = 0; i < size; ++i)
				{
					cout << arr[i] << " ";
				}
				cout << endl;

				selectionSort(arr, size);

				cout << "After sorting: ";
				for (int i = 0; i < size; ++i)
				{
					cout << arr[i] << " ";
				}
				cout << endl;

				return 0;
			}


			// Template function to sort an array using selection sort
			template <typename T>
			void selectionSort(T arr[], int size)
			{
				for (int i = 0; i < size - 1; ++i)
				{
					// Find the minimum element in the unsorted part
					int minIndex = i;
					for (int j = i + 1; j < size; ++j)
						if (arr[j] < arr[minIndex])
							minIndex = j;
					// Swap the found minimum element with the first element
					T temp = arr[minIndex];
					arr[minIndex] = arr[i];
					arr[i] = temp;
				}
			}

			template <typename T>
			void printArray(const T list[], int size)
			{
				for (int i = 0; i < size; i++)
					cout << list[i] << " ";
				cout << endl;
			}

			int test2()
			{
				int list1[] = { 3, 5, 1, 0, 2, 8, 7 };
				selectionSort(list1, 7);
				printArray(list1, 7);

				double list2[] = { 3.5, 0.5, 1.4, 0.4, 2.5, 1.8, 4.7 };
				selectionSort(list2, 7);
				printArray(list2, 7);

				string list3[] = { "Alexandria", "Cairo", "Luxor", "Aswan" };
				selectionSort(list3, 4);
				printArray(list3, 4);

				return 0;
			}
		} // namespace Ex4

		// Fraction Op overloading
		namespace Ex5
		{
			class Fraction
			{
			public:
				Fraction(int num, int denom);
				Fraction(int num);
				Fraction(const Fraction& other);
				Fraction& operator=(const Fraction& other);
				Fraction& operator=(const int& other);
				Fraction operator+(const Fraction& other) const;
				//Fraction operator+(const int& other) const;
				friend Fraction operator+(const int& lhs, const Fraction& rhs);
				friend ostream& operator<<(ostream& cout, const Fraction& rhs);

				double convertToDecimal() const
				{
					return double(numerator) / denominator;
				}

				//operator double() const;

			private:
				int numerator = 0;
				int denominator = 1;
			};

			//Fraction::operator double() const
			//{
			//	return (double)numerator / denominator;
			//}

			Fraction::Fraction(int num, int denom)
				: numerator(num), denominator(denom) {
			}

			Fraction::Fraction(int num) : Fraction(num, 1) {}

			Fraction::Fraction(const Fraction& other)
			{
				this->numerator = other.numerator;
				this->denominator = other.denominator;
			}

			Fraction& Fraction::operator=(const Fraction& other)
			{
				if (this != &other)
				{
					this->numerator = other.numerator;
					this->denominator = other.denominator;
				}
				return *this;
			}

			Fraction& Fraction::operator=(const int& other)
			{
				numerator = other;
				denominator = 1;
				return *this;
			}

			Fraction Fraction::operator+(const Fraction& other) const
			{
				int newNumerator = numerator * other.denominator
					+ other.numerator * denominator;
				int newDenominator = denominator * other.denominator;

				return Fraction(newNumerator, newDenominator);
			}

			//Fraction Fraction::operator+(const int& other) const
			//{
			//	int newNumerator = numerator
			//		+ other * denominator;
			//	int newDenominator = denominator;

			//	return Fraction(newNumerator, newDenominator);
			//}

			Fraction operator+(const int& lhs, const Fraction& rhs)
			{
				int newNumerator = lhs * rhs.denominator
					+ rhs.numerator;
				int newDenominator = rhs.denominator;

				return Fraction(newNumerator, newDenominator);
			}

			ostream& operator<<(ostream& cout, const Fraction& rhs)
			{
				cout << rhs.numerator << " / " << rhs.denominator;
				return cout;
			}

			void displayFraction(const Fraction& f)
			{
				cout << f << endl;
			}

			int test()
			{
				Fraction f1(1, 2);
				cout << f1 << endl;

				Fraction f2(2, 3);
				cout << f2 << endl;

				Fraction f3(3, 4);
				cout << f3 << endl;

				f1 = f2 = f3;
				cout << f1 << endl;

				f1 = f2;
				cout << f1 << endl;

				f1 = 1;
				cout << f1 << endl;

				Fraction f4 = f2 + f3;
				cout << f4 << endl;

				Fraction f5 = f2 + 5;
				cout << f5 << endl;

				Fraction f6 = 10 + f2;
				//cout << (double)f6 << endl;
				cout << f6 << endl;

				//double d = f6;
				//cout << d << endl;

				//displayFraction(f6);
				//displayFraction(2);

				return 0;
			}
		} // namespace Ex5

		// Fraction Op overloading 2
		namespace Ex6
		{
			class Fraction
			{
			public:
				Fraction(int num, int denom);
				Fraction(int num);
				explicit operator double() const;

			private:
				int numerator = 0;
				int denominator = 1;
			};

			Fraction::operator double() const
			{
				return (double)numerator / denominator;
			}

			Fraction::Fraction(int num, int denom)
				: numerator(num), denominator(denom) {
			}

			Fraction::Fraction(int num) : Fraction(num, 1) {}

			int test()
			{
				Fraction f1(1, 2);
				cout << (double)f1 << endl;

				return 0;
			}
		} // namespace Ex6
	} // namespace Lec14


}; // namespace past

namespace Lec2
{
	namespace Ex1
	{
		enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY };
		int main()
		{
			Day day; // Declare
			day = MONDAY; // Assign to one of the values
			cout << day;
			Day day2 = WEDNESDAY; // Declare and Assign 
			//cin >> day2;
			return 0;
		}
	} // namespace Ex

	namespace Ex2
	{
		struct Student
		{
			int studentID;
			string name;
			short intake;
			double gpa;
		};

		int main()
		{
			Student stu1;
			getline(cin, stu1.name);
			Student esraa; esraa = { 1234, "Esraa" };
			Student kareem = { 1235, "Kareem", 45, 3.5 };
			return 0;
		}
	} // namespace Ex

	namespace Ex3
	{
		int main()
		{
			double score = 85;
			if (score >= 95.0) cout << "Grade is A";
			else
			{
				cout << "Grade is not A";
				if (score >= 80.0) cout << "Grade is B";
				else
				{
					cout << "Grade is not B";
					if (score >= 65.0) cout << "Grade is C";
					else
					{
						cout << "Grade is not C";
						cout << "Grade is F";
					}
				}
			}

			return 0;
		}
	} // namespace Ex

	namespace Ex4
	{
		int main()
		{
			bool isEnrolled = true;
			bool isGraduated = false;

			cout << boolalpha; // Print bools as true/false instead of 1/0
			cout << "Enrolled: " << isEnrolled << endl;
			cout << "Graduated: " << isGraduated << endl;

			return 0;
		}
	} // namespace Ex

	namespace Ex5
	{
		int main()
		{
			double TOEFLScore = 0;
			cout << "Enter TOEFL score: ";
			cin >> TOEFLScore;
			bool hasGoodTOEFLScore = (TOEFLScore >= 79);

			bool passedEnglishPlacementTest;
			cout << "Did you pass the English Placement Test?: ";
			cin >> passedEnglishPlacementTest;

			bool isEligibleForAdmission = hasGoodTOEFLScore || passedEnglishPlacementTest;

			bool needsRemedialEnglish = !isEligibleForAdmission;

			if (isEligibleForAdmission)
				cout << "Admit student";
			else
				cout << "Enroll in a remedial English course";

			return 0;
		}
	} // namespace Ex

	namespace Ex6
	{
		int main()
		{
			cout << boolalpha << (1 < 4 > 3) << endl;
			cout << boolalpha << (1 == 2 == 0) << endl;
			return 0;
		}
	} // namespace Ex

	namespace Ex7
	{
		const int MAX_TV_CHANNEL = 100;
		bool getTvStatus(const char* tvName)
		{
			return true;
		}
		int getTvCurrentChannel(const char* tvName)
		{
			return 0;
		}
		int main()
		{
			auto tv1 = "tv1";
			bool isTvOpen = getTvStatus(tv1);
			int currentChannel = getTvCurrentChannel(tv1);
			if (isTvOpen)
				if (currentChannel <= MAX_TV_CHANNEL)
					currentChannel++;
			if (isTvOpen && currentChannel <= MAX_TV_CHANNEL)
				currentChannel++;
			return 0;
		}
	} // namescpace Ex

	namespace Ex8
	{
		int main() {
			double distance, fuel;

			cout << "Enter distance traveled (km): ";
			cin >> distance;

			cout << "Enter fuel consumed (liters): ";
			cin >> fuel;

			if (fuel == 0 || (distance / fuel > 100))
				cout << "Error: Invalid input. Fuel must be greater than zero and efficiency should be realistic." << endl;
			else
				cout << "Fuel efficiency: " << distance / fuel << " km/L" << endl;

			return 0;
		}
	} // namespace Ex

	namespace Ex8b
	{
		// Return max of two int values
		//int max(int num1, int num2)
		//{
		//	if (num1 > num2) return num1;
		//	else return num2;
		//}

		// Return max of two double values
		double max(double num1, double num2)
		{
			if (num1 > num2) return num1;
			else return num2;
		}

		// Return max of three double values
		double max(double num1, double num2, double num3)
		{
			return max(max(num1, num2), num3);
		}

		int main()
		{
			// Invoke the max function with int parameters
			cout << "The maximum of 3 and 4 is "
				<< max(3, 4) << endl;

			// Invoke the max function with the double parameters
			cout << "The maximum of 3.0 and 5.4 is "
				<< max(3.0, 5.4) << endl;

			// Invoke the max function with three double parameters
			cout << "The maximum of 3.0, 5.4, and 10.14 is "
				<< max(3.0, 5.4, 10.14) << endl;

			// Invoke the max function with an int and a double parameters
			cout << "The maximum of 3.5 and 4 is "
				<< max(3.5, 4) << endl;

			return 0;
		}
	} // namespace Ex

	namespace Ex9
	{
		const double M_PI = 3.14159265358979323846;

		// Function to calculate the area of a circle
		double calculateArea(double radius)
		{
			return M_PI * radius * radius;
		}

		// Function to calculate the area of a rectangle
		double calculateArea(double length, double width)
		{
			return length * width;
		}

		int main()
		{
			// Example usage
			cout << "Area of circle (radius 5): " << calculateArea(5.0) << endl;
			cout << "Area of rectangle (4 x 6): " << calculateArea(4.0, 6.0) << endl;

			return 0;
		}
	} // namespace Ex

	namespace Ex10
	{
		// Find the maximum of two double values
		double max(double num1, double num2)
		{
			if (num1 > num2)
				return num1;
			else
				return num2;
		}

		// Find the maximum of three double values
		double max(double n1, double n2, double n3)
		{
			double max1 = max(n1, n2);
			double max2 = max(n2, n3);
			return max(max1, max2);
		}

		// Find max of array of double values
		double max(double values[], int size)
		{
			double max = values[0];
			for (int i = 1; i < size; i++)
				if (values[i] > max)
					max = values[i];
			return max;
		}

		int main()
		{
			cout << max(1.0, 2) << endl;
			cout << max(1, 2.0) << endl;
			//cout << maxNumber(1, 2) << endl;
			return 0;
		}
	} // namespace Ex
} // namespace Lec2


int main()
{
	Lec2::Ex9::main();
	return 0;
}