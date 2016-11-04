using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace BinaryTree.Common
{

    public class BST<TKey, TValue> where TKey : IComparable<TKey> where TValue : class
    {
        private class Node
        {
            public Node(TKey key, TValue value) //, int rank)
            {
                Key = key;
                Value = value;
                Size = 1;
                Height = 1;
            }
            public TKey Key { get; }
            public TValue Value { get; set; }
            public Node Left { get; set; }
            public Node Right { get; set; }
            public int Size { get; set; }

            public int Height { get; set; }
        }

        private Node _root;

        public void Put(TKey key, TValue val)
        {
            _root = Put(_root, key, val);
        }

        public int Size()
        {
            return Size(_root);
        }
        private int Size(Node x)
        {
            if (x == null) return 0;

            return x.Size;
        }

        private Node Put(Node node, TKey key, TValue val)
        {
            if (node == null)
                return new Node(key, val);

            var keyComparison = key.CompareTo(node.Key);
            if (keyComparison < 0)
            {
                node.Left = Put(node.Left, key, val);
                node.Size = Size(node.Left) + Size(node.Right) + 1;
                node.Height = Max(Height(node.Left), Height(node.Right)) + 1;
            }
            else if (keyComparison > 0)
            {
                node.Right = Put(node.Right, key, val);
                node.Size = Size(node.Left) + Size(node.Right) + 1;
                node.Height = Max(Height(node.Left), Height(node.Right)) + 1;
            }
            else
            {
                node.Value = val;
            }

            return node;
        }

        private int Max(int i, int j)
        {
            return i >= j ? i : j;
        }

        public TValue Get(TKey key)
        {
            return Get(_root, key);
        }

        private TValue Get(Node node, TKey key)
        {
            if (node == null)
                return default(TValue);

            var keyComparison = key.CompareTo(node.Key);
            if (keyComparison == 0)
                return node.Value;
            else if (keyComparison < 0)
                return Get(node.Left, key);
            else
                return Get(node.Right, key);

        }

        public TValue Min()
        {
            return Min(_root);
        }

        private TValue Min(Node node)
        {
            if (node == null)
                return default(TValue);

            while (node.Left != null)
                node = node.Left;

            return node.Value;
        }

        public TValue Mx()
        {
            return Max(_root);
        }
        private TValue Max(Node node)
        {
            if (node == null)
                return default(TValue);

            while (node.Right != null)
                node = node.Right;

            return node.Value;
        }

        public int Rank(TKey key)
        {
            return Rank(_root, key, 0);
        }

        private int Rank(Node node, TKey key, int currentRank)
        {
            if (node == null)
                return currentRank + 1;

            var keyComparison = key.CompareTo(node.Key);
            if (keyComparison == 0)
            {
                return currentRank + Size(node) - Size(node.Right);
            }
            else if (keyComparison < 0)
            {
                return Rank(node.Left, key, currentRank);
            }
            else
            {
                currentRank = currentRank + Size(node) - Size(node.Right);
                return Rank(node.Right, key, currentRank);
            }
        }


        public bool Floor(TKey key, out TKey floorKey)
        {
            var floor = Floor(_root, key);
            if (floor != null)
            {
                floorKey = floor.Key;
                return true;
            }
            else
            {
                floorKey = default(TKey);
                return false;
            }
        }

        public TKey Floor(TKey key)
        {
            var floor = Floor(_root, key);
            return floor != null ? floor.Key : default(TKey);
        }

        private Node Floor(Node node, TKey key)
        {
            if (node == null)
                return null;
            var keyComparison = key.CompareTo(node.Key);
            if (keyComparison == 0)
                return node;
            else if (keyComparison < 0)
            {
                return Floor(node.Left, key);
            }
            else
            {
                var floor = Floor(node.Right, key);
                return floor ?? node;
            }
        }
        public TKey Ceiling(TKey key)
        {
            var ceiling = Ceiling(_root, key);
            return ceiling != null ? ceiling.Key : default(TKey);
        }
        private Node Ceiling(Node node, TKey key)
        {
            if (node == null)
                return null;
            var keyComparison = key.CompareTo(node.Key);
            if (keyComparison == 0)
                return node;
            else if (keyComparison > 0)
            {
                return Ceiling(node.Right, key);
            }
            else
            {
                var ceiling = Ceiling(node.Left, key);
                return ceiling ?? node;
            }
        }

        public void DeleteMin()
        {
            Node deletedNode = null;
            _root = DeleteMin(_root, out deletedNode);
            if (deletedNode != null)
                Console.WriteLine(deletedNode.Key);
        }

        private Node DeleteMin(Node n, out Node deltedNode)
        {
            if (n == null)
            {
                deltedNode = null; return null;
            }
            if (n.Left == null)
            {
                deltedNode = n;
                return n.Right;
            }

            n.Left = DeleteMin(n.Left, out deltedNode);
            n.Size = Size(n.Left) + Size(n.Right) + 1;
            n.Height = Max(Height(n.Left), Height(n.Right)) + 1;

            return n;

        }

        public void Delete(TKey key)
        {
            _root = Delete(_root, key);
            if (_root != null)
                _root.Size = Size(_root.Left) + Size(_root.Right) + 1;
        }




        private Node Delete(Node node, TKey key)
        {
            if (node == null) return null;

            var keyComparision = key.CompareTo(node.Key);
            if (keyComparision < 0)
            {
                node.Left = Delete(node.Left, key);
                node.Size = Size(node.Left) + Size(node.Right) + 1;
                return node;
            }
            else if (keyComparision > 0)
            {
                node.Right = Delete(node.Right, key);
                node.Size = Size(node.Left) + Size(node.Right) + 1;
                return node;
            }
            else
            {
                if (node.Right == null && node.Left == null)
                    return null;
                else if (node.Left == null && node.Right != null)
                    return node.Right;
                else if (node.Right == null && node.Left != null)
                    return node.Left;
                else
                {
                    var tempNode = node.Right;
                    Node parent = node;
                    if (tempNode.Left == null)
                    {
                        parent.Right = Delete(tempNode, tempNode.Key);
                    }
                    else
                    {
                        while (tempNode.Left != null)
                        {
                            parent = tempNode;
                            tempNode = tempNode.Left;
                        }
                        parent.Left = Delete(tempNode, tempNode.Key);
                    }
                    RecalculateSize(parent);
                    RecalculateHeight(parent);
                    tempNode.Left = node.Left;
                    tempNode.Right = node.Right;
                    RecalculateSize(tempNode);
                    RecalculateHeight(tempNode);
                    return tempNode;
                }
            }
        }

        private Node DeleteUpdated(Node node, TKey key)
        {
            if (node == null) return null;

            var keyComparision = key.CompareTo(node.Key);
            if (keyComparision < 0)
            {
                node.Left = DeleteUpdated(node.Left, key);
                node.Size = Size(node.Left) + Size(node.Right) + 1;
                return node;
            }
            else if (keyComparision > 0)
            {
                node.Right = DeleteUpdated(node.Right, key);
                node.Size = Size(node.Left) + Size(node.Right) + 1;
                return node;
            }
            else
            {
                if (node.Right == null && node.Left == null)
                    return null;
                else if (node.Left == null && node.Right != null)
                    return node.Right;
                else if (node.Right == null && node.Left != null)
                    return node.Left;
                else
                {
                    var tempNode = node.Right;
                    Node parent = node;
                    if (tempNode.Left == null)
                    {
                        parent.Right = DeleteUpdated(tempNode, tempNode.Key);
                    }
                    else
                    {
                        while (tempNode.Left != null)
                        {
                            parent = tempNode;
                            tempNode = tempNode.Left;
                        }
                        parent.Left = Delete(tempNode, tempNode.Key);
                    }
                    RecalculateSize(parent);
                    RecalculateHeight(parent);
                    tempNode.Left = node.Left;
                    tempNode.Right = node.Right;
                    RecalculateSize(tempNode);
                    RecalculateHeight(tempNode);
                    return tempNode;
                }
            }
        }


        private void RecalculateHeight(Node n)
        {
            n.Height = Max(Height(n.Left), Height(n.Right)) + 1;
        }

        private void RecalculateSize(Node node)
        {
            node.Size = Size(node.Right) + Size(node.Left) + 1;
        }

        private class BFSHelper
        {
            public BFSHelper(Node node, int level)
            {
                Node = node;
                Level = level;
            }
            public Node Node { get; }
            public int Level { get; }
        }
        public void PrintTree()
        {
            if (_root != null)
            {
                int currentLevel = 0;
                Queue<BFSHelper> q = new Queue<BFSHelper>();
                q.Enqueue(new BFSHelper(_root, currentLevel)); //You don't need to write the root here, it will be written in the loop
                while (q.Count > 0)
                {
                    var temp = q.Dequeue();
                    Node n = temp.Node;
                    if (currentLevel != temp.Level)
                    {
                        Console.WriteLine("");
                        Console.WriteLine("---------");
                        currentLevel = temp.Level;
                    }
                    Console.Write(n.Key + " "); //Only write the value when you dequeue it


                    if (n.Left != null)
                    {
                        q.Enqueue(new BFSHelper(n.Left, temp.Level + 1)); //enqueue the left child
                    }
                    if (n.Right != null)
                    {
                        q.Enqueue(new BFSHelper(n.Right, temp.Level + 1)); //enque the right child
                    }
                }
            }
        }

        public int Height()
        {
            return Height(_root);
        }

        public int HeightRecursive()
        {
            return HeightRecursive(_root);
        }

        private int Height(Node n)
        {
            if (n == null) return 0;
            return n.Height;
        }

        private int HeightRecursive(Node node)
        {
            if (node == null) return 0;

            var leftTreeHeight = Height(node.Left);
            var rightTreeHeight = Height(node.Right);
            return 1 + (leftTreeHeight >= rightTreeHeight ? leftTreeHeight : rightTreeHeight);
        }

    }

}
