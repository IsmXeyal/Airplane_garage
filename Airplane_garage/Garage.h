#pragma once

class Garage {
private:
	Airplane** airplanes = nullptr;
	size_t _count = 0;
	char* _name;
	char* _address;

public:
	Garage() = delete;
	Garage(const char* name, const char* address);
	Garage(const char* name, const char* address, Airplane** _airplanes, size_t count);

	const char* GetName()const;
	const char* GetAddress()const;
	Airplane** GetAirplanes()const;
	int GetCount()const;

	void SetName(const char* name);
	void SetAddress(const char* address);
	void SetAirplanes(Airplane**& _airplanes, size_t count);

	void Clear();
	Airplane* getAirplaneById(int id);
	Airplane** getAirplanesCapacityGreaterThan(int id);
	Airplane** getAirplanesByColor(Colors color);

	void print();

	~Garage();
};

void Garage::SetName(const char* name) {
	int len = strlen(name);
	if (len >= 3) {
		if (this->_name != NULL) {
			delete[]this->_name;
		}
		this->_name = new char[len + 1];
		strcpy_s(this->_name, len + 1, name);
	}
	else {
		assert(!"Incorrect name!");
	}
}

void Garage::SetAddress(const char* address) {
	int len = strlen(address);
	if (len >= 5) {
		if (_address != NULL) {
			delete[] _address;
		}
		_address = new char[len + 1];
		strcpy_s(_address, len + 1, address);
	}
	else {
		assert(!"Incorrect address!");
	}
}

void Garage::SetAirplanes(Airplane**& _airplanes, size_t count) {
	airplanes = new Airplane * [count];
	for (int i = 0; i < count; i++) {
		airplanes[i] = new Airplane(_airplanes[i]->GetModel(), _airplanes[i]->GetColor(),
			_airplanes[i]->GetEngine(), _airplanes[i]->GetCapacity());
	}
	_count = count;
}

Garage::Garage(const char* name, const char* address) {
	SetName(name);
	SetAddress(address);
	airplanes = NULL;
	_count = 0;
}

Garage::Garage(const char* name, const char* address, Airplane** _airplanes, size_t count) {
	SetName(name);
	SetAddress(address);
	SetAirplanes(_airplanes, count);
}

const char* Garage::GetName()const {
	return _name;
}

const char* Garage::GetAddress()const {
	return _address;
}

Airplane** Garage::GetAirplanes()const {
	return airplanes;
}

int Garage::GetCount()const {
	return _count;
}

void Garage::Clear() {
	for (int i = 0; i < _count; i++) {
		delete[] airplanes[i];
	}
	delete[] airplanes;
	airplanes = NULL;
	_count = 0;
}

Airplane* Garage::getAirplaneById(int id) {
	for (int i = 0; i < _count; i++) {
		if (id == airplanes[i]->GetId()) {
			return airplanes[i];
		}
	}
	return NULL;
}

Airplane** Garage::getAirplanesCapacityGreaterThan(int capacity) {
	int len = 0;
	for (int i = 0; i < _count; i++) {
		if (airplanes[i]->GetCapacity() >= capacity)
			len++;
	}

	Airplane** arr = new Airplane * [len];
	int a = 0;
	for (int i = 0; i < _count; i++) {
		if (airplanes[i]->GetCapacity() >= capacity) {
			arr[a++] = airplanes[i];
		}
	}

	return arr;
}

Airplane** Garage::getAirplanesByColor(Colors color) {
	int len = 0;
	for (int i = 0; i < _count; i++) {
		if (airplanes[i]->GetColor() == color)
			len++;
	}

	Airplane** arr = new Airplane * [len + 1];
	int a = 0;
	for (int i = 0; i < _count; i++) {
		if (airplanes[i]->GetColor() == color) {
			arr[a++] = airplanes[i];
		}
	}
	arr[a] = nullptr;

	return arr;
}

void Garage::print() {
	cout << "\t\tGARAGE INFO" << endl;
	cout << "==================================================" << endl;
	cout << "\tName: " << this->_name << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "\tAddress: " << this->_address << endl;
	cout << "==================================================" << endl;
	cout << "\tAll Airplanes" << endl;
	for (int i = 0; i < _count; i++) {
		airplanes[i]->print();
	}
}

Garage::~Garage() {
	delete[]_name;
	delete[]_address;

	if (airplanes != NULL) {
		this->Clear();
	}
}