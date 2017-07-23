using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeapImplementation
{
    class Heap<T> where T:IComparable 
    {
        private List<T> _arr;
        private int _size = 0;
        public Heap()
        {
            _arr = new List<T>();
            _arr.Add(default(T));
        
        }


        public void Insert(T item)
        {
            ++_size;
            _arr.Add(item);
            Swim(_size);
        }

        private void Swim(int n)
        {
            while (n > 1)
            {
                int parent = n/2;
                if (_arr[parent].CompareTo(_arr[n]) > 0)
                {
                    T temp = _arr[parent];
                    _arr[parent] = _arr[n];
                    _arr[n] = temp;
                    n = parent;
                }
                else
                {
                    break;
                }
            }
        }

        private void Sink(int n)
        {
            while (2*n <= _size)
            {
                int j = 2*n;
                if (j + 1 <= n && _arr[j].CompareTo(_arr[j + 1]) > 0)
                    j++;

                if (_arr[n].CompareTo(_arr[j]) > 0)
                {
                    var t = _arr[n];
                    _arr[n] = _arr[j];
                    _arr[j] = t;
                    n = j;
                }
                else
                {
                    break;
                }
            }
        }

        public T Front()
        {
            if (_size == 0)
                return default(T);

            T ret = _arr[1];
            _arr[1] = _arr[_size];
            _arr.RemoveAt(_size);
            _size--;

            if(_size > 0)
                Sink(1);

            return ret;
        }

        public T Peek()
        {
            if (_size == 0)
                return default(T);

            return _arr[1];
        }

    }
}
