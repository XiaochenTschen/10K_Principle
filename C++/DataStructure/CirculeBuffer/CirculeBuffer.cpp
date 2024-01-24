/* 
** circule buffer
* In order to support any type of data, template class should be used
* Class will provide methods as following:
*   .Restting buffer to empty
*   .Adding data
*   .Removing data from end
*   .Checking full/empty state
*   .Checking the current number of element in buffer
*   .Checking the total capacity of the buffer
*/

#include <iostream>
#include <string>

template <typename T>
class RingBuf{
private:
	T* dataArray;
	size_t bufSize;
	size_t head, tail;
	size_t mSize;
	bool isFull;
	bool isEmpty;
public:
	RingBuf(size_t n) : bufSize(n), dataArray(new T[n]), head(0), tail(0), mSize(0), isFull(false), isEmpty(true) {

	}
	~RingBuf(){
		delete[] dataArray;
	}

	RingBuf(const RingBuf& other){
		bufSize = other.bufSize;
		tail = other.tail;
		head = other.head;
		mSize = other.mSize;
		dataArray = new T[bufSize];
		for(int i = 0; i < bufSize; i++){
			dataArray[i] = other.dataArray[i];
		}
	}

	RingBuf& operator=(const RingBuf& other){
		if(this != &other){
			delete[] dataArray;
			bufSize = other.bufSize;
			tail = other.tail;
			head = other.head;
			mSize = other.mSize;
			dataArray = new T[bufSize];
			for(int i = 0; i < bufSize; i++){
				dataArray[i] = other.dataArray[i];
			}
		}
		return *this;
	}

	void reset(){
		head = 0;
		tail = 0;
		mSize = 0;
		isFull = false;
		isEmpty = true;
	}

	bool push(const T ele){
		if(isFull) return false;
		dataArray[head] = ele;
		head = (++head) % bufSize;
		mSize++;
		isEmpty = false;
		if(mSize == bufSize)
			isFull = true;
	}

	bool pop(T& ele){
		if(isEmpty){ return false; }
		
		ele = dataArray[tail];
		tail = (++tail) % bufSize;
		mSize--;
		if(mSize == 0)
			isEmpty = true;
		return true;
	}

	bool empty(){
		return isEmpty;
	}

	bool full(){
		return isFull;
	}

	bool peek(T& ele){

		if(isEmpty)
		{
			return false;
		}
		else{
			ele = dataArray[tail];
			return true;
		}
	}

	size_t length() const{
		return mSize;
	}

	size_t capacity(){
		return bufSize;
	}

	size_t getTail()
	{
		return tail;
	}

	size_t getHead()
	{
		return head;
	}

};

int main()
{
	RingBuf<std::string> test(5);
	for(int i = 0; i < 5; i++)
	{
		test.push("hello");
	}

	std::cout << test.getHead() << std::endl;
	test.push("world");
	std::cout << test.getHead() << std::endl;
	std::cout << std::endl;

	for(int i = 0; i < 5; i++)
	{
		std::string temp;
		bool flag = test.pop(temp);
		std::cout << flag << std::endl;
		std::cout << test.getHead() << std::endl;
		std::cout << test.getTail() << std::endl;
		std::cout << temp << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
