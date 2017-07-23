using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace HeapImplementation
{
    class Item : IComparable
    {
        public Item(int d)
        {
            Data = d;
        }

        public int Data { get; set; }
        public int CompareTo(object obj)
        {
            var item2 = (Item) obj;
            int def = this.Data.CompareTo(item2.Data);
            if (def == 0)
                return def;
            return def > 0 ? -1 : 1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var heap = new Heap<Item>();
            int val = 0;
            do
            {
                Console.WriteLine("Enter any numer : 0 to exit");
                var parms = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                val = parms[1];
                if (val != 0)
                {
                    heap.Insert(new Item(val));
                    var top = parms[0] == 1 ? heap.Peek() : heap.Front();
                    if(top != default(Item))
                        Console.WriteLine("Top of Queue: " + top.Data);
                }


            } while (val != 0);

        }
    }
}
