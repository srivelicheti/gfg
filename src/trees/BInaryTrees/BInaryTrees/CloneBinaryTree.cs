using BinaryTree.Common;
using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace BInaryTrees
{
    public class Node 
    {

        public Node(int key) //, int rank)
        {
            Key = key;
        }
        public int Key { get; }
        public Node Left { get; set; }
        public Node Right { get; set; }

        public Node Random { get; set; }

    }

    class CloneBinaryTree
    {
        public static Node Clone(string input)
        {
            var bst = GfgBinaryTreeHelper.BuildFromDelimitedTextWithRandomPointer(input);
            return Clone(bst);
        }

        private static IDictionary<int,Node> _clonedMap = new Dictionary<int, Node>();
        private static Node Clone(Node nodeToClone, Node parent = null, bool? isLeftLinkOfParent = null)
        {
            if (nodeToClone == null) return null;
            var cloned = _clonedMap.ContainsKey(nodeToClone.Key) ? 
                _clonedMap[nodeToClone.Key] : new Node(nodeToClone.Key);
            _clonedMap.Add(cloned.Key,cloned);
            if (parent != null)
            {
                if (isLeftLinkOfParent.GetValueOrDefault()) parent.Left = cloned;
                else parent.Right = cloned;
            }
            cloned.Left = Clone(nodeToClone.Left, cloned, true);
            cloned.Right = Clone(nodeToClone.Right, cloned, false);
            if (nodeToClone.Random != null)
            {
                var random = _clonedMap.ContainsKey(nodeToClone.Random.Key) ? _clonedMap[nodeToClone.Random.Key] : null;
                if (random == null)
                {
                    random = new Node(nodeToClone.Random.Key);
                    _clonedMap.Add(random.Key,random);
                }
                cloned.Random = random;
            }
            return cloned;
        }

       
    }
}
