#include "Classes.h"

using namespace std;

struct Student {
	int age;
	string first_name;
	string last_name;
	int standard;
};

// input: 15 \n john \n carmack \n 10
void Structs() {
	Student st;

	cin >> st.age >> st.first_name >> st.last_name >> st.standard;
	cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
}

class Student2 {
private:
	int age;
	string first_name;
	string last_name;
	int standard;
public:
	void set_age(int p_age) {
		age = p_age;
	}
	int get_age() {
		return age;
	}
	void set_first_name(string p_first_name) {
		first_name = p_first_name;
	}
	string get_first_name() {
		return first_name;
	}
	void set_last_name(string p_last_name) {
		last_name = p_last_name;
	}
	string get_last_name() {
		return last_name;
	}
	void set_standard(int p_standard) {
		standard = p_standard;
	}
	int get_standard() {
		return standard;
	}
	string to_string() {
		return std::to_string(age) + "," + first_name + "," + last_name + "," + std::to_string(standard);
	}
};

// input: 15 \n john \n carmack \n 10
void Class() {
	int age, standard;
	string first_name, last_name;

	cin >> age >> first_name >> last_name >> standard;

	Student2 st;
	st.set_age(age);
	st.set_standard(standard);
	st.set_first_name(first_name);
	st.set_last_name(last_name);

	cout << st.get_age() << "\n";
	cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
	cout << st.get_standard() << "\n";
	cout << "\n";
	cout << st.to_string();
}

class Student3 {
private:
	int scores;
public:
	void input() {
		char ch;
		//cin >> ch;
		string mark;
		getline(cin, mark);
		//cout << mark.length() << " " << mark << " : mark" << endl;
		if (mark.length() < 5) {
			getline(cin, mark);
		}
		stringstream ss(mark);
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		int e = 0;
		ss >> a >> b >> c >> d >> e;
		//cout << a << " " << b << " " << c << " " << d << " " << e << endl;
		scores = a + b + c + d + e;
		//cout << scores << endl;
	}
	int calculateTotalScore() {
		return scores;
	}
};

// input: 3 \n 30 40 45 10 10 \n 40 40 40 10 10 \n 50 20 30 10 10 
void ClassesAndObjects() {
	int n; // number of students
	cin >> n;
	Student3 *s = new Student3[n]; // an array of n students

	for (int i = 0; i < n; i++) {
		s[i].input();
	}

	// calculate kristen's score
	int kristen_score = s[0].calculateTotalScore();

	// determine how many students scored higher than kristen
	int count = 0;
	for (int i = 1; i < n; i++) {
		int total = s[i].calculateTotalScore();
		if (total > kristen_score) {
			count++;
		}
	}

	// print result
	cout << count;
}

class Box {
private:
	int length = 0;
	int breadth = 0;
	int height = 0;
public:
	Box() {

	}
	Box(int l, int b, int h) {
		length = l;
		breadth = b;
		height = h;
	}
	Box(const Box &obj) {
		length = obj.length;
		breadth = obj.breadth;
		height = obj.height;
	}
	int getLength() {
		return length;
	}
	int getBreadth() {
		return breadth;
	}
	int getHeight() {
		return height;
	}
	long long CalculateVolume() {
		unsigned long long int z = breadth * height;
		unsigned long long int y = z * length;
		return y;
	}
	bool operator < (Box& b) {
		if (length < b.length)
			return true;
		else if (breadth < b.breadth && length == b.length)
			return true;
		else if (height < b.height && breadth == b.breadth && length == b.length)
			return true;
		else
			return false;
	}
};

ostream& operator<<(ostream& out, Box& B) {
	out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
	return out;
}

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i<n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox<temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

// input: 5 \n 2 3 4 5 \n 4 \n 5 \n 4 \n 2 4 6 7
void BoxIt() {
	check2();
}

class BadLengthException {
	int length_of_name = 0;
public:
	BadLengthException(int name) {
		length_of_name = name;
	}

	string what() {
		return to_string(length_of_name);
	}
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if (n < 5) {
		throw BadLengthException(n);
	}
	for (int i = 0; i < n - 1; i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

// input: 3 \n Peter \n Me \n Arxwwz
void InheritedCode() {
	int T; cin >> T;
	while (T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if (isValid) {
				cout << "Valid" << '\n';
			}
			else {
				cout << "Invalid" << '\n';
			}
		}
		catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
}

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if (A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if (B == 0) throw 0;
		real = (A / B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};

int Server::load = 0;

// input: 2 \n -8 5 \n 1435434255433 5
void ExceptionalServer() {
	int T; cin >> T;
	while (T--) {
		long long A, B;
		cin >> A >> B;
		Server s;
		long long ret;
		try {
			ret = s.compute(A, B);
			cout << ret << endl;
		}
		catch (const invalid_argument& re) {
			cout << "Exception: " << re.what() << endl;
		}
		catch (std::bad_alloc& ba)
		{
			cout << "Not enough memory" << endl;
		}
		catch (const exception &exc) {

			cout << "Exception: " << exc.what() << endl;
		}
		catch (...) {
			cout << "Other Exception" << endl;
		}
	}
	cout << Server::getLoad() << endl;
}

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
private:
public:
	LRUCache(int capacity) {
		cp = capacity;
	}
	virtual void set(int x, int y) {
		if (mp.size() == 0) {
			Node* nd = new Node(NULL, NULL, x, y);
			tail = nd;
			head = nd;
			mp[x] = nd;
			//cout << "kisebb" << endl;
		}
		else if (mp.size() > 0 && mp.size() < cp) {
			Node* local = tail;
			Node* nd = new Node(NULL, NULL, x, y);
			for (int i = 0; i < cp; i++) {
				if (local->prev == NULL) {
					local->prev = nd;
					nd->next = local;
					//cout << "first" << endl;
					break;
				}
				else {
					local = local->prev;
				}
			}
			head = nd;
			mp[x] = nd;
			//cout << "kozeb" << endl;
		}
		else if (mp.size() == cp) {
			Node* nd = new Node(NULL, NULL, x, y);
			Node* local = tail;
			for (int i = 0; i < cp; i++) {
				if (local->prev == NULL) {
					local->prev = nd;
					nd->next = local;
					//cout << "firstfisrt" << endl;
					break;
				}
				else {
					local = local->prev;
				}
			}
			head = nd;
			mp[x] = nd;

			Node* new_tail = tail->prev;
			Node* old_tail = tail;
			new_tail->next = NULL;
			old_tail->prev = NULL;
			tail = new_tail;
			mp.erase(old_tail->key);
			delete old_tail;
		}

		else {
			vector<int> v;
			for (map<int, Node*>::iterator it = mp.begin(); it != mp.end(); ++it) {
				v.push_back(it->first);
				cout << it->first << " : valami" << "\n";
			}
		}

		//cout << "size: " << mp.size() << endl;
	}
	virtual int get(int x) {
		map<int, Node*>::iterator it = mp.find(x);
		if (it == mp.end()) {
			return -1;
		}
		else {
			return mp[x]->value;
		}
	}

};

void AbstractClasses_Polymorphism() {
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i<n; i++) {
		string command;
		cin >> command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			l.set(key, value);
		}
	}
}
