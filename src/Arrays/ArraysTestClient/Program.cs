using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArraysTestClient
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Replace0sWith5s.Execute(0));
            Console.Read();
        }
    }

    class Exersices
    {
        public static int[] SwapArrayElements(int[] args)
        {
            int i = 0, temp = 0;
            int nextIndex = Int32.MaxValue;
            int nextValue = Int32.MaxValue;

            while (i < args.Length)
            {
                if (args[i] == i)
                {
                    i++;
                    continue;
                }

                if (nextIndex != Int32.MaxValue &&
                    (Int32.MaxValue - nextIndex < Int32.MaxValue - args.Length))
                    throw new IndexOutOfRangeException("Input array elements cannot be swapped because index is out of range");

                if (nextIndex == Int32.MaxValue)
                {
                    nextIndex = args[args[i]];
                    nextValue = args[i];
                    args[args[i]] = i;
                }
                else if (nextIndex != Int32.MaxValue &&
                    nextIndex >= i)
                {
                    temp = args[nextIndex];
                    args[nextIndex] = nextValue;
                    nextValue = nextIndex;
                    nextIndex = temp;
                }
                else if (nextIndex < i)
                {
                    args[nextIndex] = nextValue;
                    nextIndex = Int32.MaxValue;
                    nextValue = Int32.MaxValue;
                }

                i++;
            }
            return args;
        }
    }

}
