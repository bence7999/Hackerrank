#include "Slt.h"

using namespace std;

void VectorSort() {
	int N;
	cin >> N;
	int val;
	vector<int> myvec;
	for (int i = 0; i < N; i++) {
		cin >> val;
		myvec.push_back(val);
	}
	sort(myvec.begin(), myvec.end());
	for (int i = 0; i < myvec.size(); i++) {
		cout << myvec[i] << " ";
	}
}

void VectorErase() {
	int n;
	cin >> n;
	vector<int> v;
	int val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		v.push_back(val);
	}
	int x = 0;
	cin >> x;
	int a, b;
	cin >> a >> b;
	v.erase(v.begin() + x - 1);
	v.erase(v.begin() + a - 1, v.begin() + b - 1);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

void LowerBoundSTL() {
	// TODO
}

void SetsSTL() {
	unsigned int q;
	cin >> q;
	set<int> s;
	unsigned x, y;
	for (unsigned i = 0; i <q; i++) {
		cin >> x >> y;
		//cout << x << " " << y << endl;
		switch (x) {
		case 1:
			s.insert(y);
			break;
		case 2:
			s.erase(y);
			break;
		case 3:
			set<int>::iterator itr = s.find(y);
			if (itr == s.end()) {
				cout << "No" << endl;
			}
			else {
				cout << "Yes" << endl;
			}
			break;
		}
	}
}

void MapsSTL() {
	unsigned int q;
	cin >> q;
	map <string, int> m;
	unsigned x, y;
	string s;
	for (int i = 0; i < q; i++) {
		cin >> x;
		//cout << x << endl;

		switch (x) {
		case 1:
		{
			cin >> s >> y;
			//cout << "s: " << s << " y: " << y << endl;
			map <string, int>::iterator itr = m.find(s);
			if (itr == m.end()) {
				m.insert(make_pair(s, y));
			}
			else {
				itr->second += y;
			}
			break;
		}
		case 2:
		{
			cin >> s;
			//cout << "s: " << s << endl;
			m.erase(s);
			break;
		}
		case 3:
		{
			cin >> s;
			//cout << "s: " << s << endl;
			map <string, int>::iterator itr = m.find(s);
			if (itr == m.end()) {
				cout << "0" << endl;
			}
			else {
				cout << itr->second << endl;
			}
			break;
		}
		}
	}
}

void PrintPretty() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		cout << hex << left << showbase << nouppercase;
		cout << (long long)A << endl;

		cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2);
		cout << B << endl;

		cout << scientific << uppercase << noshowpos << setprecision(9);
		cout << C << endl;
	}
}

void DequeSTL() {
	// TODO
}