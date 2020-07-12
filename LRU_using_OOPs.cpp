/* Author -- AJAY KUMAR
  Samsung Noida
  MNNIT ALLAHABAD, ALLAHABAD
  ALL Rights Reserved, 
*/
#include <bits/stdc++.h>
using namespace std;

class LRU {
	public:
		int frameSize;
		deque<int> Q; //front -> least recently used element, rear -> most recently used
		map<int, deque<int>::iterator> mp;
		
	public:
		LRU() {
			Q.clear();
			mp.clear();
			frameSize = 5;
		}
		
		LRU(int frameSize) {
			Q.clear();
			mp.clear();
			this->frameSize = frameSize;	
		}
		
		
		void insert(int page) {
			if(mp.find(page) != mp.end()) { //Page already present in the frame
				deque<int>::iterator it = mp[page];
				Q.erase(it);
				Q.push_back(page);
				mp[page] = (--Q.end()); //getting the iterator to the last node
			} else {
				if(Q.size() == frameSize) {
					int deletePage = Q.front();//delete the current LRU element, If size is full
					mp.erase(deletePage);
					Q.erase(Q.begin());
				}
				Q.push_back(page);//insert current page into the frames
				mp[page] = (--Q.end());//getting the iterator to the last node
			}
		}
		
		void printFrame() {
			cout << "Frames : ";
			for (auto it = Q.begin(); it != Q.end(); ++it) {
				cout << *it << " ";
			}
			cout << endl;
		}	
};

int main() {

	LRU lru(3);
	lru.insert(1);
	lru.insert(2);
	lru.insert(3);
	lru.printFrame();
	lru.insert(4);
	lru.printFrame();
	lru.insert(2);
	lru.printFrame();
	return 0;
}
