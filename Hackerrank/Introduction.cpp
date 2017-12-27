#include "Introduction.h"

void HelloWord() {
	cout << "Hello, World!" << endl;
	OutputDebugString("hello word\n");
}

// input: 1 2 7
void InputAndOutput() {
	string line;
	getline(cin, line);
	int sum = 0;
	istringstream iss(line);
	vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };
	for (vector<string>::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
		sum = sum + stoi(*i);
	cout << sum << endl;
}

// input: 3 12345678912345 a 334.23 14049.30493
void BasicDataTypes() {
	string line;
	getline(cin, line);
	istringstream iss(line);
	vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };
	for (vector<string>::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
		cout << *i << endl;
}

// input: 5
// input: 8
// input: 44
void ConditionalStatement() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "one" << endl;
	}
	else if (n == 2) {
		cout << "two" << endl;
	}
	else if (n == 3) {
		cout << "three" << endl;
	}
	else if (n == 4) {
		cout << "four" << endl;
	}
	else if (n == 5) {
		cout << "five" << endl;
	}
	else if (n == 6) {
		cout << "six" << endl;
	}
	else if (n == 7) {
		cout << "seven" << endl;
	}
	else if (n == 8) {
		cout << "eight" << endl;
	}
	else if (n == 9) {
		cout << "nine" << endl;
	}
	else {
		cout << "Greater than 9" << endl;
	}
}

// input: 4 /n 11
void ForLoop() {
	int n, m;
	cin >> n >> m;
	for (n; n <= m; n++) {
		if (n == 1) {
			cout << "one" << endl;
		}
		else if (n == 2) {
			cout << "two" << endl;
		}
		else if (n == 3) {
			cout << "three" << endl;
		}
		else if (n == 4) {
			cout << "four" << endl;
		}
		else if (n == 5) {
			cout << "five" << endl;
		}
		else if (n == 6) {
			cout << "six" << endl;
		}
		else if (n == 7) {
			cout << "seven" << endl;
		}
		else if (n == 8) {
			cout << "eight" << endl;
		}
		else if (n == 9) {
			cout << "nine" << endl;
		}
		else if (n > 9 & float(n % 2) == 0) {
			cout << "even" << endl;
		}
		else if (n > 9 & float(n % 2) == 1) {
			cout << "odd" << endl;
		}
	}
}

int max_of_four(int a, int b, int c, int d) {
	int max = 0;
	if (a > max) { max = a; }
	if (b > max) { max = b; }
	if (c > max) { max = c; }
	if (d > max) { max = d; }
	return max;
}

// input: 3 \n 4 \n 6 \n 5
void Function() {
	int a, b, c, d;
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	int ans = max_of_four(a, b, c, d);
	printf("%d", ans);
}

void update(int *a, int *b) {
	*a = (*a) + (*b);
	*b = abs((*a) - (*b) - (*b));
}

// input: 4 \n 5
void Pointer() {
	int a, b;
	int *pa = &a, *pb = &b;

	scanf_s("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d", a, b);
}

// input: 4 \n 1 4 3 2
void ArraysIntroduction() {
	int size;
	cin >> size;
	std::list<int> lista;
	for (int i = 0; i < size; i++) {
		int element;
		cin >> element;
		lista.push_back(element);
	}
	for (std::list<int>::reverse_iterator rit = lista.rbegin(); rit != lista.rend(); ++rit)
		std::cout << *rit << ' ';
}

// input: 2 2 \n 3 1 5 4 \n 5 1 2 8 9 3 \n 0 1 \n 1 3
void VariableSizedArrays() {
	int n, q;
	vector< vector<int> > arr;
	cin >> n >> q;
	string space;
	getline(cin, space);
	for (int i = 0; i < n; i++) {
		vector<int> sub_arr;
		string line;
		getline(cin, line);
		istringstream istring(line);
		int n;
		while (istring >> n) {
			sub_arr.push_back(n);
		}
		arr.push_back(sub_arr);
	}
	vector< vector<int> > arr2;
	for (int i = 0; i < n; i++) {
		vector<int> sub_arr;
		string line;
		getline(cin, line);
		istringstream istring(line);
		int n;
		while (istring >> n) {
			sub_arr.push_back(n);
		}
		arr2.push_back(sub_arr);
	}
	vector< vector<int> >::iterator it;
	for (it = arr2.begin(); it != arr2.end(); it++) {}
	for (int i = 0; i < arr2.size(); i++) {
		int index1 = arr2[i][0];
		int index2 = arr2[i][1];
		index2++;
		cout << arr[index1][index2] << endl;
	}
}

class Person {
protected:
	string name;
	int age;
public:
	virtual void getdata() = 0;
	virtual void putdata() = 0;
};

class Professor : public Person {
	int publications;
	int cur_id;
public:
	static int profid;
	Professor() {
		cur_id = profid;
		profid++;
	}
	void putdata() {
		cout << name << " " << age << " " << publications << " " << cur_id << endl;
	}
	void getdata() {
		cin >> name >> age >> publications;
	}
};

class Student : public Person {
	int arr[6];
	int cur_id;
public:
	static int studentid;
	Student() {
		cur_id = studentid;
		studentid++;
	}
	void putdata() {
		int sum_of_marks = 0;
		for (int i = 0; i < 6; i++) {
			sum_of_marks += arr[i];
		}
		cout << name << " " << age << " " << sum_of_marks << " " << cur_id << endl;
	}
	void getdata() {
		cin >> name >> age;
		for (int i = 0; i < 6; i++) {
			cin >> arr[i];
		}
	}
};

int Professor::profid = 1;
int Student::studentid = 1;

// input: 4 \n 1 \n Walter 56 99 \n 2 \n Jesse 18 50 48 97 76 34 98 \n 2 \n Pinkman 22 10 12 0 18 45 50 \n 1 \n White 58 87
void VirtualFunctions() {
	int n, val;
	cin >> n; //The number of objects that is going to be created.
	std::list<Person*> per;
	//Person *per[n];

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			//per[i] = new Professor;
			per.push_back(new Professor());

		}
		else 
			per.push_back(new Student());
			//per[i] = new Student; // Else the current object is of type Student
		per.back()->getdata();
		//per[i]->getdata(); // Get the data from the user.

	}


	std::list<Person*>::iterator it;
	for (it = per.begin(); it != per.end(); ++it) {
		(*it)->putdata();
		//std::cout << typeid(*it).name() << endl;
	}
	//for (int i = 0; i<n; i++)
		//per[i]->putdata(); // Print the required output for each object.

}