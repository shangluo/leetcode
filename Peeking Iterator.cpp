// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
	int peekData;
	bool prevHasNext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), peekData(0), prevHasNext(false){
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		if (prevHasNext = Iterator::hasNext())
		{
			peekData = Iterator::next();
		}
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return peekData;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		int n = peekData;
		if (prevHasNext = Iterator::hasNext())
		{
			peekData = Iterator::next();
		}

		return n;
	}

	bool hasNext() const {
		return prevHasNext;
	}
};