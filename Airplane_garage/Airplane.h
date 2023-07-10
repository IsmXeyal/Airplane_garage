#pragma once

enum Colors{ None, Black, Green, Red, White, Gray};

class Airplane {
	int _id;
	char* _model;
	Colors _color;
	double _engine;
	int _capacity;

public:
	static int staticId;
	static int MAXCOUNT;

	// All Constructors

	Airplane();
	Airplane(const char* model, Colors color);
	Airplane(const char* model, Colors color, double engine, int capacity);

	// All Get Methods

	int GetId()const;
	const char* GetModel()const;
	Colors GetColor()const;
	double GetEngine()const;
	int GetCapacity()const;

	// All Set Methods

	void SetModel(const char* model);
	void SetColor(Colors color);
	void SetEngine(double engine);
	void SetCapacity(int capacity);

	// GetColorName
	const char* GetColorName();


	void print();

	~Airplane();
};

int Airplane::staticId = 0;

// All Get Methods

int Airplane::GetId()const { 
	return this->_id; 
}

const char* Airplane::GetModel()const {
	return this->_model;
}

Colors Airplane::GetColor() const {
	return this->_color;
}

double Airplane::GetEngine()const {
	return this->_engine;
}

int Airplane::GetCapacity()const {
	return this->_capacity;
}

// All Set Methods

void Airplane::SetModel(const char* model) {
	int len = strlen(model);
	if (len >= 3) {
		if (this->_model != nullptr) {
			delete[] this->_model;
		}
		this->_model = new char[len + 1];
		strcpy_s(this->_model, len + 1, model);
	}
	else {
		assert(!"Incorrect Model name!");
	}
}

void Airplane::SetColor(Colors color) {
	this->_color = color;
}

void Airplane::SetEngine(double engine) {
	if (engine >= 5.0 && engine <= 9.5) {
		this->_engine = engine;
		return;
	}
	assert(!"Incorrect engine!");
}

void Airplane::SetCapacity(int capacity) {
	if (capacity >= 100 && capacity <= 500) {
		this->_capacity = capacity;
		return;
	}
	assert(!"Incorrect Capacity");
}

 //All Constructors

Airplane::Airplane() {
	_id = ++staticId;
	_model = nullptr;
	_color = Colors::None;
	_engine = 0;
	_capacity = 0;
}

Airplane::Airplane(const char* model, Colors color):Airplane() {
	SetModel(model);
	SetColor(color);
}

Airplane::Airplane(const char* model, Colors color, double engine, int capacity) :Airplane(model, color) {
	SetEngine(engine);
	SetCapacity(capacity);
}

// GetColorName
const char* Airplane::GetColorName() {
	switch (this->_color)
	{
	case None:		return "None";
	case Black:		return "Black";
	case Green:		return "Green";
	case Red:		return "Red";
	case White:		return "White";
	case Gray:		return "Gray";
	}
}

void Airplane::print() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Id: " << _id << endl;
	cout << "Model: " << (_model != nullptr ? _model : "NULL") << endl;
	cout << "Color: " << this->GetColorName() << endl;
	cout << "Engine: " << _engine << endl;
	cout << "Capacity: " << _capacity << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

Airplane::~Airplane() {
	delete[] _model;
}

