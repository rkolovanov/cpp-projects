#include <iostream>

using namespace std;

struct Expression {
	int a;
	int b;
};

struct RefCounter {
	RefCounter(Expression* ptr) {
		cout << "Created counter: ";
		ptr_ = ptr;
		count_ = 0;

		if (ptr != nullptr) {
			*this += 1;
		}
	}

	Expression* get() const {
		return ptr_;
	}

	void operator+=(int a) {
		count_ += a;
		cout << "Address " << ptr_ << " has " << count_ << " refs." << endl;
	}

	void operator-=(int a) {
		count_ -= a;
		cout << "Address " << ptr_ << " has " << count_ << " refs." << endl;
		if (count_ == 0) {
			cout << "Deleting counter on address " << ptr_ << endl;
			delete this;
		}
	}

	bool operator==(int a) {
		return count_ == a;
	}

private:
	int count_;
	Expression* ptr_;
};

struct SharedPtr {
	explicit SharedPtr(Expression* ptr = nullptr) {
		ptr_ = ptr;
		if (ptr != nullptr) {
			counter_ = new RefCounter(ptr);
		} else {
			counter_ = nullptr;
		}
	}

	~SharedPtr() {
		if (ptr_ != nullptr) {
			ptr_ = nullptr;
			*counter_ -= 1;
			counter_ = nullptr;
		}
	}

	SharedPtr(const SharedPtr& sp) {
		ptr_ = sp.ptr_;
		counter_ = sp.counter_;

		if (sp.ptr_ != nullptr) {
			*counter_ += 1;
		}
	}

	SharedPtr& operator=(const SharedPtr& sp) {
		if (sp.ptr_ == ptr_)
			return *this;

		

		if (ptr_ != nullptr) {
			*counter_ -= 1;
		}

		ptr_ = sp.ptr_;
		counter_ = sp.counter_;

		if (ptr_ != nullptr) {
			*counter_ += 1;
		}

		return *this;
	}

	void reset(Expression* ptr = nullptr) {
		if (counter_ != nullptr) {
			*counter_ -= 1;
		} 
		if (ptr != ptr_) {
			ptr_ = ptr;
			setCounter(ptr);
		}
	}

	Expression* get() const { return ptr_; }
	Expression& operator*() const { return *ptr_; }
	Expression* operator->() const { return ptr_; }

private:
	Expression* ptr_;
	RefCounter* counter_;

	void setCounter(Expression* ptr) {
		if (ptr != nullptr) {
			counter_ = new RefCounter(ptr);
		} else {
			counter_ = nullptr;
		}
	}

};

int main() {
	SharedPtr p1;
	{
		SharedPtr p2(new Expression());
		SharedPtr p3(new Expression());
		SharedPtr p4(p2);
		SharedPtr p5;
		p5 = p2;
		p5 = p4;
		p1 = p5;
		p3.reset(NULL);
		p3 = p5;
		p5.reset(NULL);
		SharedPtr p6;
		SharedPtr p7;
		p7 = p7;
		p4 = p6;
		p1 = p3;
		p5 = p3;
		p3.reset(nullptr);
		p1.reset(new Expression);

		p7.reset(NULL);
		p7.reset(new Expression());
		SharedPtr p8(new Expression());
		p8.reset(nullptr);
	}
	p1 = p1;
	p1.reset(nullptr);
	cin.get();
	return 0;
}