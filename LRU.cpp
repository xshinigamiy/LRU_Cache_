/* Author -- AJAY KUMAR
  MNNIT ALLAHABAD, ALLAHABAD
  ALL Rights Reserved, 
*/

#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define SIZE 100000



//Map tells whether a page is in the main memory or not
bool m[SIZE];

priority_queue< pp , vector< pp > , greater< pp > > Q;


/*
pair<int,int> = First element of the pair will contain the time when it was used last time, 
second element of the pair will contain the actual page number of the page to be searched.
*/





//This Utility function is used to repalce the time of a page used last time in the priority queue

void change(int &a , int cnt){
	//cout << '\n';
	vector< pp > v(Q.size());
	//vector will store the relative order of the elements in the queue
	
	while(!Q.empty()){
		if(Q.top().second == a)
			v.emplace_back(make_pair(cnt , a)) ;
		else
			v.emplace_back(Q.top());
		Q.pop();
	}

	for(auto p : v){
		if(p.first == 0)
			continue;
		Q.push(p);
		//cout << p.second << " " << p.first << '\n';
	}
}

//n = Number of page searches, SIZE = Cahe table size, A[] = Order in which pages are searched
unsigned int LRU_Cache(int a[] , int n , int size){
	//This variable will store the total number of cache miss 
  unsigned int miss = 0;
	int time = 0;
	for(int i = 0 ; i < n ; i++ ){
		++time;
		//current page is not present in the cache
		if(m[a[i]] == false){
		++miss;
		m[a[i]] = true;
		//cout << a[i] << " " << i << '\n';
		//Size is less than the frame size, so we can bring next page into the memory
		if(Q.size() < size)
			Q.push(make_pair(time , a[i]));
			//If the size of the cache is already full, Remove the least 
			//recent used page from the table and bring the current page 
			else{
				if(Q.top().second != a[i]){
					pp p = Q.top();
					Q.pop();
					//cout << p.first << " " << p.second << '\n';
					m[p.second] = false;
					Q.push(make_pair(time, a[i]));
				//printf("%d %d %d\n",i ,(int)Q.size(),p.second);
				}
			}
		}
		else{
			//cout << i << " " << '\n';
			change(a[i] , time);
		}
	}
	return miss;
}

int main(int argc , char* argv[] ){
	int a[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
	int n = sizeof(a)/sizeof(a[0]);
	int size = 4;	//Cache size
	memset(m , false , sizeof(m)); //This keeps track of the pages currently present in the cache,
	printf("Total number of page faults =  %d \n",LRU_Cache(a , n , size));
  return 0;
}
