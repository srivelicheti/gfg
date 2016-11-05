using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BinaryTree.Common;

namespace BInaryTrees
{
    class Value
    {
        public int Val { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {


            var array = new int[] {25,14,10,17,20,23,21,24,27,30,8,6,15,18,19,16};//,33,12,34,77,65,28,55,48,95};
            //var array = new int[] { 21,14,23,17,19 };
            var bst = new BST<int, Value>();

            foreach (var i in array)
            {
                bst.Put(i,new Value {Val =   i});
            }

            Console.WriteLine("Tree Height " + bst.Height());
            Console.WriteLine("Tree Height Recursive: " + bst.HeightRecursive());

           
            //for(int i=0;i<24;i++)
            //{
            //    bst.DeleteMin();
            //    Console.WriteLine("Tree Height " + bst.Height());
            //    Console.WriteLine("");
            //}

            Console.WriteLine("");
           // bst.PrintTree();
            Console.Read();
        }

        private static void TestDelete(int[] array, BST<int, Value> bst)
        {
            bst.DeleteUpdaed(17);
            bst.PrintTree();
        }

        private static void TestFloor(int[] array, BST<int, Value> bst)
        {
            Console.WriteLine("Floor for 14: " + bst.Floor(14));
            Console.WriteLine("Floor for 13: " + bst.Floor(13));
            Console.WriteLine("Floor for 25: " + bst.Floor(25));
            Console.WriteLine("Floor for 22: " + bst.Floor(22));
            Console.WriteLine("Floor for 33: " + bst.Floor(33));
            Console.WriteLine("Floor for 5: " + bst.Floor(5));
        }

        private static void TestCeiling(int[] array, BST<int, Value> bst)
        {
            Console.WriteLine("Ceiling for 14: " + bst.Ceiling(14));
            Console.WriteLine("Ceiling for 13: " + bst.Ceiling(13));
            Console.WriteLine("Ceiling for 25: " + bst.Ceiling(25));
            Console.WriteLine("Ceiling for 22: " + bst.Ceiling(22));
            Console.WriteLine("Ceiling for 33: " + bst.Ceiling(33));
            Console.WriteLine("Ceiling for 5: " + bst.Ceiling(5));
        }

        private static void TestRank(int[] array, BST<int, Value> bst)
        {
            var sortedAray = array.OrderBy(x => x).ToList();

            Console.WriteLine("Size of Tree " + bst.Size());
            Console.WriteLine("Rank of root 21: " + bst.Rank(18));
            Console.WriteLine("Rank of root 30: " + bst.Rank(30));
            Console.WriteLine("Rank of 17 " + bst.Rank(17));

            Console.WriteLine("--------------------------");

            Console.WriteLine("Rank of root 21: " + (sortedAray.IndexOf(21) + 1));
            Console.WriteLine("Rank of root 30: " + (sortedAray.IndexOf(30) + 1));
            Console.WriteLine("Rank of 17: " + (sortedAray.IndexOf(17) + 1));
        }
    }
}
