#include "Strings.h"

// intput: abcd \n ef
void Strings() {
	std::string a;
	std::string b;
	std::cin >> a >> b;
	std::cout << a.size() << " " << b.size() << std::endl;
	std::cout << a << b << std::endl;
	char loc = a[0];
	a[0] = b[0];
	b[0] = loc;
	std::cout << a << " " << b << std::endl;
}

std::vector<int> parseInts(std::string str) {
	std::stringstream ss(str);
	std::vector<int> myvector;
	int i;
	while (ss >> i)
	{
		myvector.push_back(i);

		if (ss.peek() == ',')
			ss.ignore();
	}
	return myvector;
}

// input: 23,4,56
void StringStream() {
	std::string str;
	std::cin >> str;
	std::vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		std::cout << integers[i] << "\n";
	}
}

// input: 4 3 \n <tag1 value = "HelloWorld"> \n <tag2 name = "Name1"> \n < / tag2> \n < / tag1> \n tag1.tag2~name \n tag1~name \n tag1~value
void AttributeParser() {
	std::string numbers;
	std::getline(std::cin, numbers);
	std::stringstream ss(numbers);
	int n, q;
	ss >> n >> q;
	std::vector<std::string> hrml;
	std::vector<std::string> queries;
	std::string input;
	for (int i = 0; i < n; i++) {
		std::getline(std::cin, input);
		hrml.push_back(input);
	}
	for (int i = 0; i < q; i++) {
		std::getline(std::cin, input);
		queries.push_back(input);
	}
	std::string ctag = "</";
	std::string etag = ">";
	std::string edelim = "=";
	std::string sdelim = " ";
	std::string prefix = "";
	std::vector< std::string > elem_vec;
	std::vector< std::vector< std::string > > vec_vec;
	std::string push_name = "";
	for (int i = 0; i < hrml.size(); i++) {
		if (hrml[i].find(ctag) == std::string::npos) {
			size_t found = hrml[i].find(etag);
			if (found != std::string::npos) {
				std::string str2 = hrml[i].substr(1, found - 1);
				std::string name = str2.substr(0, str2.find(sdelim));
				if (prefix.length() > 0)
					push_name = prefix + '.' + name;
				else {
					push_name = name;
				}
				elem_vec.push_back(push_name);
				prefix = push_name;
				if (str2.length() > name.length()) {
					str2 = str2.substr(name.length() + 1);
					if (str2.length() > name.length()) {
						do {
							std::string attr = str2.substr(0, str2.find(edelim));
							std::string a = attr.substr(0, attr.length() - 1);
							elem_vec.push_back(a);
							str2 = str2.substr(a.length() + 3);
							std::string v = str2.substr(0, str2.find(sdelim));
							elem_vec.push_back(v);
							if (str2.length() > v.length()) {
								str2 = str2.substr(v.length() + 1);
							}
							else {
								str2 = str2.substr(v.length());
								vec_vec.push_back(elem_vec);
								elem_vec.clear();
							}
						} while (str2.length() > 1);
					}
				}
				else {
					vec_vec.push_back(elem_vec);
					elem_vec.clear();
				}
			}
		}
		else {
			size_t found = prefix.find_last_of('.');
			if (found != std::string::npos) {
				prefix = prefix.substr(0, found);
			}
			else {
				prefix = "";
			}
		}
	}

	char dot = '.';
	char tilde = '~';
	std::string line;
	std::vector< std::pair<std::string, std::string> > qlist;
	std::pair<std::string, std::string> p;
	for (int i = 0; i < queries.size(); i++) {
		line = queries[i];
		size_t find = line.find(tilde);
		p.first = line.substr(0, find);
		p.second = line.substr(find + 1, line.length());
		qlist.push_back(p);
	}

	bool found_elem = false;
	for (int i = 0; i < qlist.size(); i++) {
		std::string first = qlist[i].first;
		std::string second = qlist[i].second;
		for (int j = 0; j < vec_vec.size(); j++) {
			if (vec_vec[j][0] == first) {
				for (int k = 0; k < vec_vec[j].size(); k++) {
					if (find(vec_vec[j].begin(), vec_vec[j].end(), second) != vec_vec[j].end()) {
						ptrdiff_t pos = find(vec_vec[j].begin(), vec_vec[j].end(), second) - vec_vec[j].begin();
						std::string to_out = vec_vec[j][pos + 1];
						to_out = to_out.substr(1, to_out.length() - 2);
						std::cout << to_out << std::endl;
						found_elem = true;
						break;
					}
					else {
						std::cout << "Not Found!" << std::endl;
						found_elem = true;
						break;
					}
				}
			}
		}
		if (!found_elem)
			std::cout << "Not Found!" << std::endl;
		else
			found_elem = false;
	}
}