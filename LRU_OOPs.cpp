/* Author -- AJAY KUMAR
  MNNIT ALLAHABAD, ALLAHABAD
  ALL Rights Reserved, 
*/

#include <bits/stdc++.h>
using namespace std;

class LRU {
		list<int> cache;
		int cacheSize;
		unordered_map<int, list<int>::iterator> mp;
	public:
		LRU(int);
		void insert(int);
		void print();
};

LRU::LRU(int size) {
	this->cacheSize = size;//Set the size of the cache at the beginning
}


void LRU::insert(int x) {
	if(mp.find(x) == mp.end()) { //This frame is not present into the cache;
		//Hence We must bring it here 
		//And before inserting, we must check the size of the cache
		if(cacheSize == (int)cache.size()) { //Cache is full
			//We must replace one page frame, and bring the new page into the cache
			int last = cache.back();
			mp.erase(last); //delete this entry from the Map
			cache.pop_back();// Delete this page frame from the cache
		}
	} else {
		cache.erase(mp[x]); //Remove this Node from the list
	}
	cache.push_front(x); //Insert it to the beginning of the node
	mp[x] = cache.begin(); // and change the pointer of the node in the map
}

void LRU::print() {
	for (auto it = cache.begin() ; it != cache.end(); ++it) {
		cout << *it << " ";
	}
	cout << '\n';
}


int main() {

	LRU lru(4);

	lru.insert(1);
	lru.print();
	lru.insert(2);
	lru.print();
	lru.insert(3);
	lru.print();
	lru.insert(1);
	lru.print();
	lru.insert(4);
	lru.print();
	lru.insert(5);
	lru.print();
	//LRU lru = new LRU(x);
}
