using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PreOrderBSTValidity
{

    class Node
    {
        public int data;
        public Node left;
        public Node right;
    }

    class Solution
    {
        protected static TextReader reader;
        protected static TextWriter writer;

        static void Main(string[] args)
        {
#if DEBUG
            reader = new StreamReader("..\\..\\input.txt");
            writer = Console.Out;
            // writer = new StreamWriter("..\\..\\output.txt");
#else
            reader = Console.In;
            writer = new StreamWriter(Console.OpenStandardOutput());
#endif
            Solve();
#if DEBUG
            Console.WriteLine("Completed");
            Console.ReadLine();
#endif
        }

        static void Solve()
        {
            int t = Convert.ToInt32(reader.ReadLine());
            while (t > 0) {
                SolveOne();
                t--;
            }
            writer.Flush();
#if DEBUG
            writer.Close();
#endif
        }

        private static void SolveOne()
        {
            int n = Convert.ToInt32(reader.ReadLine());
            var preArr = reader.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
            int curPre = 0;
            int min = Int32.MinValue;
            int max = Int32.MaxValue;
            Node root = ConstrucTree(preArr,ref n, ref curPre, min, max);
            if (curPre == (n))
                writer.WriteLine(1);
            else
                writer.WriteLine(0);
        }

        private static Node ConstrucTree(int[] preArr,ref int n, ref int curPre, int min, int max)
        {
            if (curPre >= n)
                return null;

            Node root = null;
            var curData = preArr[curPre];
            if(curData >min && curData < max)
            {
                root = new Node();
                root.data = curData;
                curPre++;
                root.left = ConstrucTree(preArr, ref n, ref curPre, min , curData);
                root.right = ConstrucTree(preArr, ref n, ref curPre, curData, max);
            }

            return root;

        }
    }
}
