#pragma once
#include <iostream>
template <class T, class R>
class HashObject
{
protected:
	T key;
	R* record;

public:
	HashObject() { key = (T)0; record = nullptr; }
	HashObject(T k) { key = k; record = nullptr; }
	HashObject(T k, R* r) { key = k; record = r; }
	~HashObject(){ deleteRecord(); }
	
	HashObject& operator = (HashObject const& obj) {
		this->key = obj.key;
		this->record = obj.record;
		return *this;
	}
	bool operator == (HashObject const& obj) {
		return this->record == obj.record;
	}

	void deleteRecord() {
		if (this->record) {
			delete this->record;
			this->record = nullptr;
		}
	}

	T getKey() { return this->key; }
	R* getRecord() { return this->record; }
	bool isEqualKey(T k) { return this->key == k; }
	void print() { cout << "Key: " << this->key << " | Record: " << this->record; }
};

