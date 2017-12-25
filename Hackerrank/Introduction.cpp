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