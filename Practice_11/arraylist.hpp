#pragma once

#include "collection.hpp"
#include <cassert>

namespace Collections
{

	template<typename T> class ArrayList: public ICollection<T>
	{
	public:


		ArrayList()
		{
			//set size and create new pointer
			this->size = INIT_SIZE;
			this->list = new T[INIT_SIZE];
		}

		ArrayList(const ICollection<T>& other)
		{
			//get elements form other by iterator
			this->list = new T[other.getNumElements()];
			auto it = other.getIterator();
			

			while(it->current())
			{
				this->insert(*it->current());
				it->next();
			}
			
			this->m_numElements = other.getNumElements();
			this->size = other.getNumElements();
		}

		virtual ~ArrayList()
		{
			delete[] list;
		}

		void resize( unsigned int numInstances )
		{
			//create copylist
			T* tmpList = new T[numInstances];
			std::memcpy(tmpList,this->list,sizeof(T) * numInstances);

			//re-copy
			this->list = new T[numInstances];
			std::memcpy(this->list, tmpList, sizeof(T) * this->size);

			//update size and number of elements
			this->size = numInstances;
			m_numElements = (m_numElements<=this->size) ? m_numElements : this->size;
			delete[] tmpList;
		}

		virtual void insert( const T& newElement ) override
		{
			//check if we've to reserve more memory
			if(m_numElements==this->size)
				this->reserve(3);

			//insert element
			this->list[this->m_numElements] = newElement;
			++m_numElements;
		}

		T& operator[](int index)
		{
			assert(m_numElements>index);
			return this->list[index];
		}

		class Iterator: public IIterator
		{
		public:
			Iterator( T* first, int numElements ) : 
				m_array( numElements ? first : nullptr ), m_remaining( numElements )		{}

			virtual T* next() override
			{
				if( m_remaining > 1 )
				{
					--m_remaining;
					return ++m_array;
				}
				m_remaining = 0;
				m_array = nullptr;
				return nullptr;
			}

			/// \brief Access the current element without changing the iterator
			///
			virtual T* current() const override
			{
				return m_array;
			}

			virtual ~Iterator() override	{}
		private:
			T* m_array;
			int m_remaining;
		};

		virtual std::shared_ptr<IIterator> getIterator() const override
		{
			return std::shared_ptr<IIterator>(new Iterator(this->list, this->m_numElements));
		}

	private:
		static const int INIT_SIZE = 5;

		T* list;

		unsigned int size;

		void reserve(int amount)
		{
			/*
			this->list = (T*) (realloc(this->list, amount+this->size) * sizeof(T)));
			*/

			//create copylist
			T* tmpList = new T[this->size];
			std::memcpy(tmpList,this->list,sizeof(T) * this->size);

			//re-copy
			this->list = new T[this->size+amount];
			std::memcpy(this->list, tmpList, sizeof(T) * this->size);

			//update size
			this->size+= amount;
			delete[] tmpList;
		}
	};
};