using System;

namespace BinaryTree.Common
{
    public class Node<TKey, TValue> where TKey : IComparable<TKey> where TValue : class
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
        public Node<TKey, TValue> Left { get; set; }
        public Node<TKey, TValue> Right { get; set; }
        public int Size { get; set; }

        public int Height { get; set; }
    }


    public class Node<TKey> where TKey : IComparable<TKey>
    {

        public Node(TKey key) //, int rank)
        {
            Key = key;
        }
        public TKey Key { get; }
        public Node<TKey> Left { get; set; }
        public Node<TKey> Right { get; set; }
    }
}