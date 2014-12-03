namespace Seu{
	namespace Cose{
		typedef long shared_count;
		template<typename T>
		class Share_Ptr
		{
		public:
			explicit Share_Ptr(T*p = 0);
			~Share_Ptr();
			Share_Ptr(const Share_Ptr& r);
			T& operator*()const;
			T* operator->()const;
			T* get()const;
			Share_Ptr& operator=(const Share_Ptr<T>&);
			Share_Ptr& operator=(Share_Ptr<T>&);
			bool operator==(const Share_Ptr<T>& rhs);
			bool operator==(Share_Ptr<T>& rhs);
			void swap(Share_Ptr<T>& b);
			void reset();
			shared_count use_count()const;
			bool unique()const;

		private:
			    T * px;                     // contained pointer
    			mutable shared_count pn;    // reference counter
    			void clean();
		};
		
	}
}
