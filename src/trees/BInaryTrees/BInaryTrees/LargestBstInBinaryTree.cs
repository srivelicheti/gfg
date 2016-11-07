using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BinaryTree.Common;

namespace BInaryTrees
{
    /// <summary>
    /// Example(To be used only for expected output):
    /// Input
    ///2
    ///2
    ///3 2 L 3 4 R
    ///4
    ///10 20 L 10 30 R 20 40 L 20 60 R

    ///Output
    ///3
    ///1

    ///There are two test cases.First case represents a tree with 3 nodes and 2 edges where root is 3, left child of 3 is 2 and right child of 3 is 4.   Second test case represents a tree with 4 edges and 5 nodes.
    /// </summary>
    class LargestBstInBinaryTree
    {
        private static int _currentMaxHeight;
        public static void PrintLargestBstInBinaryTree(string text)
        {
            _currentMaxHeight = 0;
            var tree = BuildFromDelimitedText(text);

            var root = tree.Root;
            GetLargestBst(root);
            Console.WriteLine(_currentMaxHeight);
        }

        private static int GetLargestBst<TKey>(Node<TKey> root) where TKey : IComparable<TKey>
        {
            if (root == null) return 0;
            var left = GetLeftTreeBstSize<TKey>(root.Left, root);
            var right = GetRightTreeBstSize(root.Right, root);

            var totalBinalryTreeHeight = left == -1 || right == -1 ? 1 : left + right + 1;
            _currentMaxHeight = Math.Max(_currentMaxHeight, totalBinalryTreeHeight);

            return totalBinalryTreeHeight;

        }

        private static int GetLeftTreeBstSize<TKey>(Node<TKey> child, Node<TKey> parent) where TKey : IComparable<TKey>
        {
            if (child == null) return 0;
            bool isBinaryTree = !(child.Key.CompareTo(parent.Key) > 0);

            var left = GetLeftTreeBstSize<TKey>(child.Left, child);
            var right = GetRightTreeBstSize(child.Right, child);

            //left = left == -1 ? 0 : left;
            //right = right == -1 ? 0 : right;
            var totalBinalryTreeHeight = left == -1 || right == -1 ? 1 : left + right + 1;
            _currentMaxHeight = Math.Max(_currentMaxHeight, totalBinalryTreeHeight);
            return isBinaryTree ? totalBinalryTreeHeight : -1;

        }
        //private int 
        private static int GetRightTreeBstSize<TKey>(Node<TKey> child, Node<TKey> parent) where TKey : IComparable<TKey>
        {
            if (child == null) return 0;

            bool isBinaryTree = !(child.Key.CompareTo(parent.Key) <= 0);

            var left = GetLeftTreeBstSize<TKey>(child.Left, child) ;
            var right = GetRightTreeBstSize(child.Right, child);
            var totalBinalryTreeHeight = left == -1 || right == -1 ? 1 : left + right + 1;
            _currentMaxHeight = Math.Max(_currentMaxHeight, totalBinalryTreeHeight);
            return isBinaryTree ? totalBinalryTreeHeight : -1;

        }

        /// <param name="input"></param>
        /// <returns></returns>
        public static BinaryTree<int> BuildFromDelimitedText(string input)
        {
            IDictionary<int, Node<int>> dic = new Dictionary<int, Node<int>>();
            var splitInput = input.Split(' ');
            var root = Convert.ToInt32(splitInput[0]);

            var rootNode = new Node<int>(root);
            var tree = new BinaryTree<int>(rootNode);
            dic.Add(rootNode.Key, rootNode);

            for (int i = 0; i < splitInput.Length; i = i + 3)
            {
                var parent = dic[Convert.ToInt32(splitInput[i])];
                var child = new Node<int>(Convert.ToInt32(splitInput[i + 1]));
                dic.Add(child.Key,child);
                if (String.CompareOrdinal(splitInput[i + 2], "L") == 0)
                {
                    parent.Left = child;
                }
                else
                {
                    parent.Right = child;
                }

            }
            return tree;
        }
    }
}
