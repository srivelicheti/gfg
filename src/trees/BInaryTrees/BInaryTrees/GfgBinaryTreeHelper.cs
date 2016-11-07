using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BinaryTree.Common;

namespace BInaryTrees
{
    public class GfgBinaryTreeHelper
    {

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
                dic.Add(child.Key, child);
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

        public static Node BuildFromDelimitedTextWithRandomPointer(string input)
        {
            IDictionary<int, Node> dic = new Dictionary<int, Node>();
            var splitInput = input.Split(' ');
            var root = Convert.ToInt32(splitInput[0]);

            var rootNode = new Node(root);
            dic.Add(rootNode.Key, rootNode);

            for (int i = 0; i < splitInput.Length; i = i + 3)
            {
                var parent = dic[Convert.ToInt32(splitInput[i])];
                var childKey = Convert.ToInt32(splitInput[i + 1]);
                var child = dic.ContainsKey(childKey) ? dic[childKey] : new Node(childKey);
                dic.Add(child.Key, child);
                if (String.CompareOrdinal(splitInput[i + 2], "L") == 0)
                {
                    parent.Left = child;
                }
                else if (String.CompareOrdinal(splitInput[i + 2], "R") == 0)
                {
                    parent.Right = child;
                }
                else
                {
                    parent.Random = child;
                }

            }
            return rootNode;
        }
    }
}
