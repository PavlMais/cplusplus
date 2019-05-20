#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const string FILE_PATH = "file.txt";


struct Member {
	string name;
	string surname;
	int age;
	int points = 0;
	int avg_points = 0;
	string compress() {
		return name + "[n]" + surname + "[s]" + to_string(age) + "[a]" + to_string(points) + "[p]" + avg_points + "[v]";
	}
};

struct Members {
	Member* mbs;
	int size;
};
void showMember(const Member& member);
Member createMember();
void saveFile(const Members& member);
Members loadFromFile();
Member parseMember(string data);




int main() {



	Member  m = createMember();
	showMember(m);
	system("pause");
	return 0;
}


void showMember(const Member& member) {
	cout << "\n   Mamber\n Name: " << member.name;
	cout << "\n Surname: " << member.surname;
	cout << "\n Age: " << member.age;
	cout << "\n Points: " << member.points;
	cout << "\n AVG Points: " << member.avg_points;
}

Member createMember() {
	string buffer;
	Member member;
	cout << "Enter your name: ";
	cin >> buffer;
	member.name = buffer;

	cout << "Enter your surname: ";
	cin >> buffer;
	member.surname = buffer;

	cout << "Enter your age: ";
	cin >> buffer;
	member.age = atoi(buffer.c_str());

	return member;
}




void saveFile(const Members& members) {
	fstream file;
	file.open(FILE_PATH, ios_base::out);

	file << members.size << "\n";

	for (int i = 0; i < members.size; i++)
		file << members.mbs[i].compress();
	

	file.close();

}

Members loadFromFile() {
	std::ifstream file(FILE_PATH);

	string buffer;

	getline(file, buffer);


	Members members;
	members.size = stoi(buffer);

	for (int i = 0; i < members.size; i++)
	{
		getline(file, buffer);
		members.mbs[i] = parseMember(buffer);

	}
	return members;
}

Member parseMember(string data) {
	int indx1 = data.find("[n]") + 3;
	int indx2 = data.find("[s]") + 3;
	int indx3 = data.find("[a]") + 3;
	int indx4 = data.find("[p]") + 3;
	int indx5 = data.find("[v]") + 3;
	Member mem;

	mem.name = data.substr(0, indx1 - 3);
	mem.surname = data.substr(indx1, indx2 - indx1 - 3);
	mem.age = stoi(data.substr(indx2, indx3 - indx2 - 3));
	return mem;
}
