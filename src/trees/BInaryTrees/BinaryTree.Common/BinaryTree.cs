using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.ComponentModel.Design.Serialization;
using System.Linq;
using System.Runtime;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree.Common
{
    public class BinaryTree<TKey> where TKey:IComparable<TKey>
    {
        private Node<TKey> _root;
        public BinaryTree(Node<TKey> root)
        {
            _root = root;
        }

        public Node<TKey> Root => _root;


    }

    //public class BinaryTree<T,TKey> where T : Node<TKey> where TKey:IComparable<TKey>
    //{
    //    private T _root;
    //    public BinaryTree(Node<TKey> root)
    //    {
    //        _root = root;
    //    }

    //    public Node<TKey> Root => _root;


    //}


}
