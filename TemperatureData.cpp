# include "TemperatureData.h"
using std::string;

TemperatureData::TemperatureData() : id(" "), year(0), month(0), temperature(-99.99){
	// TODO: implement this function
}

TemperatureData::TemperatureData(string id, int year, int month, double temperature) {
	// TODO: implement this function
	this->id = id;
	this->year = year;
	this->month = month;
	this->temperature = temperature;

}

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData& b) {
	// TODO: implement this function
	if (id < b.id){
		return true;
	} else if (id == b.id){
		if (year < b.year){
			return true;
		} else if (year == b.year){
			if (month < b.month){
				return true;
			}
		}

	}

	return false;

}

