/*
 * @lc app=leetcode.cn id=284 lang=cpp
 *
 * [284] 顶端迭代器
 */

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
		m_peek = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		// 获取下一个元素，但是不移动指针
        
		if (!m_peek)
		{
			m_value = Iterator::next();
		}
		m_peek = true;
		return m_value;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    
		if (!m_peek)
		{
			m_value = Iterator::next();
		}
		m_peek = false;
		return m_value;
	}
	
	bool hasNext() const {
	    
		return (m_peek || Iterator::hasNext());
	}
private:
	bool m_peek = false;
	int m_value = 0;
};
// @lc code=end

