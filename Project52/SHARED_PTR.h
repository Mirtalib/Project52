#pragma once


namespace HearderFiles {



	template<typename M>
	class Myshared_ptr
	{
	private:
		M* _ptr;
		int count = 0;
	public:

		Myshared_ptr(M* ptr = NULL) 
		{
			_ptr = ptr;
			++count;
		}


		Myshared_ptr(Myshared_ptr<M>& right)  {
			_ptr = right._ptr;
			right._ptr = NULL;
			right.count = 0;
			++count;
		}


		Myshared_ptr<M>& operator=(Myshared_ptr<M>& right)  {
			_ptr = right._ptr;
			right._ptr = NULL;
			right.count = 0;
			++count;
			return *this;
		}


		void reset() {
			delete _ptr;
			count = 0;
			_ptr = NULL;
		}

		void relaese() {
			count = 0;
			_ptr = NULL;
		}

		int use_count() {
			if (_ptr == NULL)
				count = 0 ;
			
			return count;
		}

		Myshared_ptr<M>& swap(Myshared_ptr<M>& right) {
			_ptr = right._ptr;
			right._ptr = NULL;
			count = 0;
			return *this;
		}

		operator bool() {
			return _ptr != NULL;
		}

		M* get() {
			return _ptr;
		}

		M& operator*() {
			return *_ptr;
		}

		M*& operator->() {
			return _ptr;
		}

		bool unique() {
			return count == 1;
		}

		bool owner_before(Myshared_ptr<M> ptr) {
			if (_ptr == NULL || ptr._ptr == NULL)
				throw exception("this pointer is NULL");

			return *_ptr > *ptr;
		}
		
		~Myshared_ptr()
		{
			if (_ptr != NULL) {
				delete _ptr;
				count = 0;
			}
		}
	};
}