# include "TemperatureDatabase.h"
# include <fstream>
# include <sstream>
# include <vector>
# include <iostream>

using std::cout, std::endl, std::string, std::ofstream, std::vector;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

int up(double n){
	if (n > 0){
		double remaind = n - int(n);
		if (remaind > 0.5){
			return int(n) + 1;
		} else {
			return int(n);
		}
	} else {
		double remaind = n - int(n);
		if (remaind > -0.5){
			return int(n);
		} else {
			return int(n)-1;
		}
	}

}

void TemperatureDatabase::loadData(const string& filename) {
	// TODO: implement this
	std::ifstream file(filename);
	if (file.fail()){
		cout << "Error: Unable to open " << filename << endl;

	}

	string id;
	int year;
	int month;
	double temp;

	string line;
	
	
	while (getline(file,line)){
		std::stringstream ss(line);
		ss >> id; 
		ss >> year;
		ss >> month;
		ss >> temp;
		
		
		if (ss.fail()){
			cout << "Error: Other invalid input" << endl;

		}else if (ss.peek() != EOF){
			cout << "Error: Other invalid input" << endl;

		}else if (year < 1800 || year > 2023){
			cout << "Error: Invalid year " << year  << endl;
		
		} else if (month < 1 || month > 12){
			cout << "Error: Invalid month " << month << endl;
			
		} else if (temp < -50.0 || temp > 50.0){
			cout << "Error: Invalid temperature " << temp << endl;
			
		}else{
			records.insert(id, year, month, temp);
		} 
		
		
	}
	file.close();
	
	
}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// TODO: implement this function
	std::ifstream file(filename);

	string id;
	string command;
	int start;
	int end;

	string line;

	ofstream newFile("result.dat");
	if (newFile.fail()){
		cout << "Error: could not open file" << endl;
	}

	while (getline(file,line)){
		std::stringstream ss;
		ss >> id;
		ss >> command;
		ss >> start;
		ss >> end;
		
		if (ss.fail()){
			cout << "Error: Other invalid input" << endl;

		}else if (ss.peek() != EOF){
			cout << "Error: Other invalid input" << endl;

		}else if(id != ""){
			cout << "Error: Invalid format" << endl;
		}else if (command != "AVG" && command != "MODE"){
			cout << "Error: Unsupported query " << command << endl;
		}else if (start > end || (start < 1800 || end > 2023)){
			cout << "Error: Invalid range" << start<< "-" << end << endl;
		}
		
		

		if (command == "AVG"){
			Node* head = records.getHead();
			vector<double> temps ;
			
			while (head != nullptr){
				if (head->data.year >= start && head->data.year <= end){
					temps.push_back(head->data.temperature);
				}
			}
			double sum; 
			
			for(size_t i = 0; i < temps.size(); i++){
				sum += temps.at(i);
			}

			double avg = sum/temps.size();
			
			newFile << id << " " << command << " " << start << " " << end <<  " " << avg << endl;
			if (newFile.fail()){
				cout << "Error: unable to write to file" << endl;
			}


			
		} else if (command == "MODE"){
			Node* Mohead = records.getHead();
			vector<double> Modtemp; 
			while (Mohead!= nullptr){

				if (Mohead->data.year >= start && Mohead->data.year <= end){
					Modtemp.push_back(up(Mohead->data.temperature));
				}
				Mohead = Mohead->next;
			}
			size_t Maxcount = 0;
			size_t index;
			for (size_t i = 0; i < Modtemp.size(); i++){
				size_t count = 0;
				for (size_t j = 0; j < Modtemp.size(); j++){
					if (Modtemp.at(i) == Modtemp.at(j)){
						count++;
					}
				}
				if (count > Maxcount){
					Maxcount = count;
					index = i;
				}else if ( count == Maxcount){
					if (Modtemp.at(i) > Modtemp.at(index)){
						index = i;
					}
				}
			}

			newFile << id << " " << command << " " << start << " " << end <<  " " << Modtemp.at(index) << endl;
			if (newFile.fail()){
				cout << "Error: unable to write to file" << endl;
			}
		}

		
		
		
	}

	
	newFile.close();
}


